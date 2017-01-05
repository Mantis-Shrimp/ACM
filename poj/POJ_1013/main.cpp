#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int num;
char right[3][10];
char left[3][10];
char result[3][10];


bool isW(char c);
bool isL(char c);

int main()
{

    scanf("%d\n",&num);
    while(num--)
    {
        for(int i = 0 ; i <=2 ; i++) scanf("%s %s %s\n",left[i],right[i],result[i]);
        for(char i = 'A'; i<='L' ; i++)
        {
            if(isW(i)) {printf("%c is the counterfeit coin and it is heavy.\n",i);break;}
            if(isL(i)) {printf("%c is the counterfeit coin and it is light.\n",i);break;}
        }
    }
    return 0;
}

bool isW(char c)
{
    for(int i = 0 ; i<=2 ; i++)
    {
        switch(result[i][0])
        {
            case 'e' :
            if(strrchr(left[i],c)!=NULL||strrchr(right[i],c)!=NULL) return false;
            break;

            case 'u' :
            if(strrchr(left[i],c)==NULL) return false;
            break;

            case 'd' :
            if(strrchr(right[i],c)==NULL) return false;
            break;
        }
    }
    return true;
}

bool isL(char c)
{
    for(int i = 0 ; i<=2 ; i++)
    {
        switch(result[i][0])
        {
            case 'e' :
            if(strrchr(left[i],c)!=NULL||strrchr(right[i],c)!=NULL) return false;
            break;

            case 'd' :
            if(strrchr(left[i],c)==NULL) return false;
            break;

            case 'u' :
            if(strrchr(right[i],c)==NULL) return false;
            break;
        }
    }
    return true;
}
