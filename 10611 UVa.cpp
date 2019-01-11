// UVa 10611
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, k, q;
int main()
{
    scanf("%d", &n);
    set<int> height;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        height.insert(k);
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &k);
        auto fst = height.lower_bound(k);
        auto lst = height.upper_bound(k);
        if(fst == height.begin())
            printf("X ");
        else
            printf("%d ", *prev(fst));
        if(lst == height.end())
            printf("X\n");
        else printf("%d\n", *lst);
    }
    return 0;
}
