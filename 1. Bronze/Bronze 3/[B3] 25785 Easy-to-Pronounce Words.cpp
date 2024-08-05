#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsEasyWord(string& word)
{
    int n = word.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (IsVowel(word[i]) == IsVowel(word[i + 1]))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string word;
    cin >> word;

    bool result = IsEasyWord(word);
    cout << result << '\n';
}