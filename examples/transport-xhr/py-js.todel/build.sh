rm -rf gen-py src/gen-js
thrift --gen py ../../Hello.thrift
(cd src && thrift --gen js:es6 ../../../Hello.thrift)

