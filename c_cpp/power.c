LL power(int a,int b,int mod){
    if(b==0) return 1;
    else if(b==1) return a%mod;
    LL y=power(a,b/2,mod);
    y=(y*y)%mod;
    if(b&1) return (y*a)%mod;
    else return y;
}
