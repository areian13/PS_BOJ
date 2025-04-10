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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxValue = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxValue)
            cout << (char)(i + 'A');
    }
    cout << '\n';
}