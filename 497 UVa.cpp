#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll t, n;
vector<ll> a;
vector<vector<ll>> dp;

ll to_int(const string& s) {
    ll ret = 0; 
    for (const char& c : s) {
        ret = ret * 10 + (c - '0');
    }
    return ret;
}

ll solve(int cur, int lst) {
    if (cur == n) 
        return 0;
    ll& ret = dp[cur][lst];
    if (~ret) return ret;
    ret = solve(cur + 1, lst);
    if (a[cur] > a[lst])
        ret = max(ret, solve(cur + 1, cur) + 1);
    return ret;
}

void build(int cur, int lst) {
    if (cur == n)
        return;
    ll& ret = dp[cur][lst];
    if (ret == solve(cur + 1, lst)) {
        build(cur + 1, lst);
    } else {
        cout << a[cur] << endl;
        build(cur + 1, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    cin.ignore();

    string s;
    cin.ignore();
    bool ok = false;
    while (t--) {
        if (ok) cout << endl;
        ok = true;
        a.push_back(-INF);
        while (getline(cin, s) && !s.empty()) {
            a.push_back(to_int(s));
        }
        n = (int) a.size();
        dp.resize(n + 1);
        for (auto& i : dp) i.resize(n + 1), fill(i.begin(), i.end(), -1);
        cout << "Max hits: " << solve(1, 0) << endl;
        build(1, 0);
        a.clear();
    }
}
