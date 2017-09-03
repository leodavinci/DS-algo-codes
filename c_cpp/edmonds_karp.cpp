int par[1001],vis[1001],gm[1001][1001],res[1001][1001];
VVI g(1001);
int bfs(int n,int s,int t){
    Rep(i,0,n) vis[i]=0;
    queue<int> q;
    vis[s]=1;
    par[s]=-1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        Rep(i,0,g[u].size()){
            int v=g[u][i];
            if(vis[v]==0 && res[u][v]>0){
                q.push(v);
                par[v]=u;
                vis[v]=1;
            }
        }
    }
    return (vis[t]==1);
}
int edmond_karp(int n,int s,int t){
    int flow=0,i,j;
    while(bfs(n,s,t)==1){
        int path_min=INT_MAX;
        for(i=t;i!=s;i=par[i]){
            j=par[i];
            path_min=MIN(path_min,res[j][i]);
        }
        for(i=t;i!=s;i=par[i]){
            j=par[i];
            res[j][i]-=path_min;
            res[i][j]+=path_min;
        }
        flow+=path_min;
    }
    return flow;
}
