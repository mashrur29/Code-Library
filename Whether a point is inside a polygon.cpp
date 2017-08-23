struct Point{
long long int x;
long long int y;
};

bool onSegment(Point a,Point b,Point c)
{
    if(c.x>=min(a.x,b.x)&&c.x<=max(a.x,b.x)&&c.y>=min(a.y,b.y)&&c.y<=max(a.y,b.y)) return true;
     return false;
}

int orientation(Point a,Point b,Point c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
}



bool doIntersect(Point p1,Point q1,Point p2,Point q2){
    long long int o1,o2,o3,o4;
    o1=orientation(p1,q1,p2);
    o2=orientation(p1,q1,q2);
    o3=orientation(p2,q2,p1);
    o4=orientation(p2,q2,q1);

  if(((o1>0&&o2<0)||(o1<0&&o2>0))&&((o3>0&&o4<0)||(o3<0&&o4>0)))
    return true;

    if(!o1&&onSegment(p1,q1,p2)) return true;
    if(!o2&&onSegment(p1,q1,q2)) return true;
    if(!o3&&onSegment(p2,q2,p1)) return true;
    if(!o4&&onSegment(p2,q2,q1)) return true;

    return false;
}

bool inside(Point polygon[],long long int n,Point p){
    Point extreme;
    extreme.x=p.x+30000;
    extreme.y=p.y+30001;
    long long int count=0,i;

    fr(i,n){
        if(doIntersect(polygon[i],polygon[i+1],p,extreme)){
           if(((orientation(polygon[i],polygon[i+1],p))==0&&onSegment(polygon[i],polygon[i+1],p))||((orientation(polygon[i],polygon[i+1],extreme))==0&&onSegment(polygon[i],polygon[i+1],extreme))||((orientation(p,extreme,polygon[i]))==0&&onSegment(p,extreme,polygon[i]))||((orientation(p,extreme,polygon[i+1]))==0&&onSegment(p,extreme,polygon[i+1]))) return true;
            count++;
        }
    }

    if(count%2!=0) return true;
    else return false;
}
