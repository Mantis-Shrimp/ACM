#include <stdio.h>
#include <string.h>
int r = 0 ;
char A[15];
char B[15];
int Alen,Blen;

int main(int argc, char **argv)
{

	scanf("%s",A);
	scanf("%s",B);
	Alen = strlen(A);
	Blen = strlen(B);
	for(int i = 0 ; i < Alen; i++)
		for(int j = 0 ; j < Blen ; j++)
			r += (A[i]-'0')*(B[j]-'0');
	printf("%d\n",r);
	return 0;
}
