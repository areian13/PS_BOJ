#include <iostream>
#include <vector>
#include <string>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<string> schools = {
    "North London Collegiate School",
    "Branksome Hall Asia",
    "Korea International School",
    "St. Johnsbury Academy"
};
map<string, string> abbre = {
    { "North London Collegiate School", "NLCS" },
    { "Branksome Hall Asia","BHA" },
    { "Korea International School","KIS" },
    { "St. Johnsbury Academy","SJA" }
};

string Decode(string& s, int k)
{
    string result = "";
    for (char c : s)
    {
        c |= 32;
        if ('a' <= c && c <= 'z')
            result += c;
    }
    result = result.substr(0, 10);

    for (char& c : result)
        c = (c - 'a' + k) % 26 + 'a';
    return result;
}

string Who(string& s)
{
    for (string& school : schools)
    {
        for (int i = 0; i < 26; i++)
        {
            if (Decode(school, i) == s)
                return school;
        }
    }
    return "-1";
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = Who(s);
    cout << abbre[result] << '\n';
}