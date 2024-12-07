/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>
using namespace std;
struct Book
{
    string Author;
    string Title;
    int Year;
};
void saveToFile(const string& filename, const vector<Book>& data) {
    fstream in;
    in.open(filename);
    for (int i = 0; i < data.size(); ++i) {
        in << data[i].Author << " " << data[i].Title << " " << data[i].Year<<"\n";
    }
    in.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    fstream in(filename);
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        string author, title;
        int year;

        getline(ss, author, ',');
        getline(ss, title, ',');
        ss >> year;
        outData.push_back({author, title, year});
    }
    in.close();
}
*/

