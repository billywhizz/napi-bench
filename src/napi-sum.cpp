#include <node_api.h>

napi_value Sum(napi_env env, napi_callback_info args) {
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, args, &argc, argv, nullptr, nullptr);
  int a = 0;
  napi_get_value_int32(env, argv[0], &a);
  int b = 0;
  napi_get_value_int32(env, argv[1], &b);
  napi_value result;
  napi_create_int32(env, a + b, &result);
  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value sum_fn;
  status = napi_create_function(env, nullptr, 0, Sum, nullptr, &sum_fn);
  if (status != napi_ok) return NULL;
  status = napi_set_named_property(env, exports, "sum", sum_fn);
  if (status != napi_ok) return NULL;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
