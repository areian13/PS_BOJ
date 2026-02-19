#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(b.begin(), b.end(),
        [](const long long& a, const long long& b)
        {
            if (a * 2 == b) return true;
            if (b * 2 == a) return false;
            if (a * 3 == b) return false;
            if (b * 3 == a) return true;
            return a < b;
        }
    );

    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << '\n';
}