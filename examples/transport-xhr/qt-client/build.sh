thrift -gen cpp:no_skeleton= -r ../../Hello.thrift
(cd gen-cpp && g++ --std=c++17 -c *.cpp && ar crs libgen.a *.o)
