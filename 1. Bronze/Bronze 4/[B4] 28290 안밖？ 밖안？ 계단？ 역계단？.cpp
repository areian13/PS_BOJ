#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    FastIO;

    unordered_map<string, string> typingType;
    typingType["fdsajkl;"] = "in-out";
    typingType["jkl;fdsa"] = "in-out";
    typingType["asdf;lkj"] = "out-in";
    typingType[";lkjasdf"] = "out-in";
    typingType["asdfjkl;"] = "stairs";
    typingType[";lkjfdsa"] = "reverse";

    string typing;
    cin >> typing;

    string result = (typingType.count(typing) == 1) ? typingType[typing] : "molu";
    cout << result << '\n';
}