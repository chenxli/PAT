#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
struct node
{
  int val;
  struct node* left;
  struct node* right;
};
node* insert(node* root, int value)
{
  if(root == NULL)
  {
    root = (struct node*)malloc(sizeof(struct node));
    root->val = value;
    root->left = root->right = NULL;
  }
  else if(root->val >= value)
    root->left = insert(root->left,value);
  else if(root->val < value)
    root->right = insert(root->right,value);
  return root;
}
int maxDepth = -1;
vector<int> num(1001);
void dfs(node* root,int depth)
{
  if(root == NULL)
  {
    maxDepth = max(maxDepth,depth);
    return;
  }
  num[depth]++;
  dfs(root->left,depth+1);
  dfs(root->right,depth+1);
}
int main()
{
  int n;
  scanf("%d",&n);
  struct node* root = NULL;
  for(int i = 0; i < n; i++)
  {
    int value;
    scanf("%d",&value);
    root = insert(root,value);
  }
  dfs(root,0);
  printf("%d + %d = %d\n",num[maxDepth-1],num[maxDepth-2],num[maxDepth-2]+num[maxDepth-1]);
  return 0;
}
