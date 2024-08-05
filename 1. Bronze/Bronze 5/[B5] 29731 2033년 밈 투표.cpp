#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, bool> isExisted;
    isExisted["Never gonna give you up"] = true;
    isExisted["Never gonna let you down"] = true;
    isExisted["Never gonna run around and desert you"] = true;
    isExisted["Never gonna make you cry"] = true;
    isExisted["Never gonna say goodbye"] = true;
    isExisted["Never gonna tell a lie and hurt you"] = true;
    isExisted["Never gonna stop"] = true;

    int n;
    cin >> n;

    bool isChanged = false;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);

        isChanged |= (isExisted.count(str) == 0);
    }

    string result = (isChanged ? "Yes" : "No");
    cout << result << '\n';
}