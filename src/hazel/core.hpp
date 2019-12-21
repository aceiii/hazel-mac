#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifdef _MSC_VER
  #ifdef HZ_SHARED_LIBRARY
    #define HZ_API __declspec(dllexport)
  #else
    #define HZ_API __declspec(dllimport)
  #endif
#else
  #ifdef HZ_SHARED_LIBRARY
    #define HZ_API __attribute__((visibility("default")))
  #else
    #define HZ_API
  #endif
#endif

#ifdef HZ_DEBUG
  #define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
  #define HZ_ASSERT(x, ...)                             \
    {                                                   \
      if (!x) {                                         \
        HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); \
      }                                                 \
    }

  #define HZ_CORE_ASSERT(x, ...)                            \
    {                                                       \
      if (!x) {                                             \
        HZ_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__) \
      }                                                     \
    }
#else
  #define HZ_ASSERT(x, ...)
  #define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
