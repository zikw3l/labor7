/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void saveToFile(const string& filename, const vector<string>& data) {
    fstream in;
    in.open(filename);
    for(int i =0 ; i < data.size(); i++) {
        in << data[i]<<"\n";
    }
    in.close();
}

void loadFromFile(const string& filename, vector<string>& outData) {
    ifstream in;
    in.open(filename);
    string line;
    if(in.is_open()) {
        while(getline(in, line)) {
            outData.push_back(line);
        }
    }
    in.close();
}

int main() {
    string filename, znaj;
    vector<std::string> data, outData;
    cin>>filename>>znaj;
    while (znaj!="0") {
        data.push_back(znaj);
        cin>>znaj;
    }
    saveToFile(filename,data);
    loadFromFile(filename,outData);
    for (int i = 0; i < outData.size(); i++) {
        cout << outData[i] << endl;
    }

}
*/
