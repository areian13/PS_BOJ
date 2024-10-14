#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i % 2 == 0 ? i / 2 : n - 1 - i / 2] = i + 1;

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}