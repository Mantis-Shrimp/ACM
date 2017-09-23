#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <ctime>
#include <climits>

#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)arr.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define READ            freopen("in.txt", "r", stdin)
#define WRITE           freopen("fracdec.out", "w", stdout)
#define SYNCOFF         std::ios_base::sync_with_stdio(false);
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}


const int32_t len = 10005;

struct garbage
{
  int32_t x;
  int32_t y;


  garbage(int32_t x,int32_t y)
  {
    this->x = x;
    this->y = y;
  }

  bool operator < (garbage& tmp) const
  {
    if(this->x < tmp.x )
      {
        return true;
      }
    else
      {
        if(this->x == tmp.x)
          {
            if(this->y < tmp.y)
              {
                return true;
              }
            else
              {
                return false;
              }
          }
        else
          {
            return false;
          }
      }
  }
};



int32_t n,w,h;
int32_t t = 0;
bool flag = false;

int32_t main(int32_t argc,char* argv[])
{
  while(1)
    {
      std::cin>>h>>w;
      flag = false;
      t = t + 1;
      if( w ==- 1 && h == -1) break;

      int32_t tmpx,tmpy;
      std::vector<garbage>  garbages;

      while(1)
        {
          std::cin>>tmpy>>tmpx;
          if(tmpx == 0 && tmpy == 0) break;
          garbages.push_back(garbage(tmpx, tmpy));

          if(tmpx == w && tmpy == h) flag = true;
        }

      if(flag == false)
        {
          garbages.push_back(garbage(w,h));
        }


      std::sort(garbages.begin(),garbages.end());

      int32_t l = garbages.size();

      // for(auto tmp : garbages)
      //   {
      //     std::cout<<"("<<tmp.x<<","<<tmp.y<<")"<<std::endl;
      //   }

      std::vector<int32_t>  dp1(l);
      std::vector<int32_t>  path(l);
      std::vector<int32_t>  dp2(l);

      for(int32_t i = 0 ; i < l ; i++)
        {
          int32_t tmp = 0;
          for(int32_t j = i - 1 ; j >= 0 ; j--)
            {
              if(
                 garbages[i].y > garbages[j].y && garbages[i].x >= garbages[j].x
                 ||
                 garbages[i].y >=garbages[j].y && garbages[i].x >  garbages[j].x
                )
                {
                  if( dp1[j] > tmp )
                    {
                      tmp = dp1[j];
                      path[i] = j;
                      dp2[i] = 0;
                    }

                  if(dp1[j] == tmp )
                    {
                      dp2[i] = dp2[j] +  dp2[i];
                    }
                }
            }

          dp1[i] = tmp + 1;
          if(dp1[i] == 1 ) dp2[i] = 1 , path[i] = -1 ;
        }


      // for( auto tmp : dp1)
      //   {
      //     std::cout<<tmp<<" ";
      //   }

      // std::cout<<std::endl;


      // for( auto tmp : dp2)
      //   {
      //     std::cout<<tmp<<" ";
      //   }

      // std::cout<<std::endl;

      // for( auto tmp : path)
      //   {
      //     std::cout<<tmp<<" ";
      //   }

      // std::cout<<std::endl;

      //for(auto tmp : garbages)
      // //  {
      //     std::cout<<tmp.x<<" ";
      //   }

      // std::cout<<std::endl;


      std::vector<int32_t> ret;
      int32_t tmp = path.back();

      while(tmp != -1 )
        {
          ret.push_back( (garbages[tmp].y - 1) * w  +  garbages[tmp].x);
          tmp = path[tmp];
        }


      if( flag == false )
        {
          std::cout<<"CASE#"<<t<<": "<<dp1.back()-1<<" "<<dp2.back();
          for(int i = ret.size() - 1 ;  i >= 0 ; i--)
            {
              std::cout<<" "<<ret[i];
            }
        }

      if( flag == true )
        {

          std::cout<<"CASE#"<<t<<": "<<dp1.back()<<" "<<dp2.back();

          for(int i = ret.size() - 1 ;  i >= 0 ; i--)
            {
              std::cout<<" "<<ret[i];
            }

          std::cout<<" "<< (h-1) * w + w;
        }

      std::cout<<std::endl;
    }

  return 0;
}
