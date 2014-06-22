// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include<stdio.h>

int bin_flag(int num)
{
if(num%2==0) return 0;

return 1;
}

void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    
    int odd=0;
    int i, j, k;
    for(i=1; i<=n; i++)
    {
    odd=bin_flag(i); 
    
    k=i;
    for(j=0;j<=n;j++)
    {
    if(odd)
    {
    //print ascending
    printf("%d",k);
    k=(k+1)%n;
    if(k==0) k=n;
    }
    if(!odd)
    {
    printf("%d",k);
    k=k-1;
    if(k==0) k=n;
    }
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
                  
