//============================================================================
// Name        : Vijos1684
// Author      :
// Version     :
// Copyright   : 2013-10-29
// Description : data structrue
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    long long n = 0;
    long long ret = 0;
    long long temp;
    scanf("%I64d",&n);

    for (int i = 0 ; i < n ; i++)
    {
    	scanf("%I64d",&temp);
    	ret ^= temp;
    }
    printf("%I64d\n",ret);
    return 1;
}