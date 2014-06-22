// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include<stdio.h>

void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    
    printf("n = %d", n);
    int arr[n],i,count,count1,*ptr;
    
    ptr=&arr[0];
    
    for(i=0;i<n;i++)
        arr[i] = i+1;

    for(i=0;i<n;i++)
    printf("%d ", arr[i]);        
        
        printf("\n\n");
        
    int j=0,k=0;
    
    for(i=0;i<n;i++)
    {
        
        if((i+1)%2==1)
        {
            
           
            while(*ptr!=n && count==n)
            {
                ptr++;
                if(*ptr==n)
                    ptr=&arr[0];
            
                printf("%d ", *ptr); 
                
                count++;               
            }
            
            printf(" %d" ,i+1);
        }
        
        if((i+1)%2==0)
        {                      
            while(*ptr!=n && count==n)
            {
             ptr--;
                if(*ptr==1)
                    ptr=&arr[n];
            
                printf("%d ", *ptr); 
                
                count++;               
            }
            
            printf(" %d" ,i+1);
            
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
                  
