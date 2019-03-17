// UVa 574
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, t, a[30];
set<vector<ll>> sums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> t >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            vector<ll> tmp;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sum += a[i];
                    tmp.push_back(a[i]);
                }
            }
            if (sum == t) {
                sort(tmp.rbegin(), tmp.rend());
                sums.insert(tmp);
            }
        }
        cout << "Sums of " << t << ":" << endl;
        if (sums.empty()) {
            cout << "NONE" << endl;
        }
        else {
            for (auto it = sums.rbegin(); it != sums.rend(); ++it) {
                int k = (int) it->size();
                vector<ll> tmp = *it;
                for (int i = 0; i < k; ++i) {
                    if (i)
                        cout << "+";
                    cout << tmp[i];
                }
                cout << endl;
            }
        }
        sums.clear();
    }
        
}

