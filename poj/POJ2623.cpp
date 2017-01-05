#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

int n,temp,a,b;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        scanf("%d",&temp);
        q.push(temp);
        if(i>=n/2+2) q.pop();
    }
    if(n%2==1)
    {
        printf("%.1f\n",q.top()*1.0);
    }
    else
    {
        a = q.top();
        q.pop();
        b = q.top();
        printf("%.1f\n",(a*1.0+b*1.0)/2);
    }
    return 0;
}
