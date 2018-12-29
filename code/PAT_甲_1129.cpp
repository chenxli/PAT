#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
struct item
{
  int id;
  int frequency;
  item(int id,int frequency):id(id),frequency(frequency){}
  friend bool operator<(item a,item b)
  {
    if(b.frequency != a.frequency)
      return a.frequency > b.frequency;
    else
      return a.id < b.id;
  }
  // bool operator<(const item &a)const
  // {
  //     if(frequency != a.frequency)
  //       return frequency > a.frequency;
  //     else
  //       return id < a.id;
  // }
};
int fre[50001];
set<item> ss;
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < n; i++)
  {
    int indice;
    scanf("%d",&indice);
    set<item>::iterator it = ss.begin();
    int count = 0;
    for(; it != ss.end(); it++)
    {
      if(count == 0)
        printf("%d:",indice);
      printf(" %d",it->id);
      count++;
      if(count >= m) break;
    }
    if(count)
      printf("\n");
    it = ss.find(item(indice,fre[indice]));
    if(it != ss.end())
      ss.erase(it);
    fre[indice]++;
    ss.insert(item(indice,fre[indice]));
  }
  return 0;
}
