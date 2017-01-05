//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-27
// Description : 字典树
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>


#define MAX 10
#define LEN 50

using namespace std;


struct Trie
{
	int num;
	bool end;
	Trie * next[MAX];
};


int n,len;
char str[LEN];
Trie temptemp[1000000];
int cur;
int ret;
Trie* root;

Trie* creat()
{
	Trie* temp = &temptemp[cur++];
	temp->num = 0;
	temp->end = false;
	for(int i = 0 ; i < MAX ; ++i)
		temp->next[i] = NULL;
	return temp;
}

int del(Trie* root)
{
	if(root==NULL) return 1;
	for(int i  = 0 ; i < MAX ; ++i)
		if(root->next[i]!=NULL) del(root->next[i]);
	delete root;
	return 1;
}

int insert(Trie* root,char str[],int len)
{
	Trie* temp = root;
	
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp->next[str[i]-'0']==NULL)
			temp->next[str[i]-'0']=creat();
		temp = temp->next[str[i]-'0'];
	}
	temp->num++;
	temp->end=true;
	if(temp->num>ret) ret = temp->num;
	return 0;
}



int main()
{
	int pos;
//	freopen("in.txt","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
//		cin.getline(str,LEN);
		gets(str);
		ret = 0;
		cur = 0;
		root = creat();
		for(int i = 1 ; i <= n ; ++i)
		{
//			cin.getline(str,LEN);
//			cout<<str<<endl;
			gets(str);
			pos = 0;
			while(str[pos]=='0'&&pos < strlen(str)-1)
				pos++;
			insert(root,str+pos,strlen(str+pos));
//			insert(root,str,strlen(str));
		}
		cout<<ret<<endl;
//		del(root);
	}
	return 0;
}