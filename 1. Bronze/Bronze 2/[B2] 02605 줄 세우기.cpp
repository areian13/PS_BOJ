#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        result.insert(result.end() - s, i);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] + 1 << ' ';
    cout << '\n';
}