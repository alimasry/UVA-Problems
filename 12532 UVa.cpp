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

const int N = 1e5 + 5;

ll n, k, a[N];
ll tree[N << 2], lazy[N << 2], l[N << 2], r[N << 2];
 
// Functions to update when query changes =============================

ll best(ll lCalc, ll rCalc) {
    return lCalc * rCalc;
}

void upd(int i) {
    tree[i] = best(tree[i << 1] + lazy[i << 1], tree[i << 1 | 1] + lazy[i << 1 | 1]);
}
 
void prob(int i) {
    lazy[i << 1] += lazy[i];
    lazy[i << 1 | 1] += lazy[i];
    lazy[i] = 0;
}

// ====================================================================
 
void inc(int s, int e, ll v, int i = 1) {
    if(s > r[i] || e < l[i])
        return;

    if(s <= l[i] && e >= r[i]) {
        tree[i] = v == 0 ? 0 : v > 0 ? 1 : -1;
        return;
    }
 
    prob(i);
 
    inc(s, e, v, i << 1);
    inc(s, e, v, i << 1 | 1);
 
    upd(i);
}

 
ll qry(int s, int e, int i = 1) {
    if(s > r[i] || e < l[i]) // change the return value depending on the query
        return 1;

    if(s <= l[i] && e >= r[i]) // may change if the query change
        return tree[i] + lazy[i];
 
    prob(i);
 
    ll lCalc = qry(s, e, i << 1);
    ll rCalc = qry(s, e, i << 1 | 1);
 
    upd(i);
 
    return best(lCalc, rCalc);
}
 
void init(int i, int s, int e) {
    l[i] = s;
    r[i] = e;
    lazy[i] = 0;
 
    if(s == e) {
        tree[i] = a[s] == 0 ? 0 : a[s] > 0 ? 1 : -1;
        return;
    }
 
    int m = s + ((e - s) >> 1);

    init(i << 1, s, m);
    init(i << 1 | 1, m + 1, e);

    upd(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> k) {

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        init(1, 0, n - 1);

        string ans;
        while (k--) {
            char c; cin >> c;
            int x, y; cin >> x >> y;
            if (c == 'P') {
                --x, --y;
                ll calc = qry(x, y);
                ans += (calc == 0 ? '0' : calc > 0 ? '+' : '-');
            } else {
                --x;
                inc(x, x, y);
            }
        }
        cout << ans << endl;
    }
}
