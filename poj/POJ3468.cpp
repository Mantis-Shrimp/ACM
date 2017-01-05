//============================================================================
// Name        : POJ_3468. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-26
// Description : Ïß¶ÎÊ÷
//============================================================================
#include <cstdio>
#define NQ 100000+5
#define LL(X)  (X<<1)
#define RR(X)  (X<<1|1)
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define DEBUG

int N,Q,a[NQ],b,c,val;
char ch;

struct e
{
	long long sum;
	int L;
	int R;
	long long lazy;
};

struct e seg_tree[3*NQ];

int pushitself(int rt);
int build(int L,int R,int rt);
int updateinterval(int l,int r,long long val,int rt);
long long query(int l,int r,int rt);
int pushdown(int rt);

int main(int argc, char* argv[])
{
	scanf("%d%d",&N,&Q);
	for(int i = 1 ; i <= N ; i++) scanf("%d",&a[i]);
	build(1,N,1);
	while(Q--)
	{
		getchar();
		scanf("%c",&ch);
#ifdef DEBUG
		printf("%c\n",ch);
#endif
		if(ch=='Q')
		{
			scanf("%d%d",&b,&c);
			printf("%I64d\n",query(b,c,1));
		}
		if(ch=='C')
		{
			scanf("%d%d%d",&b,&c,&val);
			updateinterval(b,c,val,1);
		}
#ifdef DEBUG
			for(int i = 1 ; i <= 3 *N ; i++)
			  {
				  printf("i = %d\n",i);
				  printf("L = %d,R = %d,lazy = %I64d,sum = %I64d\n",seg_tree[i].L,seg_tree[i].R,seg_tree[i].lazy,seg_tree[i].sum);
			  }
#endif
	}
}

int build(int L,int R,int rt)
{
	int mid = (L + R)>>1;
	seg_tree[rt].lazy = 0;
	seg_tree[rt].L = L;
	seg_tree[rt].R = R;
	if(L==R)
	{
		seg_tree[rt].sum = a[mid];
		return 0;
	}
	build(L,mid,LL(rt));
	build(mid+1,R,RR(rt));
	pushitself(rt);
}

int updateinterval(int l,int r,long long val,int rt)
{
    int R = seg_tree[rt].R;
	int L = seg_tree[rt].L;
	int mid = R + L >> 1;
	if(R==r&&L==l)
	{
		seg_tree[rt].sum += ((long long)(r - l +  1) * (long long)val);
		seg_tree[rt].lazy += val;
		return 0;
	}
	
	pushdown(rt);
	if(r<=mid)
	updateinterval(l,r,val,LL(rt));
	if(mid+1<=l)
	updateinterval(l,r,val,RR(rt));
	if(l<=mid&&mid+1<=r)
	updateinterval(l,mid,val,LL(rt)),
	updateinterval(mid+1,r,val,RR(rt));
	
	pushitself(rt);
	return 0;
}

long long query(int l,int r,int rt)
{
    int R = seg_tree[rt].R;
	int L = seg_tree[rt].L;
	int mid = R + L >> 1;
	if(R==r&&L==l)
        return seg_tree[rt].sum;
		
	pushdown(rt);
	
	if(r<=mid)
	return query(l,r,LL(rt));
	if(mid+1<=l)
	return query(l,r,RR(rt));
	if(l<=mid&&mid+1<=r)
	return query(l,mid,LL(rt))+ query(mid+1,r,RR(rt));
}

int pushitself(int rt)
{
	seg_tree[rt].sum = seg_tree[LL(rt)].sum + seg_tree[RR(rt)].sum;
	return 0;
}

int pushdown(int rt)
{
	if(seg_tree[rt].lazy!=0)
	{
		seg_tree[LL(rt)].sum  += (seg_tree[LL(rt)].R - seg_tree[LL(rt)].L + 1) * seg_tree[rt].lazy;
		seg_tree[RR(rt)].sum  += (seg_tree[RR(rt)].R - seg_tree[RR(rt)].L + 1) * seg_tree[rt].lazy;
		
		seg_tree[LL(rt)].lazy+= seg_tree[rt].lazy;
		seg_tree[RR(rt)].lazy+= seg_tree[rt].lazy;
		
		seg_tree[rt].lazy = 0 ;
	}
	return 0;
}
