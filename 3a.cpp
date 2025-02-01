#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

class point {
    public:
    double x, y;

    point () { }

    point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
    point (const point &p) {
        this->x = p.x;
        this->y = p.y;
    }

};

double distance(point &a, point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double bruteforce(vector<point> &points, int lo, int hi) {
    double dist = DBL_MAX;
    for(int i = lo; i < hi; i++) {
        for(int j = i+1; j < hi; j++) {
            dist = min(dist, distance(points[i], points[j]));
        }
    }
    return dist;
}

double stripClosest(vector<point> &strip, double dist) {
    int n = strip.size();
    sort(all(strip), [] (const point &a, const point &b) { 
        return a.y < b.y;
        });
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n && j - i < 7; j++) {
            if (strip[j].y - strip[i].y >= dist) break;
            dist = min(dist, distance(strip[i], strip[j]));
        }
    }

    return dist;
}

double closestDist(vector<point> &points, vector<point> &y_sorted, int lo, int hi) {
    if(hi - lo <= 3) return bruteforce(points, lo, hi);

    int mid = (lo + hi) / 2;

    vector<point> y_left, y_right;
    for(auto p: y_sorted) {
        if(p.x <= points[mid].x) y_left.push_back(p);
        else y_right.push_back(p);
    }
    double leftDist = closestDist(points, y_left, lo, mid);
    double rightDist = closestDist(points, y_right, mid, hi);
    double dist = min(leftDist, rightDist);

    vector<point> strip;
    for(auto p: y_sorted) {
        if(abs(points[mid].x - p.x) < dist) {
            strip.push_back(p);
        }
    }

    return stripClosest(strip, dist);
}

int main() {
    int n; cin >> n;
    vector<point> v(n);
    for(int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        v[i] = point(x, y);
    }

    vector<point> x_sorted(all(v));
    vector<point> y_sorted(all(v));

    sort(all(x_sorted), [] (const point &a, const point &b) { 
        return a.x < b.x;
        });
    sort(all(y_sorted), [] (const point &a, const point &b) { 
        return a.y < b.y;
        });
    
    double ans = closestDist(x_sorted, y_sorted, 0, n);
    cout << ans << endl;
}
