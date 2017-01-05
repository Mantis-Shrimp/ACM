#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;



int n = 0;
int k = 0;
int icount = 0;

vector<char> vec;
int ch = 0;

int main(int argc, char **argv)
{
	scanf("%d",&icount);
	while(icount--)
	{
		scanf("%d",&n);
		scanf("%d",&k);
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&ch);
			vec.push_back(ch);
		}
		for(int i = 1 ; i<=k ; i++)
		{
			next_permutation(vec.begin(),vec.end());
		}
		for(vector<char>::iterator it = vec.begin(); it < vec.end() -1 ; it++)
		{
			printf("%d ",*it);
		}
		printf("%d\n",*(vec.end() -1));
		vec.clear();
	}
	return 0;
}
