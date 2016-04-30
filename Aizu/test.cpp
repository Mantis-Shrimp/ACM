#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>


int main(int argc,char* argv[])
{
	int r = 10;
	int c = 10000;
	freopen("in.txt","w",stdout);
	std::cout<<r<<" "<<c<<std::endl;
	for(int i = 0 ; i < r ; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if( rand() % 2 == 0  )
				std::cout<<0<<" ";
			else
				std::cout<<1<<" ";
		}
		std::cout<<std::endl;
	}
}
