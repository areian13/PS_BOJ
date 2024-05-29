#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        char start;
        cin >> n >> start;

        for (int i = 0; i < n; i++)
        {
            string result(i + 1, (start + i - 'A') % 26 + 'A');
            cout << result << '\n';
        }
        cout << '\n';
    }
}