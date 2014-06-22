// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(j<=n-1)       
            {
                printf("%d",i+1);
            }
            else
            {
                j=0;
                printf("%d",i+1);
                printf("\n");
              }
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
    writePatternNumber(n);
    return 0;
}
                  
