#include <bits/stdc++.h>

using namespace std;


long double eps = 1e-6;

struct point
{
    long double x, y;
};

struct line
{
    long double a, b, c;
    int lf (point p)
    {
        if (a*p.x + b*p.y + c > 0)
            return 1;
        else
            return -1;
    }
};

struct circle
{
    point o;
    long double r;
};

long double dis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


pair <point, point> circle_line(circle a, line b)
{
    long double x0 = -b.a*b.c/(b.a*b.a+b.b*b.b), y0 = -b.b*b.c/(b.a*b.a+b.b*b.b);
    long double d = a.r*a.r - b.c*b.c/(b.a*b.a+b.b*b.b);
    long double mult = sqrt (d / (b.a*b.a+b.b*b.b));
    long double ax, ay, bx, by;
    ax = x0 + b.b * mult;
    bx = x0 - b.b * mult;
    ay = y0 - b.a * mult;
    by = y0 + b.a * mult;
    return {{ax, ay}, {bx, by}};
}

int circle_circle_intersection(long double x0, long double y0, long double r0,
                               long double x1, long double y1, long double r1,
                               long double &xi, long double &yi,
                               long double &xi_prime, long double &yi_prime)
{
  long double a, dx, dy, d, h, rx, ry;
  long double x2, y2;
  dx = x1 - x0;
  dy = y1 - y0;
  d = hypot(dx,dy);
  if (d > (r0 + r1))
  {
    return 0;
  }
  if (d < fabs(r0 - r1))
  {
    return 0;
  }
  a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;
  x2 = x0 + (dx * a/d);
  y2 = y0 + (dy * a/d);
  h = sqrt((r0*r0) - (a*a));
  rx = -dy * (h/d);
  ry = dx * (h/d);
  xi = x2 + rx;
  xi_prime = x2 - rx;
  yi = y2 + ry;
  yi_prime = y2 - ry;

  return 1;
}

point findpoint(circle a, circle b, point c)
{
    /*line l1, l2;
    l1.a = -2*(b.o.x - a.o.x);
    l1.b = -2*(b.o.y - a.o.y);
    l1.c = ((b.o.x - a.o.x)*(b.o.x - a.o.x) + (b.o.y - a.o.y)*(b.o.y - a.o.y) + a.r*a.r - b.r*b.r);
    point p1 = circle_line(a, l1).first;
    point p2 = circle_line(a, l1).second;*/
    point p1, p2;
    circle_circle_intersection(a.o.x, a.o.y, a.r, b.o.x, b.o.y, b.r, p1.x, p1.y, p2.x, p2.y);
    line l2 = {b.o.y - a.o.y, - b.o.x + a.o.x, -a.o.x*(b.o.y - a.o.y)+a.o.y*(b.o.x-a.o.x)};
    if (l2.lf(c) == l2.lf(p1))
        return p2;
    else
        return p1;
}


long double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

point line_line(line m, line n) {
    point res;
    long double zn = det(m.a, m.b, n.a, n.b);
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return res;
}



int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    circle bab, aab;
    bab.o = B;
    aab.o = A;
    bab.r = aab.r = dis(A, B);
    point D = findpoint(bab, aab, C);
    circle cac, aac;
    cac.o = C;
    aac.o = A;
    cac.r = aac.r = dis(C, A);
    point E = findpoint(cac, aac, B);
    line CD = {D.y - C.y, - D.x + C.x, -C.x*(D.y - C.y)+C.y*(D.x-C.x)};
    line BE = {E.y - B.y, - E.x + B.x, -B.x*(E.y - B.y)+B.y*(E.x-B.x)};
    point ans = line_line(CD, BE);
    if (abs(ans.x) < eps)
        ans.x = 0;
    if (abs(ans.y) < eps)
        ans.y = 0;
    if (dis(ans, A) + dis(ans,B) + dis(ans, C) > dis(A, C) + dis(B, C))
        ans = C;
    if (dis(ans, A) + dis(ans,B) + dis(ans, C) > dis(B, A) + dis(C, A))
        ans = A;
    if (dis(ans, A) + dis(ans,B) + dis(ans, C) > dis(A, B) + dis(C, B))
        ans = B;
    cout << fixed << setprecision(10) << ans.x << " " << ans.y;
    return 0;
}
