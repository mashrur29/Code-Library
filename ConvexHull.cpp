#include<bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};
 
const double pi = 4*atan(1);
const int maxi = 51111;
point P[maxi], C[maxi], P0;
 
inline int triArea(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
 
inline int dis(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
 
inline bool cmp(const point &a, const point &b) {
    int d = triArea(P0, a, b);
    if(d < 0) return false;
    if(!d && dis(P0, a) > dis(P0, b)) return false;
    return true;
}

inline bool normal(const point &a, const point &b) {
	return ((a.x==b.x) ? a.y < b.y : a.x < b.x);
}

inline bool issame(const point &a, const point &b) {
	return (a.x == b.x && a.y == b.y);
}

inline void makeUnique(int &np) {
	sort(&P[0], &P[np], normal);
	np = unique(&P[0], &P[np], issame) - P;
}
 
void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++) {
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x)) pos = i;
    }
 
    swap(P[0], P[pos]);
    P0 = P[0];
 
    sort(&P[1], &P[np], cmp);
 
    for(i = 0; i < 3; i++) C[i] = P[i];
 
    for(i = j = 3; i < np; i++) {
        while(triArea(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}

double det(point p, point q, point r) {
    double t = (q.x - p.x)*(r.y - q.y) - (r.x - q.x)*(q.y - p.y);
    return t;
}

double dot(point p, point q, point r) {
    double t = (q.x - p.x)*(r.x - q.x) + (q.y - p.y)*(r.y - q.y);
    return t;
}

double angle(point p, point q, point r) {
    double t = atan(dot(p, q, r)/det(p, q, r));
    return (t*180.0)/pi + 90;
}
