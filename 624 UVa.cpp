// UVa 624
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

ll n, k, a[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> k) {
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        ll ans = 0, maxx = 0;
        for (int mask = 0; mask < (1 << k) ; ++mask) {
            ll sum = 0;
            for (int i = 0; i < k; ++i) {
                if (mask & (1 << i)) {
                    sum += a[i];
                }
            }
            if (sum <= n && sum > maxx) {
                maxx = sum;
                ans = mask;
            }
        }
        for (int i = 0; i < k; ++i) {
            if (ans & (1 << i))
                cout << a[i] << ' ';
        }
        cout << "sum:" << maxx << endl;
    }
}


