#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string a, b;
        cin >> a >> b;

        cout << "Distances: ";

        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            int result = b[i] - a[i] + (b[i] < a[i]) * 26;
            cout << result << ' ';
        }
        cout << '\n';
    }
}