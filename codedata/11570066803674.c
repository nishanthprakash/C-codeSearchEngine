// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include<stdio.h>

void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int x,y;
    int buff[100];
    int g =1;
    for(x=0;x<n;x++)
    {
        int curr = x+1;
        if(g)
            g=0;
        else
            g=1;
        for(y=0;y<=n;y++)
        {
            
            printf("%d",curr);
            
            if(g)
                curr--;
            else 
                curr++;
            if(curr==0){
                curr=n;
                g = 1;
              }
            else if(curr>n)
            {    curr=0;
            g=0;
            } 
            if(curr==0)
                curr=1;
        } 
        printf("\n");
    }
    //start here
    
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
                  
