#define MX 100001
#define NIL 0
#define INF (1<<28)
VI G[MX];
int n,match[MX],dist[MX];
bool bfs(){
    int u,v,len;
    queue<int> Q;
    Rep(i,1,n+1){
        if(match[i]==NIL){
            dist[i]=0;
            Q.push(i);
        }
        else dist[i]=INF;
    }
    dist[NIL]=INF;
    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        if(u!=NIL){
            len=G[u].size();
            Rep(i,0,len) {
                v=G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]]=dist[u]+1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}
bool dfs(int u){
    int v,len;
    if(u!=NIL){
        len=G[u].size();
        Rep(i,0,len){
            v=G[u][i];
            if(dist[match[v]]==dist[u]+1){
                if(dfs(match[v])){
                    match[v]=u;
                    match[u]=v;
                    return true;
                }
            }
        }
        dist[u]=INF;
        return false;
    }
    return true;
}
int hopcroft_karp() {
    int matching=0;
    while(bfs())
        Rep(i,1,n+1)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
