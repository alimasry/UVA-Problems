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

const int N = 2e5 + 5;

map<string, ll> Hash;
ll t, n, p[N], s[N], cnt;

ll root(ll a) {
    if (p[a] == a) return a;
    return p[a] = root(p[a]);
}

ll root(string& a) {
    if (Hash.insert({a, cnt}).second) {
        p[cnt] = cnt, s[cnt] = 1;
        ++cnt;
    }
    return root(Hash[a]);
}

void merge(string& one, string& two) {
    ll a = root(one), b = root(two);
    if (a != b) {
        if (s[b] < s[a]) 
            swap(a, b);
        p[a] = b;
        s[b] += s[a];
        s[a] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cnt = 0;
        cin >> n;
        while (n--) {
            string one, two; cin >> one >> two;
            merge(one, two);
            cout << s[root(one)] << endl;
        }
        Hash.clear();
    }
}
