Working example of how to use thrift XmlHTTPRequest transport.
XmlHTTPRequest-based code in apache thrift look abandoned. I had
to make some changes in both python (my_thttpserver.py) and 
browser js code (my_thrift.js)

Example tested and confirmed to work on Chrome.

Build steps:
```
  npm install
  sh -x build.sh
  ./node_modules/rollup/dist/bin/rollup -c
```

to start server:
```
 python run-xhr-backend.py
``` 
to test server:
```
 python run-xhr-backend.py test
```

Point chrome browser to index.html. Button REQ will send XmlHTTPRequest to python server.
