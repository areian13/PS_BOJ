#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> result;
    string pre = "Present!";
    for (int i = 0; i < n; i++)
    {
        string stu;
        cin >> stu;

        if (stu != "Present!" && pre != "Present!")
            result.push_back(pre);

        pre = stu;
    }
    if (pre != "Present!")
        result.push_back(pre);

    if (result.empty())
        result.push_back("No Absences");

    for (string& stu : result)
        cout << stu << '\n';
}