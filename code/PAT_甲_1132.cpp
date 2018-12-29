#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int num;
    cin>>num;
    string tmp;
    int temp = num;
    while(temp != 0)
    {
      tmp = tmp + static_cast<char>(temp % 10 + '0');
      temp /= 10;
    }
    int len = tmp.length();
    int divide = pow(10,len/2);
    int num1 = num / divide;
    int num2 = num % divide;
    if(num1 != 0 && num2 != 0 && num % (num1 * num2) == 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
