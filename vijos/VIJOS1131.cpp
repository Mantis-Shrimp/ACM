//============================================================================
// Name        : Vijos1131
// Author      :
// Version     :
// Copyright   : 2013-11-5
// Description : number theory 
//============================================================================

#include <iostream>

int t = 0;
long x0, y0;

int gcd(int p, int q)
{
	if(q==0) return p;
	else return gcd(q, p % q);
}
int main()
{
    std::cin >> x0 >> y0;
    for (int i = x0; i <= y0; i++)
    {
        int j = x0 * y0 / i;
        int tmp = gcd(i, j);
        if (tmp == x0 && y0 == (i * j / tmp))
            ++t;
    }
    std::cout << t << std::endl;
}