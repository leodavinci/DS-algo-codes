VVI g(10010);
int par[10010],low[10010],disc[10010],ap[1000],len,vis[10010],tym;
void articulationPoint(int x){
    vis[x]=1;
    int ch=0;
    low[x]=++tym;
    disc[x]=tym;
    Rep(i,0,g[x].size()){
        int y=g[x][i];
        if(vis[y]==0){
            ch++;
            par[y]=x;
            articulationPoint(y);
            low[x]=MIN(low[x],low[y]);
            if(par[x]==-1 && ch>1)
                ap[len++]=x;
            if(par[x]!=-1 && low[y]>=disc[x])
                ap[len++]=x;
        }
        else if(y!=par[x])
            low[x]=MIN(low[x],disc[y]);
    }
}
void dfs(int n){
    Rep(i,0,n){
        par[i]=-1;
        low[i]=0;
        disc[i]=0;
        vis[i]=0;
    }
    tym=0;
    Rep(i,0,n)
        if(vis[i]==0)
            articulationPoint(i);
    Rep(i,0,len)
        printf("%d ",ap[i]);
    NL;
}
