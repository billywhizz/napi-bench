
#include "ffast.h"

namespace ffast {


int32_t sumFast(void* p, int32_t p0, int32_t p1);
v8::CTypeInfo cargssum[3] = {
v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rcsum = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infosum = v8::CFunctionInfo(rcsum, 3, cargssum);
v8::CFunction pFsum = v8::CFunction((const void*)&sumFast, &infosum);


int sum (int a, int b) {
  return a + b;
}


void sum_slowSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = sum(v0, v1);
  args.GetReturnValue().Set(rc);
}


void sumSlow(const FunctionCallbackInfo<Value> &args) {
  int32_t v0 = Local<Integer>::Cast(args[0])->Value();
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = sum(v0, v1);
  args.GetReturnValue().Set(rc);
}

int32_t sumFast(void* p, int32_t p0, int32_t p1) {
  int32_t v0 = p0;
  int32_t v1 = p1;
  return sum(v0, v1);
}

void Initialize(Local<Object> exports) {
  Isolate* isolate = Isolate::GetCurrent();
  NODE_SET_METHOD(exports, "sum_slow", sum_slowSlow);
  NODE_SET_FAST_METHOD(isolate, exports, "sum", &pFsum, sumSlow);

}

//NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

NODE_MODULE_INIT() {
    Initialize(exports);
}
}
