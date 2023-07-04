#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Point{
    public:
        double x, y;
        Point(){
            x = 0;
            y = 0;
        }
        Point(double x, double y){
            this -> x = x;
            this -> y = y;
        }
};
int orientation(Point a, Point b, Point c){
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if(v < 0){
        return -1;
    }
    if(v > 0){
        return 1;
    }
    return 0;
}

bool clockwise(Point a, Point b, Point c, bool include_collinear){
    int o = orientation(a, b, c);
    return ((o > 0) || ((o == 0) && include_collinear));
}

bool collinear(Point a, Point b, Point c){
    return (orientation(a, b, c) == 0);
}

vector<Point> convex_hull(vector<Point> a, bool include_collinear = false){
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b){
            return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const Point a, const Point b){
            int o = orientation(p0, a, b);
            if(o == 0){
               return ((p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y)) < ((p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y)); 
            }
            return o < 0;
    });
    if(include_collinear){
        int i = (int)a.size() - 1;
        while(i >= 0 && collinear(p0, a[i], a.back())){
            --i;
        }
        reverse(a.begin() + i + 1, a.end());
    }

    vector<Point> st;
    for(int i = 0; i < a.size(); ++i){
        while(st.size() > 1 && !clockwise(st[st.size() -2], st.back(), a[i], include_collinear)){
            break;
            st.pop_back();
        }
        st.push_back(a[i]);
    }
    return st;
}
void solve(int n){
    if(n == 0){
        return;
    }
    vector<Point> v(n);
    for(int i = 0; i < n; ++i){
        double x, y;
        cin >> x >> y;
        v[i] = Point(x, y);
    }
    vector<Point> vv = convex_hull(v);
    cout << vv.size() << '\n';
    for(Point p : vv){
        cout << p.x << ' ' << p.y << '\n';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1;
    while(n != 0){
        cin >> n;
        solve(n);
    }

    return 0;
}

