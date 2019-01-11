// 406 UVa
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_prime(int n)
{
    if(n == 2) return true;

    if(n < 1 || n%2 == 0) return false;

    for(int i = 3; i*i <= n; i+=2)
        if(n%i == 0) return false;

    return true;
}

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(cin >> n >> m)
    {
        vector<int> primes;
        for(int i = 1; i <= n; i++)
            if(is_prime(i))
                primes.push_back(i);
        cout << n << " " << m << ": ";
        if(primes.size()%2 == 1 && primes.size() >= 2*m - 2)
            for(int i = 0;i < 2*m - 1; i++)
            {
                cout << primes[i + primes.size()/2 - m + 1];
                if(i < 2*m - 2)
                    cout << " ";
            }
        else if(primes.size()%2 == 0 && primes.size() >= 2*m)
            for(int i = 0;i < 2*m; i++)
            {
                cout << primes[i + primes.size()/2 - m];
                if(i < 2*m - 1)
                    cout << " ";
            }
        else
            for(int i = 0; i < primes.size(); i++)
            {
                cout << primes[i];
                if(i < primes.size() - 1)
                    cout << " ";
            }
        cout << endl << endl;
    }
    return 0;

}
