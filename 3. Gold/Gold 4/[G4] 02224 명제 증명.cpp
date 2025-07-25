#include <iostream>
#include <cstdio>
#include <array>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 52

int Indexing(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}
char Charing(int idx)
{
    if (0 <= idx && idx <= 25)
        return 'A' + idx;
    return 'a' + idx - 26;
}

int main()
{
    FastIO;

    int n;
    cin>>n;

    array<array<bool, SIZE>, SIZE> isProven = { false, };
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);

        int a = Indexing(str[0]);
        int b = Indexing(str[5]);

        isProven[a][b] = true;
    }
    for (int i = 0; i < SIZE; i++)
        isProven[i][i] = true;

    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
                isProven[i][j] |= (isProven[i][k] && isProven[k][j]);
        }
    }

    vector<pair<char, char>> result;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j || !isProven[i][j])
                continue;

            result.push_back({ Charing(i), Charing(j) });
        }
    }

    printf("%d\n", (int)result.size());
    for (pair<char, char>& propose : result)
        printf("%c => %c\n", propose.first, propose.second);
}