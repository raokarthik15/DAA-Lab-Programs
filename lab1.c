/*
Digital maps, unlike humans, see cities as a bunch of nodes. We (humans) 
consider this map as a single entity. a GPS navigation or any other digital map 
divides it into hundreds of segments, with some only 24 meters long. A map 
displays n cities and their distances. Design and develop a program in C to print 
all the cities reachable from a given starting city in a digraph by using BFS 
method. Repeat the experiment for different values of n and plot a graph of the 
time taken versus n(n=no of nodes)
0 1 0 0 1 0 0 0 1 0
1 0 1 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 1 1
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
1 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 0 0
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;

void bfs(int a[n][n], int source)
{   
    int front = 0, rear = -1, curr;   //for Q traversal
    int Q[10];
    int visit[10] = {0};        //to keep a track of visited cities
    Q[++rear] = source;         //adding the first city(node) to the Q
    visit[source] = 1;          //visited source
    
    //repeat until the Q is empty 
    while(front<=rear){
        curr = Q[front++];      //removing front element
        for(int i=0;i<n;i++)
            if(a[curr][i]==1 && visit[i]==0){       //checking if the cities curr and i are connected and i is not visited
                Q[++rear] = i;                      //adding city i to the Q
                printf("City %d is reachable from %d\n", i, curr);
                visit[i] = 1;       //visited i
            }
    }

}

int main(int argc, char const *argv[])
{
    int src;
    printf("Enter no. of cities\n");
    scanf("%d",&n);
    if(n>10){
        printf("Out of my scope\n");
        exit(0);
    }
    int AM[n][n];
    printf("Enter elements of adjacency matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&AM[i][j]);

    printf("Enter source city\n");
    scanf("%d",&src);

    double timeTaken;
    clock_t begin = clock();
    bfs(AM, src);
    clock_t end = clock();
    
    timeTaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time taken = %lf", timeTaken);

    return 0;
}
