VPII edge;
int dis[10010],w[10010];
void bellmanford(int src,int v,int e){
    Rep(i,0,v) dis[i]=INT_MAX;
    dis[src]=0;
    int x,y;
    Rep(i,0,v-1){
        Rep(j,0,e){
            x=edge[j].first;
            y=edge[j].second;
            if(dis[x]+w[j]<dis[y])
                dis[y]=dis[x]+w[j];
        }
    }
    Rep(i,0,e){
        x=edge[i].first;
        y=edge[i].second;
        if(dis[x]+w[i]<dis[y])
            printf("graph contain -ve cycle\n");
    }
}
