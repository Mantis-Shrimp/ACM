#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

struct node
{
    int x, y;
    int id;
    int g;
    int h;
    char map[10];

    bool operator < (const node &a) const
    {
        return (a.h + a.g) < (h + g);
    }
};

struct node top, tmp;

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char d[] = "lurd";
int frac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
char visited[362880];
int fa[362880];
char dir[362880];
char st[10], ch;
int x, y;


//康拓展开
long long hash(char a[])
{
    int count;
    long long v = 0;

    for (int i = 1 ; i <= 9 ; i++)
    {
        count = 0;
        for (int j = 9 ; j > i ; j--)
            if (a[j] < a[i]) count++;
        v = v + count * frac[9 - i];
    }

    return v;
}


int geth(char s[])       //计算启发函数值，即曼哈顿距离
{
    int a, b, c, d, v;
    v = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (s[i] == 9)
            continue;
        a = (i + 2) / 3; //原来位置的x
        b = (i - 1) % 3 + 1; //原来位置的y
        c = (s[i] + 2) / 3;
        d = (s[i] - 1) % 3 + 1;
        v += abs(a - c) + abs(b - d);
    }
    return v;
}


int output(int idx)
{
    if (fa[idx] == -1)
        return 0;
    else
        output(fa[idx]);
    printf("%c", dir[idx]);
    return 0;
}

int Astar()
{

    memset(visited,0,sizeof(visited));
    priority_queue<node> opened;
    
    for (int i = 1 ; i <= 9 ; i++)
        top.map[i] = st[i];
    top.g = 0;
    top.h = geth(top.map);
    top.x = x;
    top.y = y;
    top.id = hash(top.map);
    fa[top.id] = -1;
    dir[top.id] = 0;

    visited[top.id] = 1;
    opened.push(top);

    while (!opened.empty())
    {
        top = opened.top();
        opened.pop();

        //      for(int i = 1 ; i <= 9 ; i++)
        //      {
        //          putchar(top.map[i]+'0');
        //          if((i)%3 == 0) putchar('\n');
        //      }
        //      printf("g=%d h=%d\n",top.g,top.h);
        //      printf("HHHHHHHHHHHHHH\n");
        //      getchar();

        if (top.map[1] == 1 &&
                top.map[2] == 2 &&
                top.map[3] == 3 &&
                top.map[4] == 4 &&
                top.map[5] == 5 &&
                top.map[6] == 6 &&
                top.map[7] == 7 &&
                top.map[8] == 8 &&
                top.map[9] == 9
           )
        {
            return 1;
        }


        for (int i = 0 ; i < 4 ; i++)
        {
            x = top.x + dx[i];
            y = top.y + dy[i];

            if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
            {
                tmp = top;

                tmp.map[top.y * 3 + top.x + 1] = tmp.map[y * 3 + x + 1];
                tmp.map[y * 3 + x + 1] = 9;

                tmp.id = hash(tmp.map);
                if (visited[tmp.id] == 1) continue;

                tmp.x = x;
                tmp.y = y;
                tmp.g++;
                tmp.h = geth(tmp.map);
                visited[tmp.id] = 1;
                opened.push(tmp);
                fa[tmp.id] = top.id;
                dir[tmp.id] = d[i];

            }
        }
    }

    return 0;
}

bool isok()
{    //求出逆序对，判断是否有解  
    int sum=0;  
    for(int i=1;i<10;i++)  
        for(int j=i+1;j<10;j++)  
            if(st[j]!=9&&st[i]!=9&&st[i]>st[j])  
                sum++;
    // printf("%d\n",sum);  
    return !(sum&1);    //由于目标解为偶数，所以状态的逆序数为偶数才可行  
}  


int main()
{
    //输入
    char str[50];
    int k;
    while (gets(str)!=NULL)
    {
        // puts(str);
        k = 0;
        for (int i = 0; str[i]; i++)
        {
            if (str[i] == 'x')
            {
                st[++k] = 9;
                x = (k - 1) % 3;
                y = (k - 1) / 3;
            }
            else if (str[i] != ' ')
                st[++k] = str[i] - '0';
        }

        
        if(isok()==0)
        {
        	printf("unsolvable\n");
        	continue;
        }

        if (Astar() == 1)
        {
            output(top.id);
            printf("\n");
        }
        else
        {
            printf("unsolvable\n");
        }
    }
    return 0;
}

