#include "support.h"

int main() {
    cout<<"--- Welcome to Daily REC ---\n";
    string instrut;
    vector<string> command;
    while (true) {
        cout<<">";
        getline(cin, instrut);
        // cout<<instrut<<endl;
        command = splitInstruct(instrut);
        switch(analise(command)) {
            case -1:
                cout<<"command error!"<<endl;
                break;
            case 1:
                helpFunc(command);
                break;
            case 2:
                recordFunc(command);
                break;
            case 3:
                addFunc(command);
                break;
            case 4:
                diaryFunc(command);
                break;
            case 0:
                return 0;
        }
    }
}