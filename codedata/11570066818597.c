// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
int mod(int a,int n)
{
    if (a>0)
        return a;
    else
        return (n+a);
}
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int starting=1;
    int order=1;
    int i,j;
    int *a=(int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++)
        a[i]=i+1;
    for (starting=0;starting<n;starting++)
    {
        for (i=0;i<=n;i++)
        {
            if(order==1)
                printf("%d",a[mod((starting+i),n)%n]);
            else
                printf("%d",a[mod((starting-i),n)%n]);
        }
        printf("\n");
        if(order==1)
            order=0;
        else
            order=1;
            
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
                  
