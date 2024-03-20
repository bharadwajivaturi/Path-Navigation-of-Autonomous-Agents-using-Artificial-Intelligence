#include <stdio.h>
#include<string.h>
#define MAXN 100
#define INF 999
// Infinite value for array

int V;
int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

char map[20][25]={"Arad", "Bucharest","Craiova","Dobreta","Eforie","Fagaras","Giurgiu",
"Hirsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti",
"Rimnicu Vilcea","Sibiu","Timisoara","Urziceni","Vaslui","Zerind"};
// Initializing the distance and
// Next array
void initialise(int graph[][V])
{
	int i,j;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			dis[i][j] = graph[i][j];

			// No edge between node
			// i and j
			if (graph[i][j] == 999)
				Next[i][j] = -1;
			else
				Next[i][j] = j;
		}
	}
}

// Function construct the shortest
// path between u and v
void constructPath(int u,int v)
{
	// If there's no path between
	// node u and v, simply return
	// an empty array
	if (Next[u][v] == -1)
        printf("No path");
    int i,j;
	// Storing the path in a vector
	int path[30];
	path[0]=u;
	i=1;
	int d=u;
	int a[30];
	
	while (u != v)
	{
		u = Next[u][v];
		path[i]=u;
		a[i-1]=dis[d][u];
		d=u;
		i++;
		
	}
	for(j=0;j<i-1;j++)
	{
	    printf("%s  -> ",map[path[j]]);
	}
	printf("%s\n\n",map[path[j]]);
	for(j=0;j<i-1;j++)
	{
	    printf("%s to %s = %d\n",map[path[j]],map[path[j+1]],a[j]);
	}
	//printf("%s\n",map[path[j]]);
	
}
// Standard Floyd Warshall Algorithm
// with little modification Now if we find
// that dis[i][j] > dis[i][k] + dis[k][j]
// then we modify next[i][j] = next[i][k]
void floydWarshall()
{
	int i,j,k;
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{

				// We cannot travel through
				// edge that doesn't exist
				if (dis[i][k] == 999 || dis[k][j] == 999)
					continue;

				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					Next[i][j] = Next[i][k];
				}
			}
		}
	}
}


int main()
{

	int i,j,n;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    
    printf("Enter adjacency matrix: \n\n");
    int graph[20][20];
    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
	{
    scanf("%d",&n);
    if(n==999) graph[i][j]=999;
    else graph[i][j]=n;
    }

	
	initialise(graph);

	
	floydWarshall();
    char source[25],dest[25];
    printf("Enter source: ");
    scanf("%s",source);
 
    printf("Enter destination: ");
    scanf("%s",dest);
	int s,d;
	for(i=0;i<20;i++){
        if(!strcmp(map[i],source))
		{
        s=i;
        break;
        }
    }

    for(i=0;i<20;i++)
	{
        if(!strcmp(map[i],dest))
		{
        d=i;
        break;
    }
    }
	
	printf("Shortest path from %s to %s: ",source,dest);
	constructPath(s, d);
	printf("Shortest Distance from %s to %s = %d",source,dest,dis[s][d]);
	return 0;
}
