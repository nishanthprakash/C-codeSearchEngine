// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
     int i=0,temp,j;
     if(n>=1 && n<=100)
     {
      int a[n+1];
     while(i<n)
     {
       a[i]=i+1;
       printf("%d",a[i]);
       i++;
     }
     a[n-1]=1;
     printf("%d\n",a[n-1]);
     
     for(i=1;i<n;i++){
       if(i%2==1){
        temp=a[0];
        a[0]=a[1];
        a[1]=temp;
        j=2;
        int k=n-2;
        
        while(j<k){
       
         temp=a[j];
         a[j]=a[k];
         a[k]=temp;
         j++;
         k--;
        }
        a[n-1]=a[1];
        int m=0;
        while(m<n){
        printf("%d",a[m]);
        m++;
       }
       printf("\n");
     }
      if(i%2==0){
        j=0;
         int k=n-2;
        while(j<k)
        {
          temp=a[j];
          a[j]=a[k];
          a[k]=temp;
          j++;
          k--;
        }
        a[n-1]=a[0];
        int m=0;
        while(m<n){
        printf("%d",a[m]);
        m++;
       }
       printf("\n");
        }
      }
     }
     else
       printf("invalid N");
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
                  
