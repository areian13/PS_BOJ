#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, string> translation;
    translation["CU"] = "see you";
    translation[":-)"] = "I¡¯m happy";
    translation[":-("] = "I¡¯m unhappy";
    translation[";-)"] = "wink";
    translation[":-P"] = "stick out my tongue";
    translation["(~.~)"] = "sleepy";
    translation["TA"] = "totally awesome";
    translation["CCC"] = "Canadian Computing Competition";
    translation["CUZ"] = "because";
    translation["TY"] = "thank-you";
    translation["YW"] = "you¡¯re welcome";
    translation["TTYL"] = "talk to you later";

    while (true)
    {
        string shortForm;
        cin >> shortForm;

        string result = translation[shortForm] != "" ? translation[shortForm] : shortForm;
        cout << result << '\n';

        if (shortForm == "TTYL")
            break;
    }
}