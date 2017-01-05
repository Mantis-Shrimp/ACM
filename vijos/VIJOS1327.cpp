
//============================================================================
// Name        : Vijos1327
// Author      :
// Version     :
// Copyright   : 2013-10-30
// Description : dynamical programming
//============================================================================

#include <cstdio>
#include <cstdlib>
#define M 5002


short dp[ M ][ M ];//dp[ i ][ j ]从第i个开始 长度为j的子串最少需要添加几个字符来构成回文
char str[ M ];
int main()
{
    int i , n , j , curr;
    while (scanf ("%d%*c" , &n) == 1)
    {
        gets(str);
        dp[ 0 ][ 0 ] = 0;
        for (i = 1; i <= n; ++ i)
        {
            dp[ i ][ 1 ] = 0;
            dp[ i ][ 0 ] = 0;
        }

        for (j = 2; j <= n; ++ j)
        {
            for (i = 1; i <= n - j + 1; ++ i)
            {
                if (str[i - 1] == str[i + j - 2])
                {
                    dp[ i ][ j ] = dp[i + 1][j - 2];
                }
                else
                {
                    if (dp[ i ][j - 1] < dp[i + 1][j - 1])
                        dp[ i ][ j ] = dp[ i ][j - 1] + 1;
                    else
                        dp[ i ][ j ] = dp[i + 1][j - 1] + 1;
                }
            }
        }
        printf ("%d\n" , dp[ 1 ][ n ]);
    }
    return 0;
}