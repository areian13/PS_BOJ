#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Weapon
{
    int c, p;
};

bool CanGoAdventure(int x, int s, vector<Weapon>& weapons)
{
    for (Weapon& weapon : weapons)
    {
        if (weapon.c <= x && weapon.p > s)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, x, s;
    cin >> n >> x >> s;

    vector<Weapon> weapons(n);
    for (int i = 0; i < n; i++)
        cin >> weapons[i].c >> weapons[i].p;

    string result = (CanGoAdventure(x, s, weapons) ? "YES" : "NO");
    cout << result << '\n';
}