//============================================================================
// Name        : POJ_2777. cpp
// Author      :
// Version     :
// Copyright   : 2012-7-26
// Description : Ïß¶ÎÊ÷
//============================================================================
#include <cstdio>
#define LMAX 100000
#define RR(X) X<<1|1
#define LL(X) X<<1
//#define DEBUG

struct e
{
	int lazy;
	int L;
	int R;
	int color;
};

int pushitself (int rt);
int build (int L,int R, int rt );
int updateinterval (int l,int r, int val, int rt );
int query( int l ,int r,int rt);
int pushdown (int rt);

int L,T,O,color[35];
int a,b,c,r,num,ch;
struct e seg_tree[3*LMAX];


int main(int agrc,char* argv[])
{
	color[1] = 1;
	for(int i = 2 ; i <=30 ; i++) color[i] = color[i-1]<<1 ;
	scanf("%d%d%d",&L,&T,&O);
	getchar();
	build(1,L,1);
	while(O--)
	{
		scanf("%c",&ch);
		if(ch=='C')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a<=b)
			updateinterval(a,b,c,1);
			else
			updateinterval(b,a,c,1);
		}
		if(ch=='P')
		{
			scanf("%d%d",&a,&b);
			if(a<=b)
			r = query(a,b,1);
			else
			r = query(b,a,1);
			num = 0 ;
			for(int i = 1 ; i<=30 ; i++)
			{
				if(r&1==1) num++;
				r>>=1;
			}
			printf("%d\n",num);
		}

#ifdef DEBUG
        for(int i = 1 ; i <= 3 *L ; i++)
        {
             printf("i = %d\n" ,i);
             printf("L = %d,R = %d,lazy = %o,color = %o\n",seg_tree[ i].L ,seg_tree[ i].R ,seg_tree[ i].lazy ,seg_tree[ i].color );
        }
#endif
		
		getchar();
	}
}

int build (int L,int R, int rt )
{
        int mid = (L + R)>>1;
        seg_tree[rt ].lazy = 0;
        seg_tree[rt ].L = L;
        seg_tree[rt ].R = R;
        if(L ==R)
       {
               seg_tree[rt].color = color[1];
               return 0;
       }
        build(L ,mid, LL(rt ));
        build(mid +1,R, RR(rt ));
        pushitself(rt);
}

int updateinterval (int l,int r, int val, int rt )
{
        int R = seg_tree [rt]. R;
        int L = seg_tree[ rt].L ;
        int mid = R + L >> 1;
        if(R ==r&& L==l )
       {
               seg_tree[rt ].color = color[val];
               seg_tree[rt ].lazy  = color[val];
               return 0;
       }
        pushdown(rt );
        if(r <=mid)
        updateinterval(l ,r, val,LL (rt));
        if(mid +1<=l)
        updateinterval(l ,r, val,RR (rt));
        if(l <=mid&& mid+1<=r )
        updateinterval(l ,mid, val,LL (rt)),
        updateinterval(mid +1,r, val,RR (rt));
       
        pushitself(rt );
        return 0;
}

int query( int l ,int r,int rt)
{
	    int R = seg_tree [rt]. R;
        int L = seg_tree[ rt].L ;
        int mid = R + L >> 1;
        if(R ==r&& L==l )
			return seg_tree[rt].color;

        pushdown(rt );
       
        if(r <=mid)
        return query (l, r,LL (rt));
        if(mid +1<=l)
        return query (l, r,RR (rt));
        if(l <=mid&& mid+1<=r )
        return query (l, mid,LL (rt)) | query(mid +1,r, RR(rt ));
}

int pushitself (int rt)
{
        seg_tree[rt].color = seg_tree[LL(rt)].color | seg_tree[RR(rt)].color ;
        return 0;
}

int pushdown (int rt)
{
        if(seg_tree [rt]. lazy!=0)
       {
               seg_tree[LL (rt)]. color  =  seg_tree[rt ].lazy;
               seg_tree[RR (rt)]. color  =  seg_tree[rt ].lazy;
               seg_tree[LL (rt)]. lazy = seg_tree [rt]. lazy;
               seg_tree[RR (rt)]. lazy = seg_tree [rt]. lazy;
              
               seg_tree[rt ].lazy = 0 ;
       }
        return 0;
}

