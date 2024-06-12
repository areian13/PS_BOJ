#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Grade(int score)
{
    static string grade = "FFFFFFDCBAA";

    string result = string(1, grade[score / 10]);
    if (score % 10 >= 7 && score >= 60 || score == 100)
        result += '+';
    return result;
}

int main()
{
    FastIO;

    string grade = "FFFFFFDCBAA";
    int tc;
    cin >> tc;

    while (tc--)
    {
        string name;
        int score;
        cin >> name >> score;

        string grade = Grade(score);
        cout << name << ' ' << grade << '\n';
    }
}