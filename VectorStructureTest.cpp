#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Donor {
    string name, password, email, bloodType, streetAddress, suburb, city, ethnicity, gender;
    int contactNumber, dobDay, dobMonth, dobYear;
    //vector<string> underlyingConditions; UNDERLYING CONDITIONS TO BE WORKED ON

    Donor(string s = " ", int i = 0) {
        name = s;
        password = s;
        email = s;
        bloodType = s;
        streetAddress = s;
        suburb = s;
        city = s;
        ethnicity = s;
        gender = s;
        contactNumber = i;
        dobDay = i;
        dobMonth = i;
        dobYear = i;
    }
};

int main()
{
    ifstream myFile;
    myFile.open("donors.csv", ios::in);

    string line;
    int linenum = 0;

    vector<Donor> donors;
    Donor transaction;

    while (getline(myFile, line)) {
        istringstream linestream(line);
        string item;

        getline(linestream, item, ',');
        transaction.name = item;
        getline(linestream, item, ',');
        transaction.password = item;
        getline(linestream, item, ',');
        transaction.email = item;
        getline(linestream, item, ',');
        transaction.bloodType = item;
        getline(linestream, item, ',');
        transaction.streetAddress = item;
        getline(linestream, item, ',');
        transaction.suburb = item;
        getline(linestream, item, ',');
        transaction.city = item;
        getline(linestream, item, ',');
        transaction.ethnicity = item;
        getline(linestream, item, ',');
        transaction.gender = item;

        getline(linestream, item, ',');
        stringstream ss(item);
        ss >> transaction.contactNumber;

        getline(linestream, item, ',');
        stringstream day(item);
        day >> transaction.dobDay;

        getline(linestream, item, ',');
        stringstream month(item);
        month >> transaction.dobMonth;

        getline(linestream, item, ',');
        stringstream year(item);
        year >> transaction.dobYear;

        donors.push_back(transaction);
        linenum++;
    }

    string search;
    cout << "search:\t";
    cin >> search;

    for (int i = 0; i < donors.size(); i++) {
        if (donors[i].email == search) {
            cout << "password:\t";
            string pword;
            cin >> pword;
            if (donors[i].password == pword) {
                cout << "yay";
                int user = i;
                cout << donors[user].name;
            }
            else {
                cout << "sadge";
            }
        }
    }
}