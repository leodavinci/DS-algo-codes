class Point{
public:
    int x, y;
    bool operator < (Point b){
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};
Point pivot;
vector<Point> points;
int ccw(Point a, Point b, Point c){
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}
int sqrDist(Point a, Point b){
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool POLAR_ORDER(Point a, Point b){
    int order = ccw(pivot, a, b);
    if (order == 0)
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    return (order == -1);
}
stack<Point> grahamScan(int N){
    stack<Point> hull;
    if (N<3)
        return hull;
    int leastY = 0;
    Rep(i,1,N)
        if(points[i]<points[leastY])
            leastY=i;
    Point temp=points[0];
    points[0]=points[leastY];
    points[leastY]=temp;
    pivot=points[0];
    sort(points.begin()+1,points.end(),POLAR_ORDER);
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);
    Rep(i,3,N){
        Point top=hull.top();
        hull.pop();
        while (ccw(hull.top(), top, points[i]) != -1){
            top = hull.top();
            hull.pop();
        }
        hull.push(top);
        hull.push(points[i]);
    }
    return hull;
}
