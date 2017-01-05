//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-21
// Description :  字典树
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>


#define MAX 26
#define W 1500
#define M 150
#define LEN 150

using namespace std;

int t,n,m,p,sol;
char ma[LEN];
char ret[LEN];
char tem[LEN];


char keys[10][10];



struct Trie
{
	int p;
	int num;
	bool end;
	Trie* next[MAX];
};

Trie *root;

Trie* creat()
{
	Trie* temp = new Trie;
	temp->p = temp->num = 0;
	temp->end = false;
	for(int i = 0 ; i < MAX ; ++i)
		temp->next[i] = NULL;
	return temp;
}


int insert(Trie* root ,char str[],int len,int p)
{
	Trie* temp = root;
	for(int i = 0 ; i < len ; i++)
	{
		if(temp->next[str[i]-'a']==NULL)
			temp->next[str[i]-'a']=creat();

		temp = temp->next[str[i]-'a'];
		temp->num = temp->num + 1;
		temp->p = temp->p + p;
	}
	temp->end = true;
	return 0;
}

int del(Trie *root)
{
	for(int i = 0 ; i < MAX; ++i)
		if(root->next[i]!=NULL)
			del(root->next[i]);
	delete root;
	return 0;
}

int DFS(Trie *root,int depth,int len)
{
	char a;
	if(depth == len+1)
	{
		if(root!=NULL&&root->p > sol) 
		{
			sol = root->p;
			for(int i = 0 ; i <= len ; ++i)
				ret[i] = tem[i];
		}
		return 0;
	}

	for(int i = 1 ; i <= keys[ma[depth]-'0'][0]; ++i)
	{
		a = keys[ma[depth]-'0'][i];
		tem[depth] = a;
//		cout<< (int)keys[ma[depth]-'0'][0] <<"a = "<<a<<endl;
		if(root->next[a-'a']!=NULL)
		{
			DFS(root->next[a-'a'],depth+1,len);
		}
	}

	return 0;
}


int main(int arg,char* argv[])
{

	freopen("in.txt","r",stdin);
	keys[2][0] = 3;
	keys[2][1] = 'a';
	keys[2][2] = 'b';
	keys[2][3] = 'c';


	keys[3][0] = 3;
	keys[3][1] = 'd';
	keys[3][2] = 'e';
	keys[3][3] = 'f';

	keys[4][0] = 3;
	keys[4][1] = 'g';
	keys[4][2] = 'h';
	keys[4][3] = 'i';


	keys[5][0] = 3;
	keys[5][1] = 'j';
	keys[5][2] = 'k';
	keys[5][3] = 'l';


	keys[6][0] = 3;
	keys[6][1] = 'm';
	keys[6][2] = 'n';
	keys[6][3] = 'o';


	keys[7][0] = 4;
	keys[7][1] = 'p';
	keys[7][2] = 'q';
	keys[7][3] = 'r';
	keys[7][4] = 's';


	keys[8][0] = 3;
	keys[8][1] = 't';
	keys[8][2] = 'u';
	keys[8][3] = 'v';

	keys[9][0] = 4;
	keys[9][1] = 'w';
	keys[9][2] = 'x';
	keys[9][3] = 'y';
	keys[9][4] = 'z';

	cin>>t;

	//	cout<<" t = "<<t<<endl;
	for (int it = 1; it <= t; ++it)
	{
			cin>>n;

			//		cout<<" n = "<<n<<endl;
			cin.getline(ma,LEN);

			//		cout<<" ma = "<<ma<<endl;
			root = creat();
			while(n--)
			{
				cin.getline(ma,LEN,' ');
				//			cout<<" ma = "<<ma<<endl;
				cin>>p;
				insert(root,ma,strlen(ma),p);
				cin.getline(ma,LEN);
				//			cout<<" ma = "<<ma<<endl;
			}

			cin>>m;
			cin.getline(ma,LEN);
			cout<<"Scenario #"<<it<<":\n";
			while(m--)
			{
				cin.getline(ma,LEN);
//				cout<<" ma = "<<ma<<endl;
				for(int id = 0 ; id < strlen(ma)-1;++id)
				{
					sol = 0;
					DFS(root,0,id);
					if(sol!=0)
					{
						for(int j = 0 ; j <= id ; ++j)
							cout<<ret[j];
						cout<<endl;
					}
					else
						cout<<"MANUALLY\n";
				}
				cout<<endl;
			}
			del(root);
			cout<<endl;
		}
		return 0;
	}
