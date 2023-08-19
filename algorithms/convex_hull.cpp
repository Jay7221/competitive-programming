#include<bits/stdc++.h>
using namespace std;
class Point
{
	public:
		int x, y;
		bool operator < (Point P) const 
		{
			if(x == P.x)
			{
				return (y < P.y);
			}
			return (x < P.x);
		}
};
istream& operator>>(istream &in, Point &p)
{
	in >> p.x >> p.y;
	return in;
}
ostream& operator<<(ostream &out, Point &p)
{
	out << p.x << ' ' << p.y;
	return out;
}


bool clockwise(Point a, Point b, Point c)
{
	return ((a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) > 0);
}
bool anti_clockwise(Point a, Point b, Point c)
{
	return ((a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) < 0);
}
bool collinear(Point a, Point b, Point c)
{
	return ((a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y)) == 0);
}
vector<Point> convex_hull(vector<Point> points)
{
	int n = points.size();
	if(n <= 2)
	{
		return points;
	}
	sort(points.begin(), points.end());
	vector<Point> up, down;

	Point first = points[0];
	Point last = points.back();

	up.push_back(first);
	down.push_back(first);

	for(int i = 1; i < n; ++i)
	{
		if(clockwise(first, points[i], last))
		{
			while(up.size() >= 2 && !clockwise(up[up.size() - 2], up[up.size() - 2], points[i] ))
			{
				up.pop_back();
			}
		}
		if(anti_clockwise(first, points[i], last))
		{
			while(down.size() >= 2 && !anti_clockwise(down[down.size() - 2], down[down.size() - 2], points[i] ))
			{
				down.pop_back();
			}
		}

	}
	up.push_back(last);
	down.push_back(last);
	vector<Point> convexHull;

	convexHull.push_back(first);
	for(int i = 1; i < up.size() - 1; ++i)
	{
		convexHull.push_back(up[i]);
	}
	for(int i = 1; i < down.size() - 1; ++i)
	{
		convexHull.push_back(down[i]);
	}
	convexHull.push_back(last);
	return convexHull;
}
void solve()
{
	int n;
	cin >> n;
	vector<Point> points(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> points[i];
	}
	vector<Point> convex_hull_vector = convex_hull(points);
	for(Point p : convex_hull_vector)
	{
		cout << p << '\n';
	}
}
int main()
{
	int t;
	t = 1;
	while(t--)
	{
		solve();
	}
	return 0;
}
