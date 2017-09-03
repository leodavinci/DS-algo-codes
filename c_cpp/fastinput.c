#define getcx getchar_unlocked
int inp()
{
    int n=0;
    int ch=getcx();int sign=1;
    while(ch<'0' || ch>'9'){if(ch=='-') sign=-1;ch=getcx();}
    while(ch>='0' && ch<='9')
    	n=(n<<3)+(n<<1)+ch-'0',ch=getcx();
    n=n*sign;
    return n;
}
