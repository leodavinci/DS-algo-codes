#define MAX 100000000
#define LMT 10000
int flag[MAX>>6],prime[1000010],len;
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
void sieve()
{
	int i,j,k;
        prime[len++]=2;
	for(i=3;i<LMT;i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	for(i=3;i<MAX;i+=2)
		if(!ifc(i))
                    prime[len++]=i;
}
