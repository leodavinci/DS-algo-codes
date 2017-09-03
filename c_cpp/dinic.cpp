map<int,int> v[1000];
typedef map<int,int>::iterator iter;
int n;
int bfs(int s,int t){
    queue<PII > q;
    int visit[n];
    fill(visit,visit+n,0);
    q.push(make_pair(s,0));
    while(!q.empty()){
        int tmp=q.front().first;
        int level=q.front().second;
        if(tmp==t) return level;
        q.pop();
        if(!visit[tmp]){
            visit[tmp]=1;
            for(map<int,int>::iterator it=v[tmp].begin();it!=v[tmp].end();it++){
                if(it->second>0 && !visit[it->first])
                    q.push(make_pair(it->first,level+1));
            }
        }
    }
    return 0;
}
int dfs(int s,int t,int lv,VI *cf){
    int tmp;
    if(s==t){
        int min=INT_MAX;
        for(VI::iterator it=cf->begin();it!=cf->end();it++)
            if(min>*it) min=*it;
            return min;
    }
    if(lv==0) return 0;
    for(iter it=v[s].begin();it!=v[s].end();it++){
        cf->push_back(it->second);
        if(it->second>0 && (tmp=dfs(it->first,t,lv-1,cf))){
            it->second-=tmp;
            if(v[it->first].find(s)!=v[it->first].end())v[it->first].insert(make_pair(s,tmp));
            else v[it->first][s]-=tmp;
            return tmp;
        }
        cf->pop_back();
    }
    return 0;
} 
int augment(int s,int t,int lv){
    int sum=0;
    int tmp;
    while((tmp=dfs(s,t,lv,new vector<int>))){
        sum+=tmp;
    }
    return sum;
} 
int maxflow(int s,int t){
    int sum=0;
    int level;
    while((level=bfs(s,t))){
        sum+=augment(s,t,level);
    }
    return sum;
}
