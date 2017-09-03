#define MAXN 50001
struct Point{
	ll x,y;
	int pos;
};
typedef struct Point point;
point pt[MAXN];
struct Solution{
	int i1,i2;
	ll dis;
};
typedef struct Solution sol;
ll distance(point p1,point p2){
		ll px=(p1.x-p2.x);
		ll py=(p1.y-p2.y);
		ll sd=px*px+py*py;
		return sd;
}
sol brute(point pt[],int n){
	int i,j,i1,i2;
	ll dis,min=999999999999999999;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			dis=distance(pt[i],pt[j]);
			if(dis<min){
				min=dis;
				i1=pt[i].pos;
				i2=pt[j].pos;
			}
		}
	}
	sol s;
	s.dis=min;
	s.i1=i1;
	s.i2=i2;
	return s;
}
int cmpx(const void *a,const void *b){
	point p1=*(point*)a;
	point p2=*(point*)b;
	return p1.x-p2.x;
}
int cmpy(const void *a,const void *b){
	point p1=*(point*)a;
	point p2=*(point*)b;
	return p1.y-p2.y;
}
sol cross(point px[],int sz,ll d){
	qsort(px,sz,sizeof(point),cmpy);
	int i,j,i1,i2;
	for(i=0;i<sz;i++){
		for(j=i+1;j<sz && ((px[j].y-px[i].y)*(px[j].y-px[i].y))<d;j++){
			if(distance(px[i],px[j])<d){
				d=distance(px[i],px[j]);
				i1=px[i].pos;
				i2=px[j].pos;
			}
		}
	}
	sol s;
	s.dis=d;
	s.i1=i1;
	s.i2=i2;
	return s;
}
sol closest(point p[],int n){
	if(n<=8) return brute(p,n);
	point pm=p[n/2];
	sol s1=closest(p,n/2);
	sol s2=closest(p+n/2,n-n/2);
	sol s;
	if(s1.dis<s2.dis) s=s1;
	else s=s2;
	point new[n];
	int i,j=0;
	for(i=0;i<n;i++){
		if(abs(p[i].x-pm.x)<=(sqrt(s.dis)+1))
			new[j++]=p[i];
	}
	sol s3=cross(new,j,s.dis);
	if(s3.dis<s.dis) return s3;
	else return s;
}
//sort the input array according to x axis.
