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

typedef complex<double> point;

#define                     X real()
#define                     Y imag()
#define vec(a,b)            ((b) - (a))
#define polar(r,t)          ((r) * exp(point(0, (t))))
#define angle(v)            (atan2((v).Y, (v).X))
#define length(v)           ((double)hypot((v).Y, (v).X))
#define lengthSqr(v)        (dot((v), (v)))
#define dist(a, b)          (abs((b) - (a)))
#define dot(a,b)            ((conj(a) * (b)).real())
#define cross(a,b)          ((conj(a) * (b)).imag())
#define rotate(v,t)         (polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m)        ((conj((p) / (m))) * (m))
#define normalize(p)        ((p) / length(p))
#define same(a,b)           (length(vec(a, b)) < EPS)
#define mid(a,b)            (((a) + (b)) / point(2, 0))

bool collinear(const point &a, const point &b) { return fabs(cross(a, b)) < EPS; }

bool ccw(const point &a, const point& b) { return cross(a, b) > 0; }

point intersect(const point &a, const point &b, const point &p, const point &q) { // handle parallel
    double d1 = cross(p - a, b - a);
    double d2 = cross(q - a, b - a);
    return (d1 * q - d2 * p) / (d1 - d2);
}

istream& operator>>(istream& in, point& p) {
    double x, y; 
    in >> x >> y;
    p = {x, y};
    return in;
}

point p[6];

point& a = p[0];
point& b = p[1];
point& c = p[2];
point& d = p[3];
point& e = p[4];
point& f = p[5];

double calc(double mid) {
    point h = polar(mid, arg(c - a)) + a;
    return fabs(cross(a - h, a - b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        for (auto& x : p)
            cin >> x;

        bool done = true;
        for (auto &x : p) 
            done &= fabs(x.X) < EPS && fabs(x.Y) < EPS;

        if (done)
            break;

        double EDF = fabs(cross(e - f, d - f) / 2.0);

        double l = 0;
        for (double size = MOD; size > EPS; size /= 2.0) {
            double mid = l + size / 2;
            if (calc(mid) < EDF) 
                l = mid;
        }

        point h = polar(l, arg(c - a)) + a;
        point g = h + b - a;

        cout << fixed << setprecision(3) << g.X << " " << g.Y << " " << h.X << " " << h.Y << endl;
    }

}
