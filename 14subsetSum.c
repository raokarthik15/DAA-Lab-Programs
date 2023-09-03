/*
Consider the Subset sum problem in which the objective is to find subset of
elements that are selected from a given set whose sum adds up to a given
number K. Assume the set contains non-negative values and also the input set
is unique (no duplicates are present.). Design and develop a program in C to
find the subset of a given set whose sum is equal to a positive integer K and
display an appropriate message if the given problem instance does not have the
solution. Note : Use Backtracking method.
*/

#include <stdio.h>

int count, w[10], d, x[10];
void subset(int cs, int k, int r)
{
    int i;
    x[k] = 1; // Consider the k'th element in the subset
    if ((cs + w[k]) == d)
    { // Print the solution - subset which makes the required sum
        printf("\nSubset solution = %d\n", ++count);
        for (i = 0; i <= k; i++)
        {
            if (x[i] == 1) // Elements that are considered in the subset
                printf("%d\n", w[i]);
        }
    }
    else if (cs + w[k] < d) // If the sum is less than the required sum
        subset(cs + w[k], k + 1, r - w[k]); // Add it to subset, k elements considered till now
    if ((cs + r - w[k] >= d) && (cs + w[k + 1]) <= d)
    { // Check if there is a possibility of forming the required sum without including the current element
        x[k] = 0; // Exclude the current element from the subset
        subset(cs, k + 1, r - w[k]); // Proceed to the next element without including the current one
    }
}

int main()
{
    int sum = 0, i, n;

    printf("enter no of elements\n");
    scanf("%d", &n);

    printf("Enter the elements in ascending order\n");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the required sum\n");
    scanf("%d", &d);

    for (i = 0; i < n; i++)
        sum += w[i];
    if (sum < d)
        printf("no solution exists\n");
    else
    {
        printf("The solution is\n");
        count = 0;
        subset(0, 0, sum);
    }
    return 0;
}
