#include<stdio.h>
using namespace std;
bool DFS(int depth,int sum,int len,int num,int total);



int sort(int*,int*);
int Sticks[64];
int Sticks_n[64];
int Sticks_s[64];
int IsValid[64];
int number;
int MaxLen;

int main()
{
	freopen("pku1011.in","r",stdin);
	freopen("pku1011.out","w",stdout);

	while(scanf("%d",&number))
	{
		MaxLen = 0;
		if(number==0) return 1;
		for(int i = 0; i<=number-1; i++)
		{
			scanf("%d",&Sticks[i]);
			IsValid[i]=1;
			MaxLen += Sticks[i];
		}
		sort(Sticks,Sticks+number);

		Sticks_n[number-1] = number;
		
		for(int i = number-1; i>=0; i--)
		{
			for(int j = i+1; j<=number-1; j++)
			{
				if(Sticks[i]!=Sticks[j])
				{
					Sticks_n[i]=j;
					break;
				}
			}
			if(i == number-1)
			{
				Sticks_s[i] = Sticks[i];
			}
			else
			{
				Sticks_s[i] = Sticks_s[i+1]+Sticks[i];
			}

		}
		
		for(int i = *Sticks; i<=MaxLen; i++)
		{
			for(int ii = 0;ii<number;ii++){IsValid[ii]=1;}
			if(MaxLen%i==0)
			{
				int num = MaxLen/i;
				//printf("------------------%5d-------------------\n",i);
				if(DFS(0,0,i,0,num)==true)
				{
					printf("%d\n",i);
					break;
				}
			}
		
		}
		
	}
}
int sort(int* begin,int*end)
{
	int len = end - begin;
	int temp = 0;
	
	for(int i = 1 ;i <= len-1 ;i++)
	{
		for(int j = 0; j< len-i;j++)
		{
			if(*(begin+j)<*(begin+j+1))
			{
				temp = *(begin+j);
				*(begin+j) = *(begin+j+1);
				*(begin+j+1) = temp;
			}
		}
	}
	return 0;
}


bool DFS(int depth,int sum,int len,int num,int total)
{
	int _sum = 0;
	int _num = num;
	int i = depth;
	while(i<number)
	{
		if(IsValid[i]==true&&sum+Sticks[i]<=len&&sum+Sticks_s[i]>=len)
		{
		IsValid[i]=false;_sum=sum+Sticks[i];if(_sum==len){_num=num+1;}
		if(_sum<len)
		{
			if(DFS(i+1,_sum,len,_num,total)==true)
			{
				IsValid[i] = true;
				return true;
			}
			else
			{
				if(depth==0) 
					return false;
			}
		}
		
		if(_sum==len&&_num<total)
		{
			if(DFS(0,0,len,_num,total)==true)
			{
				IsValid[i] = true;
				return true;
			}
		}
		if(_sum==len&&_num==total)
		{
			IsValid[i]=true;
			return true;
		}
		IsValid[i]=true;
		i = Sticks_n[i];
	    }
		else
		{
			i++;
		}
     }
	 return false;
}