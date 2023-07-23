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
};
vector<Point> convex_hull(vector<Point> &v){
    auto cmp = [](Point a, Point b){
        return (a.x == b.x ? (a.y < b.y) : (a.x < b.x));
    };
    auto orientation = [](Point a, Point b, Point c){
        ll x = a.x * 1ll * (c.y - b.y) + b.x * 1ll * (a.y - c.y) + c.x * 1ll * (b.y - a.y);
        if(x > 0){
            return 1;
        }
        if(x < 0){
            return -1;
        }
        return 0;
    };

    vector<Point> hull;
    sort(v.begin(), v.end(), cmp);
    Point p0 = v[0];
    auto dist = [](Point a, Point b){
        return ((a.x - b.x) * 1ll * (a.x - b.x) + (a.y - b.y) * 1ll * (a.y - b.y));
    };
    auto cmp2 = [p0, &orientation, &dist](Point a, Point b){
        int o = orientation(p0, a, b);
        if(o == 0){
            return (dist(a, p0) < dist(b, p0));
        }
        return (o > 0);
    };
    sort(v.begin(), v.end(), cmp2);
    for(Point p : v){
        while(hull.size() > 1){
            int n = hull.size();
            if(orientation(hull[n - 2], hull[n - 1], p) <= 0){
                hull.pop_back();
            }
            else{
                break;
            }
        }
        hull.push_back(p);
    }
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
