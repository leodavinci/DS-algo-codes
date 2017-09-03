const int MX=1001;
const int MAXINT=1000000000;
int n,st,end,vis[MX];
VVPII G(MX);
int prim(int s){
    int result=0;
    priority_queue<PII,vector<PII>,greater<PII> > pq;
    pq.push(PII(0,s));
    while(!pq.empty()){
        PII tp=pq.top();
        pq.pop();
        int v=tp.second;
        int d=tp.first;
        result+=d;
        if(vis[v]==1) continue;
        vis[v]=1;
        for(int i=0;i<G[v].size();i++){
            PII x=G[v][i];
            int v2=x.first;
            int cost=x.second;
            if(vis[v2]==1) continue;
            pq.push(pii(cost,v2));
        }
    }
    return result;
}
