




void writePatternNumber(int n)
{
  int arr[n][n+1];
  int i,j;
  int count=0;
  for (i=0 ; i<n; ++i)
  {
      count= count +1;
      arr[i][0] =arr [i][n]= count;
  }
  for (i = 0; i< n ; i = i+2)
  {
      for (j= 1; j<n; ++j)
      {
              arr[i][j]= (arr[i][j-1]+1)%(n+1);
      }
  }
  for (i = 1; i< n ; i = i+2)
  {
      for (j= n-1; j>0; j = j-1)
      {
              arr[i][j]= (arr[i][j+1]+1)%(n+1);
      }
  }
  
  for (i=0; i<n; ++i)
  {
      for (j =0; j<n+1; ++j)
      {
          printf("%d", arr[i][j]);
      }
      printf("\n");
  }
    
    
    
}



int main()
{
    
    int n;
    printf("Enter the value of N: ");
    
    writePatternNumber(2);
    return 0;
}
                  






void writePatternNumber(int n)
{
  int arr[n][n+1];
  int i,j;
  int count=0;
  for (i=0 ; i<n; ++i)
  {
      count= count +1;
      arr[i][0] =arr [i][n]= count;
  }
  for (i = 0; i< n ; i = i+2)
  {
      for (j= 1; j<n; ++j)
      {
              arr[i][j]= (arr[i][j-1]+1)%(n+1);
      }
  }
  for (i = 1; i< n ; i = i+2)
  {
      for (j= n-1; j>0; j = j-1)
      {
              arr[i][j]= (arr[i][j+1]+1)%(n+1);
      }
  }
  
  for (i=0; i<n; ++i)
  {
      for (j =0; j<n+1; ++j)
      {
          printf("%d", arr[i][j]);
      }
      printf("\n");
  }
    
    
    
}



int main()
{
    
    int n;
    printf("Enter the value of N: ");
    
    writePatternNumber(2);
    return 0;
}
                  

