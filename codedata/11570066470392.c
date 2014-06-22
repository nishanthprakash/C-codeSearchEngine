// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int lineNumber,count,isIncreasing;
    lineNumber=1;
    isIncreasing=1;
    while(lineNumber<=n){
        count=lineNumber;
        if(isIncreasing){
            while(count<=n){
                printf("%d",count);
                count++;
            }
            for(count=1;count<=lineNumber;count++){
                printf("%d",count);
            }
            isIncreasing=0;
        }
        else if(!isIncreasing){
            while(count>=1){
                printf("%d",count);
                count--;
            }
            for(count=n;count>=lineNumber;count--){
                printf("%d",count);
            }
            isIncreasing=1;
        }
        lineNumber++;
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
                  
