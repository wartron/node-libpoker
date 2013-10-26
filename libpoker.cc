#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("world"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("score"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(poker, init)  /////////// FUCK! WHY DOES THIS STRIP THE lib PART of libpoker
