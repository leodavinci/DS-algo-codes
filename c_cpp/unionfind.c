int par[MAX],rank[MAX];
int find(int x){
    if(par[x]!=x)
        par[x]=find(par[x]);
    return par[x];
}
void Union(int x,int y){
    int px=find(x);
    int py=find(y);
    if(rank[px]<rank[py])
        par[px]=py;
    else if(rank[px]>rank[py])
        par[py]=px;
    else{
        par[px]=py;
        rank[py]++;
    }
}
