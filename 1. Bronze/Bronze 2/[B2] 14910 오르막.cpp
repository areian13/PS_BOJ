#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int p = -INF;
    bool result = true;
    while (true)
    {
        int a;
        cin >> a;

        if (cin.eof())
            break;

        result &= (p <= a);
        p = a;
    }

    cout << (result ? "Good" : "Bad") << '\n';
}