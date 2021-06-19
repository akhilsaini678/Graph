#include<bits/stdc++.h>
using namespace std;

void minimumspanningtree(vector<pair<int,int>> graph[],int src,vector<int> &key,vector<bool> &mst,vector<int> &parent)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
	pq.push({0,0});
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		mst[u]=true;

		for(auto it: graph[u])
		{
			int v = it.first;
			int wt = it.second;
			if(mst[v]==false&&wt<key[v])
			{
				parent[v]=u;
				key[v]=wt;
				pq.push({key[v],v});
			}
		}
	}
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<pair<int,int>> graph[vertices+1];
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph[u].push_back({v,weight});
		graph[v].push_back({u,weight});
	}
	vector<int> parent(vertices,-1);
	vector<bool> mst(vertices,false);
	vector<int> key(vertices,1e9);

	key[0]=0;
	minimumspanningtree(graph,0,key,mst,parent);

	for(int i=1;i<vertices;i++)
	{
		count+=key[i];
		cout<<parent[i]<<" - "<<i<<endl;
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