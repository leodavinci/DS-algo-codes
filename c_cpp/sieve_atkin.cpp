bool isprime[MAXN+1];
vector<int> prime;
void sieve(){
	int i,j,ct=0;
	prime.push_back(2);
	prime.push_back(3);
	isprime[2]=true;
	isprime[3]=true;
	for(i=1;i*i<=MAXN;i++){
		for(j=1;j*j<=MAXN;j++){
			int n=4*i*i+j*j;
			if(n<=MAXN && (n%12==1 || n%12==5)){
				isprime[n]=!isprime[n];
			}
			n=3*i*i+j*j;
			if(n<=MAXN && n%12==7){
				isprime[n]=!isprime[n];
			}
			n=(3*i*i)-(j*j);
			if(i>j && n<=MAXN && n%12==11){
				isprime[n]=!isprime[n];
			}
		}
	}
	for(i=5;i*i<=MAXN;i++){
		if(isprime[i]){
			prime.push_back(i);
			int x=i*i;
			for(j=x;j<=MAXN;j+=x) isprime[j]=false;
		}
	}
}
