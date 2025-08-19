#include <iostream>
#include <vector>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanTrans(string& word, string& num)
{
    static array<int, 26> p;
    static bool init = false;

    if (!init)
    {
        init = true;
        p[0] = p[1] = p[2] = 2;
        p[3] = p[4] = p[5] = 3;
        p[6] = p[7] = p[8] = 4;
        p[9] = p[10] = p[11] = 5;
        p[12] = p[13] = p[14] = 6;
        p[15] = p[16] = p[17] = p[18] = 7;
        p[19] = p[20] = p[21] = 8;
        p[22] = p[23] = p[24] = p[25] = 9;
    }

    int n = word.size();
    if (n != num.size())
        return false;

    for (int i = 0; i < n; i++)
    {
        if (p[word[i] - 'a'] != num[i] - '0')
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> words(n);
    for (auto& word : words)
        cin >> word;

    string num;
    cin >> num;

    int result = 0;
    for (auto& word : words)
        result += CanTrans(word, num);
    cout << result << '\n';
}