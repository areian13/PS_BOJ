#include <iostream>
#include <cstdio>
#include <array>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SUIT 4
#define VALUE 13
#define SIZE (SUIT * VALUE)

int main()
{
    FastIO;

    array<string, SUIT> suit = { "Clubs","Diamonds","Hearts","Spades" };
    array<string, VALUE> value = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };

    int n;
    cin >> n;

    vector<array<int, SIZE>> suffle(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> suffle[i][j];
            suffle[i][j]--;
        }
    }

    array<int, SIZE> deck;
    for (int i = 0; i < SIZE; i++)
        deck[i] = i;

    while (true)
    {
        int k;
        cin >> k;

        if (cin.eof())
            break;

        k--;
        array<int, SIZE> temp;
        for (int i = 0; i < SIZE; i++)
            temp[i] = deck[suffle[k][i]];
        deck = temp;

        for (int i = 0; i < SIZE; i++)
            printf("%s of %s\n", value[deck[i] % VALUE].c_str(), suit[deck[i] / VALUE].c_str());
        printf("\n");
    }
}