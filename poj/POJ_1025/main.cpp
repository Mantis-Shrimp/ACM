#include <stdio.h>
#include <list>
#include <string.h>

using namespace std;

int bed;
int total_bed;
int num;
list<char> wlist;
char chs[1000];
char flag[260];

int main()
{
    int len;
    //freopen("in.txt","r",stdin);
    scanf("%d",&total_bed);
    while(total_bed!=0)
    {
        scanf("%s",chs);
        bed = 0,num = 0;
        len = strlen(chs);
        memset(flag,'N',260*sizeof(char));

        for(int i = 0 ; i < len ; i++)
        {
            switch(flag[chs[i]])
            {
                case 'N':

                   if(bed==total_bed)
                   {
                       wlist.push_back(chs[i]);
                       flag[chs[i]] = 'W';
                   }
                   else
                   {
                       bed++;
                       flag[chs[i]] = 'F';
                   }

                break;
                case 'W':

                    for(list<char>::iterator it = wlist.begin(); it != wlist.end();)

                    if(*it==chs[i])  it = wlist.erase(it);
                    else it++;

                     flag[chs[i]] = 'N';
                    num++;

                break;

                case 'F':

                   flag[chs[i]] = 'N';
                   bed--;
                   if(!wlist.empty())
                   {
                       bed++;
                       flag[*wlist.begin()]='F';
                       wlist.erase(wlist.begin());
                   }
               break;
            }
        }

        if(num==0) printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n",num);

        scanf("%d",&total_bed);
    }
    return 0;
}
