#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string bracket;
        cin >> bracket;

        while (true)
        {
            int idx = bracket.find("()");
            if (idx == -1)
                break;
            bracket.replace(idx, 2, "");
        }

        string result = (bracket.empty() ? "YES" : "NO");
        cout << result << '\n';
    }
}