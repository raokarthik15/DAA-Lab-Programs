/*
There have been a number of fire outbreak cases recorded in the Florida area 
that has brought about loss of lives to inhabitants and loss of properties. Some 
routes within the district can be reconstructed into shortcut routes, so that fire 
man can traverse through the district in order to prevent fire incidents. The 
objective is to find the minimum distance and shortest path from the fire station 
to all the residential layout in Florida area. Write an algorithm by applying 
Floyd’s method to find the solution for the given scenario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;

int min(int x, int y)
{   return x<y ? x : y;  }

void Floyd(int W[n][n])
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
}

int main()
{
    printf("Enter number of residential layouts: \n");
    scanf("%d",&n);

    int C[n][n];
    printf("Enter cost matrix:(-1 if no connection)\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&C[i][j]);
            C[i][j] == -1 ? C[i][j] = 9999 : C[i][j];
        }

    clock_t begin = clock();
    Floyd(C);
    clock_t end = clock();

    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;

    printf("Distance matrix of shortest paths' length:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            C[i][j] == 9999 ? printf("%d ",-1) : printf("%d  ",C[i][j]);
        printf("\n");
    }
    printf("Time taken = %lf",timetaken);

    return 0;
}