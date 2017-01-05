//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-20
// Description : 字典树
//============================================================================

#include <iostream>
#include <cmath>
#include <cstring>

#define MAX 2
#define LEN 15
#define NUM 15

using namespace std;


char chs[NUM][LEN];
int t;
int n;
int flag = 0;


struct Trie
{
	Trie *next[MAX];
	bool end;
};

Trie *root ;



Trie* creat()
{
	Trie* temp = new Trie;
	temp->end = false;
	for(int i = 0 ; i < MAX ; ++i)
		temp->next[i] = NULL;
	return temp;
}


int insert(Trie *root,char str[],int len)
{
	Trie * temp = root;

	for(int i = 0 ; i < len ;++i)
	{
		if(temp->next[str[i]-'0']==NULL)
			temp->next[str[i]-'0']=creat();
		
		temp = temp->next[str[i]-'0'];
	}
	temp->end = true;

	return 1;
}


int find(Trie *root ,char str[],int len) //若存在str[]的前缀（不包括完全匹配）返回1，否则返回0
{
	Trie * temp = root;

	for(int i = 0 ; i < len-1 ;++i)
	{
		if(temp->next[str[i]-'0']==NULL)
			return 0;
		temp = temp->next[str[i]-'0'];

		if(temp->end==true) return 1;
	}
	
	return 0;
}

int del(Trie *root)
{
	Trie * temp = root;
	for (int i = 0; i < MAX; ++i)
		if(temp->next[i]!=NULL)
			del(temp->next[i]);
	delete temp;
	temp = NULL;
	return 0;
}

int main()
{
	n = 0;
	do
	{
		do
		{
			cin.getline(chs[n++],LEN);

		}while(chs[n-1][0]!='9');

		t++;
		
		root = creat();
		
		flag = 0;

		for(int i = 0 ; i < n - 1 ; ++i)
			insert(root,chs[i],strlen(chs[i]));

		for (int i = 0; i < n - 1; ++i)
		{
			if(find(root,chs[i],strlen(chs[i]))==1)
				flag = 1;
		}

		if(flag==0)
			cout<<"Set "<<t<<" is immediately decodable\n";
		if(flag==1)
			cout<<"Set "<<t<<" is not immediately decodable\n";
		
		del(root);

		n = 0;
	}while(cin.getline(chs[n++],LEN));
	return 0;
}