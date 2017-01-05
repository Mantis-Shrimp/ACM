#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


struct cow
{
	int index;
	int vote1;
	int vote2;
};

int N,K;
bool great1(const cow& cow1 , const cow& cow2);
bool great2(const cow& cow1 , const cow& cow2);

vector<cow> cows;
cow mycow;

int main(int argc, char **argv)
{
	scanf("%d%d",&N,&K);
	for(int i = 1 ; i <= N ; scanf("%d%d",&mycow.vote1,&mycow.vote2), mycow.index = i, cows.push_back(mycow),i++);
	sort(cows.begin(),cows.end(),great1);
	//for(int i = 0 ; i<N; i++,printf("%d",cows[i].index));
	sort(cows.begin(),cows.begin()+K,great2);
	printf("%d\n",cows[0].index);
	getchar();
	return 0;
}


bool great1(const cow& cow1 , const cow& cow2)
{
	return cow1.vote1 > cow2.vote1 ;
}

bool great2(const cow& cow1 , const cow& cow2)
{
	return cow1.vote2 > cow2.vote2 ;
}
