#define MAXVAL 1000001
int bit[MAXVAL];
LL get(int i){
	LL sum=0;
	while(i>0){
		sum+=bit[i];
		i-=(i&-i);
	}
	return sum;
}
void update(int i,int val){
	while(i<MAXVAL){
		bit[i]+=val;
		i+=(i&-i);
	}
}
