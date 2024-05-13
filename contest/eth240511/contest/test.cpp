#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(int k, const vector<int>& types, const vector<int>& hours) {
    vector<long long> prefix_sum(k + 1, 0);
    for (int i = 0; i < types.size(); ++i) {
        prefix_sum[min(k, hours[i])] += types[i];
    }

    for (int i = 1; i <= k; ++i) {
        prefix_sum[i] += prefix_sum[i - 1];
        if (prefix_sum[i] < i) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> types(n);
        vector<int> hours(n);

        for (int i = 0; i < n; ++i) {
            cin >> types[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> hours[i];
        }

        int low = 0;
        int high = n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(mid, types, hours)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
