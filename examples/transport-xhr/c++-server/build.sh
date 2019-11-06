thrift -gen cpp:no_skeleton= -r ../../Hello.thrift
(cd gen-cpp && g++ -std=c++17 -c *.cpp && ar crs libgen.a *.o)
g++ --std=c++17 -c run-xhr-backend.cpp
g++ --std=c++17 -o run-xhr-backend run-xhr-backend.o gen-cpp/libgen.a -L/usr/local/lib -lthrift
