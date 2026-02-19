#include <iostream>
#include <ctime>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 8140;

int main()
{
    FastIO;

    srand((unsigned)time(NULL));
    for (int i = 0; i < 814; i++)
    {
        int x = rand() % (MAX * 2 + 1) - MAX;
        int y = rand() % (MAX * 2 + 1) - MAX;
        cout << x << ' ' << y << '\n';
    }
}