#include<stdio.h>
#include<conio.h>

void swap2(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void print(int a[100][100],int n,int j)
{
    int i;
     for(i=0;i<n;i++)
   {
       printf("%d",a[j][i]);
     
   }
    printf("%d",a[j][0]);
}
void writePatternNumber(int n)
{
   int arr[n][n+1];
   int i,j=0;
   int width=0;
     for(int i=0;i<n;i++)
   {
       arr[i][j]=i+1;
     
   }
    print(arr,n,j);
   while(width<n)
   {
   
   for(int i=0;i<n-1;i++)
   {
    swap2(&arr[i],&arr[i+width]);
    }

   print(arr,n,j);
   width++;
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
                  
