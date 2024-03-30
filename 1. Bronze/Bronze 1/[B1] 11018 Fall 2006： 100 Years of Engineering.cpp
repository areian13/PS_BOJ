#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define G 9.81

struct Fuel
{
    double m, t, f;
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        double M;
        cin >> n >> M;

        vector<Fuel> fuel(n);
        for (int i = 0; i < n; i++)
        {
            double m, t, f;
            cin >> m >> t >> f;

            fuel[i] = { m,t,f };
            M += m;
        }

        double v = 0;
        double result = 0;
        for (int i = 0; i < n; i++)
        {
            double a = fuel[i].f / M - G;

            result += v * fuel[i].t + 0.5 * a * fuel[i].t * fuel[i].t;
            v += a * fuel[i].t;
            M -= fuel[i].m;
        }

        printf("Data Set %d:\n%.2lf\n\n", t, result);
    }
}