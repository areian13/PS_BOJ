#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Village
{
    int x, a;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Village> villages(n);
    long long aTotal = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> villages[i].x >> villages[i].a;
        aTotal += villages[i].a;
    }

    sort(villages.begin(), villages.end(),
        [](const Village& a, const Village& b)
        {
            return a.x < b.x;
        }
    );

    long long aSum = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        aSum += villages[i].a;
        if (aSum >= (aTotal + 1) / 2)
        {
            idx = i;
            break;
        }
    }

    int result = villages[idx].x;
    cout << result << '\n';
}