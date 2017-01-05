#include <stdio.h>
#include <string.h>

#define maxn 100000
int text[maxn + 10], buffer[maxn + 10], n, k;
int main()
{
    int i, a, b, c, sz;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i) text[i-1] = i;
    
    for (i = 1; i <= k; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        sz = b - a + 1;
        memcpy(buffer, text + a - 1, sizeof(int)*sz);
        memmove(text + a - 1, text + b, sizeof(int) * (n - b));
        n -= sz;
        memmove(text + c + sz, text + c, sizeof(int) * (n - c));
        memcpy(text + c, buffer, sizeof(int)*sz);
        n += sz;
    }
    for (i = 0; i < 10; ++i)
        printf("%d\n", text[i]);
    return 0;
}