#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
  char data[15];
  int lchild,rchild;
};
struct node tree[21];
int ischild[21];
void inorder(int root,int depth)
{
  if(root == -1) return;
  else if(tree[root].lchild == -1 && tree[root].rchild == -1)
    printf("%s",tree[root].data);
  else
  {
    if(depth > 1) printf("(");
    inorder(tree[root].lchild,depth+1);
    printf("%s",tree[root].data);
    inorder(tree[root].rchild,depth+1);
    if(depth > 1) printf(")");
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%s %d %d",tree[i].data,&tree[i].lchild,&tree[i].rchild);
    ischild[tree[i].lchild] = 1;
    ischild[tree[i].rchild] = 1;
  }
  int root = -1;
  for(int i = 1; i <= n; i++)
  {
    if(!ischild[i])
    {
      root = i;
      break;
    }
  }
  inorder(root,1);
  return 0;
}
