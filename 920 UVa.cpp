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
#define dist(a, b)          (abs((b) - (a)))
#define dot(a,b)            ((conj(a) * (b)).real())
#define cross(a,b)          ((conj(a) * (b)).imag())
#define rotate(v,t)         (polar(v, t))
#define rotateabout(v,t,a)  (rotate(vec(a, v), t) + (a))
#define reflect(p,m)        ((conj((p) / (m))) * (m))
#define normalize(p)        ((p) / length(p))
#define same(a,b)           (abs(vec(a, b)) < EPS)
#define mid(a,b)            (((a) + (b)) / point(2, 0))

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

ll t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        vector<point> p(n);
        for (int i = 0; i < n; ++i)
            cin >> p[i];

        sort(p.begin(), p.end(), [](const point& p1, const point& p2) {
                return p1.X > p2.X;
                });

        double maxy = 0.0, ans = 0.0;
        for (int i = 1; i < n; ++i) {
            if (p[i].Y > maxy) {
                point v = p[i] - p[i - 1];
                point a = p[i - 1] + point((maxy - p[i - 1].Y) * v.X / v.Y, maxy - p[i - 1].Y);
                maxy = p[i].Y;
                ans += dist(a, p[i]);
            }
        }

        cout << fixed << setprecision(2) << ans << endl;
    }
}
