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

