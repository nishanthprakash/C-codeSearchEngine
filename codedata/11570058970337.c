// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{int t,a;
int p[20]={0},p1[20]={0};
for(int i=1;i<=n;i++)
{
if(i%2==1)
{
t=i;
for(a=1;a<=n&&t<=n;a++)
{
p[a]=t;
t=t+1;
}
for(int l=1;a<=n+1;a++,l++)
{
p[a]=l;
}
printf("\n");
for(int m=1;m<=n+1;m++)
printf("%d",p[m]);
}
else
{
int temp;
p1[1]=i;
for(int j=n+1,k=2;j>=2;j--,k++)
{
p1[k]=p[j];
}
printf("\n");
for(int l=1;l<=n+1;l++)
printf("%d",p1[l]);
}
}
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
                  
