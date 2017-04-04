/*
ID: 15864532
PROG: calfflac
LANG: C++
*/

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("calfflac.in", "r", stdin)
#define write           freopen("calfflac.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxn = 210000;


char str[maxn],str0[maxn],str1[maxn];
int p[maxn],flag[maxn];
int pos,l,cnt,ret,c,cn,po;

int main(int argc, char const *argv[])
{
	//gets(str0);
	cnt = 0;
	cn = 0;
	po = 0;
	int len = 0;
	read;
	write;
		
	while ((c = getchar())!= EOF )
 	{
 		str[cn++] = (char)c;
 		//tolower(c)
 		//putchar(c);
 	}
 	str[cn] = 0;
 	// puts(str);
	
 	for(int i = 0 ; i < cn ; i++)
 	{
 		if( (str[i]>='A'&&str[i]<='Z') || (str[i]>='a'&&str[i]<='z') )
 		{
 			str0[len] = str[i];
 			flag[len] = i;
 			len ++;
 		}
 	}
 	str0[len] = 0;
 	// puts(str0);
 	for(int i = 0 ; i < len ; i++)
 		str0[i] = tolower(str0[i]);
	// puts(str0);
	//system("pause");
	//while(gets(str0))
	//{
		//gets(str1);
	
		//int len = strlen(str0);
		str1[0]='$';
		str1[1]='#';
		
		for(int i = 0 ; i < len ; i++)
		{
			str1[2*i+2] = str0[i];
			str1[2*i+3] = '#';
		}

		str1[2*len+2] = '@';

		p[0] = 1;
		ret = l = pos = 0;

		for(int i = 1 ; i < (2 * len +3) ; i++ )
		{
			if(l > i ) p[i] = Min(p[2*pos-i],l-i+1);
			else p[i] = 1;
			while(str1[i-p[i]]==str1[i+p[i]]) p[i]++;
			
			if((i+p[i]-1) > l)
			{
				l = i + p[i] -1;
				pos = i;
			}

			//AMax(ret,p[i]);
			if(ret < p[i])
			{
				ret = p[i];
				po = pos;
			}
		}
		
		 // puts(str1);
		 // for(int i = 0 ; i < (2 * len +3) ; i++ )
		 // {
		 // 	printf("%d  ", p[i]);
		 // }
		 // printf("\n");

		printf("%d\n",ret-1);
		// printf("%d\n",((po-ret+1)-1)/2);
		// printf("%d\n",flag[((po-ret+1)-1)/2]);
		// printf("%d\n",((po+ret-1)-1)/2-1);
		// printf("%d\n",flag[((po+ret-1)-1)/2-1]);

		
		for(int i = flag[((po-ret+1)-1)/2]; i <= flag[((po+ret-1)-1)/2-1]  ; i++)
			putchar(str[i]);
		putchar('\n');
		//printf("Case %d: %d\n",++cnt,ret-1);
		//gets(str0);
	//}
	return 0;
}