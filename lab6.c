/*
Assume that NMIT college needs to maintain the student details like USN, name,
and contact details in a record. USN should be generated randomly. Design and
develop a program in C to sort the records based on USN by using quick sort
algorithm, Determine the time required to sort the roll numbers. Repeat the
experiment for different values of n and plot a graph of the time taken versus 
n. (n=no of elements).
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateUSNlist(int USNlist[],int len)
{
    int usn;
    time_t tm;
    srand((unsigned int)time(&tm));
    
    for(int i=0;i<len;i++){
        
        usn = rand()%9+1;
        int iter = 3;
        while(iter--)   usn = usn*10 + (rand()%10);
        USNlist[i] = usn;
    }
}

void Swap(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
}

int Partition(int USNlist[], int low, int high)
{
    // int mid = (high+low)/2;
    int pivot = USNlist[low];
    int i = low;
    int j = high;
    while(i<j){
        while(USNlist[i] <= pivot) i++;
        while(USNlist[j] > pivot) j--;
        if(i<j) Swap(&USNlist[i], &USNlist[j]);
    }
    Swap(&USNlist[low], &USNlist[j]);
    return j;
}

void QuickSort(int USNlist[], int low, int high)
{
    if(low<high){
        int index = Partition(USNlist, low, high);
        QuickSort(USNlist, low, index-1);
        QuickSort(USNlist, index+1, high);
    }
}

int main()
{
    int len;
    printf("Enter number of students:\n");
    scanf("%d",&len);

    int USNlist[len];
    generateUSNlist(USNlist, len);

    clock_t begin = clock();
    QuickSort(USNlist, 0, len-1);
    clock_t end = clock();

    for(int i=0;i<len;i++)
        printf("%d ", USNlist[i]);
    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime taken = %lf", timetaken);


    return 0;
}