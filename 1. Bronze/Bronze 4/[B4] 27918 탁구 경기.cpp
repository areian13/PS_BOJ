#include <iostream>
#include <cstdio>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;


    int n;
    cin >> n;

    array<int, 2> score = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        char round;
        cin >> round;

        score[round == 'P']++;

        if (abs(score[0] - score[1]) >= 2)
            break;
    }
    printf("%d:%d\n", score[0], score[1]);
}