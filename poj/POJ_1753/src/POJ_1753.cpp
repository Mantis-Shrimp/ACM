//============================================================================
// Name        : POJ_1753.cpp
// Author      : 
// Version     :
// Copyright   : 2012-5-2
// Description : http://poj.org/problem?id=1753 Flip Game Ã¶¾Ù
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int dfs(int depth,int n);
bool check(int n);

char rect[6][6],brect[6][6],wrect[6][6];
char bpress[6][6],wpress[6][6];
int num;

int main()
{
	memset(rect,0,6*6*sizeof(char));
	memset(brect,0,6*6*sizeof(char));
	memset(wrect,0,6*6*sizeof(char));
	memset(bpress,0,6*6*sizeof(char));
	memset(wpress,0,6*6*sizeof(char));
    num=INT_MAX;

	for(int ii = 1 ; ii <=4 ; ii++) scanf("%s",&rect[ii][1]);

	for(int ih = 1 ; ih <=4 ; ih++)
	{
		for(int iw = 1 ; iw <=4 ; iw++)
		{
			brect[ih][iw] = rect[ih][iw]=='b'?1:0;
			wrect[ih][iw] = rect[ih][iw]=='w'?1:0;
		}
	}

	dfs(1,0);
	if(num==INT_MAX) printf("Impossible\n");
	else printf("%d\n",num);
	return 0;
}

int dfs(int depth,int n)
{
	if(depth==5)
	{
		check(n);
		return 0;
	}

	for(int i = 0; i<=1 ; i++)
	{
		bpress[1][depth]=i;
		wpress[1][depth]=i;
		if(i==1) n++;
		dfs(depth+1,n);
	}
	return 0;
}

bool check(int n)
{
	int bnum=0,wnum=0;
	for(int ih = 2 ; ih<=5 ; ih++)
	{
		for(int iw = 1 ; iw<=4 ; iw++)
		{
			bpress[ih][iw]=( bpress[ih-1][iw] + bpress[ih-2][iw] + bpress[ih-1][iw-1] + bpress[ih-1][iw+1] + brect[ih-1][iw])%2;
			wpress[ih][iw]=( wpress[ih-1][iw] + wpress[ih-2][iw] + wpress[ih-1][iw-1] + wpress[ih-1][iw+1] + wrect[ih-1][iw])%2;
		    if(ih==5) continue;
			bnum += bpress[ih][iw];
		    wnum += wpress[ih][iw];
		}
	}
	if(bpress[5][1]+bpress[5][2]+bpress[5][3]+bpress[5][4]==0)
		if(bnum+n<num) num=bnum+n;
	if(wpress[5][1]+wpress[5][2]+wpress[5][3]+wpress[5][4]==0)
		if(wnum+n<num) num=wnum+n;
	return true;
}
