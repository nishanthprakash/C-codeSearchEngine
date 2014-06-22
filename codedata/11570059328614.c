// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
//FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
void writePatternNumber(int n)
{
    // PRINT THE REQUIRED PATTERN WITH N ROWS
    // WRITE YOUR CODE HERE
    int x=0,k,i,j,a[100][100]={0,0};
    for(i=1;i<=n;i++)
    {
        if(i==1)
        x=2;
        else
        x=1;
        printf("%d ",i);
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                a[i][j]=1;
                printf("1 ");
            }
            else if(i+j==n)
            {
                a[i][j]=n;
                printf("%d ",n);
            }
            else
            {
                for(k=1;k<=n;k++)
                {
                    if(a[i][k]==x)
                    {
                    continue;
                    x++;
                    }
                    if(a[k][j]==x)
                    {
                    continue;
                    x++;
                    }
                    else
                    {
                        a[i][j]=x;
                        printf("%d ",x);
                        x++;
                        break;
                    }
                }
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
                  
