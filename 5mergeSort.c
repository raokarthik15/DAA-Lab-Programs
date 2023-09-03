/*
“Deloit”, a software company needs to maintain its employee details like
employeeid, name, address in a record, design and develop a program in C to 
sort the employee records based on their employee ID by using merge sort 
algorithm, employee ID should be generated randomly. Determine the time
required to sort the elements. Repeat the experiment for different values of n 
and plot a graph of the time taken versus n. (n=no of elements).
*/
//0.0327
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateIDs(int* IDlist,int len)
{
    int ID;
    time_t tm;
    srand((unsigned int)time(&tm));
    
    for(int i=0;i<len;i++){
        
        ID = rand()%9+1;
        int iter = 4;
        while(iter--)   ID = ID*10 + (rand()%10);
        IDlist[i] = ID;
    }
}

void merge(int *IDlist, int low, int mid, int high)
{
    int temp[500000];
    
    int i=low;
    int l=low;
    int j=mid+1;

    while(l<=mid && j<=high){
        if(IDlist[l]<=IDlist[j])
            temp[i++] = IDlist[l++];
        else
            temp[i++] = IDlist[j++];
        // Equivalent statement using ternary
        // temp[i++] = IDlist[l] <= IDlist[j] ? IDlist[l++] : IDlist[j++];
    }
    while(j<=high)
        temp[i++]=IDlist[j++];
    while(l<=mid)    
        temp[i++]=IDlist[l++];
    
    for(int k=low;k<=high;k++) IDlist[k] = temp[k];
}

void mergesort(int* IDlist, int low, int high)
{   
    if(high>low){
        int mid = (low+high)/2;
        mergesort(IDlist, low, mid);
        mergesort(IDlist, mid+1, high);
        merge(IDlist, low, mid, high);
    }
}

int main()
{   
    int len;
    printf("Enter number of employees\n");
    scanf("%d",&len);

    int IDlist[len];
    generateIDs(IDlist, len);

    double timetaken;
    printf("Sorted employee ids\n");
    clock_t begin = clock();
    mergesort(IDlist,0,len-1);
    clock_t end = clock();

    for(int i=0;i<len;i++)
        printf("%d\n",IDlist[i]);

    timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time taken = %lf", timetaken);

    return 0;
}