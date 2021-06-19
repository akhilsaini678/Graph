#include<bits/stdc++.h>
using namespace std;

bool bipartite(vector<int> graph[],int src,vector<int> &color)
{
	if(color[src]==-1) color[src]=1;
	for(auto it: graph[src])
	{
		if(color[it]==-1)
		{
			color[it]=1-color[src];
			if(!bipartite(graph,it,color)) return false;
		}
		else if(color[src]==color[it])
		{
			return false;
		}
	}
	return true;
}

void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<int> graph[vertices+1];
	bool sign=true;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> color(vertices+1,-1);

	for(int i=0;i<vertices;i++)
	{
		if(color[i]==-1)
			if(!bipartite(graph,i,color))
			{
				sign=false;
				break;
			}
	}
	if(sign)
		cout<<"It is a bipartite graph."<<endl;
	else
		cout<<"It is not a bipartite graph."<<endl;
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