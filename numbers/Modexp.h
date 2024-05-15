#include <iostream>
using namespace std;

/* Compute modinv with modexp(b, m-2, m) */
template<typename T>
T modexp(T b, T e, T m) {
    T res = 1;
    for (; e; b = b * b % m, e /=2)
        if (e&1)  res = res * b % m;
    return res;
}