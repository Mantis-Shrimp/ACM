#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

struct str
{
	char str[10000];
};

str url;
char com[100];
stack<str> backstrack;
stack<str> forstrack;

int main(int argc, char **argv)
{
	freopen("out.txt","w",stdout);
	strcpy(url.str,"http://www.acm.org/");
	scanf("%s",com);
	while(strcmp(com,"QUIT")!=0)
	{
		if(strcmp(com,"VISIT")==0)
		{
			while(forstrack.empty()==false)forstrack.pop();
			backstrack.push(url);
			getchar();
			scanf("%s",url.str);
			printf("%s\n",url.str);
			scanf("%s",com);
			continue;
		}
		if(strcmp(com,"BACK")==0)
		{
			if(backstrack.empty()) {printf("Ignored\n");scanf("%s",com);continue;}
			forstrack.push(url);
			url = backstrack.top();
			backstrack.pop();
			printf("%s\n",url.str);
			scanf("%s",com);
			continue;
		}
		if(strcmp(com,"FORWARD")==0)
		{
			if(forstrack.empty()) {printf("Ignored\n");scanf("%s",com);continue;}
			backstrack.push(url);
			url = forstrack.top();
			forstrack.pop();
			printf("%s\n",url.str);
			scanf("%s",com);
			continue;
		}
	}
	return 0;
}
