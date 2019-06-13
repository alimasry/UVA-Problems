// 10667 UVa
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

ll p, s, n, a, b, c, d, board[N][N], b_empty[N][N];

ll getSum(int& i, int& j, int& ii, int& jj)
{
    return board[ii][jj] - board[i - 1][jj] - board[ii][j - 1] + board[i - 1][j - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
#endif
    cin >> p;
    while (p--)
    {
        memset(board, 0, sizeof(board));
        cin >> s >> n;
        while (n--)
        {
            cin >> a >> b >> c >> d;
            for(int i = a; i <= c; i++)
                for(int j = b; j <= d; j++)
                    board[i][j] = 1;
        }

        for(int i = 1; i <= s; i++)
            for(int j = 1; j <= s; j++)
                board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];

        ll maxx = 0;
        for(int i = 1; i <= s; i++)
            for(int j = 1; j <= s; j++)
                for(int ii = i; ii <= s; ii++)
                    for(int jj = j; jj <= s; jj++)
                        if(getSum(i, j, ii, jj) == 0)
                            maxx = max(maxx, (ii - i + 1ll) * (jj - j + 1ll));
                            
        cout << maxx << endl;
    }
}
