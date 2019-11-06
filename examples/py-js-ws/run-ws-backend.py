import ipdb
import os
import sys
sys.path.append('./gen-py')

from hello import Hello

from thrift.protocol.TJSONProtocol import *
from thrift.server import TServer
from thrift.transport import TTransport
import tornado
from tornado.websocket import WebSocketHandler

class HelloHandler:
    def __init__(self):
        pass

    def sayHello(self):
        print 'Hello'
        return 'Hello'

class ThriftWSHandler(WebSocketHandler, TServer.TServer):
    def initialize(self, processor, inputProtocolFactory, outputProtocolFactory):
        TServer.TServer.__init__(self, processor, None, None, None,
                                 inputProtocolFactory, outputProtocolFactory)

    def check_origin(self, origin):
        print "check_origin", origin
        return True
        #ipdb.set_trace()
        #return WebSocketHandler.check_origin(self, origin)
        
    def open(self):
        print "websocket open"
        #ipdb.set_trace()

    def on_close(self):
        print "websocket closed"
        
    def on_message(self, message):
        self.write_message(self.handle_request(message))

    def handle_request(self, data):
        #ipdb.set_trace()
        itrans = TTransport.TMemoryBuffer(data)
        otrans = TTransport.TMemoryBuffer()
        iprot = self.inputProtocolFactory.getProtocol(itrans)
        oprot = self.outputProtocolFactory.getProtocol(otrans)
        self.processor.process(iprot, oprot)
        return otrans.getvalue()
    
def main():
    handler = HelloHandler()
    processor = Hello.Processor(handler)
    pfactory = TJSONProtocolFactory()

    application = tornado.web.Application([
        (r"/thrift", ThriftWSHandler,
            dict(processor=processor, inputProtocolFactory=pfactory,
                 outputProtocolFactory=pfactory))
    ])

    application.listen(8888)
    tornado.ioloop.IOLoop.instance().start()

def do_test():
    import TWebsocketClient
    transport = TWebsocketClient.TWebsocketClient("ws://localhost:8888/thrift")
    protocol = TJSONProtocol(transport)
    client = Hello.Client(protocol)
    transport.open()
    print client.sayHello()
    transport.close()
        
if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        do_test()
        sys.exit(0)
    main()

