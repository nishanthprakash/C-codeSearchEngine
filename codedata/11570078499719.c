// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    
    int i,k,j,a[n][n+1];
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n+1;j++)
      {
         if(i == 1 && j!=1 && j!=(n+1))
         {
           a[i][j]=j;
         }
         else if(i==n)
         {
          a[i][j]=n-j-1;
         }
         else if(j==1 || j==(n+1))
         { 
           a[i][j]=i;
         }
         else
         {
           for(k=1;k<=n;k++)
           {
              if(k!=a[i][1]||k!=a[i][n]||k!=a[i][n+1])
              { 
                a[i][j]=k;
              }
           }
         }
      }
    }
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n+1;j++)
      {
        printf("%d",a[i][j]);
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
                  
