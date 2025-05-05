#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<double> credits(n), grades(n);
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < n; ++i) {
        cout << "Enter credits for course " << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter grade point (0-10) for course " << i + 1 << ": ";
        cin >> grades[i];

        totalCredits += credits[i];
        totalGradePoints += credits[i] * grades[i];
    }

    double cgpa = totalGradePoints / totalCredits;
    cout << "Your CGPA is: " << cgpa << endl;
    return 0;
}

