#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

struct point { 
    double x, y;
    point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {} 
};

double dist(point p1, point p2) {
    // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); 
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = theta * PI / 180.0;
    return point(p.x * cos(rad) - p.y * sin(rad),
            p.x * sin(rad) + p.y * cos(rad)); 
}

// ax + by + c = 0
struct line { double a, b, c; };

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
        // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

bool areParallel(line l1, line l2) {
    // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); 
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;

    // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS)   p.y = -(l1.a * p.x + l1.c);
    else                    p.y = -(l2.a * p.x + l2.c);

    return true; 
}

struct vec { 
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {} 
};
vec toVec(point a, point b) {
    // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); 
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s); 
}

// nonnegative s = [<1 .. 1 .. >1]
// shorter.same.longer
point translate(point p, vec v) {
    // translate p according to v
    return point(p.x + v.x , p.y + v.y); 
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    // translate a to c
    return dist(p, c); 
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);

    if (u < 0.0) { 
        c = point(a.x, a.y);
        // closer to a
        return dist(p, a); 
    }

    // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y);
        // closer to b
        return dist(p, b); 
    }

    // Euclidean distance between p and b
    return distToLine(p, a, b, c); 
}

// since oa . ob = |oa| x |ob| x cos(theta) -> theta = acos(oa . ob / (|oa| x |ob|))
double angle(point a, point o, point b) { // RETURNS ANGLE AOB IN RAD
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; 
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}

ll n;
point st, en, tl, br;

bool ok(point p1, point p2) {
    point i;
    line l, li;

    pointsToLine(st, en, li);
    pointsToLine(p1, p2, l);

    if (areSame(li, l)) 
        return min(st.x, en.x) <= br.x && max(st.x, en.x) >= tl.x && min(st.y, en.y) <= tl.y && max(st.y, en.y) >= br.y;

    if (areIntersect(l, li, i) == false) return false;
    return fabs(dist(p1, i) + dist(i, p2) - dist(p1, p2)) < EPS && fabs(dist(st, i) + dist(i, en) - dist(st, en)) < EPS;
}

bool isInside(point p) {
    return p.x <= br.x && p.x >= tl.x && p.y <= tl.y && p.y >= br.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    while (n--) {
        cin >> st.x >> st.y >> en.x >> en.y >> tl.x >> tl.y >> br.x >> br.y;

        if (tl.x > br.x) swap(tl.x, br.x);
        if (tl.y < br.y) swap(tl.y, br.y);

        bool can = false;
        can |= ok(tl, {tl.x, br.y});
        can |= ok(tl, {br.x, tl.y});
        can |= ok(br, {tl.x, br.y});
        can |= ok(br, {br.x, tl.y});

        if (isInside(st) || isInside(en))
            cout << "T" << endl;
        else
            cout << (can ? "T" : "F") << endl;
    }


}