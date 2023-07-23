#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point{
    int x, y;
    Point(){
        x = 0, y = 0;
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (Point p) const {
        if(x < p.x){
            return true;
        }
        if(x > p.x){
            return false;
        }
        return (y < p.y);
    }
    bool operator == (Point p) const {
        return ((x == p.x) && (y == p.y));
    }
};
bool cw(Point a, Point b, Point c){
    return ((a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) < 0);
}
bool ccw(Point a, Point b, Point c){
    return ((a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) > 0);
}
vector<Point> convex_hull(vector<Point> &points){
    vector<Point> hull;
    sort(points.begin(), points.end());

    vector<Point> up, down;
    Point first = points[0], last = points.back();
    up.push_back(first);
    down.push_back(first);

    int n = points.size();
    for(int i = 1; i < points.size(); ++i){
        if(i == n - 1 || cw(first, points[i], last)){
            while(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], points[i])){
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if(i == n - 1 || ccw(first, points[i], last)){
            while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], points[i])){
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }
    for(Point p : up){
        hull.push_back(p);
    }
    for(Point p : down){
        hull.push_back(p);
    }
    sort(hull.begin(), hull.end());
    hull.resize(unique(hull.begin(), hull.end()) - hull.begin());
    return hull;
}
int main(){
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].x >> v[i].y;
    }
    for(Point p : convex_hull(v)){
        cout << p.x << ' ' << p.y << '\n';
    }
    return 0;
}
