/*
ID: 15864532
PROB:spin
LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
struct wheel
{
	int spd,start[6],len[6],size;
};
int main()
{
	short sp[361];
	wheel w[5];
	int time,i,j,k;
	ifstream fin;
	ofstream fout;
 
	fin.open("spin.in");
	for(i=0;i<5;i++) {
		fin>>w[i].spd>>j;
		w[i].size=j;
		while(--j>=0)
			fin>>w[i].start[j]>>w[i].len[j];
	}
	fin.close();
 
	fout.open("spin.out");
	for(time=0;time<360;time++) {
		for(i=0;i<360;i++)
			sp[i]=-1;
		for(i=0;i<5;i++) {
			for(j=0;j<w[i].size;j++) {
				for(k=w[i].start[j];k<=w[i].start[j]+w[i].len[j];k++) {
					if(sp[k%360]==i-1)
						sp[k%360]=i;
				}
				w[i].start[j]=(w[i].start[j]+w[i].spd)%360;
			}
		}
		for(i=0;i<360;i++)
			if(sp[i]==4) {
				fout<<time<<endl;
				return 0;
			}
	}
	fout<<"none"<<endl;
	fout.close();
}