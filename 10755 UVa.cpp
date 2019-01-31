// 10755 UVa
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

ll t, a, b, c, g[25][25][25];

inline ll getSum(int& i, int& j, int& k, int& ii, int& jj, int& kk)
{
    return g[ii][jj][kk] - g[i - 1][jj][kk] - g[ii][j - 1][kk] - g[ii][jj][k - 1] + g[i - 1][j - 1][kk] + g[i - 1][jj][k - 1] + g[ii][j - 1][k - 1] - g[i - 1][j - 1][k - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        for(int i = 1; i <= a; i++)
            for(int j = 1; j <= b; j++)
                for(int k = 1; k <= c; k++)
                {
                    scanf("%lld", &g[i][j][k]);
                    g[i][j][k] += g[i - 1][j][k] + g[i][j - 1][k] + g[i][j][k - 1] - g[i - 1][j - 1][k] - g[i][j - 1][k - 1] - g[i - 1][j][k - 1] + g[i - 1][j - 1][k - 1];
                }

        ll maxx = g[a][b][c];
        for(int i = 1; i <= a; i++)
            for(int j = 1; j <= b; j++)
                for(int k = 1; k <= c; k++)
                    for(int ii = i; ii <= a; ii++)
                        for(int jj = j; jj <= b; jj++)
                            for(int kk = k; kk <= c; kk++)
                                maxx = max(maxx, getSum(i, j, k, ii, jj, kk));
        printf("%lld\n", maxx);
        if(t)
            printf("\n");
    }
} 