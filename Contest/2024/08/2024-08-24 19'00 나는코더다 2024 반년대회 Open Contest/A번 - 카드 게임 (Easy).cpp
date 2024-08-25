#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountCard(int h, vector<int>& d)
{
    int n = d.size();

    for (int i = 0; i < n; i++)
    {
        h -= d[i];

        if (h <= 0)
            return i + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, h;
    cin >> n >> h;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int result = CountCard(h, d);
    cout << result << '\n';
}