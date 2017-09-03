int tree[1000010];
void build_tree(int node,int x,int y){
	if(x>y) return;
	if(x==y){
		tree[node]=a[x];
		return;
	}
	build_tree(2*node+1,x,(x+y)/2);
	build_tree(2*node+2,(x+y)/2+1,y);
	tree[node]=MAX(tree[2*node+1],tree[2*node+2]);
}
int query(int node,int st,int end,int x,int y){
	if(st>end) return -1;
	if(st>y || end<x) return -1;
	if(st>=x && end<=y)
		return tree[node];
	int v1=query(2*node+1,st,(st+end)/2,x,y);
	int v2=query(2*node+2,(st+end)/2+1,end,x,y);
	if(v1==-1) return v2;
	else if(v2==-1) return v1;
	return MAX(v1,v2);
}
