# ACM 模板

## 最长不升子序列\(n \log n\)

```c++
//m[0,1,2,3....,n-1] 输入的原始序列
//dp[i]表示长度为i的子序列的最后一个元素的最大值
memset(dp,0,sizeof(dp));
for(int i = 0; i < n ; i++)
  {
    *std::upper_bound(dp+1,dp+1+n,m[i],std::greater<int>()) = m[i];
  }
int ret = 1;
while(dp[ret] != 0)
  {
    ret++;
  }
  ret = ret -1;

```

## 最长递增子序列 \(n\log n\)
```c++
//l[0,1,2,3....,n-1] 输入的原始序列
//dp[i]表示长度为i的子序列的最后一个元素可以允许的最小值
for(int i = 0 ; i <= idx ; i++)
  dp[i] = INT_MAX;
for(int i = 0 ; i < idx ; i++)
{
    *lower_bound(dp + 1, dp + idx, l[i]) = l[i];
}
int ret = 1;
while(dp[ret]!=INT_MAX)
  ret++;
ret = ret - 1;
```

## 最长递减子序列 \(n^2\)

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
ret = ret -1;
```

## 最长不增子序列 \(n^2\)
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
ret = ret -1;
```
