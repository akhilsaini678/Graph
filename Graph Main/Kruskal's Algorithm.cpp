#include<bits/stdc++.h>
using namespace std;

vector<int> parent(100000);
vector<int> ranked(100000);


struct node{
	int wt;
	int u;
	int v;
	node(int first,int second,int third)
	{
		wt=first;
		u=second;
		v=third;
	}
};


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

bool cmp(node a, node b)
{
	return a.wt<b.wt;
}


void solve()
{
	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<node> graph;
	vector<pair<int,int>> mst;
	for(int i=0;i<vertices;i++)
		parent[i]=i,ranked[i]=0;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph.push_back({weight,u,v});
	}

	sort(graph.begin(),graph.end(),cmp);

	for(int i=0;i<edge;i++)
	{
		if(find_parent(graph[i].u)!=find_parent(graph[i].v))
		{
			union_(graph[i].u,graph[i].v);
			mst.push_back({graph[i].u,graph[i].v});
			count+=graph[i].wt;
		}
	}

	for(int i=0;i<mst.size();i++)
	{
		cout<<mst[i].first<<" -> "<<mst[i].second<<endl;
	}
	cout<<count<<endl;
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