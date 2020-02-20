# cth = Chrome + THrift

cth was an attempt to build generic GUI app development framework based on Thrift. All GUI programming would be done in JS client and everything else is done in Thrift server.

Examples are organized around IDL file Hello.thrift.

Thrift-supplied transports suitable for the project are XHR (XmlHTTPRequest) and WS (WebSocket). The Apache Thrift version I've found didn't have WS transport suitable for C++.

The project was abandoned in favor of [dipole](https://github.com/philotymic/dipole).
