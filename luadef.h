#pragma once

// CV_EXPORTS_W : include this file in lua_generated_include

#if defined _WIN32
#  define LUA_CDECL __cdecl
#  define LUA_STDCALL __stdcall
#else
#  define LUA_CDECL
#  define LUA_STDCALL
#endif

#ifndef LUA_EXTERN_C
#  ifdef __cplusplus
#    define LUA_EXTERN_C extern "C"
#  else
#    define LUA_EXTERN_C
#  endif
#endif

#ifndef LUA_EXPORTS
# if (defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined(LUAAPI_EXPORTS)
#   define LUA_EXPORTS __declspec(dllexport)
# elif defined __GNUC__ && __GNUC__ >= 4 && (defined(LUAAPI_EXPORTS) || defined(__APPLE__))
#   define LUA_EXPORTS __attribute__ ((visibility ("default")))
# elif defined __clang__ 
#   define LUA_EXPORTS __attribute__ ((visibility ("default")))
# else
#   define LUA_EXPORTS
# endif
#endif

#ifndef LUAAPI
#  define LUAAPI(rettype) LUA_EXTERN_C LUA_EXPORTS rettype LUA_CDECL
#endif
