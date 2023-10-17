#include<iostream>

using namespace std;

struct Student {
    int id;
    string name;
    string class_name;
};

Student student[1000];

void Insert(int id, string name, string class_name) {
        student[id] = {id, name, class_name};
}

void Delete(int id){
    student[id] = {0, "", ""};
}

string Infor(int id) {
    if (student[id].id != 0) {
        return student[id].name + "," + student[id].class_name;
    } else {
        return "NA,NA";
    }
}

int main() {
    string s;
    while(true) {
        cin >> s;
        if(s == "Exit") {
            break;
        }
        else if(s == "Insert") {
            int id;
            string name;
            string class_name;
            cin >> id >> name >> class_name;
            Insert(id, name, class_name);
        }
        else if(s == "Delete") {
            int id;
            cin >> id;
            Delete(id);
        }
        else if(s == "Infor") {
            int id;
            cin >> id;
            cout << Infor(id) << endl;
        }
    }
}
