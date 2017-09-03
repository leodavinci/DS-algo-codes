#define MAX 100100
int hs[MAX],n;
typedef pair<int , int> P;
stack< P > S;
int large_histo()
{
	long long best=0,temp;
	int start=0;
	for(int i=0;i<=n;i++)
	{
		start=i;
		while(!S.empty() && (hs[i] < S.top().second))
		{
			temp=(LL)(i-S.top().first)*S.top().second;
			if(best < temp) best=temp;
			start=S.top().first; 
			S.pop();
		}
		S.push(make_pair(start,hs[i]));
	}
	while(!S.empty()) S.pop();
	return best;
}
