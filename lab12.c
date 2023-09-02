/*
DigiMap services is a module in G-Maps which is used to find the distance from 
one place to another or from your location to the nearest desired location. This 
requires the Shortest Path Algorithm, as there are various routes/paths 
connecting them but it has to show the minimum distance. . Represent a 
city/place with a vertex and the route between two cities/places as an edge, 
then by using Dijkstra’s algorithm, find the shortest routes between any two 
cities/places or from one city/place to another city/place.
*/

#include<stdio.h>
#include<stdlib.h>

int n;
int visited[20] = {0};
int distance[20];

void Dijsktra(int A[n][n], int src)
{   
    if(src==-1) return;
    visited[src] = 1;

    for(int i=0;i<n;i++)
        if(distance[i]>distance[src]+A[src][i])
            distance[i] = distance[src]+A[src][i];
    
    int min = 9999, next=-1;
    for(int i=0; i<n; i++)
        if(distance[i] < min && !visited[i]){
            next = i;
            min = distance[i];
        }
        
    Dijsktra(A,next);
}

int main()
{   
    int source;
    printf("Enter number of nodes(<20):\n");
    scanf("%d",&n);
    
    int AM[n][n];
    printf("Enter cost matrix (-1 if no connection):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&AM[i][j]);
            AM[i][j] == -1 ? AM[i][j] = 9999 : AM[i][j];
        }
    
    printf("Enter source: ");
    scanf("%d",&source);

    for(int i=0;i<n;i++) 
        distance[i]=9999;
    
    distance[source]=0;
    Dijsktra(AM,source);

    printf("Minimum distance from source:\n");
    for(int i=0;i<n;i++)
        printf("%d to %d = %d\n",source,i,distance[i]);

    return 0;
}

/*
Nodes = 9 -> 0 1 2 3 4 5 6 7 8

-1 4 -1 -1 -1 -1 -1 8 -1
4 -1 8 -1 -1 -1 -1 11 -1
-1 8 -1 7 -1 4 -1 -1 2
-1 -1 7 -1 9 14 -1 -1 -1
-1 -1 -1 9 -1 10 -1 -1 -1
-1 -1 4 14 10 -1 2 -1 -1
-1 -1 -1 -1 -1 2 -1 1 6
8 11 -1 -1 -1 -1 1 -1 7
-1 -1 2 -1 -1 -1 6 7 -1
*/