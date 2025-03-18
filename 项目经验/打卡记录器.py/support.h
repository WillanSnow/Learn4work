# include <iostream>
#include <vector>
using namespace std;

vector<string> splitInstruct(string instruct) {
    string temp = "";
    vector<string> ret;
    for (auto &c: instruct) {
        if (c == ' ') {
            ret.push_back(temp);
            temp = "";
        }
        else temp+=c;
    }
    if (temp != "") ret.push_back(temp);
    return ret;
}

int analise(vector<string> &commad) {
    if (commad.size() == 0) return -1;
    else if (commad[0] == "exit" || commad[0] == "quit") return 0;
    else if (commad[0] == "help") return 1;
    else if (commad[0] == "record") return 2;
    else if (commad[0] == "add") return 3;
    else if (commad[0] == "diary") return 4;
    else return -1;
}

void helpFunc(vector<string> &command) {
    cout<<"This is help"<<endl;
}

void recordFunc(vector<string> &command) {
    cout<<"This is record"<<endl;
}

void addFunc(vector<string> &command) {
    cout<<"This is add"<<endl;
}

void diaryFunc(vector<string> &command) {
    cout<<"This is diary"<<endl;
}