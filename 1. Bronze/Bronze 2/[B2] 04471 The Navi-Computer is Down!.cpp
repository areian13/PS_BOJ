#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double Dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;


    while (tc--)
    {

        string a;
        double x1, y1, z1;
        cin.ignore();
        getline(cin, a) >> x1 >> y1 >> z1;

        string b;
        double x2, y2, z2;
        cin.ignore();
        getline(cin, b) >> x2 >> y2 >> z2;

        printf("%s to %s: %.2lf\n", a.c_str(), b.c_str(), Dist(x1, y1, z1, x2, y2, z2));
    }
}