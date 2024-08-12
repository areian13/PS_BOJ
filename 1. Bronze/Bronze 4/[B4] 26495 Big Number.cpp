#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<array<string, 5>, 10> bigNum = 
    {
        "0000",
        "0  0",
        "0  0",
        "0  0",
        "0000",

        "   1",
        "   1",
        "   1",
        "   1",
        "   1",

        "2222",
        "   2",
        "2222",
        "2",
        "2222",

        "3333",
        "   3",
        "3333",
        "   3",
        "3333",

        "4  4",
        "4  4",
        "4444",
        "   4",
        "   4",

        "5555",
        "5",
        "5555",
        "   5",
        "5555",

        "6666",
        "6",
        "6666",
        "6  6",
        "6666",

        "7777",
        "   7",
        "   7",
        "   7",
        "   7",

        "8888",
        "8  8",
        "8888",
        "8  8",
        "8888",

        "9999",
        "9  9",
        "9999",
        "   9",
        "   9",
    };

    string cmd;
    cin >> cmd;

    for (auto c : cmd)
    {
        for (int i = 0; i < 5; i++)
            cout << bigNum[c - '0'][i] << '\n';
        cout << '\n';
    }
}