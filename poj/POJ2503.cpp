#include <cstdio>
#include <map>
#include <string>

#define LEN  100


using namespace std;

map<string,string> dic;
char cword[LEN],cindex[LEN],in[LEN];
string word,index;

int main()
{
     map<string,string>::iterator it;

    while(gets(in)&&in[0]!='\0')
    {
        sscanf(in,"%s %s",cword,cindex);
        word.assign(cword);
        index.assign(cindex);
        dic.insert(make_pair(index,word));
    }

    while(scanf("%s", in) != EOF)
    {
        index.assign(in);
        it = dic.find(index);

        if(it==dic.end())
        {
            puts("eh");
        }
        else
        {
             puts((*it).second.c_str());
        }
    }
    return 0;
}
