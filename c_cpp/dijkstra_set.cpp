const int MX=1001;
int n;
VVPII G(MX);
VI D(MX,INT_MAX); 
void Dijkstra(int s){
    set<PII> Q;
    D[s]=0;
    Q.insert(PII(0,s));
    while(!Q.empty()){
        PII top=*Q.begin();
        Q.erase(Q.begin());
        int v=top.second;
        int d=top.first;
        for(VPII::const_iterator it=G[v].begin();it!=G[v].end();it++){
            int v2=it->first;
            int cost=it->second;
            if(D[v2]>D[v]+cost){
                if(D[v2]!=INT_MAX)
                    Q.erase(Q.find(pii(D[v2],v2)));
                D[v2]=D[v]+cost;
                Q.insert(pii(D[v2],v2));
            }
        }
    }
}
