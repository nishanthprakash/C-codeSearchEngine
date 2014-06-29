



void writePatternNumber(int n)
{
    int i,k,r;
    
    
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



int main()
{
    
    int n;
    printf("Enter the value of N: ");
    
    writePatternNumber(n);
    return 0;
}
                  





void writePatternNumber(int n)
{
    int i,k,r;
    
    
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



int main()
{
    
    int n;
    printf("Enter the value of N: ");
    
    writePatternNumber(n);
    return 0;
}
                  

