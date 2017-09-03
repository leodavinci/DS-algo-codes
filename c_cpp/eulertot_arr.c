#define MAX 1000000
int tot[MAX];
void euler()
{
	int t,n,i,j;
	tot[0]=0;tot[1]=0;
	for(i=2;i<=MAX;i++) tot[i]=i;
	for(i=2;i<=MAX;i++){
		if(tot[i]==i){
			for(j=i;j<=MAX;j+=i)
				tot[j]=(tot[j]/i)*(i-1);
		}
	}
	tot[1]=1;
}
