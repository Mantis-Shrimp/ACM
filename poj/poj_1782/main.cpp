#include <stdio.h>
#include <vector>
using namespace std;


int fun();
int print_no();
int print();
int print_n();

vector<char> temp;
char ch[500];
int len = 0 ;
int flag = -1 ;
int count = 0 ;

int main(int argc, char **argv)
{
	while(gets(ch)!=NULL)
	{
		flag = 0 ;
		count = 0 ;
		temp.clear();
		fun();
		printf("\n");
	}
	return 0;
}


int fun()
{
	while(1)
		{
			switch(flag)
			{
				case 0:

				if(ch[count]==0){temp.clear();flag = 0 ;return 1;}
				else{temp.push_back(ch[count]);flag = 1;count++;}
				break;

				case 1:
				if(ch[count]==0)
				{print_no();flag=0;temp.clear();return 1;}
				if(ch[count]==temp[temp.size()-1])
				{
					temp.push_back(ch[count]);
					flag = 3 ;
					count++;
				}
				else
				{
					temp.push_back(ch[count]);
					flag = 2 ;
					count++;
				}

                break ;

				case 2:

				if(ch[count]==0)
				{print_no();flag=0;temp.clear();return 1;}

				if(ch[count]==temp[temp.size()-1])
				{

					flag = 3 ;
					print_n();
					temp.clear();
					temp.push_back(ch[count]);
					temp.push_back(ch[count]);
					count++;
				}
				else
				{
					temp.push_back(ch[count]);
					flag = 2 ;
					count++;
				}

				break ;

				case 3:

				if(ch[count]==0)
				{print();flag=0;temp.clear();return 1;}

				if(ch[count]==temp[temp.size()-1])
				{

					flag = 3 ;
					temp.push_back(ch[count]);
					if(temp.size()==9)
					{
						print();
						temp.clear();
						flag = 0;
					}
					count++;
				}
				else
				{
					print();
					temp.clear();
					temp.push_back(ch[count]);
					flag = 1 ;
					count++;
				}
				break;
				default:
				break;
			}
		}
}


int print_no()
{
	printf("1");
	for(vector<char>::iterator it = temp.begin(); it<temp.end() ; it++)
	{
		*it=='1'?printf("%c%c",'1','1'):printf("%c",*it);
	}
	printf("1");
	return 1;
}



int print_n()
{
	printf("1");
	for(vector<char>::iterator it = temp.begin(); it<(temp.end() -1) ; it++)
	{
		*it=='1'?printf("%c%c",'1','1'):printf("%c",*it);
	}
	printf("1");
	return 1;
}

int print()
{
	printf("%d",temp.size());
	printf("%c",temp[0]);
	return 1;
}
