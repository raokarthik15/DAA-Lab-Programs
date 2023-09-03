
/*
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water. Given an m x n 2D binary grid which represents a map 
of '1's (land) and '0's (water), return the number of islands using DFS algorithm. 
Design and develop a program in C to print all the lands reachable from a given 
starting land in a digraph by using DFS method. Repeat the experiment for 
different values of n and plot a graph of the time taken versus n(n=no of nodes)
*/

/*
void read_matrix(int** M)
{
    printf("Enter adjacency matrix\n");
    M=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        M[i] = (int)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            scanf("%d",&M[i][j]);
    }
}
*/


// int countIslands(int M[n][n])
// {   
//     int islands=0;
    
//     //Checking inner elements
//     for(int i=1;i<n-1;i++)
//         for(int j=1;j<n-1;j++)
//             if(M[i][j] && !M[i-1][j] && !M[i][j-1] && !M[i+1][j] && !M[i][j+1])
//                     islands++;

//     //Checking boundary elements except corners
//     for(int i=0,j=1;j<n-1;j++)
//         if(M[i][j] && !M[i+1][j] && !M[i][j-1] && !M[i][j+1])
//             islands++;
    
//     for(int i=1,j=n-1;i<n-1;i++)
//         if(M[i][j] && !M[i-1][j] && !M[i][j-1] && !M[i+1][j])
//             islands++;
    
//     for(int i=n-1,j=n-1;j>0;j--)
//         if(M[i][j] && !M[i-1][j] && !M[i][j+1] && !M[i][j-1])
//             islands++;
    
//     for(int i=n-1,j=0;i>0;i--)
//         if(M[i][j] && !M[i+1][j] && !M[i][j+1] && !M[i-1][j])
//             islands++;

//     //Checking corners
//     if(M[0][0] && !M[1][0] && !M[0][1])         islands++;
//     if(M[0][n-1] && !M[1][n-1] && !M[0][n-2])   islands++;
//     if(M[n-1][0] && !M[n-2][0] && !M[n-1][1])   islands++;
//     if(M[n-1][n-1] && !M[n-1][n-2] && !M[n-2][n-1]) islands++;

//     return islands;
// }


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char traversal[50];
int iter;
int n;
int src;
int visit[10] = {0};

int adjacent(int M[n][n], int source)
{   
    for(int i=source,j=0;j<n;j++)
        if(M[i][j]==1 && visit[j]==0) return j;
    return -1;
}
void dfsTraversal(int M[n][n], int source)
{   
    visit[source] = 1;
    traversal[iter++] = source+'0';
    // char curr[] = {source+'0'};
    // strcat(traversal,curr);
    // printf("%d ",source);

    int next=adjacent(M,source);
    while(next!=-1){
        if(visit[next]==0) dfsTraversal(M,next);
        next=adjacent(M,source);
    }
}


void dfs(int M[n][n], int source)
{
    visit[source] = 1;
    int next = adjacent(M,source);

    while(next!=-1){
        if(source == src) printf("%d is reachable from %d\n",next,source);
        if(visit[next]==0) dfs(M,next);
        next = adjacent(M,source);
    }
}


int main()
{
    printf("Enter no. of cities/lands\n");
    scanf("%d",&n);
    
    int AM[n][n];
    printf("Enter elements of adjacency matrix\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&AM[i][j]);

    printf("Enter source city\n");
    scanf("%d",&src);

    double timetaken;
    clock_t begin = clock();

    //printf("No. of islands = %d\n",countIslands(AM));
    // dfs(AM, src);
    // iter=0;
    dfsTraversal(AM,src);
    
    clock_t end = clock();
    timetaken = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("%s\n",traversal);

    printf("Time taken = %lf seconds", timetaken);
    
    return 0;
}