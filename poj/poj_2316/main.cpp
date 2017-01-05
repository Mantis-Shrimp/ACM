#include <stdio.h>
#include <string.h>
char digtals[100] = {0};
int diglen  = 0 ;
char buttons[100];
int butlen = 0;


int main()
{
	while(scanf("%s",buttons)!=EOF)
	{
		diglen = strlen(buttons);
		for(int i = 0;i < diglen;i++)
		   {
		       digtals[i]+=(buttons[i]-'0');
			   if(digtals[i]>=10) digtals[i]%=10;
		   }
		   diglen= diglen>butlen?diglen:butlen;


	}
	 for(int j = 0 ;j<diglen;j++) printf("%d",digtals[j]);
}
