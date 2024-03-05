#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string keyword, text;
        cin >> keyword >> text;

        int n = keyword.size();
        int m = text.size();

        string result(m, '\0');
        for (int i = 0; i < m; i++)
            result[i] = ((text[i] - 'A') + (keyword[i % n] - 'A')) % 26 + 'A';

        printf("Ciphertext: %s\n", result.c_str());
    }
}