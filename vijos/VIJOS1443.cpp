//============================================================================
// Name        : POJ1443
// Author      :
// Version     :
// Copyright   : 2013-11-3
// Description :
//============================================================================
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
long f[30100], s[30100], sum[30100];
int getfather(int v)
{
    if (f[v] != v)
    {
        int p = getfather(f[v]);
        s[v] += s[f[v]];
        f[v] = p;
    } return f[v];
}
int main()
{
    int f1, f2, num, a, b; char ch;
    scanf("%d\n", &num);
    for (int i = 1; i <= 30000; i++)
    {
        s[i] = 0;
        sum[i] = 1;
        f[i] = i;
    }
    for (int i = 1; i <= num; i++)
    {
        scanf("%c %d %d\n", &ch, &a, &b);
        f1 = getfather(a), f2 = getfather(b);
        if (ch == 'M')
        {
            f[f1] = f2;
            s[f1] = sum[f2];
            sum[f2] += sum[f1];
        }
        else if (ch == 'C')
        {
            if (f1 == f2) printf("%d\n", abs(s[a] - s[b]) - 1);
            else printf("-1\n");

        }
    }
    return 0;
}