import ipdb
import sys
sys.path.append('gen-py')

from hello import Hello

from thrift.transport import TSocket, THttpClient
from thrift.transport import TTransport
from thrift.protocol import TJSONProtocol
from thrift.server import TServer
from my_thttpserver import MyTHttpServer

class HelloHandler:
    def __init__(self):
        self.log = {}

    def sayHello(self):
        print 'Hello'
        return 'Hello'

def do_test():
    transport = THttpClient.THttpClient('http://localhost:9090')
    transport = TTransport.TBufferedTransport(transport)
    protocol = TJSONProtocol.TJSONProtocol(transport)

    client = Hello.Client(protocol)
    transport.open()
    print "server response:", client.sayHello()
    transport.close()

    
if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        do_test()
        sys.exit(0)
        
    handler = HelloHandler()
    processor = Hello.Processor(handler)
    #transport = TSocket.TServerSocket(host='127.0.0.1', port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TJSONProtocol.TJSONProtocolFactory()

    #server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    host = 'localhost'; port = 9090
    
    server = MyTHttpServer(processor, (host, port), pfactory)
    
    # You could do one of these for a multithreaded server
    # server = TServer.TThreadedServer(
    #     processor, transport, tfactory, pfactory)
    # server = TServer.TThreadPoolServer(
    #     processor, transport, tfactory, pfactory)

    print('Starting the server...')
    server.serve()
    print('done.')
