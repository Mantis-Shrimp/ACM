#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>


#define LEN   25

char room[LEN][LEN];
int flag[LEN][LEN];
int w,h;
int w0,h0;
int ret = 0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


int dfs(int x,int y)
{
  if( (x >= 0 && x < w) &&  (  y >= 0 && y < h ))
    {
      if( (room[y][x] == '@' || room[y][x] == '.' ) &&  flag[y][x] == 0 )
        {
          ret = ret + 1;
          flag[y][x] = 1;
          for(int i = 0 ; i < 4 ; i++)
            dfs(x+dx[i],y+dy[i]);
        }
    }
  return 0;
}

int main(int arc,char* argv[])
{
  //freopen("in.txt","r",stdin);
  
  while(std::cin >> w >> h)
    {
      std::cin.get();
      //std::cout<<w<<" "<<h<<std::endl;
      if(w==0 &&  h==0) break;
      ret = 0;
      for(int i = 0 ; i < h ; i++)
        std::cin.getline(room[i],LEN);
      memset(flag,0,sizeof(flag));

      for(int i = 0 ; i < h ; i++)
        {
          for(int j = 0 ; j < w ; j++)
            {
              if(room[i][j] == '@'  )
                w0 = j,h0 = i;
            }
        }
      dfs(w0,h0);
      std::cout<<ret<<std::endl;
    }
}
