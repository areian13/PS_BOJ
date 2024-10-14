#include <iostream>
#include <set>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_SCORE 200

struct Gap
{
    int keGap;
    int msGap;

    friend bool operator<(const Gap& a, const Gap& b)
    {
        if (a.keGap != b.keGap)
            return a.keGap < b.keGap;
        return a.msGap < b.msGap;
    }
};

int main()
{
    FastIO;

    int id;
    cin >> id;

    set<Gap> result;
    array<int, 2> ke = { 508,108 };
    array<int, 2> ms = { 212,305 };
    for (int keGap = 0; keGap <= MAX_SCORE; keGap++)
    {
        for (int msGap = 0; msGap <= MAX_SCORE; msGap++)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    int value = (keGap * ke[i] + msGap * ms[j]) * 4763;
                    if (value == id)
                        result.insert({ keGap,msGap });
                }
            }

        }
    }

    cout << result.size() << '\n';
    for (Gap value : result)
        cout << value.keGap << ' ' << value.msGap << '\n';
}