/*
“Aircel” a mobile network company need to maintain the telephone numbers 
of its customer in order to call and inform them about the new year offer. They 
have to sort the contact numbers in ascending order to keep track of the 
customers whom they called. Design and develop a program in C to sort the
phone numbers by using insertion sort algorithm, Input should be generated 
randomly. Determine the time required to sort the elements. Repeat the 
experiment for different values of n and plot a graph of the time taken versus
n. (n=no of elements).
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateNumberList(long long numList[], int len)
{
    long long x;
    time_t tm;
    srand((unsigned int)time(&tm));
    
    for(int i=0;i<len;i++){
        
        x = rand()%4 + 6;
        int iter = 9;
        while(iter--)   x = x*10 + (rand()%10);
        numList[i] = x;
    }
}

void InsertionSort(long long* list, int len)
{   
    long long phone;
    int j;
    for(int i=0;i<len;i++){
        phone=list[i];
        j=i-1;
        while(j>=0 && phone<list[j]){
            list[j+1] = list[j];
            j--;
        }
        list[j+1]=phone;
    }
}

int main()
{   
    int length;

    printf("Enter count of phone numbers:\n");
    scanf("%d",&length);

    long long listOfNumbers[length];
    generateNumberList(listOfNumbers, length);

    double timetaken;
    clock_t begin = clock();

    InsertionSort(listOfNumbers, length);

    clock_t end = clock();
    for(int i=0;i<length;i++)
        // Format specifier: I64d = lld
        printf("%I64d\n",listOfNumbers[i]);
    timetaken = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Time taken = %lf seconds",timetaken);

    return 0;
}