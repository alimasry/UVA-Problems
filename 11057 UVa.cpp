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

const int N = 1e4 + 5;

ll n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll sum; cin >> sum;

        pll ans;
        ll diff = INF;
        set<ll> have;
        for (int i = 0; i < n; ++i) {
            if (have.count(sum - a[i]) && llabs(2 * a[i] - sum) < diff) {
                diff = llabs(2 * a[i] - sum);
                ans = {a[i], sum - a[i]};
            }
            have.insert(a[i]);
        }
        if (ans.first > ans.second) swap(ans.first, ans.second);
        cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << "." << endl << endl;
    }
}
