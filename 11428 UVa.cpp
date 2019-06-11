#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 1e4 + 5;

ll n;

ll solve(ll target) {
    ll l = 0, r = target;
    while (l < r) {
        ll mid = l + ((r - l + 1) >> 1);
        if (mid * mid * mid <= target) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n && n) {
        pll ans = {-1, -1};
        for (ll y = 1; y < 100; ++y) {
            for (ll x = y; x <= 100; ++x) {
                if (x * x * x == y * y * y + n) {
                    ans = {x, y};
                    break;
                }
            }
            if (~ans.first) break;
        }
        if (~ans.first) {
            cout << ans.first << ' ' << ans.second << endl;
        } else {
            cout << "No solution" << endl;
        }
    }
}
