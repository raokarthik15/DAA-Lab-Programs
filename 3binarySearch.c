/*
“Digishop” a online shopping website needs to keep track of the product
availability based on the product ID. Design a program in C to read the product
ID provided by the customer and search for it’s availability by using Binary
search method and display the relevant message whether the product is in 
stock or not. Determine the time required to search for the product. Repeat 
the experiment for different values of n and plot a graph of the time taken 
versus n. (n=no of elements).
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bSearch(int a[], int low, int high, int key)
{
    if(high<low)
        return -1;
    int mid = (high+low)/2;
    if(key == a[mid]) return mid;
    else if(key<a[mid]) return bSearch(a, low, mid-1, key);
    else return bSearch(a, mid+1, high, key);
}

int main()
{
    int n, key, result, loc, x;
    printf("Enter no. of elements\n");
    scanf("%d",&n);

    time_t tm;
    srand((unsigned int) time(&tm));
    
    int a[n];
    for(int i=0;i<n;i++) a[i]=rand()%500;
    
    for(int i=0;i<n;i++){
        loc = i;
        for(int j=i+1;j<n;j++)
            if(a[loc]>a[j])
                loc = j;
        if(loc!=i){
            x = a[loc];
            a[loc] = a[i];
            a[i] = x;
        }
    }
    
    printf("Enter key\n");
    scanf("%d",&key);

    double timetaken;
    clock_t begin = clock();
    result = bSearch(a, 0, n-1, key);

    result==-1 ? printf("Not found\n") : printf("Found at index %d\n", result);
    clock_t end = clock();
    timetaken = (double)(end-begin)/(double)CLOCKS_PER_SEC;
    printf("Time taken = %.20lf\n", timetaken);

    return 0;
}