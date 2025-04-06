#include <iostream>
#include <vector>
using namespace std;

double dailyHomeworks() {
    int additional;
    cout << "How many daily homeworks have there been since 4/4/2025? There were 21 on this day. \n";
    cin >> additional;
    int nonPerfectCount;
    cout << "How many daily homeworks did you *not* get full points on? (this is just to make counting easier) \n";
    cin >> nonPerfectCount;

    vector<double> missedScores(nonPerfectCount);
    int totalScore = 0;

    for (int i = 0; i < nonPerfectCount; ++i) {
        cout << "Enter the score you got for missed hw #" << (i + 1) << " (out of 2): ";
        cin >> missedScores[i];
        totalScore += missedScores[i] * 50; // scale to 100
    }

    int totalHomeworks = 21 + additional;
    int perfectHomeworks = totalHomeworks - nonPerfectCount;
    totalScore += perfectHomeworks * 100; // each perfect is 2 * 50 = 100

    double hwCategoryaverage = totalScore / static_cast<double>(totalHomeworks);
    cout << "Daily HW average: " << hwCategoryaverage << ". Daily homeworks are 10% of your grade" <<  endl << endl;
    return hwCategoryaverage;
}

double chapterAssignments() {
    cout << "How many chapter assignments are in? (there will be 7 of these over the whole class) \n";
    int chcount;
    cin >> chcount;
    int totalchs = 0;
    for (int i = 0; i < chcount; i++) {
        cout << "Enter score for chapter homework " << i + 1 << " (out of 25): ";
        int chscore;
        cin >> chscore;
        totalchs += chscore;
    }
    double chCategoryAverage = (totalchs / double(chcount)) / 25.0 * 100.0;
    cout << "Chapter HW average: " << chCategoryAverage << ". Chapter homeworks are 20% of your grade" << endl << endl;
    return chCategoryAverage;
}

double hourExams() {
    cout << "How many exams are in? ";
    int examcount;
    cin >> examcount;
    int totalexams = 0;
    for (int i = 0; i < examcount; i++) {
        cout << "Enter score for exam " << i + 1 << " (out of 100): ";
        int examscore;
        cin >> examscore;
        totalexams += examscore;
    }
    double exCategoryAverage = totalexams / double(examcount);
    cout << "Exam average: " << exCategoryAverage << ". Hour exams are 15% of your grade" << endl << endl;
    return exCategoryAverage;
}

double getTotal() {
    double classTotal = 0;
    double hwCategoryAverage = dailyHomeworks();
    double chCategoryAverage = chapterAssignments();
    double exCategoryAverage = hourExams();
    classTotal = (chCategoryAverage * 0.3333) + (hwCategoryAverage * 0.1666) + (exCategoryAverage * 0.5);
    return classTotal;
}

int main() {
    double classTotal = getTotal();
    cout << fixed;
    cout.precision(2);
    cout << "Your overall class grade is: " << classTotal << "%\n";

    if (classTotal >= 90) {
        cout << "You have an A! Good stuff :D\n";
    }

    cin.ignore();
    cin.get();
    return 0;
}
