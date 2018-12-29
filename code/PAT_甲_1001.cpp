#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c = a + b;
	bool flag = true;
	if(c<0)
	{
		flag = false;
		c = -1 * c;
	}
	string str;
	int count = 1;
	str = static_cast<char>(c%10+'0');
	c/=10;
	while(c!=0)
	{
		count++;
		str = static_cast<char>(c%10+'0') + str;
	    c /= 10;
		if(count%3==0&&c!=0)
		{
			str = ','+str;
			count=0;
		}
	}
	if(flag)
		cout<<str<<endl;
	else
		cout<<"-"<<str<<endl;
	return 0;
}