#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];
int main()
{
  int n, ans = 0;
  scanf("%d",&n);
  int left = n - 1, num;
  for(int i = 0; i < n; i++)
  {
    scanf("%d",&num);
    pos[num] = i;
    if(num == i && num != 0)
      left--;
  }
  int k = 1;//保存除0外不在本位的最小数
  while(left)
  {
    if(pos[0] == 0)
    {
      while(k < n)
      {
        if(pos[k] != k)
        {
          swap(pos[0],pos[k]);
          ans++;
          break;
        }
        k++;
      }
    }
    while(pos[0] != 0)
    {
      int temp = pos[0];
      swap(pos[0],pos[temp]);
      ans++;
      left--;
    }
  }
  printf("%d\n",ans);
  return 0;
}
