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

ll n, q;

struct SegmentTree {
    vector<ll> tree, lazy, l, r;

    SegmentTree(int size) : tree(4 * size), lazy(4 * size), l(4 * size), r(4 * size) {
        init(1, 0, size - 1);
    }
     
    // Functions to update when query changes =============================

    ll best(ll lCalc, ll rCalc) {
        return lCalc + rCalc;
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
     
    void inc(int a, int b, ll v, int i = 1) {
        if(a > r[i] || b < l[i])
            return;

        if (l[i] == r[i]) {
            tree[i] = v;
            return;
        }
     
        prob(i);
     
        inc(a, b, v, i << 1);
        inc(a, b, v, i << 1 | 1);
     
        upd(i);
    }

     
    ll qry(int a, int b, int i = 1) {
        if(a > r[i] || b < l[i]) // change the return value depending on the query
            return 0;

        if(a <= l[i] && b >= r[i]) // may change if the query change
            return tree[i] + lazy[i];
     
        prob(i);
     
        ll lCalc = qry(a, b, i << 1);
        ll rCalc = qry(a, b, i << 1 | 1);
     
        upd(i);
     
        return best(lCalc, rCalc);
    }
     
    void init(int i, int a, int b) {
        l[i] = a;
        r[i] = b;
     
        if(a == b)
            return;
     
        int m = a + ((b - a) >> 1);

        init(i << 1, a, m);
        init(i << 1 | 1, m + 1, b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (cin >> n && n) {
        if (t > 1)
            cout << endl;

        SegmentTree resistance(n);

        for (int i = 0; i < n; ++i) {
            ll res; cin >> res;
            resistance.inc(i, i, res);
        }

        cout << "Case " << t++ << ":" << endl;
        string s;
        while (cin >> s && s != "END") {
            ll x, y; cin >> x >> y;
            --x;
            if (s == "M") 
                cout << resistance.qry(x, --y) << endl;
            else
                resistance.inc(x, x, y);
        }
    }
}
