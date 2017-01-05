//============================================================================
// Name        : VIJOS1001. cpp
// Author      :
// Version     :
// Copyright   : 2013-3-23
// Description : 模拟
//============================================================================

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define N (100+10)

using namespace std;


struct stu
{
	string name;
	int avg;
	int rp;
	int money;
	int p;
	char ld;
	char ds;
	bool operator < (const stu& a) const
	{
		return  money > a.money;
	}
};




int main()
{
	int n;
	int money = 0;
	stu stus[N];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>stus[i].name>>stus[i].avg>>stus[i].rp>>stus[i].ld>>stus[i].ds>>stus[i].p;

		stus[i].money = 0;


		//院士
		if(stus[i].avg>80&&stus[i].p>0) stus[i].money+=8000;

		//五四
		if(stus[i].avg>85&&stus[i].rp>80) stus[i].money+=4000;

		//优秀
		if (stus[i].avg>90) stus[i].money+=2000;

		//西部
		if (stus[i].avg>85&&stus[i].ds=='Y') stus[i].money+=1000;

		//贡献
		if(stus[i].rp>80&&stus[i].ld=='Y') stus[i].money+=850;

		money += stus[i].money;
	}

	stable_sort(stus,stus+n,less<stu>());
	cout<<stus[0].name<<endl<<stus[0].money<<endl<<money<<endl;
}