#include<bits/stdc++.h>
using namespace std;


struct node {
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


void solve()
{

	int vertices,edge,u,v,weight,count=0;
	cin>>vertices>>edge;
	vector<node> graph;
	bool sign=false;
	for(int i=0;i<edge;i++)
	{
		cin>>u>>v>>weight;
		graph.push_back({weight,u,v});
	}

	vector<int> distance(vertices,1e9);

	distance[0]=0;
	for(int i=0;i<vertices-1;i++)
	{
		for(auto it : graph)
		{
			if(distance[it.u]+it.wt<distance[it.v])
			{
				distance[it.v]=+it.wt+distance[it.u];	
			}
		}
	}

	for (auto it : graph)
	{
		if(distance[it.u]+it.wt<distance[it.v])
		{
			sign=true;	
		}
	}

	for(int i=0;i<vertices;i++)
	{
		cout<<distance[i]<<" ";
	}
	if(sign==true)
		cout<<"There is a negative edge cycle."<<endl;
	else
		cout<<"There is no negative edge cycle."<<endl;
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