//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2014-1-22
// Description : 数论 Miller_Rabin素数测试  Pollard_rho因子分解
//============================================================================

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef long long LL;

LL factor[1000];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

LL muti_mod(LL a, LL b, LL c)//返回(a*b) mod c,a,b,c<2^63
{
    a %= c;
    b %= c;
    LL ret = 0;
    while (b)
    {
        if (b & 1)
        {
            ret += a;
            if (ret >= c) ret -= c;
        }
        a <<= 1;
        if (a >= c) a -= c;
        b >>= 1;
    }
    return ret;
}

LL pow_mod(LL x, LL n, LL mod) //返回x^n mod c ,非递归版
{
    if (n == 1) return x % mod;
    int bit[90], k = 0;
    while (n)
    {
        bit[k++] = n & 1;
        n >>= 1;
    }
    LL ret = 1;
    for (k = k - 1; k >= 0; k--)
    {
        ret = muti_mod(ret, ret, mod);
        if (bit[k] == 1) ret = muti_mod(ret, x, mod);
    }
    return ret;
}

bool witness(LL a, LL n, LL x, LL t) //以a为基，n-1=x*2^t，检验n是不是合数
{
    LL ret = pow_mod(a, x, n);
    LL last = ret;
    for (int i = 1; i <= t; i++)
    {
        ret = muti_mod(ret, ret, n);
        if (ret == 1 && last != 1 && last != n - 1) 
            return 1;
        last = ret;
    }
    if (ret != 1) return 1;
    return 0;
}

bool Miller_Rabin(LL n,int S) // n>=2,合数返回1，素数返回0
{
    
    if(n==2) return 0;

    LL x = n - 1, t = 0;
    while ((x & 1) == 0) 
        x >>= 1, t++;
    
    if (t == 0) return 1; // t=0时，n为偶数
    for (int k = 0; k < S; k++)
    {
        LL a = rand() % (n - 1) + 1;
        if (witness(a, n, x, t))
            return 1;
    }
    return 0;
}

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

LL Pollard_rho(LL x, LL c)
{
    LL i = 1, x0 = rand() % x, y = x0, k = 2,d;
    while (1)
    {
        i++;
        x0 = (muti_mod(x0, x0, x) + c) % x;
        if (y == x0) 
            return x;
        if(y>x0)
            d = gcd(y - x0, x);
        else
            d = gcd(x0 - y, x);
        
        if (d != 1 && d != x)   
            return d;
        
        if (i == k)
        {
            y = x0;
            k += k;
        }
    }
}

//对n进行素因子分解
void findfac(LL n)
{
    if(Miller_Rabin(n,20)==0)//素数
    {
        factor[tol++]=n;
        return;
    }
    LL p=n;
    while(p>=n)
        p=Pollard_rho(p,rand()%(p-1)+1);
    findfac(p);
    findfac(n/p);
}


int main(int argc, char const *argv[])
{
    int T;
    LL n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        if(Miller_Rabin(n,20)==0)
        {
            printf("Prime\n");
        }
        else
        {
            tol=0;
            findfac(n);
            LL ans = factor[0];
            //printf("tol=%d\n",tol);
            //for(int i = 0 ; i < tol ; i++)
            //    printf("%lld", factor[i]);
            //printf("\n");
            
            for(int i=1;i<tol;i++)
                if(factor[i]<ans)
                    ans=factor[i];
            printf("%I64d\n",ans);
        }
    }
    return 0;
}