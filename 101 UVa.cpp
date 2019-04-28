#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 30;

int n, location[N];
stack<int> pile[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        location[i] = i;
        pile[i].push(i);
    }
    string command;
    while (cin >> command && command != "quit") {
        string op; 
        int a, b; cin >> a >> op >> b;
        if (a == b || location[a] == location[b]) continue;
        if (command == "move") {
            if (op == "onto") {
                while (pile[location[a]].top() != a) {
                    int r = pile[location[a]].top();
                    pile[r].push(r);
                    location[r] = r;
                    pile[location[a]].pop();
                }
                pile[location[a]].pop();
                while (pile[location[b]].top() != b) {
                    int r = pile[location[b]].top();
                    pile[r].push(r);
                    location[r] = r;
                    pile[location[b]].pop();
                }
                location[a] = location[b];
                pile[location[b]].push(a);
            } else {
                while (pile[location[a]].top() != a) {
                    int r = pile[location[a]].top();
                    pile[r].push(r);
                    location[r] = r;
                    pile[location[a]].pop();
                }
                pile[location[a]].pop();
                location[a] = location[b];
                pile[location[b]].push(a);
            }
        } else {
            if (op == "onto") {
                stack<int> temp;
                while (pile[location[a]].top() != a) {
                    int r = pile[location[a]].top();
                    temp.push(r);
                    pile[location[a]].pop();
                }
                pile[location[a]].pop();
                while (pile[location[b]].top() != b) {
                    int r = pile[location[b]].top();
                    pile[r].push(r);
                    location[r] = r;
                    pile[location[b]].pop();
                }
                location[a] = location[b];
                pile[location[b]].push(a);
                while (!temp.empty()) {
                    int r = temp.top();
                    location[r] = location[b];
                    pile[location[b]].push(r);
                    temp.pop();
                }
            } else  {
                stack<int> temp;
                while (pile[location[a]].top() != a) {
                    int r = pile[location[a]].top();
                    temp.push(r);
                    pile[location[a]].pop();
                }
                pile[location[a]].pop();
                location[a] = location[b];
                pile[location[b]].push(a);
                while (!temp.empty()) {
                    int r = temp.top();
                    location[r] = location[b];
                    pile[location[b]].push(r);
                    temp.pop();
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i  << ":";
        stack<int> tmp;
        while (!pile[i].empty()) {
            tmp.push(pile[i].top());
            pile[i].pop();
        }
        while (!tmp.empty()) {
            cout << ' ' << tmp.top();
            tmp.pop();
        }
        cout << endl;
    }
}
