#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int s, n, w;
    cin >> s >> n >> w;

    int a = max(s - 100, 0) * 25 + n * 15 + w * 20;
    int b = max(s - 250, 0) * 45 + n * 35 + w * 25;

    printf("Plan A costs %.2f\n", (float)a / 100);
    printf("Plan B costs %.2f\n", (float)b / 100);

    if (a == b)
        printf("Plan A and B are the same price.\n");
    else
        printf("Plan %c is cheapest.\n", (a < b ? 'A' : 'B'));
}