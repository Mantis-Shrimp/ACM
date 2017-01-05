#include <stdio.h>
//#include<algorithm>
//using namespace std;
#include <time.h>

int BestCom[4];
int CurCom[4];
int BestType;
int BestNum;
int isBest;
int Denomination[150];
int Need;
int NumberofDenomination;
int tie;

int input();
int DFS(int depth,int value ,int type,int num,int prei);
int output();
int bubble(int*,int*);


time_t dwStart = 0;
time_t dwEnd = 0;
//time_t Sort = 0;
//time_t StSort = 0;
//time_t EnSort = 0;



int main(int argc, char **argv)
{
	freopen("pku1010.in","r",stdin);
	freopen("pku1010.out","w",stdout);
	
	
	dwStart =  clock();
	
	while(NumberofDenomination = input())
	{
		bubble(Denomination,Denomination + NumberofDenomination);
		//sort(Denomination,Denomination + NumberofDenomination);
		while(scanf("%d",&Need)&&Need!=0)
	    {
			isBest = 0;
			tie = 0;
			DFS(0,0,0,0,0);
			output();
		}
	}
	
	dwEnd = clock();
	printf("total : %f",(double)(dwEnd - dwStart)/CLOCKS_PER_SEC);
	//printf("sort : %d",Sort);
	return 0;
}


int input()
{
	Denomination[0] = 0 ;
	int i = 1 ;
	do
	{
		if(scanf("%d",&Denomination[i++])==EOF) return 0;
	}
	while(Denomination[i-1]!=0);
	return i - 2;
}


int DFS(int depth,int value ,int type,int num,int prei)
{
	
	int _type = type;
	int _num = 0;
	int _value = 0;
	
	for(int i = prei; i<= NumberofDenomination ; i++)
	{
		CurCom[depth] = i ;
		
		if((depth==0&&i!=0)
		   ||(depth>=1&&prei-i!=0))
			   _type = type +1;
		
		if(i!=0)_num=num+1;
		
		if((_value=value+Denomination[i])>Need) break;
		//
		
		
		///////////////////////////////////////////
		
		if(depth<=2) DFS(depth+1,_value,_type,_num,i);
		if(depth==3&&_value==Need)
		{
			
			//printf("%d  %d            %d %d %d %d \n",_type,_num,CurCom[0],CurCom[1],CurCom[2],CurCom[3]);
			
			if(
			  isBest==0||
			  (isBest==1&&_type>BestType)||
			  (isBest==1&&_type==BestType&&_num<BestNum)||
			  (isBest==1&&_type==BestType&&_num==BestNum&&Denomination[CurCom[3]]>Denomination[BestCom[3]])
		      )
			  {
				  tie = 0;
				  isBest = 1;
				  BestCom[0] =CurCom[0];
				  BestCom[1] =CurCom[1];
				  BestCom[2] =CurCom[2];
				  BestCom[3] =CurCom[3];
				  BestNum = _num;
				  BestType = _type;
			  }
			  else
			 {
			       if(isBest==1&&_type==BestType&&_num==BestNum&&Denomination[CurCom[3]]==Denomination[BestCom[3]])
			       {
				    tie =1;
			       }
			  }
		}
		
	}
	return 1;
}

int output()
{
	
	if(isBest==0) 
		{
		  printf("%d",Need);
		  printf(" ---- none\n"); return 1;
		}
		
	printf("%d (%d):",Need,BestType);
	
	if(tie == 1)
	{ 
		printf(" tie\n");
		return 1;
	}
	
	for(int i = 0 ; i<=3;i++)
	{
		if(BestCom[i]!=0) 
			printf(" %d",Denomination[BestCom[i]]);
	}
	printf("\n");
	return 1;
}


int bubble(int *begin,int *end)
{
	
	//StSort = clock();
	int temp = 0;

	for(int *i = begin; i < end ;i++)
	{
		for(int *j = begin;j < end - ( i -begin ) ; j++)
		{
			if(*j>*(j+1))
			{
			   temp = *j;
			   *j = *(j+1);
			   *(j+1) = temp;
			}
		}
	}
	//EnSort = clock();
	//Sort += (EnSort-StSort); 
	return 1;
}
