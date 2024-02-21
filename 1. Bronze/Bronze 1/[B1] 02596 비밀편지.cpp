#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<string, 8> codes = { "000000","001111","010011","011100","100110","101001","110101","111010" };

int CountDiff(string& code, int idx)
{
    int result = 0;
    for (int i = 0; i < 6; i++)
        result += (code[i] != codes[idx][i]);
    return result;
}

int SimilarCodeNum(string code)
{
    for (int i = 0; i < 8; i++)
    {
        if (CountDiff(code, i) <= 1)
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    string letter;
    cin >> n >> letter;

    string result = "";
    for (int i = 0; i < n; i++)
    {
        int codeNum = SimilarCodeNum(letter.substr(i * 6, 6));
        if (codeNum != -1)
            result += (codeNum + 'A');
        else
        {
            result = to_string(i + 1);
            break;
        }
    }
    cout << result << '\n';
}