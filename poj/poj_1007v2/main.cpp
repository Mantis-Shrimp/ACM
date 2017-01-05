#include<iostream>
#include<string>
using namespace std;

int number;
int length;

typedef struct node
{
	string dnssequeue_v;
	int weight_v;
	struct node *next;
} *slink,node;

class dnadata
{
private:
	slink Head_v;
public:
	dnadata();
	~dnadata();
	int insert_f(string dnasequeue_p);
	int realse_f();
	int output_f();
private:
	int weight_f(string dnasequeue_p);
};

dnadata::dnadata()
{
	Head_v = new node();
	Head_v->next = NULL;
	Head_v->weight_v = -1;
}

int dnadata::insert_f(string dnasequeue_p)
{
	slink pb = new node();
	pb->weight_v = weight_f(dnasequeue_p);
	pb->dnssequeue_v = dnasequeue_p;
	pb->next = NULL;
	
	slink pa = Head_v;
	
	while(pa->next!=NULL&&pb->weight_v>=pa->next->weight_v)
	{
		pa = pa->next;
	}
	
	pb->next = pa->next;
	pa->next = pb;
	
	return 1;
}

int dnadata::weight_f(string dnasequeue_p)
{
	int weight_v = 0 ;
	for(int i = 0 ; i<=length-1;i++)
	{
		for(int j = i+1;j<=length-1;j++)
		{
			if(dnasequeue_p[i]>dnasequeue_p[j])
			{
				weight_v++;
			}
		}
	}
	return weight_v ;
}

int dnadata::output_f()
{
	slink pa = Head_v->next;
	while(pa)
	{
		cout<<pa->dnssequeue_v<<endl;
		pa = pa->next;
	}
}

dnadata::~dnadata()
{
	slink pa = Head_v;
	slink pb = NULL;

	while(pa->next)
	{
		pb =pa;
		pa = pa->next;
		delete pb;
	}
	delete pa;
}



int main()
{
	cin>>length>>number;
	dnadata dna;
	string sequeue;
	while(number--)
	{
		cin>>sequeue;
		dna.insert_f(sequeue);
	}
	dna.output_f();
}
