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

struct Segment {
    double x1, x2, a;
    bool operator< (const Segment& other) const {
        return x1 < other.x1;
    }
};

ll t, n;

bool equal(double a, double b) {
    return fabs(a - b) < EPS;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;

        vector<Segment> x(n);

        for (int i = 0; i < n; ++i) {
            double y;
            cin >> x[i].x1 >> y >> x[i].x2 >> y >> x[i].a;
            if (x[i].x1 > x[i].x2) swap(x[i].x1, x[i].x2);
        }


        sort(x.begin(), x.end());


        vector<Segment> ans;

        double r = 0.0, curx = x[0].x1;
        while (true) {
            r = 1e15;
            double res = 1;

            for (int i = 0; i < n; ++i) {
                if (!equal(curx, x[i].x1) && curx < x[i].x1) r = min(r, x[i].x1 - EPS);
                if (!equal(curx, x[i].x2) && curx < x[i].x2) r = min(r, x[i].x2 - EPS);
            }

            for (int i = 0; i < n; ++i) {
                if ((equal(curx, x[i].x1) || curx > x[i].x1) && (equal(r, x[i].x2) || r < x[i].x2))
                    res *= x[i].a;
            }

            if (r == 1e15) break;

            ans.push_back({curx, r + EPS, res});

            curx = r + EPS;
        }

        cout << fixed << setprecision(3);

        cout << (int) ans.size() + 2 << endl;
        cout << "-inf " << x[0].x1 << " 1.000" << endl;
        for (auto s : ans)
            cout << s.x1 << ' ' << s.x2 << ' ' << s.a << endl;
        cout << ans.back().x2 << " +inf 1.000" << endl;

        if (t)
            cout << endl;
    }
}
