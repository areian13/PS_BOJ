#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define COUNT 3

struct Snack
{
    char name;
    int c, w;
};

char GoodSnack(vector<Snack>& snacks)
{
    double goodRatio = 0;
    int goodIdx = -1;

    for (int i = 0; i < COUNT; i++)
    {
        double w = snacks[i].w * 10;
        double c = snacks[i].c * 10;

        if (c >= 5'000)
            c -= 500;

        double r = w / c;
        if (r > goodRatio)
        {
            goodRatio = r;
            goodIdx = i;
        }
    }

    return snacks[goodIdx].name;
}

int main()
{
    FastIO;

    vector<Snack> snacks(COUNT);
    string names = "SNU";
    for (int i = 0; i < COUNT; i++)
    {
        snacks[i].name = names[i];
        cin >> snacks[i].c >> snacks[i].w;
    }

    char result = GoodSnack(snacks);
    cout << result << '\n';
}