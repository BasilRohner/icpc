#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define rvi(v) for (int &i : v) scanf("%d",i);
#define rvl(v) for (ll &i : v) scanf("%d",i); 

#define pi acos(-1)
#define rou cd(cos(2*pi/n), sin(2*pi/n))

vector<int> sieve(int n) {

}

vector<int> lpd(int n) {

}



void fft(vcd &a) {

    int n = a.size();
    if (n==1) return;

    vcd left(n/2), right(n/2);
    codd(a,left); ceve(a,right);
    fft(left); fft(right);

    cd root(1);
    for (int i = 0; 2*i < n; i++) {
        a[i] = left[i] + rou*right[i];
        a[i+n/2] = left[i] - rou*right[i];
        rou *= rouk;
    }
}

void ifft(vcd &a) {

    int n = a.size();
    if (n==1) return;

    vcd left(n/2), right(n/2);
    for (int i = 0; 2*i < n; i++) {
        left[i] = a[2*i];
        right[i] = a[2*i+1];
    }

    ifft(left);
    ifft(right);

    cd rou(1);
    for (int i = 0; 2*i < n; i++) {
        a[i] = left[i] + rou*right[i]; 
        a[i+n/2] = left[i] - rou*right[i];
        a[i] /= 2; a[i+n/2] /= 2;
        rou *= rouk;
    }
}

vi multiply(vi const& a, vi const& b) {

    vcd fa(a.begin(), a.end());
    vcd fb(b.begin(), b.end());

    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa); fft(fb);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    ifft(fa);

    vi res(n);
    for (int i = 0; i < n; i++)
        res[i] = round(fa[i].real());
    return res;
}
