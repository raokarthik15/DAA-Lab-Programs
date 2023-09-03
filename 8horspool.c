/*
Consider the problem of searching for genes in DNA sequences using Horspool’s algorithm. A DNA sequence is represented by a text on the alphabet {A, C, G, T}, and the gene or gene segment is the pattern. A gene segment of your chromosome 10 has the pattern TCCTATTCTT . Design and develop a program in C to locate the above pattern in the following DNA sequence by applying Horspool’s algorithm. TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT.
Also compute the number of comparisons using this method as compared to linear search method.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TEXTLEN 100
#define PATLEN 20
#define CHARS 256

void shiftTable(char table[], char pattern[])
{
    int m = strlen(pattern);

    for(int i=0;i<CHARS;i++)
        table[i] = m;           //Initialise all values of table with len(pattern)
    for(int i=0;i<m-1;i++){
        //(total idx) - current idx = remaining characters
        table[(int)pattern[i]] = m-1-i;                 //Update value for characters in pattern, with the no. of characters present
    }                                                   //after it. Do this for all characters in pattern, except the last one.
}

int horspool(char text[], char pattern[])   //returns no. of comparisons and prints indices where pattern matches
{
    char table[CHARS];
    shiftTable(table, pattern);
    int m = strlen(pattern);
    int n = strlen(text);
    if(!m || n<m) return 0;   //if size of pattern is 0 or larger than text
    
    int i=m-1, j;           //Point i at last index no. of pattern - used to traverse through text
    int count = 0;
    while(i<n){             //Till i points to the last index of text
        j=0;                //Var for counting number of matches and to traverse through pattern starting from the end
        while(j<m && text[i-j] == pattern[m-1-j]) j++;      //while total pattern matches, increment j
        if(j==m){                                           //If total pattern match
            count+=j;
            printf("Found at index %d\n",i-j+1);            //print
            i++;                                            //and move to next index
        }
        /*When j=0 i.e. when no characters match, add value in hashtable for the mismatched
        character. Else subtract the no. of matched characters (j). This is done because
        hashtable contains the no. of characters that must be matched - another definition.
        When j characters are matched then value in (table - j) more characters are needed to match.
        In case there are m-1 matches, then move to next index since j's value will be m in this case
        and will result in an infinite loop or wrong answers. (since the maximum value in the hashtable
        could be m)*/ 
        else{
            count+=j+1;
            i += (table[(int)text[i-j]] - j) > 0 ? table[(int)text[i-j]]-j : 1;
        }
    }
    return count;
}

int main()
{   
    char text[TEXTLEN];
    char pattern[PATLEN];
    int comparisons;

    printf("Enter text (character limit = 100):\n");
    gets(text);                 //TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT
    //fgets(text, TEXTLEN, stdin);
    printf("Enter pattern (character limit = 20):\n");
    gets(pattern);              //TCCTATTCTT
    //fgets(pattern, PATLEN, stdin);

    clock_t begin = clock();
    comparisons = horspool(text,pattern);
    clock_t end = clock();

    double timetaken = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("No. of comparisons = %d\n",comparisons);
    printf("Time taken = %lf",timetaken);

    return 0;
}