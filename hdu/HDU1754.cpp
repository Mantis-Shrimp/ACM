//============================================================================
// Name        : HDU_1754. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-25 
// Description : Ïß¶ÎÊ÷
//============================================================================
#include <cstdio>
#define NMAX 2000000 + 5

char chs[10];
int r,sum[3*NMAX],a[NMAX],M,N;
int m,n;

int build(int l,int r,int rt);
int query(int L,int R,int l,int r,int rt);
int update(int p,int val,int L,int R,int rt);

int main(int argc,char* argv[])
{
	    //freopen("in.txt","r",stdin);
	    //freopen("out.txt","w",stdout);
	    while(scanf("%d%d",&N,&M)!=EOF)
		{
		for(int i = 1 ; i <=N ; i++) scanf("%d",&a[i]);
		build(1,N,1);
		getchar();
		while(M--)
		{
		   scanf("%c",chs);
			switch(chs[0])
		   {
			   case 'Q':
				   scanf("%d%d",&m,&n);
				   printf("%d\n",query(m,n,1,N,1));
				   break;
			   case 'U':
				   scanf("%d%d",&m,&n);
				   update(m,n,1,N,1);
				   break;
			   default:
				   //printf("BBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
				   break;
		   }
			getchar();
		}
		}
}

int build(int l,int r,int rt)
{
	if(l==r) {sum[rt] = a[l];return 0;}
	build(l,l+r>>1,rt<<1);
	build((l+r>>1)+1,r,rt<<1|1);
	sum[rt] = sum[rt<<1] > sum[rt<<1|1] ? sum[rt<<1] : sum[rt<<1|1];
	return 0;
}

int query(int L,int R,int l,int r,int rt)
{
	int mid = l + r >> 1;
	int rr,rl;
	if(L==l&&r==R) return sum[rt];
	if(R<=mid) return query(L,R,l,mid,rt<<1);
	if(L>=mid+1) return query(L,R,mid+1,r,rt<<1|1);
	if(L<=mid&&mid+1<=R) 
	{ 
		rl = query(L,mid,l,mid,rt<<1);
	    rr = query(mid+1,R,mid+1,r,rt<<1|1);
		return rl>rr?rl:rr;
	}
}

int update(int p,int val,int l,int r,int rt)
{
	int mid = l + r >> 1;
	if(l==r) {sum[rt] = val; return 0;}
	if(p<=mid) update(p,val,l,mid,rt<<1);
	if(mid+1<=p) update(p,val,mid+1,r,rt<<1|1);
	sum[rt] = sum[rt<<1] > sum[rt<<1|1] ? sum[rt<<1] : sum[rt<<1|1];
	return 0 ;
}
