const int MX=1001;
int n,st,end;
VVPII G(MX);
VI D(MX,INT_MAX);
void Dijkstra(int s){
    priority_queue<PII,vector<PII>,greater<PII> > pq;
    D[s]=0;
    pq.push(PII(0,s));
    while(!pq.empty()){
        PII tp=pq.top();
        pq.pop();
        int v=tp.second;
        int d=tp.first;
        if(v==end-1) break;
        if(d>D[v]) continue;
        for(int i=0;i<G[v].size();i++){
            PII x=G[v][i];
            int v2=x.first;
            int cost=x.second;
            if(D[v2]>D[v]+cost){
                D[v2]=D[v]+cost;
                pq.push(pii(D[v2],v2));
            }
        }
    }
}
