#include <iostream>
#include <array>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 26> points;
    points['L' - 'A'] = 120;
    points['S' - 'A'] = 150;
    points['B' - 'A'] = 150;
    points['N' - 'A'] = 40;
    points['C' - 'A'] = 160;
    points['D' - 'A'] = 100;
    points['R' - 'A'] = 100;
    points['O' - 'A'] = 100;

    while (true)
    {
        string a;
        cin >> a;

        if (a == "#")
            break;

        unordered_map<string, int> users;
        while (true)
        {
            string s;
            cin >> s;

            if (s == "00A")
                break;

            char c;
            cin >> c;

            users[s] += points[c - 'A'];
        }

        int result = 0;
        for (auto user : users)
            result += (user.second >= 200);
        cout << a <<' '<< result << '\n';
    }
}