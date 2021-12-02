#include <iostream>
#include "string"
#include <vector>
#include "Listing.h"
using namespace std;

Listing l1("(902)555-6666", "Sam");
Listing l2("(902)333-3333", "Scott");
Listing l3("(902)888-8888", "Amira");

vector<Listing> listings = {l1, l2, l3};

//used to print the current listings contained inside the vector
void printCurrentList() {
    cout << "\n===================================";
    cout << "\nCurrent phone number listings...";
    cout << "\n===================================";

    //cycle through and print the listings inside the vector
    if (listings.empty()) {
        cout << "\nThere are no current listings";
    } else {
        for (int i=0; i<listings.size(); ++i) {

            int id = i;
            string name = listings[i].getName();
            string pnum = listings[i].getTelNum();

            cout << "\nid: " << id << "; name: " << name << "; phone number: " << pnum;
        }
    }
}

void addListing() {
    cout << "\n===================================";
    cout << "\nAdd a new listing";
    cout << "\n===================================";
    string phone;
    string name;

    cout << "\nPhone: ";
    cin.get();
    getline(cin, phone);
    cin.clear();

    cout << "\nName: ";
    getline(cin, name);
    cin.clear();

    Listing l4(phone, name);
    listings.push_back(l4);
}

void deleteListing() {

    printCurrentList();

    cout << "\n===================================";
    cout << "\nDelete listing";
    cout << "\n===================================\n";

    if (!listings.empty()) {
        cout << "\nType in the ID of the listing you want to delete";
        int id;
        cin >> id;

        listings.erase(listings.begin() + (id));

        printCurrentList();
    } else {
        cout << "\nSorry, there are no current listings. You should add one first.";
    }
}

void editListing() {

    printCurrentList();

    cout << "\n===================================";
    cout << "\nEdit listing";
    cout << "\n===================================\n";

    int id;
    string name;
    string phone;

    if (!listings.empty()) {
        cout << "What is the ID of the listing you wish to edit? ";
        cin >> id;

        cout << "New number: ";
        cin.get();
        getline(cin, phone);
        listings[id].setTelNum(phone);
        cin.clear();

        cout << "New name: ";
        getline(cin, name);
        listings[id].setName(name);
        cin.clear();

        printCurrentList();

    } else {
        cout << "\nSorry, there's nothing to edit yet. You should add a listing first.";
    }
}

void chooseOption() {
    cout << "\n===================================";
    cout << "\nWhat would you like to do?";
    cout << "\n===================================\n";

    cout << "\n1. Print current list"
         << "\n2. Add a new listing"
         << "\n3. Delete a listing"
         << "\n4. Edit a listing"
         << "\n5. Exit program";

    cout << "\n\nType the number of the command you want to run: ";

    int opt;
    cin >> opt;

    if (opt == 1) {
        printCurrentList();
    } else if (opt == 2) {
        addListing();
        printCurrentList();
    } else if (opt == 3) {
        deleteListing();
    } else if (opt == 4) {
        editListing();
    }else if (opt == 5) {
        exit(0);
    }

    opt = 0;
    chooseOption();
}

int main() {

    chooseOption();

    return 0;
}
