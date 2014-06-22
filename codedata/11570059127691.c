// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int i=1;
    int m=n+1;
    int a=0;
    
    for(int k=1;k<=(n+1)/2;k++)
    {
    for(int j=1;j<=m;j++)
    {
    if(i>n)
    i=1;
    printf("%d",i);
    i++;
    }
    printf("\n");
    if(a<n/2)
    {
    a++;
    for(int j=1;j<=m-1;j++)
    {
    if(i<1)
    i=n;
    printf("%d",i);  
    i--; 
    } 
     printf("%d",i++);
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
                  
