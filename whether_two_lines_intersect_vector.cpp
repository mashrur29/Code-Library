struct Point {
    double x;
    double y;
    
    Point() {}
    Point(double _x, double _y) {x = _x; y = _y;}
};

double cross_product(Point p1, Point p2) {
    return (((p1.x) * (p2.y)) - ((p2.x) * (p1.y)));
}

bool doIntersect(Point l1a, Point l1b, Point l2a, Point l2b) {
    Point v1, v2;
    double c1, c2;
    
    v1 = Point(l1b.x -l1a.x, l1b.y - l1a.y);
    v2 = Point(l2a.x - l1a.x, l2a.y - l1a.y);
    c1 = cross_product(v1, v2);
    v2 = Point(l2b.x - l1a.x, l2b.y - l1a.y);
    c2 = cross_product(v1, v2);
    if((c1 * c2) >= 0) return false;
    
    v1 = Point(l2b.x -l2a.x, l2b.y - l2a.y);
    v2 = Point(l1a.x - l2a.x, l1a.y - l2a.y);
    c1 = cross_product(v1, v2);
    v2 = Point(l1b.x - l2a.x, l1b.y - l2a.y);
    c2 = cross_product(v1, v2);
    if((c1 * c2) >= 0) return false;
    
    return true;
}
