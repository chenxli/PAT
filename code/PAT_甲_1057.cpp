#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrtN = 316;
stack<int> st;
int block[sqrtN];
int table[maxn];
//分块查找
void peekMedian(int k)
{
  int sum = 0;
  int idx = 0;
  while(sum + block[idx] < k)//确定元素所在块
  {
    sum += block[idx++];
  }
  int num = idx * sqrtN;//该块的一个元素
  while(sum + table[num] < k)
  {
    sum += table[num++];
  }
  printf("%d\n",num);
}
void Push(int x)
{
  st.push(x);
  block[x/sqrtN]++;
  table[x]++;
}
void Pop()
{
  int x = st.top();
  st.pop();
  block[x/sqrtN]--;
  table[x]--;
  printf("%d\n",x);
}
int main()
{
  int x,query;
  memset(block,0,sizeof(block));
  memset(table,0,sizeof(table));
  scanf("%d",&query);
  char cmd[20];
  for(int i = 0; i < query; i++)
  {
    scanf("%s",cmd);
    if(strcmp(cmd,"Pop") == 0)
    {
      if(st.empty())
        printf("Invalid\n");
      else
        Pop();
    }
    else if(strcmp(cmd,"Push") == 0)
    {
      scanf("%d",&x);
      Push(x);
    }
    else
    {
      if(st.empty())
        printf("Invalid\n");
      else
      {
        int K = st.size();
        if(K % 2 == 0)
          K = K / 2;
        else
         K = (K+1) / 2;
        peekMedian(K);
      }
    }
  }
  return 0;
}
