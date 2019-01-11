#include <bits/stdc++.h>

using namespace std;

const int N = 35;
const long long INF = 1e9;
typedef pair<int, int> ii;
long double EPS = 1e-6;

int n;
long double matrix[N][N];

long long det()
{
    long double ret = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (fabs(matrix[j][i]) >= EPS)
            {
                if (j != i)
                {
                    ret *= -1;
                    swap(matrix[j], matrix[i]);
                }
                break;
            }
        }
        if (fabs(matrix[i][i]) < EPS)
            return 0;

        ret *= matrix[i][i];
        long double tmp = 1 / matrix[i][i];

        for (int j = 0; j < n; j++)
            matrix[i][j] *= tmp;

        for (int j = i + 1; j < n; j++)
        {
            for (int k = n - 1; k >= i; k--)
            {
                matrix[j][k] -= matrix[i][k] * matrix[j][i];
            }
        }
    }
    return round(ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << int(det()) << endl;
    }
    cout << '*' << endl;
}