//============================================================================
// Name        : UVa_10324. cpp
// Author      :
// Version     :
// Copyright   : 2013-12-24 
// Description : 模拟
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int N = 1000000+5;
char str[N];
int len,sum[N],a,b,t,s,T;

int main(int argc, char const *argv[])
{
	//freopen("in.txt", "r", stdin);
	T = 0 ;
	while(scanf("%s\n",str+1)!=EOF)
	{
		// printf("%s\n",str+1);
		T++;
		len = strlen(str+1);
		if(len==0) return 0;
		sum[0] = 0;
		for(int i = 1 ; i <=len ; i++)
			sum[i] = str[i] + sum[i-1] - '0';
		scanf("%d",&t);

		printf("Case %d:\n",T);
		for(int i = 1 ; i <= t ; i++)
		{
			scanf("%d%d",&a,&b);
			a++;
			b++;
			s = sum[max(a,b)] - sum[min(a,b)-1];
			//printf("s = %d\n",s);
			if(s==0||s==(max(a,b)- min(a,b) + 1)) 
				printf("Yes\n");
			else 
				printf("No\n");
		}
	
	}
	return 0;
}