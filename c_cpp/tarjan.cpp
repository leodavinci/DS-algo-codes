VVI g(10010);
stack<int> st;
int low[10010],disc[10010],stmem[10010],tym;
void tarjan(int x){
    stmem[x]=1;
    st.push(x);
    low[x]=++tym;
    disc[x]=tym;
    Rep(i,0,g[x].size()){
        int y=g[x][i];
        if(disc[y]==0){
            tarjan(y);
            low[x]=MIN(low[x],low[y]);
        }
        else if(stmem[y]==1)
            low[x]=MIN(low[x],disc[y]);
    }
    if(low[x]==disc[x]){
        int w=0;
        while(st.top()!=x){
            w=st.top();
            st.pop();
            stmem[w]=0;
            printf("%d ",w);
        }
        w=st.top();
        st.pop();
        stmem[w]=0;
        printf("%d\n",w);
    }
}
void dfs(int n){
    Rep(i,0,n){
        low[i]=0;
        disc[i]=0;
        stmem[i]=0;
    }
    tym=0;
    Rep(i,0,n)
        if(disc[i]==0)
            tarjan(i);
}
