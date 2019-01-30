// 10130 UVa
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
const ll N = 1005;
const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

ll dp[1005][35];
ll t, n, g, k, p[1005], w[1005];

ll solve(ll i, ll j)
{
    if(i == n)
        return 0;
    ll& ret = dp[i][j];
    if(~ret)
        return ret;
    ret = solve(i + 1, j);
    if(j >= w[i])
        ret = max(ret, solve(i + 1, j - w[i]) + p[i]);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n; 
        for(int i = 0; i < n; i++)  
            cin >> p[i] >> w[i];

        cin >> g;
        ll sum = 0;
        while(g--)
        {
            cin >> k;
            sum += solve(0, k);
        }
        cout << sum << endl;
    }
}   