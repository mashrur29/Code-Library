#include<bits/stdc++.h>
using namespace std;
 
#define pi      acos(-1.00)
#define eps     1e-9
#define D(x)    cout << #x " = " << (x) << endl
 
const int inf = numeric_limits<int>::max();
bool eq(double a, double b) { return fabs( a - b ) < eps; } //two numbers are equal
 
struct point{
    double x, y;
    point(){}
 
    point(double xx, double yy) {x = xx, y = yy;} // NEVER USE xx = 0 or yy = 0 HERE
} origin = point(0, 0);
 
 
 
point operator+(const point &u, const point &v) {return point(u.x + v.x, u.y + v.y);} //OK
point operator-(const point &u, const point &v) {return point(u.x - v.x, u.y - v.y);} //OK
point operator*(const point &u, double v) {return point(u.x*v, u.y*v);} //OK
point operator*(double v, const point &u) {return point(u.x*v, u.y*v);} //OK
point operator*(const point &u, const point &v) {return point(u.x * v.x - u.y * v.y, u.x * v.y + v.x * u.y);} // multiplying two complex numbers
point operator/(const point &u, double v) {assert(abs(v) > eps); return point(u.x/v, u.y/v);} //OK
bool operator != (const point &u, const point &v) {return !(eq(u.x, v.x) && eq(u.y, v.y));} //OK
 
ostream &operator <<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")";
} //OK
 
bool operator <(const point &u, const point &v){
    if(fabs(u.x - v.x ) < eps) return u.y + eps < v.y;
    return u.x + eps < v.x;
}
 
double norm(point u){return sqrt(u.x * u.x + u.y * u.y);} //OK
double arg(point u){ assert(u != origin); return atan2(u.y, u.x);} //OK
point polar(double r, double theta) {return point(r * cos(theta), r * sin(theta));} //OK
 
double dotp(point u, point v) {return u.x * v.x + u.y * v.y;} //OK
double crsp(point u, point v) {return u.x * v.y - u.y * v.x;} //OK
 
 
point unit_vector(point u) { return u / norm(u); } //OK
point rtt(point piv, point u, double theta) {return (u - piv) * polar(1.00, theta) + piv;} //OK
point projection(point p, point st, point ed) { return dotp(ed - st, p - st) / norm(ed - st) * unit_vector(ed - st) + st;} //OK
point extend(point st, point ed, double len) { return ed + unit_vector(ed-st) * len;} //OK
 
point segmentProjection(point p, point st, point ed)
{
    double d = dotp(p - st, ed - st) / norm(ed - st);
    if(d < 0) return st;
    if(d > norm(ed - st) + eps) return ed;
    return st + unit_vector(ed - st) * d;
} //OK
 
double distancePointSegment(point p, point st, point ed) {return norm(p - segmentProjection(p, st, ed)); } //OK
double distancePointLine( point P, point st, point ed) { return norm( projection(P, st, ed) - P ); } //OK
 
point reflection(point p, point st, point ed){
    point proj = projection(p, st, ed);
    if(p != proj) return extend(p, proj, norm(p - proj));
    return proj;
} //OK
 
 
int main()
{
   
 
    return 0;
}
