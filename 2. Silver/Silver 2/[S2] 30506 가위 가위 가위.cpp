#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 100

int Indexing(char c, string& hand)
{
    for (int i = 0; i < 3; i++)
    {
        if (hand[i] == c)
            return i;
    }
}

char NextHand(char c, string& hand)
{
    return hand[(Indexing(c, hand) + 1) % 3];
}
char PrevHand(char c, string& hand)
{
    return hand[(Indexing(c, hand) + 2) % 3];
}

int main()
{
    FastIO;

    int k;
    cin >> k;

    int preK = k;
    string hand = "025";

    string result;
    result.resize(SIZE, '2');
    for (int i = 0; i < SIZE; i++)
    {
        result[i] = NextHand(result[i], hand);
        cout << '?' << ' ' << result << endl;

        cin >> k;

        if (k == preK)
            result[i] = NextHand(result[i], hand);
        else if (k < preK)
            result[i] = PrevHand(result[i], hand);
        preK = k + (k <= preK);
    }
    for (int i = 0; i < SIZE; i++)
        result[i] = NextHand(result[i], hand);

    cout << '!' << ' ' << result << endl;;
}