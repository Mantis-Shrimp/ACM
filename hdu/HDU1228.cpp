//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   : 2013-4-27
// Description : 字符串HASH
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define LEN 1000

using namespace std;



char word[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int hash[LEN + 10];

int ELFhash(char *key)
{
	unsigned long h = 0;
	unsigned long g;
	while( *key )
	{
		h =( h<< 4) + *key++;
		g = h & 0xf0000000L;
		if( g ) h ^= g >> 24;
		h &= ~g;
	}
	return h;
}
int main()
{
	int pos;
	int a,b;
	char astr[20],bstr[20];
	for(int i = 0 ; i < 10 ; ++i)
		hash[ELFhash(word[i])%LEN] = i;

	do
	{
		a = b = 0;
		while(scanf("%s",astr)&&astr[0]!='+')
			a = a * 10 + hash[ELFhash(astr)%LEN];

		while(scanf("%s",bstr)&&bstr[0]!='=')
			b = b * 10 + hash[ELFhash(bstr)%LEN];
		if(a+b!=0)
			printf("%d\n", a+b);

	}while(a!=0||b!=0);
}
