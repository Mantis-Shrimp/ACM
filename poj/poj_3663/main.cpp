#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> cows ;
int N = 0 ;
int S = 0 ;
int icount = 0 ;
int tem;

int main(int argc, char **argv)
{
	scanf("%d %d",&N,&S);

	for(int k = 0 ; k < N ; k++ ) scanf("%d",&tem),cows.push_back(tem);
	sort(cows.begin(),cows.end(),greater<int>());

	for(int i = 0 ; i < N ; i++ )
		for(int j = i + 1 ; j < N ; j++)
			if(cows[i]+cows[j]<=S) {icount += (N - j);break;} ;
	printf("%d\n",icount);
	return 0;
}
