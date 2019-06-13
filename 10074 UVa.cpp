// 10074 UVa
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int N = 1e2 + 5;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const double PI = acos(-1);

ll n, m, mapp[N][N];

ll getSum(int& i, int& j, int& ii, int& jj)
{
    return mapp[ii][jj] - mapp[i - 1][jj] - mapp[ii][j - 1] + mapp[i - 1][j - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
#endif
    while(cin >> n >> m && n && m)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                cin >> mapp[i][j];
                mapp[i][j] += mapp[i - 1][j] + mapp[i][j - 1] - mapp[i - 1][j - 1];
            }
        ll maxx = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(mapp[i][j] - mapp[i - 1][j] - mapp[i][j - 1] + mapp[i - 1][j - 1] == 0)
                    for(int ii = i; ii <= n; ii++)
                        for(int jj = j; jj <= m; jj++)
                            if(getSum(i, j, ii, jj) == 0)
                                maxx = max(maxx, (ii - i + 1ll) * (jj - j + 1ll));
        cout << maxx << endl;
    }
}
