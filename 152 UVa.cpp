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

struct point {
    ll x, y, z;
};

int dist(point a, point b) {
    ll dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return min((int) floor(sqrt(dx * dx + dy * dy + dz * dz)), 11);
}

const int N = 5005;

int d[15], minn[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    point p;
    vector<point> v;
    while (cin >> p.x >> p.y >> p.z && (p.x || p.y || p.z)) 
        v.push_back(p);
    
    memset(minn, 0x7F, sizeof(minn));

    int n = (int) v.size();
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            minn[i] = min(minn[i], dist(v[i], v[j]));
        }

    for (int i = 0; i < n; ++i)
        ++d[minn[i]];

    for (int i = 0; i < 10; ++i)
        cout << setw(4) << d[i];
    cout << endl;
}
