/*
LANG: C++
ID: 15864532
PROG: msquare
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<set>
using namespace std;
int top=1,bottom=0;
int CharNumber=0;
struct node
{
	int x[9];
 
	inline bool operator<(const node &n) const
	{
        for (int i = 1; i <= 8; i++)
            if (x[i] < n.x[i])
                return true;
            else if (x[i] > n.x[i])
                return false;
        return false;
    }
 
    inline bool operator==(const node &n) const
    {
        for (int i = 1; i <= 8; i++)
            if (x[i] != n.x[i])
                return false;
        return true;
    }
};
set <node> s;
node next;
node start,end;
struct q
{
	int step;
	string now;
	node statue;
}que[100000];
void PrintChar(char c)
{
	cout << c;
	CharNumber++;
	if(CharNumber==60)
	{
		cout << endl;
		CharNumber=0;
	}
}
void in(int st,string n,node sta)
{
	bottom++;
	que[bottom].step=st;
	que[bottom].now=n;
	que[bottom].statue=sta;
	s.insert(sta);
}
void out()
{
	top++;
}
void End()
{
	cout << que[bottom].step << endl;
	for(int i=0;i<que[bottom].step;i++)
		PrintChar(que[bottom].now[i]);
	cout << endl;
}
int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	for(int i=1;i<=8;i++)
	{
		start.x[i]=i;
		cin >> end.x[i];
	}
	start.x[0]=0;
	end.x[0]=0;
	if(start==end)
	{
		cout << '0' << endl << endl;
		return 0;
	}
	string stri;
	in(0,stri,start);
	while(top<=bottom)
	{
		q cur=que[top];
		next.x[1]=cur.statue.x[8];
		next.x[2]=cur.statue.x[7];
		next.x[3]=cur.statue.x[6];
		next.x[4]=cur.statue.x[5];
		next.x[5]=cur.statue.x[4];
		next.x[6]=cur.statue.x[3];
		next.x[7]=cur.statue.x[2];
		next.x[8]=cur.statue.x[1];
		if(s.find(next)==s.end())
		{
			string str=cur.now;
			str.push_back('A');
 
			in(cur.step+1,str,next);
			if(que[bottom].statue==end)
			{
				End();
				return 0;
			}
		}
		next.x[1]=cur.statue.x[4];
		next.x[2]=cur.statue.x[1];
		next.x[3]=cur.statue.x[2];
		next.x[4]=cur.statue.x[3];
		next.x[5]=cur.statue.x[6];
		next.x[6]=cur.statue.x[7];
		next.x[7]=cur.statue.x[8];
		next.x[8]=cur.statue.x[5];
		if(s.find(next)==s.end())
		{
			string str=cur.now;
			str.push_back('B');
 
			in(cur.step+1,str,next);
			if(que[bottom].statue == end)
			{
				End();
				return 0;
			}
		}
		next.x[1]=cur.statue.x[1];
		next.x[2]=cur.statue.x[7];
		next.x[3]=cur.statue.x[2];
		next.x[4]=cur.statue.x[4];
		next.x[5]=cur.statue.x[5];
		next.x[6]=cur.statue.x[3];
		next.x[7]=cur.statue.x[6];
		next.x[8]=cur.statue.x[8];
		if(s.find(next)==s.end())
		{
			string str=cur.now;
			str.push_back('C');
 
			in(cur.step+1,str,next);
			if(que[bottom].statue==end)
			{
				End();
				return 0;
			}
		}
		top++;
	}
	return 0;
}