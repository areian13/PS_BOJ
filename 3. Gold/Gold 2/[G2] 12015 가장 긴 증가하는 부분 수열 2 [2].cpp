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

    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        auto p = lower_bound(lis.begin(), lis.end(), a);
        if (p == lis.end()) lis.push_back(a);
        else *p = a;
    }
    cout << lis.size() << '\n';
}