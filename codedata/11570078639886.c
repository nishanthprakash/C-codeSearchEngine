// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int b[n];
    int j=1,i;
    for(j=1;j<=n;++j)
        b[j-1]=j;
    int count=0;
    for(j=0;j<n+1;++j)
    {
        for(i=0;i<n;++i)
        {
         printf("%d",b[i]);
         count++; 
            if(count == n+1)
            {    printf("\n");
                 i=n;
                 count=0;
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
                  
