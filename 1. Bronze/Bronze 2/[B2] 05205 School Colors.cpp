#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct RGB
{
    int r, g, b;

    friend double operator-(const RGB & a, const RGB & b)
    {
        return sqrt(pow(a.r - b.r, 2) + pow(a.g - b.g, 2) + pow(a.b - b.b, 2));
    }
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        vector<RGB> rgb(n);
        for (int i = 0; i < n; i++)
        {
            int r, g, b;
            cin >> r >> g >> b;

            rgb[i] = { r,g,b };
        }

        double maxDiff = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                maxDiff = max(maxDiff, rgb[i] - rgb[j]);
        }

        vector<array<int, 2>> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (maxDiff == rgb[i] - rgb[j])
                    result.push_back({ i + 1,j + 1 });
            }
        }

        printf("Data Set %d:\n", t);
        for (array<int, 2>& idx : result)
            printf("%d %d\n", idx[0], idx[1]);
    }
}