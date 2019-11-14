# cth = Chrome + THrift

cth is an attempt to build generic GUI app development framework. All GUI programming is done in JS client and everything else is done in server. Apache Thrift used to organize client-server communication.

Examples are organized around IDL file Hello.thrift

Thrift-supplied transports suitable for cth are XHR (XmlHTTPRequest) and WS (WebSocket). The Apache Thrift version I've found didn't have WS transport suitable for C++.

see also [czc](https://github.com/philotymic/czc) which is twin project where [ZeroC ICE](https://zeroc.com/) is used to connect Chrome/JS client and server (C++ or python)
