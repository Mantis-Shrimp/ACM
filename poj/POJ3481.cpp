#include <cstdio>
#include <map>

using namespace std;



map<int,int> m;
int p,k,c;


int main()
{
    while(scanf("%d",&c)&&c!=0)
    {
        if(c==0) return 0;
        if(c==1)
        {
            scanf("%d%d",&k,&p);
           // printf("___%d %d\n",pair<int,int>(p,k).first,pair<int,int>(p,k).second);
            m.insert(pair<int,int>(p,k));
        }
        if(c==2)
        {
            if(m.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",(--m.end())->second);
                m.erase(--m.end());
            }
        }
        if(c==3)
        {

            if(m.empty())
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n",m.begin()->second);
                m.erase(m.begin());
            }
        }
    }
    return 0;
}
