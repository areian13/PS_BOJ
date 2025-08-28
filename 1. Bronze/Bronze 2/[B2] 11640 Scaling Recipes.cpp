#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Elem
{
    string n;
    double w, r;
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int r, p, d;
        cin >> r >> p >> d;

        vector<Elem> elems(r);
        double mw;
        for (auto& [n, w, r] : elems)
        {
            cin >> n >> w >> r;
            if (r == 100.0)
                mw = w;
        }

        printf("Recipe # %d\n", tc);
        for (auto& [n, w, r] : elems)
        {
            double result = (1. * d / p) * (mw * r / 100);
            printf("%s %.1lf\n", n.c_str(), result);
        }
        printf("----------------------------------------\n");
    }
}