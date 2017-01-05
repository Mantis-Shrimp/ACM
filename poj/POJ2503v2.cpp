//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-21
// Description : 字典树
//============================================================================
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>


#define MAX 26
#define N (100010)
#define LEN 15

using namespace std;


struct  Trie
{
	int num;
	int idx;
	bool end;
	Trie * next[MAX];
};


Trie * creat()
{
	Trie* temp = new Trie;
	temp->num = 0;
	temp->idx = -1;
	temp->end = false;
	for(int i = 0 ; i < MAX ; ++i)
		temp->next[i] = NULL;
	return temp;
}

int insert(Trie *root , char str[],int len,int idx)
{
	Trie * temp = root;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp->next[str[i]-'a']==NULL)
			temp->next[str[i]-'a'] = creat();		
		temp = temp->next[str[i]-'a'];
		temp->num = temp->num + 1;
	}
	temp->end = true;
	temp->idx = idx;
	return 0;
}


int find(Trie *root , char str[],int len)
{
	Trie * temp = root;
	for(int i = 0 ; i < len ; ++i)
	{
		if(temp->next[str[i]-'a']==NULL)
			return -1;		
		temp = temp->next[str[i]-'a'];
	}
	return temp->idx;
}

int del(Trie* root)
{
	if(root==NULL) return 1;
	for(int i = 0 ; i < MAX ; ++i)
		if(root->next[i]!=NULL)
			del(root->next[i]);
	delete root;
	return 1;
}

int n;
char dic[N][LEN],a[LEN];
Trie* root;





int main(int arg,char* argv[])
{
	int r = 0;
	n = 0;
	root = creat();
	dic[n][0]=cin.get();
	while(dic[n][0]!='\n')
	{
		cin.getline(&dic[n][1],LEN-1,' ');
		cin.getline(a,LEN);
		insert(root,a,strlen(a),n);
		n++;
		dic[n][0]=cin.get();
	}

	while(cin.getline(a,LEN))
	{
		r = find(root,a,strlen(a));
		if(r==-1)
			cout<<"eh"<<endl;
		else
			cout<<dic[r]<<endl;
	}
	return 0;
}