    /* 
    ID:15864532
    LANG:C++ 
    TASK:camelot 
    */  
    #include<cstdio>  
    #include<cstring>  
    #include<queue>  
    #include<cstdlib>//里面有abs （取绝对值）   
    #define INF 0x3f3f3f3f  
    #define max(a,b) ((a)>(b)?(a):(b))  
    using namespace std;  
    const int maxR=31,maxC=28;  
    int R,C,n=0;  
    int kx,ky,nx[maxR*maxC],ny[maxR*maxC],d[maxC][maxR][maxC][maxR],ans=INF;//(kx,ky)表示国王坐标，(nx[i],ny[i])表示第i个骑士的坐标,d[x][y][a][b]表示(x,y)到(a,b)按照骑士走法最短距离  
    //我们把地图想象成坐标轴，前一个下标表示x(非常规写法的r即行)，下一个表示y   
      
    struct point{  
        int x,y,step;  
    };  
    void bfs(int sx,int sy){//宽度优先搜索-最短路   
        int dx[8]={-1,1,2,2,1,-1,-2,-2};  
        int dy[8]={2,2,1,-1,-2,-2,-1,1};  
        bool vis[maxC][maxR]={0};  
        queue<point>Q;  
        Q.push((point){sx,sy,0});  
        while(!Q.empty()){  
            point a=Q.front();Q.pop();  
            int x=a.x,y=a.y;  
            if(vis[x][y])continue;  
            vis[x][y]=1;  
            d[sx][sy][x][y]=a.step;  
            for(int i=0;i<8;i++){  
                int newx=x+dx[i],newy=y+dy[i];  
                if(newx>=0&&newx<C&&newy>=0&&newy<R)Q.push((point){newx,newy,a.step+1});  
            }  
        }  
          
    }  
    int main()  
    {  
        freopen("camelot.in","r",stdin);  
        freopen("camelot.out","w",stdout);  
        memset(d,0x3f3f3f3f,sizeof(d));  
        char ch;  
        scanf("%d %d\n",&R,&C);  
        scanf("%c %d\n",&ch,&ky);  
        kx=ch-'A',ky--;//习惯0下标开始   
        while((ch=getchar())!=EOF)if(ch>='A'&&ch<='Z'){  
            scanf("%d",&ny[n]);  
            ny[n]--,nx[n++]=ch-'A';  
            bfs(nx[n-1],ny[n-1]);  
        }  
        if(n==0){//特殊情况，没有骑士   
            printf("0\n");  
            return 0;  
        }  
        for(int dx=-2;dx<=2;dx++)  
        for(int dy=-2;dy<=2;dy++){  
            int newn=dx+kx,newm=dy+ky;  
            if(newn>=0&&newn<C&&newm>=0&&newm<R)bfs(newn,newm);} //求出 （枚举的骑士接国王的坐标）到任何点的最短距离   
        for(int newx=0;newx<C;newx++)  
        for(int newy=0;newy<R;newy++)  
        {  
            int t=0;  
            for(int i=0;i<n;i++){  
                if(d[nx[i]][ny[i]][newx][newy]==INF){t=INF;break;//如果集合点有一个骑士无法到达则退出   
                }  
                t+=d[nx[i]][ny[i]][newx][newy];  
            }  
            if(t==INF)continue;//此点无效，找下一个点   
            for(int dx=-2;dx<=2;dx++)//+-2的范围是因为：骑士一次能走2格，所以一定多走骑士。集合点一定会在国王坐标+-2之内，因为当骑士接近国王的时候（只能绕圈才能会和的时候），国王走到骑士旁边就是最短接国王的距离   
            for(int dy=-2;dy<=2;dy++){  
                int newn=dx+kx,newm=dy+ky,king=(abs(kx-newn)==abs(ky-newm)?abs(kx-newn):abs(kx-newn)+abs(ky-newm));//(newn,newm)表示某个骑士接国王的位置  king表示国王到（骑士接国王的位置）的最短距离，当在国王的对角线上能到达的时候距离是abs(kx-newn)否则是两个坐标之差的和   
                if(newn>=0&&newn<C&&newm>=0&&newm<R)  
                for(int i=0;i<n;i++)  
                ans=min(ans,t-d[nx[i]][ny[i]][newx][newy]+d[nx[i]][ny[i]][newn][newm]+king+d[newn][newm][newx][newy]);//枚举出到(newn,newm)接国王的骑士的最小花费   
            }  
        }  
        printf("%d\n",ans);  
        return 0;  
    }  