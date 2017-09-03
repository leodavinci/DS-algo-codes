void FailureFunction(char P[], int F[],int m){
	int i,j;
	F[0]=0;
	j=0;
	i=1;
	while(i<m){
		if(P[i]==P[j]){
			F[i]=j+1;
			i++;
			j++;
		}else if(j>0){
			j=F[j-1];
		}else {
			F[i]=0;
			i++;
		}
	}
}

int KMP(char T[], char P[]){
	int i,j,F[100];
	int m=strlen(P);
	int n=strlen(T);
	FailureFunction(P,F,m);
	i=0;
	j=0;
	while(i<n){
		if(T[i]==P[j]){
			if(j==m-1)
				return i-j;
			else{
				i++;
				j++;
			}
		}else if(j>0){
			j=F[j-1];
		}else{
			i++;
		}
	}
	return -1;
}
