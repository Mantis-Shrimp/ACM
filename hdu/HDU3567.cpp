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

int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, -1};

char d[] = "dlru";
int frac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
char visited[10][362880];
int step[10][362880];
int fa[10][362880];
char dir[10][362880],ch;
char st[10][15] ={"0123456789","0912345678","0192345678","0129345678",
							"0123945678","0123495678","0123459678",
							"0123456978","0123456798","0123456789"
};
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


int output(int idx,int id)
{
    if (fa[idx][id] == -1)
        return 0;
    else
        output(idx,fa[idx][id]);
    printf("%c", dir[idx][id]);
    return 0;
}

int BFS(int idx)
{
    // priority_queue<node> opened;
    queue<node> opened;

    for (int i = 1 ; i <= 9 ; i++)
        top.map[i] = st[idx][i];
    top.g = 0;
    top.h = geth(top.map);
    
    top.x = (idx -1) % 3;
    top.y = (idx -1) / 3;
    
    top.id = hash(top.map);
    fa[idx][top.id] = -1;
    dir[idx][top.id] = 0;
    visited[idx][top.id] = 1;
    step[idx][top.id] = 0;
    opened.push(top);

    while (!opened.empty())
    {
        // top = opened.top();
        top = opened.front();
        opened.pop();

        // for(int i = 1 ; i <= 9 ; i++)
        // {
        //     // putchar(top.map[i]+'0');
        //     printf("%d",top.map[i]);
        //     if((i)%3 == 0) putchar('\n');
        // }
        // printf("g=%d h=%d\n",top.g,top.h);
        // printf("HHHHHHHHHHHHHH\n");
        // getchar();


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
                if (visited[idx][tmp.id] == 1) 
                	continue;

                tmp.x = x;
                tmp.y = y;
                tmp.g++;
                tmp.h = geth(tmp.map);
                visited[idx][tmp.id] = 1;
                opened.push(tmp);
                fa[idx][tmp.id] = top.id;
                dir[idx][tmp.id] = d[i];
                step[idx][tmp.id] = tmp.g;
            }
        }
    }

    return 0;
}


int main()
{
    //输入
    int k,T;
    char s[15],d[15],tar[15];

    scanf("%d",&T);
    // printf("%d\n",T);
    getchar();
    
    for(int i = 1 ; i <= 9 ; i++) 
    	for(int j = 1 ; j <= 9 ;j++)
    		st[i][j] = st[i][j] - '0';

    memset(visited,0,sizeof(visited));
    for(int i = 1 ; i <= 9 ; i++)
    	BFS(i);

    for(int c = 1 ; c <= T ; c++)
    {
    	int idx;
    	gets(s + 1);
    	gets(d + 1);

    	for(int j = 1 ; j < 10 ;j++)
    	{
    		if(s[j]=='X')
    		{
    			idx = j;
    			s[j] = 9;
    		}
    		else
    		{
    			s[j] = s[j] - '0';
    		}

    		if(d[j]=='X')
    		{
    			d[j] = 9;
    		}
    		else
    		{
    			d[j] = d[j] - '0';
    		}
    	}

    	for(int i = 1 ; i <= 9 ; i++)
    	{
    		for(int j = 1 ; j <= 9 ;j++)
    		{
    			if(d[j]==s[i])
    			{
    				tar[j] = st[idx][i];
    				break;
    			}
    		}
    	}


    	// for(int i = 1 ; i <= 9 ; i++)
    	// 	printf("%d",tar[i]);
    	// printf("\n");
    	
    	printf("Case %d: %d\n",c,step[idx][hash(tar)]);
    	output(idx,hash(tar));
    	printf("\n");
    	// printf("%d\n", T);
    }
    return 0;
}

