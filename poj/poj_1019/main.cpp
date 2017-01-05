#include<stdio.h>


int BinarySearch(int,int,int);

unsigned int e[33050] = {0} ;
unsigned int sum[33050] = {0} ;
char seq[170000] = {0} ;
int count = 0;
int input = 0;


int main()
{
	int j = 1 ;
	int _pos = 0 ;
        
	for(int i = 1;i<=9; i++ ) 
	{ e[i] = e[i-1] + 1 ; seq[j] = i ; j++ ;}
	
	for(int i = 10 ; i <= 99 ; i++ ) 
	{ e[i] = e[i-1] + 2 ; seq[j] = i/10; seq[j+1] = i%10; j=j+2;}

        for(int i = 100 ; i<= 999 ; i++ )  
	{ e[i] = e[i-1] + 3 ; seq[j] = i/100; seq[j+1] = (i/10)%10; j=j+3;}

	for(int i = 1000 ; i<=9999 ; i++ ) 
	{ e[i] = e[i-1] + 4 ; seq[j] = i/1000; seq[j+1] = (i/100)%10; seq[j+2] = (i/10)%10 ; seq[j+3] = i%10; j= j+4 ;}
	
	for(int i = 10000 ; i <= 33049 ; i++ ) 
	{e[i] = e[i-1] + 5 ; seq[j] = i/10000; seq[j+1] = (i/1000)%10; seq[j+2] = (i/100)%10 ; seq[j+3] = (i/10)%10; 
	seq[j+4] = i%10;  j= j+5 ;}
        

	for(int i = 1 ; i <= 33049 ; i++ ) { sum[i] = sum[i-1] + e[i] ;}
        
	scanf("%d",&count);

	while(count--)
	{
		scanf("%d",&input);
		_pos = BinarySearch(1,33049,input);
		if(sum[_pos]==input) printf("%d\n",seq[e[_pos]]);
		else printf("%d\n",seq[input-sum[_pos]]);
	}
	
	return 1;  
}

int BinarySearch(int Start , int End , int Destination)
{
	if(End == Start + 1) return Start;
	int Mid = (Start + End)/2;
	if(sum[Mid] == Destination) return Mid;
	if(sum[Mid]>Destination) BinarySearch(Start,Mid,Destination);
	else BinarySearch(Mid,End,Destination);
}

