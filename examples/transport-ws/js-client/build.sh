rm -rf src/gen-js
(cd src && thrift --gen js:es6 ../../../Hello.thrift)

