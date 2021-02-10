
# #pragma
#pragma comment(linker, "/stack:200000000")  
#pragma GCC optimize("Ofast")  
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")  


## paking
#pragma pack(push, 1)  
/* class declaration */  
#pragma pack(pop)  



## conditional with priority
#define unlikely(expr)  __builtin_expect(!!(expr), 0)  
#define likely(expr)    __builtin_expect(!!(expr), 1)




# compilers:
clang++   

- `Xclang -fdump-record-layouts main.cpp` 
- `Xclang -fdump-vtable-layouts main.cpp`  









