typedef struct {
	int d,x,y;
}result;

result extendedEuclid(int a, int b) {
	result res,resp;
	if(b==0) {		
		res.d=a;
		res.x=1;
		res.y=0;
		return res;
	}
	resp=extendedEuclid(b,a%b);
	res.d=resp.d;
	res.x=resp.y;
	res.y=resp.x-((a/b)*resp.y);
	return res;
}
