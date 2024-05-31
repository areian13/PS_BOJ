#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SuitIndex(char suit, string& suits)
{
    for (int i = 0; i < 4; i++)
    {
        if (suit == suits[i])
            return i;
    }
    return -1;
}

string NoCard(string& suits, array<array<bool, 13>, 4>& isExistedCard)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (!isExistedCard[i][j])
                return suits[i] + (" " + to_string(j + 1));
        }
    }
}

int main()
{
    FastIO;

    array<array<bool, 13>, 4> isExistedCard = { false };
    string suits = "SBVK";

    for (int i = 0; i < 51; i++)
    {
        char suit;
        int num;
        cin >> suit >> num;

        isExistedCard[SuitIndex(suit, suits)][num - 1] = true;
    }

    string result = NoCard(suits, isExistedCard);
    cout << result << '\n';
}