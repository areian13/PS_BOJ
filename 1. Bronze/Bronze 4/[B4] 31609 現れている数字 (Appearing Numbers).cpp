#include <iostream>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    set<int> result;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        result.insert(a);
    }

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << '\n';
}