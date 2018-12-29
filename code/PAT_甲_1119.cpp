#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
struct node
{
  int val;
  struct node *left,*right;
};
int isUnique = 1;
struct node* build(vector<int> pre,vector<int> post,int a,int b,int c,int d)
{
  if(a > b) return NULL;
  struct node *root = (struct node*)malloc(sizeof(struct node));
  root->val = pre[a];
  if(a == b)//很关键的判断
  {
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  int temp = pre[a+1];// 前面的判断确保这个访问是安全的
  int pos = c;
  while(post[pos] != temp)
  {
    pos++;
  }
  if(pos+1 == d)
    isUnique = 0;
  root->left = build(pre,post,a+1,a+pos-c+1,c,pos);
  root->right = build(pre,post,a+pos-c+2,b,pos+1,d-1);
  return root;
}
vector<int> in;
void inorder(struct node* root)
{
  if(root)
  {
    inorder(root->left);
    in.push_back(root->val);
    inorder(root->right);
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> pre,post;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d",&val);
    pre.push_back(val);
  }
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d",&val);
    post.push_back(val);
  }
  struct node *root = build(pre,post,0,n-1,0,n-1);
  inorder(root);
  if(isUnique)
    printf("Yes\n");
  else
    printf("No\n");
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    if(cnt == 0)
    {
      printf("%d",in[i]);
      cnt++;
    }
    else
      printf(" %d",in[i]);
  }
  printf("\n");
  return 0;
}
