/*
Bangalore Water supply Board responsibility is to distribute water evenly 
among all the areas in Bangalore city. A new layout has been developed by 
Maxworth real estate developers. BWSB should connect the water lines to the 
new layout with minimum cost. The objective is to connect the water pipes so 
that it reaches all the houses in new layout with minimum cost. Write an 
algorithm by applying Kruskal’s method to find the minimum spanning tree for 
the given scenario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct edge{
    int u,v;
    int cost;
};

void Kruskal(struct edge G[],int edges)
{
    struct edge S[edges];
    struct edge temp[edges];

    S[0] = temp[0] = G[0];
    int nodes=1;

    for(int i=1;i<edges;i++){
        temp[nodes] = G[i];
        if(!isCyclic(temp, nodes+1)){
            S[nodes] = temp[nodes];
            nodes++;
        }
    }

    int tcost = 0;
    printf("Minimum spanning tree\n");
    for(int i=0;i<nodes;i++){
        printf("%d -- %d = %d\n",S[i].u,S[i].v,S[i].cost);
        tcost+=S[i].cost;
    }
    printf("Cost = %d",tcost);
}

int compare(const void* p1, const void* p2)
{
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;
    return (*x)[2] - (*y)[2];
}

int main()
{
    struct edge G[20];
    int verts,edges;

    printf("Enter no. of vertices:\n");
    scanf("%d",&verts);
    printf("Enter no. of edges:\n");
    scanf("%d",&edges);

    printf("Enter edge list\nu v cost\n");
    for(int i=0;i<edges;i++)
        scanf("%d%d%d",&G[i].u,&G[i].v,&G[i].cost);

    qsort(G,edges,sizeof(G[0]),compare);
    Kruskal(G,edges);

    return 0;
}