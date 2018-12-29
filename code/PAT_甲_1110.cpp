#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct node
{
  int left = -1;
  int right = -1;
};
int main()
{
  int n;
  scanf("%d",&n);
  vector<struct node> v;
  int isChild[20] = {0};
  for(int i = 0; i < n; i++)
  {
    //getchar();
    char left[3],right[3];
    struct node temp;
    scanf("%s %s",left,right);
    if(left[0] != '-')
    {
      int tmp = static_cast<int>(left[0]-'0');
      if(left[1] != '\0')
        tmp = tmp * 10 + static_cast<int>(left[1]-'0');
      temp.left = tmp;
      isChild[temp.left] = 1;
    }
    if(right[0] != '-')
    {
      int tmp = static_cast<int>(right[0]-'0');
      if(right[1] != '\0')
        tmp = tmp * 10 + static_cast<int>(right[1]-'0');
      temp.right = tmp;
      isChild[temp.right] = 1;
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
  queue<int> q;
  vector<int> tree;
  q.push(root);
  //层次遍历，如果在最后一层前出现空节点就不是完全二叉树
  while(!q.empty())
  {
    int temp = q.front();
    tree.push_back(temp);//访问该节点
    if(temp != -1 && v[temp].left == -1)
      q.push(-1);
    else if(temp != -1 && v[temp].left != -1)
      q.push(v[temp].left);
    if(temp != -1 && v[temp].right == -1)
      q.push(-1);
    else if(temp != -1 && v[temp].right != -1)
      q.push(v[temp].right);
  //  printf("%d\n",q.front());
    q.pop();
  }
  bool flag = true;
  bool flg = true;
  int index = -1;
  for(int i = 0; i < tree.size(); i++)
  {
    if(tree[i] == -1)
    {
      flag = false;
      if(index == -1)
        index = i;
    }
    else if(tree[i] != -1 && !flag)
    {
      flg = false;
      break;
    }
  }
  if(flg)
    printf("YES %d\n",tree[index-1]);
  else
    printf("NO %d\n",root);
  return 0;
}
