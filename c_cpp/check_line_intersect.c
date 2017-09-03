struct point{
    int x;
    int y;
};
typedef struct point Point;
int onSegment(Point p,Point q,Point r){
    if (q.x<=max(p.x,r.x) && q.x>=min(p.x,r.x) &&
        q.y<=max(p.y,r.y) && q.y>=min(p.y,r.y))
       return 1;
    return 0;
}
int orientation(Point p,Point q,Point r){
    int val=(q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0)?1:2;
}
int doIntersect(Point p1,Point q1,Point p2,Point q2){
    int o1=orientation(p1,q1,p2);
    int o2=orientation(p1,q1,q2);
    int o3=orientation(p2,q2,p1);
    int o4=orientation(p2,q2,q1);
    if (o1!=o2 && o3!=o4) return 1;
    if (o1==0 && onSegment(p1,p2,q1)) return 1;
    if (o2==0 && onSegment(p1,q2,q1)) return 1;
    if (o3==0 && onSegment(p2,p1,q2)) return 1;
    if (o4==0 && onSegment(p2,q1,q2)) return 1;
    return 0;
}