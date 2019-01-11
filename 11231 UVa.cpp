// UVa 11231
#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int main()
{
    while(true)
    {
        scanf("%d%d%d", &n, &m, &c);
        if(n + m == 0) return 0;
        if(c == 1)
            cout << ((m - 7)/2 + ((m - 7)%2)) * ((n - 7)/2 + ((n - 7)%2)) + ((m - 8)/2 + ((m - 8)%2)) * ((n - 8)/2 + ((n - 8)%2)) << endl;
        
        if(c == 0)
            cout << ((n - 7)/2) * ((m - 7)/2 + ((m - 7)%2)) + ((m - 7)/2) * ((n - 7)/2 + ((n - 7)%2))<< endl;
    }
}

