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

const int N = 205;

pll a[N];
ll n, p[N], s[N];

struct edge {
    ll x, y, dist;
    bool operator< (const edge& other) const {
        return dist < other.dist;
    }
};

vector<edge> edges;

ll root(ll x) {
    if (p[x] == x) return x;
    return p[x] = root(p[x]);
}

void merge(ll x, ll y) {
    x = root(x), y = root(y);
    if (x != y) {
        if (s[x] < s[y]) swap(x, y);
        p[y] = x;
        s[x] += s[y];
    }
}

ll dist(int i, int j) {
    ll dx = a[i].first - a[j].first, dy = a[i].second - a[j].second;
    return dx * dx + dy * dy;
}

bool valid(ll mid) {
    for (int i = 0; i < n; ++i)
        p[i] = i, s[i] = 1;

    for (auto& x : edges) 
        if (x.dist <= mid) merge(x.x, x.y);

    return root(0) == root(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll T = 1;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            for (int j = 0; j < i; ++j)
                edges.push_back({i, j, dist(i, j)});
        }

        ll l = 0, r = 1e9;
        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (valid(mid)) 
                r = mid;
            else 
                l = mid + 1;
        }
        cout << "Scenario #" << T++ << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << sqrt(l) << endl << endl;
        edges.clear();
    }
    return 0;
}
