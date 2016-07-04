#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define eps 1e-5
#define MAXN 4000037
#define MAXM 7300037
#define INF 1000000000
using namespace std;
int mod = 4000037;
int n, m;
int vis[MAXN], cnt[MAXN], hash[MAXN];
int locate(int key)
{
    int pos;
    pos = (key % mod + mod) % mod;
    while(vis[pos] && hash[pos] != key)
        if (++pos >= mod) pos -= mod;
    return pos;
}
void add(int key)
{
    int pos = locate(key);
    cnt[pos] ++;
    vis[pos] = 1;
    hash[pos] = key;
}
int f[11], p[11];
int numpow(int x, int num)
{
    int ans = 1;
    for(int i = 1; i <= num; i++) ans *= x;
    return ans;
}
int num[7][155];
int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &f[i], &p[i]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            num[i][j] = f[i] * numpow(j, p[i]);
    int ans = 0;
    if(n == 1)
    {
        for(int i = 1; i <= m; i++)
            if(num[1][i] == 0) ans++;
    }
    else if(n == 2)
    {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                if(num[1][i] + num[2][j] == 0) ans++;
    }
    else if(n == 3)
    {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    if(num[1][i] + num[2][j] + num[3][k] == 0) ans++;
    }
    else if(n == 4)
    {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                add(-(num[1][i] + num[2][j]));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                ans += cnt[locate(num[3][i] + num[4][j])];
    }
    else if(n == 5)
    {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                add(-(num[1][i] + num[2][j]));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    ans += cnt[locate(num[3][i] + num[4][j] + num[5][k])];
    }
    else if(n == 6)
    {
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    add(-(num[1][i] + num[2][j] + num[3][k]));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
                for(int k = 1; k <= m; k++)
                    ans += cnt[locate(num[4][i] + num[5][j] + num[6][k])];
    }
    printf("%d\n", ans);
    return 0;
}
