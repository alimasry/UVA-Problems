#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int dcmp(double x, double y) {
    return fabs(x - y) < EPS ? 0 : x > y ? 1 : -1;
}

struct point { 
    double x, y;
    point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {} 
    bool operator== (const point& other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }
};

struct point_i {
    int x, y;
    point_i(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

double dist(point p1, point p2) {
    // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y); 
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) { double rad = theta * PI / 180.0;
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

bool lineSegmentIntersect(point p1, point p2, point q1, point q2) {
    point i;
    line l1, l2;

    pointsToLine(p1, p2, l1);
    pointsToLine(q1, q2, l2);

    if (areSame(l1, l2)) 
        return min(q1.x, q2.x) <= max(p1.x, p2.x) && max(q1.x, q2.x) >= min(p1.x, p2.x)  && min(q1.y, q2.y) <= max(p1.y, p2.y) && max(q1.y, q2.y) >= min(p1.y, p2.y);

    if (areIntersect(l1, l2, i) == false) return false;
    return fabs(dist(p1, i) + dist(i, p2) - dist(p1, p2)) < EPS && fabs(dist(q1, i) + dist(i, q2) - dist(q1, q2)) < EPS;
}

// Circle

int insideCircle(point_i p, point_i c, int r) {
    int dx = p.x - c.x, dy = p.y - c.y;
    int Eucl = dx * dx + dy * dy, rSq = r * r;
    return Eucl < rSq ? 0 : Eucl == rSq ? 1 : 2; // inside/border/outside
}

struct Circle {
    point c;
    double r;

    const double PI = acos(-1);

    double area() { return PI * r * r; }
    double perimeter() { return 2 * PI * r; }
    bool isInside(point p) { return dist(c, p) <= r; }
    double arcLength(double angle) { return angle / 360.0 * perimeter(); }
    double chordLength(double angle) { angle *= PI / 180.0; return 2 * r * sin(angle / 2); }
    double sectorArea(double angle) { angle *= PI / 180.0; return angle * area(); }
    double segmentArea(double angle) { return sectorArea(angle) - r * chordLength(angle) / 2.0; }
};

// a function to get a valid center of a circle given 
// the 2 pts of intersection between it and another and its radius
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; 
} // to get the other center, reverse p1 and p2

// Triangles

double Heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * Heron(ab, bc, ca)); 
}

double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); 
}


double rInCircle(double ab, double bc, double ca) {
    return Heron(ab, bc, ca) / (0.5 * (ab + bc + ca)); 
}

double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a)); 
}

// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0;
    // no inCircle center
    line l1, l2;
    // compute these two angle bisectors
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr);
    return 1; 
}

// cosine rule:
//      c^2 = a^2 + b^2 - 2ab(cos(theta))
//  sine rule:
//      a / sin(A) = b / sin(B) = c / sine(C) = 2R


// Polygons

// we assume that the points are entered in ccw order
// P[0] is always equal P[n]

double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)
        result += dist(P[i], P[i + 1]);
    return result;
}

double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int) P.size() - 1; ++i) {
        x1 = P[i].x, x2 = P[i + 1].x;
        y1 = P[i].y, y2 = P[i + 1].y;
        result += x1 * y2 - x2 * y1;
    }
    return result / 2.0;
}

bool isConvex(const vector<point> &P) {
    // returns true if all three
    int sz = (int)P.size(); // consecutive vertices of P form the same turns
    if (sz <= 3) return false; // a point/sz=2 or a line/sz=3 is not convex
    bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
    for (int i = 1; i < sz-1; i++) { // then compare with the others
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false; // different sign -> this polygon is concave
    }
    return true; 
} // this polygon is convex

bool isConvex_with_collinear(const vector<point> &P) {
    int sz = (int) P.size();
    if (sz <= 3) return false;
    int s = 0;
    while (s < sz - 1 && collinear(P[s], P[s + 1], P[(s + 2) == sz ? 1 : s + 2]))
        ++s;
    if (s == sz - 1) return false;

    bool isLeft = ccw(P[s], P[s + 1], P[(s + 2) == sz ? 1 : s + 2]);
    for (int i = 0; i < sz - 1; ++i) {
        if (collinear(P[i], P[s + 1], P[(s + 2) == sz ? 1 : s + 2]))
            continue;
        if (ccw(P[i], P[s + 1], P[(s + 2) == sz ? 1 : s + 2]) != isLeft)
            return false;
    }
    return true;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon_angle(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    // assume the first vertex is equal to the last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        else sum -= angle(P[i], pt, P[i+1]); // right turn/cw
    }
    
    return fabs(fabs(sum) - 2*PI) < EPS; 
} 

// another solution is to cut the polygon into triangle and check that the sum of 
// area of those triangle is equal to the area of the polygon
bool inPolygon(point pt, const vector<point> &P) {
    if ((int) P.size() == 0) return false;
    double A = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i) {
        point a = pt, b = P[i], c = P[i + 1];
        A += Heron(dist(a, b), dist(b, c), dist(a, c));
    }
    return fabs(A - area(P)) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v)); 
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]);
        // Q[i] is on the left of ab
        if (left1 * left2 < -EPS)
        // edge (Q[i], Q[i+1]) crosses line ab
        P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    // make P’s first point = P’s last point
    return P; 
}

point pivot(0, 0);
bool angleCmp(point a, point b) {
    // angle-sorting function
    if (collinear(pivot, a, b)) // special case
        return dist(pivot, a) < dist(pivot, b); // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; // compare two angles
}

vector<point> convexHull(vector<point> P) {
    if (P.empty()) return P;
    // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P; 
    }
    // special case, the CH is P itself
    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]

    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0];
    // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]

    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n) { // NOTE: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (collinear(S[j - 1], S[j], P[i])) { // MAY change if the points on the line are collinear
            S.pop_back();
            S.push_back(P[i++]);
        }
        else if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
        else S.pop_back(); // or pop the top of S until we have a left turn
    }
    
    return S; // return the result
} 

vector<point> convexPolygonIntersection(vector<point> &P1, vector<point> &P2) {
    int sz1 = (int) P1.size() - 1;
    int sz2 = (int) P2.size() - 1;

    vector<point> I;
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            if (lineSegmentIntersect(P1[i], P1[i + 1], P2[j], P2[j + 1])) {
                point In;
                line l1, l2;
                pointsToLine(P1[i], P1[i + 1], l1);
                pointsToLine(P2[j], P2[j + 1], l2);
                if (areIntersect(l1, l2, In))
                    I.push_back(In);
            }
        }
        if (inPolygon(P1[i], P2)) {
            I.push_back(P1[i]);
        }
    }

    for (int i = 0; i < sz2; ++i) {
        for (int j = 0; j < sz1; ++j) {
            if (lineSegmentIntersect(P2[i], P2[i + 1], P1[j], P1[j + 1])) {
                point In;
                line l1, l2;
                pointsToLine(P1[j], P1[j + 1], l1);
                pointsToLine(P2[i], P2[i + 1], l2);
                if (areIntersect(l1, l2, In))
                    I.push_back(In);
            }
        }
        if (inPolygon(P2[i], P1))
            I.push_back(P2[i]);
    }

    return convexHull(I);
}

ll n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n && n) {
        vector<point> P1, P2;
        for (int i = 0; i < n; ++i) {
            double x, y; cin >> x >> y;
            P1.push_back({x, y});
        }
        P1.push_back(P1[0]);
        reverse(P1.begin(), P1.end()); // to be ccw

        cin >> m;
        for (int i = 0; i < m; ++i) {
            double x, y; cin >> x >> y;
            P2.push_back({x, y});
        }
        P2.push_back(P2[0]);
        reverse(P2.begin(), P2.end()); // to be ccw

        auto I = convexPolygonIntersection(P1, P2);

        double ans = area(P1) + area(P2) - area(I) * 2;
        cout << setw(8) << fixed << setprecision(2) << ans;
    }
    cout << endl;
}
