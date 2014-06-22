// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
void shiftleftbyone(char array[], int n)
{
int i ;
char array2[10] ;
for(i = 0 ; i < n-1 ; i++ )
array2[i] = array[i+2] ;
array2[n-1] = array[1] ;
array2[n] = array2[0] ;
   for (i = 0 ; i < n+1 ; i++ )
        printf("%c",array2[i]); 
    printf("\n");  
    
}

void shiftrightbyone(char array[], int n)
{
int i ;
char array2[10] ;
for(i = 0 ; i < n ; i++ )
array2[i] = array[i-1] ;
array2[n]= array2[0] ;
 for (i = 0 ; i < n+1 ; i++ )
        printf("%c",array2[i]); 
    printf("\n");
}
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
     int i , temp ;
    char a[10], b[10] ;
    for (i = 0 ; i < n ; i++ )
    {
    a[i] = 49 + i;
    }
    a[n] = a[0]; 
    for (i = 0 ; i < n+1 ; i++ )
        printf("%c",a[i]); 
    printf("\n");    
        
    for (i = n ; i >= 0 ; i-- )
        printf("%c",a[i]); 
    printf("\n"); 
     
 
    shiftleftbyone(a, n) ;
    shiftrightbyone(a ,n);
    
    // repeat that statement till n 
    for(i = 0 ; i < n ; i++ )
    {
    if (i < n-2 )
    b[i] = a[i + 2 ] ;
    }   
    
     for (i = 0 ; i < n+1 ; i++ )
        printf("%c",b[i]); 
    printf("\n");    
    // PRINT THE REQUIRED PATTERN WITH N ROWS
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

              
