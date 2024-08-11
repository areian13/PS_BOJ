#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Info
{
    int p, y;
    string s;


    friend istream& operator>>(istream& is, Info& i)
    {
        is >> i.p >> i.y >> i.s;
        return is;
    }
    friend ostream& operator<<(ostream& os, Info& i)
    {
        os << i.p << ' ' << i.y << ' ' << i.s;
        return os;
    }
};

int main()
{
    FastIO;

    array<Info, 3> team;
    for (int i = 0; i < 3; i++)
        cin >> team[i];

    sort(team.begin(), team.end(), [](const Info& a, const Info& b) {
        return a.y % 100 < b.y % 100;
        }
    );
    for (int i = 0; i < 3; i++)
        cout << team[i].y % 100;
    cout << '\n';

    sort(team.begin(), team.end(), [](const Info& a, const Info& b) {
        return a.p > b.p;
        }
    );
    for (int i = 0; i < 3; i++)
        cout << team[i].s[0];
    cout << '\n';
}