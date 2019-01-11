// 10168 UVa

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<bool> isPrime(10000001, true);

void markPrimesInRange_sieve(int n)
{
    isPrime[0] = isPrime[1] = 0;

    for (ll i = 2; i*i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = 0;
        }
    }

}

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    markPrimesInRange_sieve(10000000);

    while(cin >> n)
    {
        if(n < 8)
        {
            cout << "Impossible." << endl;
            continue;
        }
        if(n%2 == 0)
        {
            for(int i = 1 ; i <= n - 4; i++)
                if(isPrime[i] && isPrime[n - i - 4])
                {
                    cout << 2 << " " << 2 << " " << i  << " " << n - i - 4 << endl;
                    break;
                }
        }
        else
        {
            for(int i = 1 ; i <= n - 5; i++)
                if(isPrime[i] && isPrime[n - i - 5])
                {
                    cout << 2 << " " << 3 << " " << i  << " " << n - i - 5 << endl;
                    break;
                }
        }
    }

    return 0;
}
