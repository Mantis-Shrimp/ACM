#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2010;//墙数上限
struct Twall//墙的结构类型
{
    int x1, x2, y;//行坐标为y，两个端点的列坐标在lx表的指针为x1,x2
};
int n, m, w, n1, m1;//房间规模为n*m，墙数为w
Twall a[MAXN];//墙序列
int lx[MAXN];//存储墙端点的x坐标，表长为n1
long long ans;//被困的格子
bool f[MAXN];//状态转移方程：当前可从lx[i]走至右上角的标志为f[i]
bool g[MAXN];//g[j]=false,表明当前行第j列为被困格

void init()//输入墙的信息
{
    ans = (long long)n*m;//初始时所有格子未被困
    n1 = 0;//lx表长初始化
    for (int i = 1; i <= w; i++) {//每输入堵墙的两个端点坐标
        scanf("%d%d%d%d", &a[i].x1, &a[i].y, &a[i].x2, &a[i].y);
        ++a[i].x2;
        ans -= a[i].x2 - a[i].x1;//被困格子数的初始值为房间中除墙外的格子
        lx[++n1] = a[i].x1; lx[++n1] = a[i].x2;//存储第i墙的两个端点的x坐标
    }
    lx[++n1] = 0; lx[++n1] = n;
}

void discrete(int a[], int &len)//递增排序数组a,并剔去重复元素
{
    sort(a + 1, a + 1 + len);
    int j = 1;
    for (int i = 2; i <= len; i++)
        if (a[j] != a[i])
            a[++j] = a[i];
    len = j;
}

int bin(int a[], int len, int k)//在a数组中二分查找值为k的元素下标
{
    int l = 1, r = len, m;
    while (l<=r)
    {
        m = (l + r) >> 1;
        if (a[m] == k) return m;
        if (a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

bool cmp_Twall(Twall a, Twall b)//返回同行的a堵墙在b堵墙右方，或者a堵墙在b堵墙上方的标志
{
    if (a.y == b.y) return a.x2 > b.x2;
    else return a.y > b.y;
}

void deal_f(int k)//计算行宽为k时可通过行的格子数，调整被困的格子数
{
    long long t = 0;
    for (int i = 1; i < n1; i++)//统计可通行的列宽
        if (f[i])                            //lx中的第i个x坐标和i+1个x坐标间为一条通向右上角的通道
            t += lx[i + 1] - lx[i];
    ans -= (long long)t*k;        //调整被困的格子数
}

void solve()                            //计算和输出被困的格子数
{
    discrete(lx, n1);                //离散化：递增排序lx数组，并剔去重复元素
    for (int i = 1; i <= w; i++)//计算每堵墙两端的x坐标在lx中的下标位置
    {
        a[i].x1 = bin(lx, n1, a[i].x1);
          a[i].x2 = bin(lx, n1, a[i].x2);
    }
    sort(a + 1, a + 1 + w, cmp_Twall);//按照由右而左、由上而下排序每堵墙
    int last = m;                                     //从顶行出发    
    memset(f, 0, sizeof(f));                     //状态转移方程初始化    
    f[n1 - 1] = true;
    int st = 1, ed;                                  //从a序列的第1堵墙开始分析
    while (st<=w)                                  //自上而下分析每堵墙
    {
        ed = st;                                        //a[st...ed]中的墙位于同一行，且与a[ed+1]不同行
        while ((ed < w) && (a[ed + 1].y == a[ed].y)) ++ ed;
        if (a[st].y != last - 1) {                    //若当前行与前面分析的墙并非相邻行，则计算状态转移方程
            for (int i = n1 - 2; i >= 1; i--)
                f[i] = f[i] || f[i + 1];
            deal_f(last - a[st].y - 1);             //累计行宽为(last-a[st].y-1)时被困的格子数
        }
        memset(g, true, sizeof(g));
        for (int i = st; i <= ed; i++)              //计算a[st..ed]中墙的并集，即当前行被困的格子
            for (int j = a[i].x1; j < a[i].x2; j++)
                g[j] = false;
        f[n1 - 1] = f[n1 - 1] && g[n1 - 1];    //计算状态转移方程
        for (int i = n1 - 2; i >= 1; i--)
            f[i] = g[i] && (f[i] || f[i + 1]);
        deal_f(1);                                            //将当前行被困的格子数计入ans    
        last = a[st].y;                                    //记下当前的行号和下一个不同行的墙序号
        st = ed + 1;
    }
    for (int i = n1 - 2; i >= 1; i--)                 //计算状态转移方程
        f[i] = f[i] || f[i + 1];
    deal_f(last);                                             //将最后last行中被困的格子数计入ans
    printf("%lld\n", ans);                             //输出被困的格子数
}

int main()
{
    int CASE = 0;                                            //测试编号初始化                
    while (scanf("%d%d%d",&m,&n,&w)==1,!(n==0&&m==0&&w==0))
    {
        init();                                                    //输入墙的信息    
        printf("Case %d: ", ++CASE);                //输出测试用例编号
        solve();                                                    //计算和输出被困的格子数    
    }
    return 0;
}
