// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include<stdio.h>
void writePatternNumber(int n)
{
int i,j, mat[101][101];
    for(i=0;i<n;i++)
    {
        mat[0][i]=i+1;
        mat[i][0]=i+1;
   }
    
    for(i=1;i<=n;i++)
    {
        
        for(j=1;j<=n;j++)
        {    
            mat[j][i]=mat[i-1][j-1];
            printf("%d",mat[i-1][j-1]);
                            
        }   
         
        mat[i][j]=mat[i][0];
        printf("%d\n",mat[i][j]);
        
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

                  
