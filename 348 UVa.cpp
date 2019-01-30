// 348 UVa
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

ll dp[15][15];
ll n, c, a[15], b[15];

ll solve(ll l, ll r)
{
    if(l == r)
        return 1;
    ll& ret = dp[l][r];
    if(~ret)
        return ret;
    ret = INF;
    for(int i = l; i < r; i++)
        ret = min(ret, solve(l, i) + solve(i + 1, r) + a[l] * b[i] * b[r]);
    return ret;
}

void build(ll l, ll r)
{
    if(l == r)
        cout << 'A' << l + 1;

    ll& ret = dp[l][r];

    for(int i = l; i < r; i++)
    {
        if(ret == solve(l, i) + solve(i + 1, r) + a[l] * b[i] * b[r])
        {
            cout << '(';
            build(l, i);
            cout << " x ";
            build(i + 1, r);
            cout << ')';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        memset(dp, -1, sizeof(dp));
        cout << "Case " << ++c << ": " ;
        if(n == 1)
            cout << "(A1)" << endl;
        else
        {
            solve(0, n - 1);
            build(0, n - 1);
            cout << endl;
        }
    }
}   
