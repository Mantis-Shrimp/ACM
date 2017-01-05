//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-21
// Description : 字典树
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX 10
#define LEN 25
#define N 15000

using namespace std;


struct Trie
{
	int val;
	int num;
	bool end;
	Trie* next[MAX];
};


char ma[LEN];
Trie * root;
int t,n;
Trie list[N*1000];
int cur;


Trie* creat()
{
	Trie* temp = &list[cur++];
	temp->val = 0;
	temp->num = 0;
	temp->end = false;
	for(int i = 0 ; i < MAX ; i++)
		temp->next[i] = NULL;
	return temp;
}

int insert(Trie* root, char str[],int len) // 插入，Trie树中存在str[]的前缀或者str[]是已存在串的前缀返回1，
										   //否则返回0
{
	int flaga = 0;
	int flagb = 0;
	Trie* temp = root;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp->next[str[i]-'0']==NULL)
		{
			temp->next[str[i]-'0'] = creat();
			flaga++;
		}
		temp = temp->next[str[i]-'0'];
		temp->num = temp->num + 1;
		if(temp->end==true) flagb++;
	}
	temp->end = true;

	if(flaga==0||flagb!=0) return 1;
	return 0;
}


int main()
{
	int flag = 0;
	scanf("%d",&t);
	while(t--)
	{
		cur = 0;
		scanf("%d",&n);
		root = creat();

		flag = 0;
		gets(ma);

		while(n--)
		{	
			gets(ma);
			if(insert(root,ma,strlen(ma))==1)
				flag++;

		}
		
		if(flag==0)
			puts("YES");
		else 
			puts("NO");
	}
}