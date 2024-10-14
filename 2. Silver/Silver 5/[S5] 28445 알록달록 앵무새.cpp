#include <iostream>
#include <array>
#include <string>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Parrot
{
    array<string, 2> color;

    friend bool operator<(const Parrot& a, const Parrot& b)
    {
        if (a.color[0] != b.color[0])
            return a.color[0] < b.color[0];
        return a.color[1] < b.color[1];
    }
};

int main()
{
    FastIO;

    array<string, 4> color;
    for (int i = 0; i < 4; i++)
        cin >> color[i];

    set<Parrot> result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            result.insert({ color[i],color[j] });
    }
    for (auto i = result.begin(); i != result.end(); i++)
        cout << i->color[0] << ' ' << i->color[1] << '\n';
}