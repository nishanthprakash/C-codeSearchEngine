// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <stdio.h>
void writePatternNumber(int n)
{
  int arr[n][n+1];
  int i,j;
  int count=0;
  for (i=0 ; i<n; ++i)
  {
      count= count +1;
      arr[i][0] =arr [i][n]= count;
  }
  for (i = 0; i< n ; i = i+2)
  {
      for (j= 1; j<n; ++j)
      {
              arr[i][j]= (arr[i][j-1]+1)%(n+1);
      }
  }
  for (i = 1; i< n ; i = i+2)
  {
      for (j= n-1; j>0; j = j-1)
      {
              arr[i][j]= (arr[i][j+1]+1)%(n+1);
      }
  }
  
  for (i=0; i<n; ++i)
  {
      for (j =0; j<n+1; ++j)
      {
          printf("%d", arr[i][j]);
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
    writePatternNumber(2);
    return 0;
}
                  
