#include <bits/stdc++.h>

using namespace std;

// #pragma GCC oPointimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,avx512,fma")

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double

#define PI 3.1415926535897932384626433832795l

// -------------------------<rng>-------------------------
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

struct Point
{
    ll x, y;
    bool operator<(Point p) const
    {
        return ((x == p.x) ? (y < p.y) : (x < p.x));
    }
    bool operator==(Point p) const
    {
        return ((x == p.x) && (y == p.y));
    }
};

vector<Point> convex_hull(vector<Point> &a, bool include_collinear = false)
{
    auto orientation = [](Point a, Point b, Point c)
    {
        ll v = a.x * 1ll * (b.y - c.y) + b.x * 1ll * (c.y - a.y) + c.x * 1ll * (a.y - b.y);
        if (v < 0)
            return -1; // clockwise
        if (v > 0)
            return +1; // counter-clockwise
        return 0;
    };

    auto cw = [&orientation](Point a, Point b, Point c, bool include_collinear)
    {
        // check if points a, b, c are clockwise
        int o = orientation(a, b, c);
        return o < 0 || (include_collinear && o == 0);
    };
    auto collinear = [&orientation](Point a, Point b, Point c)
    {
        return orientation(a, b, c) == 0;
    };

    // Find the leftmost point
    Point p0 = *min_element(a.begin(), a.end(),
                            [&orientation](Point a, Point b)
                            {
                                return make_pair(a.y, a.x) < make_pair(b.y, b.x);
                            });

    // Sort points according to the angle made to the left most point
    sort(a.begin(), a.end(),
         [&p0, &orientation](const Point &a, const Point &b)
         {
             int o = orientation(p0, a, b);
             if (o == 0)
             {
                 // if points lie on same angle from p0, then put the close point first
                 return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
             }
             return o < 0;
         });

    // If collinear points are to be included, reverse the points on the line from first to last point
    if (include_collinear)
    {
        int i = (int)a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back()))
        {
            i--;
        }
        reverse(a.begin() + i + 1, a.end());
    }

    vector<Point> hull;
    for (int i = 0; i < (int)a.size(); i++)
    {
        while (hull.size() > 1 && !cw(hull[hull.size() - 2], hull.back(), a[i], include_collinear))
        {
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }

    return hull;
}
bool solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
    }
    int m;
    cin >> m;
    vector<Point> b(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i].x >> b[i].y;
    }
    vector<Point> v;
    for (Point p : a)
    {
        v.push_back(p);
    }
    for (Point p : b)
    {
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    if (v.size() != n + m)
    {
        return false;
    }
    vector<Point> h = convex_hull(v, true);
    sort(h.begin(), h.end());
    sort(a.begin(), a.end());
    return (a == h);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if (solve())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
