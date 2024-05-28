#include <iostream>
#include <cstdio>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 6

int main()
{
    FastIO;

    array<int, SIZE> len = { 0, };
    for (int i = 0; i < SIZE; i++)
    {
        string str;
        getline(cin, str);

        len[i] = str.size() - (str[str.size() - 1] == ' ');
    }
    printf("Latitude %d:%d:%d\n", len[0], len[1], len[2]);
    printf("Longitude %d:%d:%d\n", len[3], len[4], len[5]);
}