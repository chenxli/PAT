#include <cstdio>
#include <cstdlib>
using namespace std;
#define maxn 0x7fffffff
struct Node_Type
{
  int dis;
  int bsend;
  int bback;
  int path[508];
}res,cur;
int c,n,s,m,cnt = 0;
int bk[508],rel[508][508],vst[508];
void dfs(int p)
{
  int i,j;
  if(p == s)
  {
    if(cur.dis < res.dis)
      res = cur;
    else if(cur.dis == res.dis)
    {
      if(cur.bsend < res.bsend)
        res = cur;
      else if(cur.bsend == res.bsend && cur.bback < res.bback)
        res = cur;
    }
    return;
  }
  for(i = 1; i <= n; i++)
  {
    if(vst[i] == 0 && rel[p][i] != -1)
    {
      vst[i] = 1;
      int distmp = cur.dis;
      int bsendtmp = cur.bsend;
      int bbacktmp = cur.bback;
      cur.dis += rel[p][i];
      int tmp = bk[i] - c / 2;
      if(tmp >= 0)
       cur.bback += tmp;
      else
      {
        tmp = -tmp;
        if(tmp <= cur.bback)
            cur.bback -= tmp;
        else
        {
          cur.bsend += (tmp - cur.bback);
          cur.bback = 0;
        }
      }
      cnt++;
      cur.path[cnt] = i;
      dfs(i);
      cnt--;
      cur.dis = distmp;
      cur.bsend = bsendtmp;
      cur.bback = bbacktmp;
      vst[i] = 0;
    }
  }
}

int main()
{
  int i,j;
  int si,sj,tij;
  scanf("%d %d %d %d",&c,&n,&s,&m);
  for(i = 1; i <= n; i++)
  scanf("%d",&bk[i]);
  for(i = 0; i <= n; i++)
  {
    vst[i] = 0;
    for(j = 0; j <= n; j++)
      rel[i][j] = -1;
  }
  for(i = 1; i <= m ;i++)
  {
    scanf("%d %d %d",&si,&sj,&tij);
    rel[si][sj] = tij;
    rel[sj][si] = tij;
  }
  cur.dis = 0;
  cur.bsend = 0;
  cur.bback = 0;
  res.dis = maxn;
  res.bsend = maxn;
  res.bback = maxn;
  dfs(0);
  printf("%d 0",res.bsend);
  for(i = 1; res.path[i] != s; i++)
    printf("->%d",res.path[i]);
  printf("->%d",s);
  printf(" %d\n",res.bback);
  return 0;
}
