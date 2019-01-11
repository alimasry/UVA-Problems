// UVa 10077
#include <bits/stdc++.h>

using namespace std;

string s;
int n, k, a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(true)
    {
        cin >> n >> k;

        if(n == 1 && k == 1) return 0;

        s = "";

        int last_Ra, last_La, last_Lb, last_Rb;

        if(n < k)
        {
            s += 'L';
            last_La = 0;
            last_Lb = 1;
            last_Ra = last_Rb = 1;
            a = 1;
            b = 2;
        }
        else
        {
            s += 'R';
            last_Ra = 1;
            last_Rb = 0;
            last_La = last_Lb = 1;
            a = 2;
            b = 1;
        }
        while(true)
        {
            if(a *k == n * b) break;

            if(n * b < a * k)
            {
                s += 'L';
                a += last_La;
                b += last_Lb;
                last_Ra = a - last_La;
                last_Rb = b - last_Lb;
            }
            else
            {
                s += 'R';
                a += last_Ra;
                b += last_Rb;
                last_La = a - last_Ra;
                last_Lb = b - last_Rb;
            }

        }
        cout << s << endl;
    }
}
