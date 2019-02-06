#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct term
{
	int source, destination, weight;
};
typedef struct term edge;

struct Graph
{
	int V, E;
	edge list[25];
};

void FinalSolution(int dist[], int n, int path[25])
{
	int i,x,st[10],sp;
	printf("\nVertex\tDistance Path from vertex 1\n");
	
	for(i=2; i<=n; ++i)
	{
		printf("%d\t %d\t", i, dist[i]);
		x=i;st[0] = x;sp=0;
		while(1)
		{
			sp++;
 			st[sp] = path[x];
			x=path[x];
			if (x==1) break;
		}
		while(sp!=-1)
		{
			printf("%d",st[sp]);
			if(sp!=0) printf("-->");
			sp--;
		}
		printf("\n");
	}
}


void BellmanFord(struct Graph graph, int source)
{
	int V = graph.V;
	int E = graph.E;
	int path[25],StoreDistance[25];
	int i,j,flag,u,v,weight;
	
	for(i=1;i<=V;i++)
	{
		StoreDistance[i] = INT_MAX;
		path[i] = -1;
	}
	StoreDistance[source] = 0;
	
	for(i=1;i<=V-1;i++)
	{
		flag = 0;
		for(j=1;j<=E;j++)
		{
			u = graph.list[j].source;
			
			v = graph.list[j].destination;
			
			weight = graph.list[j].weight;
			
			if(StoreDistance[u] + weight < StoreDistance[v])
			{
				StoreDistance[v] = StoreDistance[u] + weight;
				path[v] = u;
				flag++;
			}
		}
		if(flag==0) break;
	}
	for(i=1;i<=E;i++)
	{
		u = graph.list[i].source;
		v = graph.list[i].destination;
		weight = graph.list[i].weight;
		if(StoreDistance[u] + weight < StoreDistance[v])
			printf("This graph contains negative edge cycle\n");
	}
	FinalSolution(StoreDistance, V, path);
	return ;
}

int main()
{
	int i,V,E,S;
	struct Graph graph;
	printf("\nEnter number of vertices in graph\n");
	scanf("%d",&V);
	printf("\nEnter number of edges in graph\n");
	scanf("%d",&E);
	printf("\nEnter your source vertex number\n");
	scanf("%d",&S);
	
	graph.V=V;
	graph.E=E;
	
	for(i=1;i<=E;i++)
	{
		printf("\nEnter edge %d properties Source, destination, weight respectively\n",i);
		scanf("%d",&graph.list[i].source);
		scanf("%d",&graph.list[i].destination);
		scanf("%d",&graph.list[i].weight);
	}
	printf("Graph information \n no of vertices = %d no of edges = %d\n",graph.V,graph.E);
	printf("Edge information\n");
	for(i=1;i<=E;i++)
		printf("\t%d\t%d\t%d\n",graph.list[i].source,graph.list[i].destination,graph.list[i].weight);
	BellmanFord(graph,S);
	return 0;
}
