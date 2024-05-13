#include <iostream>
using namespace std;

template<class T>
struct SubMatrix {

    typedef vector<T> vec;
    typedef vector<vector<T>> mat;
    mat p;

    SubMatrix(mat& v) {
        p.assign(v.size(), vec(v.at(0).size()));
        for (int r = 0; r < v.size(); r++)
            for (int c = 0; c < v.at(0).size(); c++)
                p[r+1][c+1] = v[r][v] + p[r][c+1] + p[r+1][c] - p[r][c];
                
    }
    T sum(int u, int l, int d, int r) {
        return p[d][r] - p[d][l] - p[u][r] + p[u][l];
    }
};