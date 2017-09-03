#define MAX 100002
#define ull unsigned long long
ull tree[3*MAX],offset[3*MAX];
void refresh(int node,int b,int e)
{
	if(offset[node]==0) return;
	tree[node]+=offset[node]*(e-b+1);
	if(b==e) {offset[node]=0;return;}
	offset[2*node+1]+=offset[node];
	offset[2*node+2]+=offset[node];
	offset[node]=0;
}
ull query(int node,int b,int e,int i,int j)
{
	ull p1,p2;
	refresh(node,b,e);
	if(b>j || e<i) return 0;
	if(b>=i && e<=j){
		return tree[node];
	}
	p1=query(2*node+1,b,(b+e)/2,i,j);
	p2=query(2*node+2,(b+e)/2+1,e,i,j);
	return p1+p2;
}
void update(int node,int b,int e,int i,int j,ull val)
{
	refresh(node,b,e);
	if(b>j || e<i) return;
	if(b>=i && e<=j){
		offset[node]+=val;
		refresh(node,b,e);
		return;
	}
	update(2*node+1,b,(b+e)/2,i,j,val);
	update(2*node+2,(b+e)/2+1,e,i,j,val);
	tree[node]=tree[node*2+1]+tree[node*2+2];
}
