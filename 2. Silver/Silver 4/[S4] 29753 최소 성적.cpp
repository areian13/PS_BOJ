#include <iostream>
#include <array>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


struct Lecture
{
    int c;
    string g;
};

double Score(string& g)
{
    if (g == "F")
        return 0.0;
    return (4 - (g[0] - 'A') + (g[1] == '+' ? 0.5 : 0.0));
}

double AvgScore(vector<Lecture>& lectures)
{
    double scoreSum = 0;
    int cSum = 0;

    for (Lecture& lecture : lectures)
    {
        scoreSum += lecture.c * Score(lecture.g);
        cSum += lecture.c;
    }
    return (double)(int)(scoreSum * 100 / cSum) / 100;
}

int main()
{
    FastIO;

    array<string, 9> grades = { "F","D0","D+","C0","C+","B0","B+","A0","A+" };

    int n;
    double x;
    cin >> n >> x;

    vector<Lecture> lectures(n);
    for (int i = 0; i < n - 1; i++)
        cin >> lectures[i].c >> lectures[i].g;

    int c;
    cin >> c;
    lectures[n - 1].c = c;

    string result = "impossible";
    for (string grade : grades)
    {
        lectures[n - 1].g = grade;
        double score = AvgScore(lectures);
        if (score > x)
        {
            result = grade;
            break;
        }
    }
    cout << result << '\n';
}