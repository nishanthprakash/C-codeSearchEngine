#include<stdio.h>
#include<maths.h>
#include<stdam.h>// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int i,j,k;
    for(i=1;i<=n;i++){
             
    
    if(i%2==1)
    {
       
    for(k=i;k<=n;k++)
    {
    if(k!=n)
    {
    printf("%d",k);
    }
    if(k==n)
    {
    for(k=1;k<=n-i;k++)
    printf("%d",k);
    }
    }
    }
    else
    {
    
    for(k=i;k>=1;k--)
    if(k!=1)
    {
    printf("%d",k);
    }
    if(k==1)
    {
    for(k=n;k>=n-i;k--)
    printf("%d",k);
    }
    }
    printf("\n");
    
    }
    
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
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
                  
