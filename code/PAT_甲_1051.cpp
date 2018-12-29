#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
  int M,N;
  cin>>M>>N;
  int t;
  cin>>t;
  while(t--)
  {
    stack<int> sta;
    sta.push(0);
    vector<int> v(N,0);
    for(int i = 0; i < N; i++)
    {
      cin>>v[i];
    }
    int idx = 0;
    int num = 1;
    bool flag = true;
    while(idx < N)
    {
      while(sta.top() < v[idx] && sta.size() < M + 1)
      {
        sta.push(num++);
      }
      if(sta.top() == v[idx])
      {
        sta.pop();
        idx++;
      }
      else
      {
        flag = false;
        break;
      }
    }
    if(flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
