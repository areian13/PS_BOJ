#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define COUNT 3

struct Skill
{
    int c, d;
};

int TTK(int h, array<Skill, COUNT>& skills)
{
    int result = 0;

    while (h > 0)
    {
        for (int i = 0; i < COUNT; i++)
        {
            if (result % skills[i].c == 0)
                h -= skills[i].d;
        }
        result++;
    }
    result--;

    return result;
}

int main()
{
    FastIO;

    array<Skill, COUNT> skills;
    for (int i = 0; i < COUNT; i++)
        cin >> skills[i].c >> skills[i].d;

    int h;
    cin >> h;

    int result = TTK(h, skills);
    cout << result << '\n';
}