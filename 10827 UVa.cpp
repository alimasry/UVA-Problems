// 10827 UVa
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int N = 105;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
const double PI = acos(-1);

ll t, n, b[N][N];

ll sum(int i, int j, int ii, int jj)
{
    return b[ii][jj] - b[i - 1][jj] - b[ii][j - 1] + b[i - 1][j - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                cin >> b[i][j];
                b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            }

        ll maxx = LLONG_MIN;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int ii = i; ii <= n; ii++)
                    for(int jj = j; jj <= n; jj++)
                        maxx = max(maxx, sum(i, j, ii, jj));

        for(int i = 1; i <= n; i++)
            for(int ii = i; ii <= n; ii++)
                for(int jj = 1; jj < n; jj++)
                    for(int kk = n; kk > jj; kk--)
                        maxx = max(maxx, sum(i, 1, ii, jj) + sum(i, kk, ii, n));

        for(int j = 1; j <= n; j++)
            for(int ii = 1; ii < n; ii++)
                for(int jj = j; jj <= n; jj++)
                    for(int kk = n; kk > ii; kk--)
                        maxx = max(maxx, sum(1, j, ii, jj) + sum(kk, j, n, jj));

        for(int i = 1; i < n; i++)
            for(int j = 1; j < n; j++)
                for(int ii = n; ii > i; ii--)
                    for(int jj = n; jj > j; jj--)
                        maxx = max(maxx, sum(1, 1, i, j) + sum(1, jj, i, n) + sum(ii, 1, n, j) + sum(ii, jj, n, n));

        cout << maxx << endl;
    }

}
