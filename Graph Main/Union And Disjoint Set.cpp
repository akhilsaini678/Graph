#include<bits/stdc++.h>
using namespace std;

vector<int> parent(100000);
vector<int> ranked(100000);

int find_parent(int u)
{
	if(parent[u]==u)
		return u;

	return parent[u]=find_parent(parent[u]);
}

void union_(int u,int v)
{
	int x=find_parent(u);
	int y=find_parent(v);

	if(ranked[x]>ranked[y])
		parent[y]=x;
	else if (ranked[x]<ranked[y])
		parent[x]=y;
	else
	{
		parent[x]=y;
		ranked[y]++;
	}
}




void solve()
{
	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	for(int i=0;i<vertices;i++)
		parent[i]=i,ranked[i]=0;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		union_(u,v);
	}
	if(find_parent(5)!=find_parent(4))
	{
		cout<<"They belong to different components."<<endl;
	}
	else
	{
		cout<<"They belong to same components."<<endl;
	}
}

void fast()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("D:\\Online\\Coding\\Contest\\input.txt","r",stdin);
	freopen("D:\\Online\\Coding\\Contest\\output.txt","w",stdout);
	#endif
}

int main()
{
	fast();
	int t=1;
	cin>>t;
	while(t--) solve();
	return 0;
}