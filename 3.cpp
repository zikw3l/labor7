#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

enum Score {
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student {
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const Groups& groups) {
    fstream out(filename);
    for (auto& v : groups) {
        out << v.first << '\n';
        for (auto& student : v.second) {
            out << student.Name << "," << student.Year << '\n';
            for (auto& el : student.RecordBook) {
                out << el.first << " " << el.second << '\n';
            }
        }
    }
}

Score strl(const string& s) {
    if (s == "Unsatisfactorily") return Score::Unsatisfactorily;
    if (s == "Satisfactorily") return Score::Satisfactorily;
    if (s == "Good") return Score::Good;
    if (s == "Excellent") return Score::Excellent;
    return Score::Unsatisfactorily;
}

void loadFromFile(const string& filename, Groups& outGroups) {
    ifstream file(filename);
    string l;
    string group;
    Student student;
    while (getline(file, l)) {
        if (l.find("Group") == 0) {
            group = l.substr(5);
        } else if (l.find("Name") == 0) {
            student.Name = l.substr(4);
        } else if (l.find("Year") == 0) {
            student.Year = stoi(l.substr(4));
        } else if (l.find("Subject") == 0) {
            stringstream ss(l.substr(7));
            string subject, gradeStr;
            getline(ss, subject, ',');
            getline(ss, gradeStr);
            gradeStr = gradeStr.substr(8);
            Score grade = strl(gradeStr);
            student.RecordBook[subject] = grade;
        }

        if (l.find("Grade book") == 0) {
            outGroups[group].push_back(student);
            student = Student();
        }
    }
}