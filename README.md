# cth = Chrome + Thrift

cth is an attempt to build generic GUI app development framework. All GUI programming is done in JS client and everything else is done in server. Apache Thrift used to organize client-server communication.

Examples are organized around IDL file Hello.thrift

Thrift-supplied transports suitable for cth are XHR (XmlHTTPRequest) and WS (WebSocket). The Apache Thrift version I've found didn't have WS transport suitable for C++.
