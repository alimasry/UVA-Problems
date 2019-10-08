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

#define X real()
#define Y imag()
#define cross(a,b) ((conj(a) * (b)).imag())

struct line {
    point st, en;
    line(point st, point en) : st(st), en(en) {}
};

bool onLine(point p, point a, point b) {
    return fabs(abs(p - a) + abs(p - b) - abs(a - b)) < EPS;
}

double orient(point a, point b, point c) {
    return cross(b - a, c - a);
}

bool intersect(line l1, line l2) {
    point a = l1.st, b = l1.en;
    point c = l2.st, d = l2.en;

    if (fabs(cross(b - a, d - c)) < EPS) 
        return onLine(c, a, b) || onLine(d, a, b);

    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);

    return oa * ob < EPS && oc * od < EPS;
}

bool isInside(point p, point a, point b, point c, point d) {
    return fabs((fabs(cross(p - a, p - b)) + fabs(cross(p - b, p - c)) + fabs(cross(p - c, p - d)) + fabs(cross(p - d, p - a))) / 2.0 
                - fabs(cross(a - b, a - d))) < EPS;
}

ll n;
double x[4], y[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    while (n--) {
        for (int i = 0; i < 4; ++i)
            cin >> x[i] >> y[i];

        point st(x[0], y[0]), en(x[1], y[1]);

        line l(st, en);

        point a(x[2], y[2]);
        point b(x[2], y[3]);
        point c(x[3], y[3]);
        point d(x[3], y[2]);

        line rec[] = {line(a, b), line(b, c), line(c, d), line(d, a)};

        bool ok = isInside(l.st, a, b, c, d) || isInside(l.en, a, b, c, d);

        if (abs(l.en - l.st) > EPS) {
            for (int i = 0; i < 4; ++i)
                ok |= intersect(l, rec[i]);
        }

        cout << (ok ? "T" : "F") << endl;
    }
}
