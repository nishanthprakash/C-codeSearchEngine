// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
#include<stdlib.h>
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int arr[n][n+1];
    int i, j, k, l;
    for(i = 0; i < n; i = i + 2)
    {
        k = i;
        l = 1;
        for(j = 0; j < n-i; j++)
        {
            arr[i][j] = k+1;
            k++;
        }
        for(j = n-i; j < n+1; j++)
        {
            arr[i][j] = l;
            l++;
        }
    }
    for(i = 1; i < n; i = i + 2)
    {
        k = i;
        l = n;
        for(j = 0; j < i + 1; j++)
        {
            arr[i][j] = k+1;
            k--;
        }
        for(j = i+1; j < n+1; j++)
        {
            arr[i][j] = l;
            l--;
        } 
    } 
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n+1; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}
// FUNCTION SIGNATURE ENDS

// DO NOT IMPLEMENT THE main( ) METHOD
int main()
{
    //DO NOT CHANGE ANY CODE IN THIS FUNCTION
    int n;
    printf("Enter the value of N: ");
    //ASSUME INPUT HAVE ALREADY BEEN TAKEN
    writePatternNumber(n);
    return 0;
}
                  
