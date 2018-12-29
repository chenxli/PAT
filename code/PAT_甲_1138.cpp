#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
struct node
{
  int val;
  node* left;
  node* right;
};
vector<int> post;
node* createTree(vector<int> &pre,vector<int> &in,int pl,int pr,int il,int ir)
{
  if(pl > pr) return NULL;
  node* root = (node*)malloc(sizeof(node));
  root->val = pre[pl];
  root->left = NULL;
  root->right = NULL;
  int pos = il;
  while(in[pos] != pre[pl])
  {
    pos++;
  }
  root->left = createTree(pre,in,pl+1,pl+pos-il,il,pos-1);
  root->right = createTree(pre,in,pl+pos-il+1,pr,pos+1,ir);
  return root;
}
void postorder(node* root)
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->val);
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> pre,in;
  for(int i = 0; i < n ; i++)
  {
    int num;
    scanf("%d",&num);
    pre.push_back(num);
  }
  for(int i = 0; i < n; i++)
  {
    int num;
    scanf("%d",&num);
    in.push_back(num);
  }
  node* root = createTree(pre,in,0,n-1,0,n-1);
  postorder(root);
  printf("%d\n",post[0]);
  return 0;
}
