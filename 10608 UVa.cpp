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

const int N = 3e4 + 5;

ll n, m, t, p[N], s[N];

ll root(ll a) {
    if (p[a] == a) return a;
    return p[a] = root(p[a]);
}

void merge(ll a, ll b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (s[b] < s[a]) swap(a, b);
    p[a] = b;
    s[b] += s[a];
    s[a] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) p[i] = i, s[i] = 1;

        for (int i = 0; i < m; ++i) {
            ll a, b; cin >> a >> b;
            merge(a, b);
        }

        ll ans = 0;
        for (int i = 1; i <= n; ++i)  {
            ans = max(ans, s[i]);
        }
        
        cout << ans << endl;
    }
}
