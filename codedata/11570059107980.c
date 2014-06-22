// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int i,k,c,a;
    for(i=0;i<n;i++)
    {
           if(i%2==0)
           {
            c=0;
            for(k=i;k<n;k++)
            {
             printf("%d",(k+1));
             c++;           
            }
            for(a=0;a<n-c;a++)
            {
                printf("%d",(a+1));
            }
           }
           else
           {
           c=0;
            for(k=i;k>=0;k--)
            {
             printf("%d",(k+1));
             c++;           
            }
            for(a=n-1;a>c-1;a--)
            {
                printf("%d",(a+1));
            }
           } 
          printf("%d",(i+1));
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
                  
