#include <iostream>
#include <climits>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    while (true)
    {
        string t;
        cin >> t;

        if (cin.eof())
            break;

        if (t.size() != 10)
        {
            int value = stoi(t);
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
    }

    cout << minValue << ' ' << maxValue << '\n';
}