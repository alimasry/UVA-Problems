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

const int N = 1e5 + 5;

ll t, n, a[N];

bool valid(ll mid) {
    if (a[0] > mid) return false;
    if (a[0] == mid) --mid;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] == mid)
            --mid;
        else if (a[i] - a[i - 1] > mid)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    for (int T = 1; T <= t; ++T) {
        cin >> n;
        
        for (int i = 0; i < n; ++i) 
            cin >> a[i];

        ll l = 1, r = INF;
        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (valid(mid)) 
                r = mid;
            else
                l = mid + 1;
        }
        cout << "Case " << T << ": " << l << endl;
    }
}
