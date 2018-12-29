#include<cstdio>
#include<map>
#include<vector>
using namespace std;

const int N=101;
map<int,vector<int> > adjlist;
int levelLeaves[N] = {0};

void dfs(int node,int level)
{
  if(adjlist[node].empty())
  {
    levelLeaves[level]++;
    return;
  }
  vector<int>::iterator iter=adjlist[node].begin();
  for(;iter!=adjlist[node].end();iter++)
    dfs(*iter,level+1);
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int leavs = n-m;
  while(m--)
  {
    int non_leaf_id,child_num;
    scanf("%d%d",&non_leaf_id,&child_num);
    for(int i=0;i<child_num;i++)
    {
      int child_id;
      scanf("%d",&child_id);
      adjlist[non_leaf_id].push_back(child_id);
    }
  }
  dfs(1,0);
  int cnt=levelLeaves[0];
  printf("%d",levelLeaves[0]);
  for(int i=1;cnt<leavs;i++)
  {
    printf(" %d",levelLeaves[i]);
    cnt+=levelLeaves[i];
  }
  return 0;
}
