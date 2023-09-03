/*
“Sunshine” a job search portal is looking for engineering graduates, they need 
to sort the candidate’s resume based on their ranking (Average Percentage). 
Ranking should be generated randomly. Design and develop a program in C to 
sort the resumes by using heap sort algorithm. Determine the time required to 
sort the elements. Repeat the experiment for different values of n and plot a 
graph of the time taken versus n.(n=no of elements).
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateRankList(int RankList[],int len)
{
    int rank;
    time_t tm;
    srand((unsigned int)time(&tm));
    
    for(int i=1;i<=len;i++){
        rank = rand()%9+1;
        int iter = 3;
        while(iter--)   rank = rank*10 + (rand()%10);
        RankList[i] = rank;
    }
}

void Swap(int *n, int *m)
{
    int temp = *n;
    *n = *m;
    *m = temp;
}

void Insert(int H[], int len)
{
    int i, j, k;
    k=i=len/2;                          //Start by leaving all leaf nodes
    j=i*2;                              //Left child of node
    while(k>=1){
        if(j+1<=len)
            j = H[j]>H[j+1] ? j : j+1;  //Compare children
        if(j>len || H[i]>H[j])
            i = --k;
        else{                           //Swap if any child is greater
            Swap(&H[i], &H[j]);
            i=j;                        //Now compare with new children
        }
        j=i*2;                          //Point to its left child
    }
}

void Delete(int H[], int len)
{
    int k = len;
    int i,temp,j;
    while(k>1){
        i=1;
        temp = H[1];                    //Store the first element that is to be deleted
        H[1] = H[k];                    //Place the last element at the first place
        j = i*2;                        //Left child
        //Adjustment loop
        while(j<k){
            if(j+1<=k)
                j = H[j]>H[j+1] ? j : j+1;
            if(H[i]<H[j]){
                Swap(&H[i], &H[j]);
                i=j;
                j=i*2;
            }
            else
                break;
        }
        H[k--] = temp;
    }
}

void HeapSort(int H[], int len)
{
    Insert(H,len);
    Delete(H,len);
}

void InsertOne(int H[], int n)
{
    int i=n;        //n represents the no. of element to be inserted
    int temp = H[i];        //insert element as leaf (at the end)
    while(i>1 && temp>H[i/2]){      //till parent exists and current element is greater than parent
        H[i] = H[i/2];              //copy parent value to current place (child element)
        i/=2;                       //update i to parent index (where the current element might be inserted)
    }
    H[i] = temp;                    //insert the element in its correct position
}

void DeleteOne(int H[], int len)
{   //Delete 1st element
    int i=1;            //point at root    
    int j=i*2;          //point at left child of i (now pointing at root)
    int temp = H[1];    //Store the first element (to be deleted)
    H[1] = H[len];      //Bring last element (leaf) to the root
    while(j<=len-1){    //while there exists a left child
        j = H[j]>H[j+1] ? j : j+1;      //Compare for left and right children
        if(H[i]<H[j]){                  //IFF child is strictly larger
            Swap(&H[i], &H[j]);         //Swap
            i=j;                        //Update i to child index
            j=i*2;                      //j to i's left child
        }
        else break;                     //if parent is larger, stop
    }
    H[len] = temp;                      //Insert the deleted element(largest) at the end
                                        //To obtain ascending order
}


void heapsort(int H[], int len)
{
    for(int i=1;i<=len;i++) InsertOne(H, i);            //Insert element one by one at leaf
    for(int i=len;i>1;i--) DeleteOne(H, i);             //Delete element from heap
}

int main()
{
    int len;
    printf("Enter no. of resumes\n");
    scanf("%d",&len);
    int RankList[len+1], RL[len+1];
    RankList[0] = 0;
    RL[0] = 0;
    generateRankList(RL,len);

    // generateRankList(RankList,len);
    // for(int i=1;i<=len;i++) RL[i] = RankList[i];

    // printf("Ranks are:\n");
    // for(int i=1; i<=len; i++) printf("%d ", RankList[i]);
    
    clock_t begin = clock();
    // HeapSort(RankList, len);
    heapsort(RL, len);
    clock_t end = clock();

    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;

    // printf("\nSorted ranks are:\n");
    // for(int i=1; i<=len; i++) printf("%d ", RankList[i]);
    printf("\nSorted ranks are:\n");
    for(int i=1; i<=len; i++) printf("%d ", RL[i]);
    printf("\nTime taken = %lf", timetaken);

    return 0;
}