#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char _a[150];
char a[150];
char b[150];
char r[150];

int alen;
int blen;
int rlen;

int multiplication(char a[],int alen,char b[],int blen,char r[],int rlen);
int IsCyclic();
int check();

int main(int argc, char **argv)
{
	while(scanf("%s",_a)!=EOF)
	{
		alen = strlen(_a) ;
		for(int iindex = 0 ; iindex<alen;iindex++) a[iindex]=_a[iindex]-'0';
		for(int iindex = alen ; iindex < 2*alen;iindex++) a[iindex]=_a[iindex-alen]-'0';
		if(IsCyclic()==1)printf("%s is cyclic\n",_a);
		else printf("%s is not cyclic\n",_a);
	}
	return 0;
}

int multiplication(char a[],int alen,char b[],int blen,char r[],int rlen)
{
	int len = 0;
	int istart = 0 ;
	int jindex = 0 ;
	char* _r = (char*) malloc( sizeof(char) * ( alen + blen + 1 ) ) ;
	memset(_r,0,sizeof(char) * ( alen + blen + 1 ));

	for(int ia = 0 ; ia < alen; ia++)
	{
		for(int ib = 0; ib < blen; ib++)
		{
			_r[ia + ib + 1] += a[ia] * b[ib];
			_r[ia + ib] += _r[ia + ib + 1] / 10;
		    _r[ia + ib + 1] = _r[ia + ib + 1] % 10 ;
			len = ia + ib + 1 ;
		}
	}

	for(int iindex =  len; iindex >0 ; iindex-- )
	{
		_r[iindex - 1] += _r[iindex] / 10;
		_r[iindex] = _r[iindex] % 10 ;
	}

	for(istart = 0 ; istart < len;istart++)
	{
		if(_r[istart]!=0) break;
	}
	for(int iindex = istart ; iindex<=len ;iindex++,jindex++ )
	{
		r[jindex] = _r[iindex];
	}
	return jindex ;
}


int IsCyclic()
{
	int len = 0 ;
	for(int iindex = 1; iindex<=alen; iindex++ )
	{
		if(iindex==10)
			continue ;
		if(iindex<10)
		{
		blen = 1;
		b[0] = (char) iindex;
		}
		else
		{
			blen = 2;
			b[0] = (char) iindex /10 ;
			b[1] = (char) iindex % 10;
		}
		len = multiplication(a,alen,b,blen,r,rlen);
		if(len>alen) return 0;
			if(check()==0)
			return 0 ;

		}

	return 1;
}

int check()
{
	int count = 0 ;
	for(int jindex = 0; jindex<alen;jindex++)
	{
		count = 0 ;
		for(int kindex = 0 ; kindex < alen;kindex++)
		{
			if(a[kindex+jindex] == r[kindex]) count++;
		}
		if(count==alen) return 1;
	}
	return 0 ;
}

