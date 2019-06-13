// 11413 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll N = 1e3 + 5;
const ll INF = 1e10;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll n, m, a[N];

bool valid(ll mid) {
    ll cnt = 1, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > mid) {
            return false;
        }
        if (sum + a[i] <= mid) {
            sum += a[i];
        }
        else {
            sum = a[i];
            cnt++;
        }
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll l = 1, r = INF;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (valid(mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
}

