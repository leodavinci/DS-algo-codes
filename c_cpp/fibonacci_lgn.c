long long MODD;
long long fb(long long n)
{
    long long tmp[2][2]={{0,0},{0,0}},sol[2][2]={{1,0},{0,1}},fib[2][2]={{1,1},{1,0}};
    int i,j,k;
    while(n)
    {
        if(n&1) {
        for(i=0;i<2;i++) for(j=0;j<2;j++) tmp[i][j]=0;
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                    tmp[i][j]=(tmp[i][j]+sol[i][k]*fib[k][j])%MODD;
        for(i=0;i<2;i++) for(j=0;j<2;j++) sol[i][j]=tmp[i][j];
        }
        for(i=0;i<2;i++) for(j=0;j<2;j++) tmp[i][j]=0;
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                    tmp[i][j]=(tmp[i][j]+fib[i][k]*fib[k][j])%MODD;
        for(i=0;i<2;i++) for(j=0;j<2;j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (sol[0][1])%MODD;
}
