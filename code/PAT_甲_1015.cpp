#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
  if(n==1) return false;
  for(int i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
    return false;
  }
  return true;
}
int reverse(int n,int d)
{
   int res=0;
   while(n!=0)
   {
   	int tmp=n%d;
   	res=res*d+tmp;
   	n/=d;
   }
   //cout<<res;
   return res;
}

int main()
{
  int num;
  scanf("%d",&num);
  while(num>=0)
  {
    int d;
    scanf("%d",&d);
    if(isPrime(reverse(num,d))&&isPrime(num))
     printf("Yes\n");
    else
     printf("No\n");
    cin>>num;
  }
  return 0;
}
