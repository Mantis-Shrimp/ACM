# ACM 模板

## 状态压缩

```c++
0; \\空集
i<<i; \\只含第i的元素的集合{i}
(1<<n)-1;\\含有全部i个元素的集合{0,1,2,3,...,n-1}
if(S>>i & 1); \\判断第i个元素是否属于集合sp
S|1<<i;\\向集合S中加入第i个元素
S&~(1<<i);\\从集合S中去除第i个元素
S|T;\\集合S与集合T的并
S&T;\\集合S与集合T的交

for(int i = 0 ; i < 1 << n ; i++) //枚举集合{0,1,2,3,...,n-1}的全部子集
{
  ;//对子集的处理
}

```




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
