#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node
{
  int val;
  struct node* left;
  struct node* right;
};

node* root = NULL;
vector<int> vec;
void createBST(node* &root,vector<int> &pre,vector<int> &mid,int pl,int pr,int ml,int mr)
{
  if(pr < pl || mr < ml) return;
  int pos = ml;
  while(mid[pos] != pre[pl])
  {
    pos++;
  }
  root = new node;
  root->val = pre[pl];
  root->left = NULL;
  root->right = NULL;
  createBST(root->left,pre,mid,pl+1,pl+pos-ml,ml,pos-1);
  createBST(root->right,pre,mid,pl+pos-ml+1,pr,pos+1,mr);
}
/*
 一开始的建树方法,一个节点一个节点地插到树上,有两个测试点超时
 void createBST(node* &root,int val)
 {
    if(root == NULL)
    {
       root = new node;
      root->val = val;
      root->left = NULL;
      root->right = NULL;
  }
  else
  {
  if(val > root->val)
    createBST(root->right,val);
  else
    createBST(root->left,val);
}
}
*/
node* findLCA(node* root,int u,int v)
{
  if((u >= root->val && v <= root->val) || (u <= root->val && v >= root->val))
    return root;
  else
  {
    if(u < root->val && v < root->val)
      return findLCA(root->left,u,v);
    else  if(u > root->val && v > root->val)
      return findLCA(root->right,u,v);
  }
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  unordered_map<int,bool> map;
  vector<int> mid;
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d",&val);
    vec.push_back(val);
    map[val] = true;
  }
  mid = vec;
  sort(mid.begin(),mid.end());
  createBST(root,vec,mid,0,m-1,0,m-1);
  for(int i = 0; i < n; i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    if(!map[u] && !map[v])
      printf("ERROR: %d and %d are not found.\n",u,v);
    else if(!map[u])
      printf("ERROR: %d is not found.\n",u);
    else if(!map[v])
      printf("ERROR: %d is not found.\n",v);
    else
    {
      node* res = findLCA(root,u,v);
      if(res->val == u)
      {
        printf("%d is an ancestor of %d.\n",u,v);
      }
      else if(res->val == v)
      {
        printf("%d is an ancestor of %d.\n",v,u);
      }
      else
      {
        printf("LCA of %d and %d is %d.\n",u,v,res->val);
      }
    }
  }
  return 0;
}
