#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Dist(string& a, string& b)
{
    int result = 0;
    for (int i = 0; i < 4; i++)
        result += (a[i] != b[i]);
    return result;
}

int MinMentalDist(vector<string>& mbtis)
{
    int n = mbtis.size();

    if (n > 32)
        return 0;

    int result = INT_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int distAB = Dist(mbtis[i], mbtis[j]);
            for (int k = j + 1; k < n; k++)
            {
                int dist = distAB + Dist(mbtis[j], mbtis[k]) + Dist(mbtis[k], mbtis[i]);
                result = min(result, dist);
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<string> mbtis(n);
        for (int i = 0; i < n; i++)
            cin >> mbtis[i];

        int result = MinMentalDist(mbtis);
        cout << result << '\n';
    }
}