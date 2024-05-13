#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
const ll INF = 1e9;
const ll MINF = -1e9;
const ll EPS = 1e-9;
const ll MOD = 1e7+7;
 
#define rvi(a) for (int i = 0; i < a.size(); i++) scanf("%d",&a[i]);
#define rvl(a) for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
#define rvd(a) for (int i = 0; i < a.size(); i++) scanf("%llf",&a[i]);
 
void solve() {
    int k; scanf("%d",&k);
}
 
int main() {
    int n; cin >> n;
 
    stack<int> a, b, c;
    vector<string> res;
 
    for (int i = 0; i < n; i++){
        int num; cin >> num;
        a.push(num);
    }
 
    while (!b.empty() || !a.empty()){
        if (c.empty()){
            if (!a.empty() && a.top() != 1){
                res.push_back("A B");
                b.push(a.top());
                a.pop();
            }
            else {
                res.push_back("A C");
                c.push(a.top());
                a.pop();
            }
        }
        else {
            if (!b.empty() && b.top() == c.top() + 1){
                res.push_back("B C");
                c.push(b.top());
                b.pop();
                continue;
            }
            if (a.empty() && b.top() != c.top() + 1){
                cout << -1 << "\n";
                return 0;
            }
            if (!a.empty() && a.top() == c.top() + 1){
                res.push_back("A C");
                c.push(a.top());
                a.pop();
                continue;
            }
            if (!a.empty() && a.top() != c.top() + 1){
                res.push_back("A B");
                b.push(a.top());
                a.pop();
                continue;
            }
        }
    }
 
    cout << res.size() << "\n";
    for (string s : res){
        cout << s << "\n";
    }
 
    return 0;
}