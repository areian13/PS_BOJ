#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c;
    cin >> c;

    int result = 0;
    for (int i = 0; i < c; i++)
    {
        string s;
        cin >> s;

        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.substr(i, 3) == "for")
                cnt++, i += 2;
            else if (s.substr(i, 5) == "while")
                cnt++, i += 4;
        }
        result = max(result, cnt);
    }
    cout << result << '\n';
}