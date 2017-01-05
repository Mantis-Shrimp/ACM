//============================================================================
// Name        : POJ_1426.cpp
// Author      : 
// Version     :
// Copyright   : 2012-7-9
// Description : Find The Multiple BFS
//============================================================================

#include <cstdio>
#include <string>
using namespace std;

#define MAX 1000000
string queue[MAX];
string str;
string r[205];
char c[2]={'0','1'};
int front,rear,n;

int BFS();
bool ISOK();

int main()
{
	//while(scanf("%d",&n)&&n!=0)
	printf("#include <stdio.h>\n#include<string>\nusing namespace std;\nstring r[250];\nint n;\nint main()\n{\n");
	for(n = 1 ; n <= 200 ; n++)
	{
		front=0,rear=1;
		BFS();
	}
	//while(scanf("%d",&n)&&n!=0)
    for(n=1;n<=200;n++)
	{
		printf("r[%d]=\"%s\";\n",n,r[n].c_str());
	}
    puts("while(scanf(\"%d\",&n)&&n!=0)\n{\nprintf(\"\%s\\n\",r[n].c_str());\n}\nreturn 0;\n}\n");
	return 0;
}

int BFS()
{
	queue[0]="1";
	while(rear!=front)
	{
		str=queue[front];
		front=(front+1)%MAX ;
		if(ISOK()){r[n]=str; return 0;}
		for(int i = 0 ; i<2 ;i++)
		{
			queue[rear] = str + c[i] ;
			rear = (rear + 1)%MAX;
		}
	}
	return 0;
}

bool ISOK()
{
	int len = str.length();
	int mod = str[0] - '0' ;
	mod %= n ;
	for(int i = 1 ; i < len ; i++)
	{
		mod = (((mod % n) *10) %n + str[i] - '0' ) % n;
	}
	if(mod==0)
		return true;
	else
		return false;
}
