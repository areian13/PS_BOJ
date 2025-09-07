#include <iostream>
#include <unordered_set>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_set<double> canSee;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        canSee.insert(atan2(y, x));
    }

    int result = canSee.size();
    cout << result << '\n';
}