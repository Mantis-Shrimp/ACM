/*
ID: 15864532
PROG: namenum
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
#define read            freopen("namenum.in", "r", stdin)
#define write           freopen("namenum.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
const int maxnod = 20000;
const int sigma_size = 26;


char m[10][5];
char str[100];
char ret[100];
int c;


struct Trie
{
	int ch[maxnod][sigma_size];
	int val[maxnod];
	int prefix[maxnod];
	int sz;
	Trie(){sz = 1;memset(ch[0],0,sizeof(ch[0]));};
	int idx(char c) {return c - 'A';}
	int insert(char* s,int v)
	{
		int u = 0, n = strlen(s);
		for(int i = 0; i < n ; i++)
		{
			int c = idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				prefix[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
			prefix[u]++;
		}
		val[u] = v;
	}

	int find(char* s)
	{
		int u = 0,n = strlen(s);
		for(int i = 0; i < n ; i++)
		{
			int c = idx(s[i]);
			if(!ch[u][c]) return 0 ;
			u = ch[u][c];
		}
		if(val[u]==0) return 0;
		else return 1;
	}
};

Trie trie;

int DFS(int d ,int n)
{
	if(d==n)
	{
		ret[d] = 0;
		//printf("%s\n",ret);
		if(trie.find(ret))
		{
			printf("%s\n",ret);
			c++;
		}
		return 0;
	}

	for(int i = 0 ; i < 3 ; i++)
	{
		ret[d] = m[str[d]-'0'][i];
		DFS(d+1 , n);
	}
	return 0;
}



int main(int argc, char const *argv[])
{
	
	m[2][0]='A';
	m[2][1]='B';
	m[2][2]='C';


	m[3][0]='D';
	m[3][1]='E';
	m[3][2]='F';

	m[4][0]='G';
	m[4][1]='H';
	m[4][2]='I';

	m[5][0]='J';
	m[5][1]='K';
	m[5][2]='L';

	m[6][0]='M';
	m[6][1]='N';
	m[6][2]='O';

	m[7][0]='P';
	m[7][1]='R';
	m[7][2]='S';

	m[8][0]='T';
	m[8][1]='U';
	m[8][2]='V';

	m[9][0]='W';
	m[9][1]='X';
	m[9][2]='Z';

	c = 0;
	FILE *dict  = fopen ("dict.txt", "r");
	
	read;
	write;

	while(fscanf(dict,"%s",str)!=EOF)
		trie.insert(str, 1);

	scanf("%s",str);
	DFS(0,strlen(str));

	if(c==0)
		printf("NONE\n");

	return 0;
}