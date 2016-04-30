#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;



int main()
{
  int T,a,b;

  cin >> T;
  while(T--)
    {
      cin>>a>>b;
      int flag = 0;
      for(int m = 0 ; m <= 6 ; m++)
        {
          for(int n = 0 ; n <= 6 ; n++)
            {
              if(m * (a-2) *180 *b + n *( b - 2 ) *180 *a            ==  360 * a *b)
                {
                  flag = 1;
                  cout << "Yes"<< endl;
                  break;
                }
            }
          if(flag == 1) break;
        }

      if(flag == 0)
        cout << "No" << endl;

    }
}
