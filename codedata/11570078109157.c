// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int a[n][n+1];
    int i,j;
    for(i=0;i<n;++i){
        a[i][0]=i+1;
        a[i][n]=i+1;
        a[0][i]=i+1;
        a[n-1][n-i-1]=i+1;
    }
   for(i=0;i<n;++i){
        for(j=0;j<4;++j)
        {
            printf("%d",a[i%4][j]);
        }
        printf("%d\n",a[i%4][0]);      
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
                  
