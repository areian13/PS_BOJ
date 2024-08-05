#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Medal
{
    int gold, silver, bronze;
    int cnt;

    friend istream& operator>>(istream& is, Medal& m)
    {
        is >> m.gold >> m.silver >> m.bronze;
        m.cnt = m.gold + m.silver + m.bronze;
        return is;
    }
    friend ostream& operator<<(ostream& os, Medal& m)
    {
        os << m.gold << ' ' << m.silver << ' ' << m.bronze;
        return os;
    }
    friend bool operator>(Medal& a, Medal& b)
    {
        if (a.gold != b.gold)
            return a.gold > b.gold;
        if (a.silver != b.silver)
            return a.silver > b.silver;
        return a.bronze > b.bronze;
    }
};

string HowWin(Medal& a, Medal& b)
{
    if (a.cnt > b.cnt && a > b)
        return "both";
    if (a.cnt > b.cnt)
        return "count";
    if (a > b)
        return "color";
    return "none";
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        Medal USA, RUS;
        cin >> USA >> RUS;

        cout << USA << ' ' << RUS << '\n';

        string result = HowWin(USA, RUS);
        cout << result << "\n\n";
    }
}