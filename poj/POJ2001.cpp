//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-20
// Description : 字典树
//============================================================================


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

#define MAX 26
#define LEN 25
#define N 1500

using namespace std;


struct Trie
{
	int val;
	int num;
	bool end;
	Trie* next[MAX];
};


char ma[N][LEN];
Trie * root;


Trie* creat()
{
	Trie* temp = new Trie;
	temp->val = 0;
	temp->num = 0;
	temp->end = false;
	for(int i = 0 ; i < MAX ;++i) temp->next[i] = NULL;
	return temp;
}

int insert(Trie* root,char str[],int len)
{
	Trie* temp = root;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp->next[str[i]-'a']==NULL)
			temp->next[str[i]-'a'] = creat();

		temp = temp->next[str[i]-'a'];
		temp->num = temp->num + 1;
	}
	temp->end = true;
	return 0;
}

int find_short_Prefix(Trie* root,char str[],int len)
{
	Trie* temp = root;

	for(int i = 0 ; i < len ; ++i)
	{
		temp = temp->next[str[i]-'a'];
		if(temp->num==1)
		{
			for(int j = 0 ; j <= i ; ++j)
				cout<<str[j];
			cout<<endl;
			return 0;
		}
		if(i == (len - 1))
		{
			for(int j = 0 ; j <= i ; ++j)
				cout<<str[j];
			cout<<endl;
		}
	}

	return 0;
}

int del(Trie* root)
{

	for(int i = 0 ; i < MAX ; ++i)
		if(root->next[i]!=NULL)
			del(root->next[i]);
	delete root;
	root = NULL;
	return 0;
}

int main()
{
	int n = 0;
	root = creat();
	while(cin.getline(ma[n++],LEN))
		insert(root,ma[n-1],strlen(ma[n-1]));

	for (int i = 0; i < n; ++i)
	{
		cout<<ma[i]<<" ";
		find_short_Prefix(root,ma[i],strlen(ma[i]));
	}
	del(root);
}
