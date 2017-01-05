//============================================================================
// Name        : POJ_1154.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-11
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstring>
#define MAX 30
using namespace std;
char letter[MAX][MAX],pass[MAX][MAX],alph[MAX];
int r,c;
int main()
{
	memset(alph,0,sizeof(alph)),memset(pass,0,sizeof(pass));
	scanf("%d%d",&r,&c);
	for(int ir = 1 ; ir <= r ; ir++)
		for(int ic = 1 ; ic <=c ; ic++)
		{
			scanf("%c",&letter[ir][ic]);
		}
	return 0;
}
