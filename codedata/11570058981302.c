#include<stdio.h>
#include<conio.h>
// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
int a[n][5],i,c,j,flag=1,flag2,countline=1;
i=0;
while(countline<=n)
{
if(flag==1||flag2==1)
{c=1;
n++;//counting number of lines 
flag==2;//
for(j=1;j<=4;j++)
{
a[i][j]=c++;
}
i++;
}
if(flag==2)
{
a[i][0]=a[i-1][1];
a[i][1]=a[i-1][0];
a[i][2]=a[i-1][3];
a[i][3]=a[i-1][2];
flag=1;flag2=2;
i++;
n++;
}
if(flag2==2||flag==1)
{
a[i][0]=3;
a[i][1]=4;
a[i][2]=1;
a[i][3]=2;
i++;
n++;
flag2==2;
flag==2;
}
i=0;//inserting last values
c=1;
for(j=0;j<5;j++)
{if(c==5)
   c=1;
a[i++][j]=c++;
}
}
for(i=0;i<=n;i++)
{
for(j=0;j<=4;j++)
{
printf("%d",a[i][j]);
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
   
    writePatternNumber(n);
    return 0;
}
                  
