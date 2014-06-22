// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int i,j,num;
    for(i=1;i<=n;i++)
    {
        num=i;
        for(j=0;j<=n;j++)
        {
        if(i%2!=0)
        {
           printf("%d",num);
           
           if(num==n)
               num=1;
           else
               num=num+1;
            
        }
        else
        {
            printf("%d",num);
            if(num==1)
                num=n;
            else
                num=num-1;
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
    writePatternNumber(5);
    writePatternNumber(8);
    writePatternNumber(n);
    return 0;
}
                  
