// vector structure

typedef long double dd;

struct point {
    dd x, y, z;
    point() {}
    point(dd x1, dd y1, dd z1) {
        x = x1;
        y = y1;
        z = z1;
    }

    dd operator * (const point &p) const {
        return x*p.x+y*p.y+z*p.z;
    }

    point operator + (const point &p) const {
        return point(x+p.x, y+p.y, z+p.z);
    }

    point operator - (const point &p) const {
        return point(x-p.x, y-p.y, z-p.z);
    }

    point operator ^ (const point &p) const {
        return point(y*p.z - p.y*z, p.x*z - p.z*x, x*p.y - p.x*y);
    }

    dd length() const {
        return sqrtl(*this * *this);
    }

    void normalize() {
        dd d = length();
        x/=d;
        y/=d;
        z/=d;
    }

    point operator * (dd t) const {
        return point(t * x, t * y, t * z);
    }

    point operator / (dd t) const {
        return point(x / t, y / t, z / t);
    }
};
