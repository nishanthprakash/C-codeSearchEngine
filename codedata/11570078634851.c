// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    int i=1;
    int m,k,l;
    for(i=1;i<=n;i++)
    {
      l=i;
    
    if(i % 2 != 0)
    {
    m=1;
    for(k=0;k<=n;k++)
    {
    if(l <= n)
    printf("%d",l++);
    else
    printf("%d",m++);
    }
    }
    else 
    {
    m=n;
    for(k=0;k<=n;k++)
    {
    if( l >0)
    printf("%d",l--);
    else
    printf("%d",m--);
    }
    }
    printf("\n");
    }
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
                  
