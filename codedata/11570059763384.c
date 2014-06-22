// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
int a[100];
for(int i=1;i<=n+1;i++)
{
if(a[i]==n+1)
a[i]=1;
else
a[i]=i;
}
for(int i=1;i<=n+1;i++)
{
printf("%d",a[i]);
}
printf("\n");
for(int i=1;i<=n+1;i++)
{
   for(int j=1;j<=n+1;j++)
   {
   if(j%2==1)
   {
   if(++a[j]==n)
   a[j]=1;
   }
   else
   {
   if(--a[j]==0)
   a[j]=n;
   }
}
for(int i=1;i<=n+1;i++)
{
printf("%d",a[i]);
}
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
                  
