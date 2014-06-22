// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int i,j,k;
    for(i=1;i<=n;i++)
    {    k=i; 
         
            for(j=1;j<=n;j++){
                if(i%2==1){
                    if(k%(n+1)==0) k=1;
                    printf("%d",k%(n+1));
                    k++;
                  }
                    
                else{
                  if(k%(n+1)==0) k=n;
                  printf("%d",k%(n+1));
                  k--;
            
                }
                        }       
          printf("%d\n",i);
  
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
                  
