#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int s,d,w;
};

void pp(int p[],int s)
{
	
	while(p[s]!=-1)
	{
		cout<<p[s]<<" ";
		s=p[s];
	}	
}

int main()
{
	int m,n,s,flag,x,y,w;
	cin>>m>>n>>s;
	edge e[n];
	int dist[100],parent[100];

	memset(parent,-1,sizeof(parent));

	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>w;
		e[i].s=x,e[i].d=y,e[i].w=w;
		dist[i]=9999;
	}

	dist[s]=0;

	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dist[e[j].s] + e[j].w < dist[e[j].d])
				parent[e[j].d]=e[j].s,
				dist[e[j].d]=dist[e[j].s] + e[j].w;
		}
	}

	for(int j=0;j<n;j++)
	{
		if(dist[e[j].s] + e[j].w < dist[e[j].d])
			flag=1,
			dist[e[j].d]=dist[e[j].s] + e[j].w;
	}
	
	for(int i=0;i<m;i++)
		cout<<dist[i]<<" ";cout<<endl;

	pp(parent,1);

}