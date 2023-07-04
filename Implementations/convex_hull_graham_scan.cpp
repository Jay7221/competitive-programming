class ConvexHull{
    class Point{
        double x, y;
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
            while(i >= 0 && collinear(p0, a[i], back())){
                --i;
            }
            reverse(a.begin() + i + 1, a.end());
        }

        vector<Point> st;
        for(int i = 0; i < a.size(); ++i){
            while(st.size() > 1 && clockwise(st[st.size() -2], st.back(), a[i], include_collinear)){
                st.pop_back();
            }
        }
        return st;
    }
};