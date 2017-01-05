#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;


struct color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
} ;

color col;
int R,G,B;


vector<color>::iterator count;

vector<color> maps;


int main(int argc, char **argv)
{

	double distance;
	double  dis = 0;
	for(int iindex = 0 ; iindex < 16 ; iindex++, scanf("%d%d%d",&col.R,&col.G,&col.B), maps.push_back(col));
	scanf("%d%d%d",&R,&G,&B);
	while(R>=0&&R<=255&&G>=0&&G<=255&&B>=0&&B<=255)
	{
		distance = 1000000.0;
		for(vector<color>::iterator it = maps.begin(); it < maps.end(); it++)
		{
			dis = sqrt(((*it).R - R)*((*it).R - R) + ((*it).G - G)*((*it).G - G) + ((*it).B - B)*((*it).B - B));

			if(distance > dis ) distance = dis ,count = it ;
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",R,G,B,(*count).R,(*count).G,(*count).B);
		scanf("%d%d%d",&R,&G,&B);
	}
	return 0;
}
