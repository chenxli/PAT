#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<int,int> pos;
vector<int> in,pre;
void lca(int inl,int inr,int preRoot,int a,int b)
{
	if(inl > inr) return;
	int inRoot = pos[pre[preRoot]];
	int aIn = pos[a];
	int bIn = pos[b];
	if(aIn == inRoot || bIn == inRoot) 
		printf("%d is an ancestor of %d.\n",aIn == inRoot ? a : b, aIn == inRoot ? b : a);
	else if(aIn < inRoot && bIn > inRoot) 
		printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
	else if(aIn > inRoot && bIn < inRoot) 
		printf("LCA of %d and %d is %d.\n",a,b,in[inRoot]);
	else if(aIn < inRoot && bIn < inRoot)
		lca(inl,inRoot-1,preRoot+1,a,b);
	else if(aIn > inRoot && bIn > inRoot)
		lca(inRoot+1,inr,preRoot+inRoot-inl+1,a,b);
}
int main()
{
	int m,n,a,b;
	scanf("%d %d",&m,&n);
	in.resize(n+1);
	pre.resize(n+1);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&in[i]);
		pos[in[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d",&pre[i]);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&a,&b);
		if(pos[a] == 0 && pos[b] == 0)
			printf("ERROR: %d and %d are not found.\n",a,b);
		else if(pos[a] == 0 || pos[b] == 0)
			printf("ERROR: %d is not found.\n",pos[a] == 0 ? a : b);
		else lca(1,n,1,a,b);
	}
	return 0;
}