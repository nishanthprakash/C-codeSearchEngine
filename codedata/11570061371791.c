// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int i,j;
    int a[20][20];
    int t=1;
    int b=1;
    for(i=0;i<n;i++)
    {
    a[i][0]=b;
    
    a[i][n]=b;
        b++;
    }
    for(i=0;i<n;i++)
    {
    for(j=1;j<n;j++)
    {
    a[i][j]=++t;
    if(a[i][j]>n)
    {while(n>0)
    {
    a[i][j]=a[i-1][n];
    n--;
    }
    }
    }
    }
    for(i=0;i<n;i++)
    {
    for(j=0;j<n+1;j++)
    {
    printf("%d ",a[i][j]);
    }
    printf("\n");
    }// PRINT THE REQUIRED PATTERN WITH N ROWS
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
                  
