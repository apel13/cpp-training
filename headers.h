//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_HEADERS_H
#define CPP_TRAINING_HEADERS_H

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _USE_MATH_DEFINES

#define unlikely(expr)  __builtin_expect(!!(expr), 0)
#define likely(expr)    __builtin_expect(!!(expr), 1)


#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cassert>
#include <climits>
#include <stack>
#include <bitset>
#include <list>
#include <set>
#include <queue>
#include <sstream>
#include <iterator>
#include <regex>
#include <queue>
#include <deque>

using namespace std;

#endif //CPP_TRAINING_HEADERS_H
