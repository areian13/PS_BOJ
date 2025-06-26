#include <iostream>
#include <cstdio>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int a, b;
        double x, y, z;
        cin >> a >> b >> x >> y >> z;

        if (a == 2)
        {
            double xt = x * cos(y);
            double yt = x * cos(y);
            x = xt, y = yt;
        }
        else if (a == 3)
        {
            double rho = x, t = y, phi = z;
            if (phi > PI)
                phi -= PI * 2;

            z = rho * cos(t);

            double k = sqrt(rho * rho - z * z);
            x = k * cos(phi);
            y = k * sin(phi);
        }

        if (b == 2)
        {
            double r = sqrt(x * x + y * y);
            double phi = r == 0 ? 0 : atan2(y, x);
            if (phi < 0)
                phi += PI * 2;

            x = r, y = phi;
        }
        else if (b == 3)
        {
            double rho = sqrt(x * x + y * y + z * z);
            double t = rho == 0 ? 0 : acos(z / rho);

            double r = sqrt(x * x + y * y);
            double phi = r == 0 ? 0 : atan2(y, x);
            if (phi < 0)
                phi += PI * 2;

            x = rho, y = t, z = phi;
        }

        printf("%.6lf %.6lf %.6lf\n", x, y, z);
    }
}