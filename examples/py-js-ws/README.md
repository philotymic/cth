based on code from https://github.com/omribahumi/python_tornado_thrift

Working example of how to use thrift WebSocket transport.
Example tested and confirmed to work on Chrome.

Build steps:
```
  npm install
  sh -x build.sh
  ./node_modules/rollup/dist/bin/rollup -c
```

to start server:
```
 python run-ws-backend.py
``` 
to test server:
```
 python run-ws-backend.py test
```

Point chrome browser to index.html. Button REQ will send websocket request to python server.
