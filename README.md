# ACM 模板


## 最长递增子序列 （n×logn）
```c++
for(int i = 0 ; i <= idx ; i++)
  dp[i] = INT_MAX;

for(int i = 0 ; i < idx ; i++)
{
    *lower_bound(dp + 1, dp + idx, l[i]) = l[i];
}

int ret = 0;

for(int i = 1 ; i <= idx ; i++)
{
    if(dp[i] == INT_MAX)
    {
        ret = i - 1;
        break;
    }
}
```

## 最长递减子序列 （n×n）

```c++
int ret = 1;
for(int i = 0 ; i < idx ; i++)
{
    for(int j = 1 ; j <= ret ; j++)
    {
        if(p[i].y >= dp[j])
        {
            dp[j] = p[i].y;
            break;
        }
    }
    if(dp[ret] != 0 ) ret = ret + 1;
}
```

## 最长不增子序列 （n×n）
```c++
int ret = 1;
for(int i = 0 ; i < m ; i++)
{
    for(int j = 1; j <= ret ; j++ )
    {
        if( dp[j] < dolls[i].h )
        {
            dp[j] = dolls[i].h;
            break;
        }
    }
    if(dp[ret] != 0 ) ret ++;
}
```
