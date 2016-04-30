#include <cstdio>
#include <iostream>


using namespace std;



int print(unsigned int m)
{
  for(int i = 0 ; i <= 31 ; i++)
    {
      if( ( (m << i)   & (1 << 31     ) )== 0)
        cout <<0;
      else
        cout <<1;
    }

  return 1;
}


int main()
{
  unsigned int a,b;
  unsigned int c,d;


  cin >>a >> b;
  cin >> c >> d;


  for(int i = a; i <= b ; i++)
    {
      for(int j = c ; j <= d ;j++)
        {
          print(i);
          cout << " ";
          print(j);

          cout<< " ";
          print(i ^ j);
          cout<< " " << (i ^ j)  << endl;
          // cout << print(i) <<  "XOR" <<  print(j)   << "= " << print(i ^ j)  <<  " " <<  (i ^ j) << endl;
        }
    }
}
