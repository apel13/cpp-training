//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_HEADERS_H
#define CPP_TRAINING_HEADERS_H

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _USE_MATH_DEFINES

#define unlikely(expr)  __builtin_expect(!!(expr), 0)
#define likely(expr)    __builtin_expect(!!(expr), 1)


#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <forward_list>

#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cmath>
#include <limits>
#include <climits>
#include <numeric>
#include <cassert>
#include <memory>
#include <stdexcept>

#include <bitset>
#include <sstream>
#include <iterator>
#include <regex>

#include <condition_variable>
#include <thread>

using namespace std;

#endif //CPP_TRAINING_HEADERS_H
