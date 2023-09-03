/*
DMART is providing special offer to its customer on New Year’s Eve. Customers 
can buy anything they want with flat80% discount, but the products they buy 
should fit into the basket provided by DMART. The objective is to collect the 
expensive products which fit into the given basket and overall weight of the 
basket cannot exceed 15kg.Write an algorithm by using knapsack algorithm 
using dynamic programming to find the best subset for the given scenario.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ITEMS 10
#define CAPACITY 5

int Weights[MAX_ITEMS+1] = {0};
int Values[MAX_ITEMS+1] = {0};
int Knapsack[MAX_ITEMS+1][CAPACITY+1];

int max(int x, int y)
{   return x>y ? x : y; }

int MFKnapsack(int K[MAX_ITEMS+1][CAPACITY+1], int i, int j)
{
    if(K[i][j]<0)
        K[i][j] = j<Weights[i] ? MFKnapsack(K,i-1,j) : 
        max(MFKnapsack(K,i-1,j), Values[i] + MFKnapsack(K,i-1,j-Weights[i])); 
    return K[i][j];
}

int main()
{
    for(int i=0;i<=MAX_ITEMS;i++)
        for(int j=0;j<=CAPACITY;j++)
            if(i==0||j==0) Knapsack[i][j]=0;
            else Knapsack[i][j]=-1;
    
    int n;
    printf("Enter no. of items\n");
    scanf("%d",&n);

    printf("Enter weight and value of each item\n");
    printf("\tWt Val\n");
    for(int i=1;i<=n;i++){
        printf("Item %d: ",i);
        scanf("%d %d",&Weights[i],&Values[i]);
    }
    
    clock_t begin = clock();
    int maxprofit = MFKnapsack(Knapsack, n, CAPACITY);
    clock_t end = clock();

    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Max profit = %d\nTime Taken = %lf",maxprofit, timetaken);
    
    return 0;
}