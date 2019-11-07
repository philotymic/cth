#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/THttpServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/TToString.h>
//#include <thrift/stdcxx.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "gen-cpp/Hello.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::concurrency;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace hello;

class HelloHandler : public HelloIf {
public:
  HelloHandler() {}
  void sayHello(std::string& ret) {
    std::cout << "HelloHandler::sayHello called" << std::endl;
    ret = "Hello";
  }
};

/*
  this is example code from thrift/tutorial/cpp/CppServer.cpp

  CalculatorIfFactory is code generated.
  CalculatorCloneFactory is useful for getting access to the server side of the
  transport.  It is also useful for making per-connection state.  Without this
  CloneFactory, all connections will end up sharing the same handler instance.
*/
/*
class CalculatorCloneFactory : virtual public CalculatorIfFactory {
 public:
  virtual ~CalculatorCloneFactory() {}
  virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo)
  {
    stdcxx::shared_ptr<TSocket> sock = stdcxx::dynamic_pointer_cast<TSocket>(connInfo.transport);
    cout << "Incoming connection\n";
    cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
    cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
    cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
    cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
    return new CalculatorHandler;
  }
  virtual void releaseHandler( ::shared::SharedServiceIf* handler) {
    delete handler;
  }
};
*/

int main() {
  auto handler = make_shared<HelloHandler>();
  auto processor = make_shared<HelloProcessor>(handler);
  auto server_socket = make_shared<TServerSocket>(9090);
  auto transport_factory = make_shared<THttpServerTransportFactory>();
  auto protocol = make_shared<TJSONProtocolFactory>();
  
  TSimpleServer server(processor, server_socket, transport_factory, protocol);

  cout << "Starting the server..." << endl;
  server.serve();
  cout << "Done." << endl;
  return 0;
}
