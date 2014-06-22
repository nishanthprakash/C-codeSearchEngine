#include<stdio.h>// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int );
void writePatternNumber(int n)
{
int j;
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    for(int i=1;i<=n;i++)
    {
    for(j=1;j<=1;j++)
    {
    printf("%d",i);
    printf("\n");
    }
    for(j=2;j<=4;j++)
    {
    if(i+j==5)
    {
    printf("4");
  }
  printf("\n");
    }
    for(j=2;j<=4;j++)
    {
    if((i+j==3)||(i+j==7))
    {
    printf("2");
    }
    printf("\n");
    }
    for(j=2;j<=4;j++)
    {
    if(i+j==4)
    {
    if(j%2==0)
    {
    printf("1");
  
    }
    else
    {
    printf("3");
   
    }
    }
    printf("\n");
    }
    for(j=2;j<=4;j++)
    {
    if(i+j==8)
    {
    printf("8");
    }
    printf("\n");
    }
    for(j=2;j<=4;j++)
    {
    if(i+j==6)
    {
    if(j%2==0)
    {
    printf("3");
    }
    
    else
    {
    printf("1");
    
    }
        printf("\n");

    }
    for(j=5;j<=5;j++)
    {
    printf("%d",i);
        printf("\n");

    }
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
    
    scanf("%d",&n);
    writePatternNumber(n);
    return 0;
}
}
                  
