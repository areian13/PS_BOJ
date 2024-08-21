#include <iostream>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ContraryMBTI(string& mbti)
{
    static unordered_map<char, char> contrary;
    static bool isInited = false;

    if (!isInited)
    {
        contrary['I'] = 'E';
        contrary['E'] = 'I';
        contrary['S'] = 'N';
        contrary['N'] = 'S';
        contrary['T'] = 'F';
        contrary['F'] = 'T';
        contrary['P'] = 'J';
        contrary['J'] = 'P';
        isInited = true;
    }

    string result = "";
    for (char c : mbti)
        result += contrary[c];
    return result;
}

int main()
{
    FastIO;

    string mbti;
    cin >> mbti;

    string result = ContraryMBTI(mbti);
    cout << result << '\n';
}