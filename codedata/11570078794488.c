// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    int i,k,r;
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    if((n<1) || (n>100))
    {
        printf("unexpected value/out of assumption!!\n");
    }   
    else
    {
        
        for(i=1;i<n;i=i+4)
        {
            for(k=1;k<(n+1);k++)
            {
                if((k%2) != 0)
                {
                    int l=k;
                    for(r=1;r<=(n+1);r++)
                    {
                        printf("%d",l);
                        if(l<n)
                            l++;
                        else
                            l=1;   
                    }    
                }
                else
                {
                    int l=k;
                    for(r=1;r<=(n+1);r++)
                    {
                        printf("%d",l);
                        if(l>1)
                            l--;
                        else
                            l=n;   
                    }
                }
                printf("\n");
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
                  
