//============================================================================
// Name        : POJ1141. cpp
// Author      :
// Version     :
// Copyright   : 2012-8-1
// Description : DP 区间动态规划
//============================================================================

#include <cstdio>
#include <string>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 100 + 5

char chs[MAX];
int dp[MAX][MAX],len;
string s[MAX][MAX],a;

int dpf(int i ,int j);

int main(int argc, char **argv)
{
    while(gets(chs+1)!=NULL)
    {
        memset(dp,-1,sizeof(dp));
        len = strlen(chs+1);
        dpf(1,len);
        //printf("%d\n",dp[1][len]);
        printf("%s\n",(s[1][len]).c_str());
    }
    return 0;
}

int dpf(int i ,int j)
{
    int r = INT_MAX,temp = INT_MAX,flag = 0;

    if(i>j) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==j)
    {
        dp[i][j] = 1;
        if(chs[i]=='('||chs[i]==')') s[i][j] = "()";
        else s[i][j] = "[]";
        return 1;
    }

    if
    (
       (chs[i]=='('&&chs[j]==')')||
       (chs[i]=='['&&chs[j]==']')
    )
    {
        r = dpf(i+1,j-1);
        s[i][j] = chs[i] + s[i+1][j-1] + chs[j];
        for(int k = i; k <= j-1 ; k++)
       {
           temp = dpf(i,k) + dpf(k+1,j);
           if(temp < r) r = temp,flag = k;
       }
       if(flag!=0) s[i][j]= s[i][flag] + s[flag+1][j];
    }
    else
    {
       for(int k = i; k <= j-1 ; k++)
       {
           temp = dpf(i,k) + dpf(k+1,j);
           if(temp < r) r = temp,flag = k;
       }
       s[i][j]= s[i][flag] + s[flag+1][j];
    }
    dp[i][j] = r ;
    return r;
}
