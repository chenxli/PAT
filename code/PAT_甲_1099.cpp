#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct node
{
  int val = 0;
  int left = -1;
  int right = -1;
};
vector<int> vec;
vector<node> v;
int getNode(int root)
{
  queue<int> q;
  int count = 0;
  if(v[root].left != -1)
  {
    q.push(v[root].left);
    count++;
  }
  while(!q.empty())
  {
    int temp = q.front();
    if(v[temp].left != -1)
    {
      q.push(v[temp].left);
      count++;
    }
    if(v[temp].right != -1)
    {
      q.push(v[temp].right);
      count++;
    }
    q.pop();
  }
  return count;
}
void createBST(int root,int low,int high)
{
  if(low > high) return;
  int count = getNode(root);
  v[root].val = vec[count+low];
  if(v[root].left != -1)
  {
    createBST(v[root].left,low,low+count-1);
  }
  if(v[root].right != -1)
  {
    createBST(v[root].right,count+low+1,high);
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> isChild(100,0);
  for(int i = 0; i < n; i++)
  {
    int l,r;
    scanf("%d %d",&l,&r);
    node temp;
    if(l != -1)
    {
      temp.left = l;
      isChild[l] = 1;
    }
    if(r != -1)
    {
      temp.right = r;
      isChild[r] = 1;
    }
    v.push_back(temp);
  }
  int root = -1;
  for(int i = 0; i < n; i++)
  {
    if(isChild[i] == 0)
    {
      root = i;
      break;
    }
  }
  for(int i = 0; i < n; i++)
  {
    int num;
    scanf("%d",&num);
    vec.push_back(num);
  }
  sort(vec.begin(),vec.end());
  createBST(root,0,vec.size()-1);
  //层次遍历
  vector<int> order;
  queue<int> q;
  q.push(root);
  while(!q.empty())
  {
    int temp = q.front();
    order.push_back(v[temp].val);
    if(v[temp].left != -1)
      q.push(v[temp].left);
    if(v[temp].right != -1)
      q.push(v[temp].right);
    q.pop();
  }
  for(int i = 0; i < order.size(); i++)
  {
    printf("%d",order[i]);
    if(i < order.size() - 1)
      printf(" ");
  }
  return 0;
}
