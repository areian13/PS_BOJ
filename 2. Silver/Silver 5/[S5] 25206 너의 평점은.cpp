#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define LEN 20

double NumGrade(string& grade)
{
    if (grade == "F")
        return 0;

    return 4 - (grade[0] - 'A') + (grade[1] == '+' ? 0.5 : 0.0);
}

int main()
{
    FastIO;

    double result = 0;
    int scoreSum = 0;
    int pfCnt = 0;
    for (int i = 0; i < LEN; i++)
    {
        string name, grade;
        double score;
        cin >> name >> score >> grade;

        if (grade == "P")
            continue;

        result += score * NumGrade(grade);
        scoreSum += score;
    }
    result /= scoreSum;

    lf(4);
    cout << result << '\n';
}