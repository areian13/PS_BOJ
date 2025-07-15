#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<int> a(4);
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum + 300 <= 1800)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';

}