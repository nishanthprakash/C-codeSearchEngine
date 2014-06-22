// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 4
#define MAX 5
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    int i,j=1;
    int pattern[MAXVALUE]={1,2,3,4};
    int result[n][MAX];
    for(i=0;i<n;i++){
        result[(i)][0]=j;
        j++;
        if(j%5==0) 
            j=1;
    }
    j=1;
    for(i=0;i<n;i++){
        result[i][MAX]=j%(MAXVALUE+1);
        j++;
        if(j%5==0) 
            j=1;
    }
    
    for(i=0;i<n;i+4){
        int temp[MAXVALUE];
        int k;
        
        
        
    }
    
        
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
                  
