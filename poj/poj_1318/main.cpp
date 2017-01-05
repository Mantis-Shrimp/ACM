#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
using namespace std;


int comp(const void* ,const void*);

struct str
{
	char sou[20];
	char des[20];
};

struct cmp
{
	bool operator()(const str &a ,const str &b) const
	{
		return strcmp(a.sou,b.sou)<= 0?true:false;
	}
};





set<str,cmp> data;
//set<str> data;
int count = 0 ;
int len = 0 ;
char ch[20];
str strtemp;
int flag = 0 ;


int main()
{
	//freopen("io.h","w",stdout);
	gets(ch);
	while(strcmp(ch,"XXXXXX")!=0)
	{
		strcpy(strtemp.des,ch);
		strcpy(strtemp.sou,ch);
		len = strlen(ch);
		qsort(strtemp.des,len,sizeof(char),comp);
		data.insert(strtemp);
		count ++ ;
		gets(ch);
	}



   //for(set<str,cmp>::iterator it = data.begin(); it != data.end();it++)
	//	{
			//if(strcmp((*it).des,ch)==0) puts((*it).sou),flag++;
	//		puts(it->sou);
	//		puts("**");
	//		puts(it->des);
	//	}



	gets(ch);
	while(strcmp(ch,"XXXXXX")!=0)
	{
		len = strlen(ch);
		qsort(ch,len,sizeof(char),comp);
		flag =0 ;

		for(set<str,cmp>::iterator it = data.begin(); it != data.end();it++)
		{
			if(strcmp((*it).des,ch)==0) puts((*it).sou),flag++;
			//puts(it->sou);
			//puts("**");
			//puts(it->des);
		}
		if(flag==0) puts("NOT A VALID WORD");
		puts("******");
		gets(ch);
	}

	return 1;
}

int comp(const void *a,const void *b)
{
	return  (*(char*)b)-(*(char *)a);
}
