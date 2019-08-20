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

const int N = 105;

struct point {
    double x, y;
    bool operator< (const point& other) const {
        return x > other.x;
    }
} p[N];

double dist(point a, point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return hypot(dx, dy);
}

struct line { double a, b, c; };

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (p1.x - p2.x == 0) {
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

// ax + by + c = 0
// x = -(by + c) / a
point get(line l, double y) { // given y return the x
    return (point) {-(l.b * y + l.c) / l.a, y};
}

ll t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        sort(p, p + n);

        double ans = 0.0, maxy = p[0].y;
        for (int i = 1; i < n; ++i) {
            if (maxy <= p[i].y) {
                line l;
                pointsToLine(p[i], p[i - 1], l);
                ans += dist(p[i], get(l, maxy));
                maxy = max(maxy, p[i].y);
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}
