#include <iostream>
using namespace std;

template<typename T>
T binexp(T b, T e) {
    T res = 1;
    for (; e; b = b * b, e /=2)
        if (e&1)  res = res * b;
    return res;
}