#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Student
{
    int x;
    array<int, 4> grades;
    bool isAwarded;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Student> students(n);
    for (int i = 0; i < n; i++)
    {
        int x, a, b, c, d;
        cin >> x >> a >> b >> c >> d;

        students[i] = { x,a,b,c,d,false };
    }

    for (int i = 0; i < 4; i++)
    {
        Student& result = *max_element(students.begin(), students.end(),
            [&i](const Student& a, const Student& b)
            {
                if (a.isAwarded != b.isAwarded)
                    return a.isAwarded > b.isAwarded;
                if (a.grades[i] != b.grades[i])
                    return a.grades[i] < b.grades[i];
                return a.x > b.x;
            }
        );

        cout << result.x << ' ';
        result.isAwarded = true;
    }
    cout << '\n';
}