#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
bool isPalindromic()
{
    int size = v.size();
    for(int i =  0; i < size / 2; i++)
    {
        if(v[i] != v[v.size() - i - 1])
         return false;
    }
    return true;
}
void func(int n,int b)
{
    if(n == 0)
     v.push_back(0);
    while(n != 0)
    {
        v.push_back(n % b);
        n /= b;
    }
}
int main()
{
    int n, b;
    cin>>n>>b;
    func(n,b);
    if(isPalindromic())
     cout<<"Yes"<<endl;
    else 
     cout<<"No"<<endl;
    int size = v.size();
    for(int i = size - 1; i > 0; i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<v[0];
    return 0;
}