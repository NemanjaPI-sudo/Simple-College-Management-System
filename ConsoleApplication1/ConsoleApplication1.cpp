#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class student {
public:
    long int reg;
    string name, branch;

    void input() {
        cout << "\nEnter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll no: ";
        cin >> reg;
        cin.ignore();
        cout << "Enter Branch: ";
        getline(cin, branch);
    }

    void display() {
        cout << "\nName: " << name;
        cout << "\nRoll no.: " << reg;
        cout << "\nBranch: " << branch << endl;
    }

    bool operator ==(const student& a) const {
        return reg == a.reg;
    }
};

vector <student> v;

void get_file() {
    student x;
    ifstream file("College.txt");
    if (file.is_open()) {
        while (file >> x.reg >> ws && getline(file, x.name) && getline(file, x.branch)) {
            v.push_back(x);
        }
        file.close();
    }
}

void write_file() {
    ofstream file("College.txt");
    if (file.is_open()) {
        for (int i = 0; i < v.size(); i++) {
            file << v[i].reg << endl << v[i].name << endl << v[i].branch << endl;
        }
        file.close();
    }
}

void insert_new() {
    student x;
    x.input();
    v.push_back(x);
    cout << "\nStudent added successfully!\n";
}

void show() {
    if (v.empty()) {
        cout << "\nNo students to display.\n";
        return;
    }
    cout << "\nStudent Records:\n";
    for (int i = 0; i < v.size(); i++) {
        v[i].display();
    }
}

void delete_data() {
    if (v.empty()) {
        cout << "\nNo students to delete.\n";
        return;
    }
    long int reg;
    cout << "\nEnter Roll no. of student to delete: ";
    cin >> reg;
    auto it = find(v.begin(), v.end(), student{ reg, "", "" });
    if (it != v.end()) {
        v.erase(it);
        cout << "\nStudent with Roll no. " << reg << " deleted successfully.\n";
    }
    else {
        cout << "\nStudent with Roll no. " << reg << " not found.\n";
    }
}

void edit_data() {
    if (v.empty()) {
        cout << "\nNo students to edit.\n";
        return;
    }
    long int reg;
    cout << "\nEnter Roll no. of student to edit: ";
    cin >> reg;
    auto it = find(v.begin(), v.end(), student{ reg, "", "" });
    if (it != v.end()) {
        cout << "\nEditing Student with Roll no. " << reg << ":\n";
        it->input();
        cout << "\nStudent details updated successfully.\n";
    }
    else {
        cout << "\nStudent with Roll no. " << reg << " not found.\n";
    }
}

void search_and_show() {
    if (v.empty()) {
        cout << "\nNo students to search.\n";
        return;
    }
    long int reg;
    cout << "\nEnter Roll no. of student to search: ";
    cin >> reg;
    auto it = find(v.begin(), v.end(), student{ reg, "", "" });
    if (it != v.end()) {
        cout << "\nStudent found:\n";
        it->display();
    }
    else {
        cout << "\nStudent with Roll no. " << reg << " not found.\n";
    }
}

int main() {
    get_file();
    while (true) {
        cout << "\t\t\t\t\t----------------------------------\n";
        cout << "\t\t\t\t\t Simple College Management System\n";
        cout << "\t\t\t\t\t----------------------------------\n";
        cout << "\n\t\t\t\t\tEnter <1> Add new student"
            << "\n\t\t\t\t\tEnter <2> to Display all students"
            << "\n\t\t\t\t\tEnter <3> to Remowe student"
            << "\n\t\t\t\t\tEnter <4> to Edit student"
            << "\n\t\t\t\t\tEnter <5> to Search student"
            << "\n\t\t\t\t\tEnter <0> to Exit\n";
        cout << "\n\n\n\t\t\t\t\tEnter Your Choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            insert_new();
            break;
        case 2:
            show();
            break;
        case 3:
            delete_data();
            break;
        case 4:
            edit_data();
            break;
        case 5:
            search_and_show();
            break;
        case 0:
            cout << "\nExiting program...\n";
            write_file();
            return 0;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }
}
