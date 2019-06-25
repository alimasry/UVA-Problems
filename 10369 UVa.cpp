#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

const int N = 505;

pll a[N];
ll t, n, m, p[N], s[N];

ll root(ll x) {
    if (x == p[x]) return x;
    return p[x] = root(p[x]);
}

void merge(ll x, ll y) {
    x = root(x), y = root(y);
    if (x != y) {
        if (s[x] > s[y]) swap(x, y);
        p[x] = y;
        s[y] += s[x];
    }
}

ll dist(int x, int y) {
    ll dx = a[x].first - a[y].first, dy = a[x].second - a[y].second;
    return dx * dx + dy * dy;
}

bool valid(ll mid) {
    for (int i = 0; i < m; ++i) 
        p[i] = i, s[i] = 1;

    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j)
            if (dist(i, j) <= mid) merge(i, j);

    set<ll> have;
    for (int i = 0; i < m; ++i) 
        have.insert(root(i));

    return (int(have.size()) <= n); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < m; ++i)
            cin >> a[i].first >> a[i].second;

        ll l = 0, r = 1e6;
        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (valid(mid))
                r = mid;
            else 
                l = mid + 1;
        }
        cout << fixed << setprecision(2) << sqrt(l) << endl;
    }
}
