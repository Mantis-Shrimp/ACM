/*
PROG:   prefix
ID  :   15864532
LANG:   C++
*/
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
using namespace std ;
#define SET(arr, what)  memset(arr, what, sizeof(arr))
#define FF(i, s, e)     for(int i=s; i<e; i++)
#define SD(a)           scanf("%d", &a)
#define SSD(a, b)       scanf("%d%d", &a, &b)
#define SF(a)           scanf("%lf", &a)
#define SS(a)           scanf("%s", a)
#define SLD(a)          scanf("%lld", &a)
#define PF(a)           printf("%d\n", a)
#define PPF(a, b)       printf("%d %d\n", a, b)
#define SZ(arr)         (int)a.size()
#define SWAP(a,b)       a=a xor b;b= a xor b;a=a xor b;
#define read            freopen("prefix.in", "r", stdin)
#define write           freopen("prefix.out", "w", stdout)
#define MAX             1<<30
#define ESP             1e-5
#define lson            l, m, rt<<1
#define rson            m+1, r, rt<<1|1
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline void AMin(T &a,T b){if(a>b)a=b;}
template<class T> inline void AMax(T &a,T b){if(a<b)a=b;}
template<class T> inline T Min(T a,T b){return a>b?b:a;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
 
struct Trie_Node
{
    bool IsEnd;
    Trie_Node *branch[26];
    Trie_Node(): IsEnd( false )
    {
        memset( branch, 0, sizeof(branch) );
    }// Init
};
 
class Trie
{    
    public:
        Trie();
        void Trie_Insert( char tt[] );
        void Trie_Find( long j );
 
    private:
        Trie_Node *root;
}t; // type class "Trie" object t
 
long slen;
bool prefix[200400];
char line[204], ss[200400];
 
Trie::Trie()
{
    root = new Trie_Node();
}// Trie
 
void Trie::Trie_Insert( char tt[] )
{
    Trie_Node *ptr = root;
    int tlen = strlen( tt );
    for ( int i=0; i<tlen; ++i )
    {
        if ( ptr->branch[ tt[i]-'A' ]==NULL )
        {
            Trie_Node *tmp = new Trie_Node();
            ptr->branch[ tt[i]-'A' ] = tmp;
        }
 
        ptr = ptr->branch[ tt[i]-'A' ];
    }
 
    ptr->IsEnd = true;
}// Trie_Insert
 
void ReadData()
{    
    while ( gets( line ) )
    {
        if ( line[0]=='.' ) break;
 
        char *tok = strtok( line, " " );
        while ( tok )
        {
            t.Trie_Insert( tok );
            //printf("%s\n", tok);
            tok = strtok( NULL, " " );
        }// Insert
    }
 
    char str[204];
    while ( gets( str ) )
    {
        strcat( ss, str );
    }
 
    slen = strlen( ss );
 
    return ;
}// ReadData
 
void Trie::Trie_Find( long j )
{
    Trie_Node *ptr = root;
    for ( ; ; ++j )
    {
        ptr = ptr->branch[ ss[j]-'A' ];
        if ( ss[j]=='\0' || ptr==NULL )
            return ;
        if ( ptr->IsEnd )
			prefix[ j+1 ]=true;
    }
 
    return ;
}// Trie_Find
 
void Solve()
{
    prefix[0] = true;
    for ( long i=0; i<slen; ++i )
    {
        if ( !prefix[i] )   continue;
 
		t.Trie_Find( i );
    }// Searching
 
	int result;
	for ( result=slen; !prefix[result]; --result );
    printf("%d\n", result);
 
    return ;
}// Solve
 
int main()
{
    write;
    read;
    ReadData();
    Solve();
 
    return 0;
}