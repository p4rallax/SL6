#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//#include<bits/stdc++.h>

int g[100][100],m,parent[100][100],visited_all,dp[100][100];


int tsp(int mask,int pos)
{

    if(mask==visited_all)
    return g[pos][0];

    if(dp[mask][pos]!=-1)
    return dp[mask][pos];

    int ans=999;


    for(int city=0;city<m;city++)
    {
        if((mask & (1<<city))==0)
        {
            int cur=g[pos][city]+tsp((mask | 1<<city),city);

            if(ans>cur)
            {
                ans=cur;
                parent[pos][mask]=city;
            }

        }
    }

    return dp[mask][pos]=ans;
}


int main()
{
	int i,j;
	printf("\n Enter the number of cities\n");
	scanf("%d",&m);
	visited_all=(1<<m)-1;
	memset(g,0,sizeof(g));
	printf("\n Enter the cost matrix\n");
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			scanf("%d",&g[i][j]);
	
	
	

	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			dp[i][j]=-1;
	

	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			parent[i][j]=-1;

	printf("%d\n ",tsp(1,0));

	int path[10];
	int pc=0,cn=0,cm=1;

	do
	{
		path[pc++]=cn;
		cn=parent[cn][cm];
		cm = cm | (1<<cn);
	}while(cn!= -1);

	for(int i=0;i<m;i++)
		printf("%d\t ",path[i]);
}