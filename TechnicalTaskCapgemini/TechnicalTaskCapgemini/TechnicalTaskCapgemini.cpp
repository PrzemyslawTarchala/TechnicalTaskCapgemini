#include <iostream>
#include <algorithm>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

struct Phone {

    int id;
    string brand, model, factor, year, screenSize, price;
};

string getWholeLine() {

    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

void goUpper(int amountOfPhones, Phone phones[]) {

    transform(phones[amountOfPhones].brand.begin(), phones[amountOfPhones].brand.end(), phones[amountOfPhones].brand.begin(), ::toupper);
    transform(phones[amountOfPhones].model.begin(), phones[amountOfPhones].model.end(), phones[amountOfPhones].model.begin(), ::toupper);
}

void toFile(int amountOfPhones, Phone phones[]) {

    fstream file;
    file.open("PhoneShop.txt", ios::out | ios::app);
    file << phones[amountOfPhones].id << endl;
    file << phones[amountOfPhones].brand << endl;
    file << phones[amountOfPhones].model << endl;
    file << phones[amountOfPhones].factor << endl;
    file << phones[amountOfPhones].year << endl;
    file << phones[amountOfPhones].screenSize << endl;
    file << phones[amountOfPhones].price << endl;
    file.close();
}

int fromFile(Phone phones[]) {

    int position = 0;
    int phone = 0;
    string line = " ";

    fstream file;
    file.open("PhoneShop.txt", ios::in | ios::app);

    while (getline(file, line)) {
        switch (position) {
        case 0: phones[phone].id = stoi(line); position++; break;
        case 1: phones[phone].brand = line; position++; break;
        case 2: phones[phone].model = line; position++; break;
        case 3: phones[phone].factor = line; position++; break;
        case 4: phones[phone].year = line; position++; break;
        case 5: phones[phone].screenSize = line; position++; break;
        case 6: phones[phone].price = line; position = 0; phone++; break;
        }
    }
    file.close();
    return phone;
}

void showBrand(int amountOfPhones, Phone phones[]) {

    bool isFindAnyone = false;
    string brand = "";

    cout << endl << "Enter name: ";
    cin >> brand;
    transform(brand.begin(), brand.end(), brand.begin(), ::toupper);
    system("cls");

    for (int i = 0; i < amountOfPhones; i++) {
        if (brand == phones[i].brand) {
            cout << "ID:           " << phones[i].id << endl;
            cout << "Brand:        " << phones[i].brand << endl;
            cout << "Model:        " << phones[i].model << endl;
            cout << "Factor:       " << phones[i].factor << endl;
            cout << "Year:         " << phones[i].year << endl;
            cout << "Screen size:  " << phones[i].screenSize << endl;
            cout << "Price:        " << phones[i].price << " $" << endl << endl;
            isFindAnyone = true;
        }
    }
    if (isFindAnyone == false) cout << "There is no such phone." << endl;
    system("pause");
}

void sameFactorAndScreenSize(int amountOfPhones, Phone phones[]) {

    bool isFindAnyone = false;
    string factor = "";
    string screenSize = "";

    cout << endl << "Enter factor: ";
    cin >> factor;
    cout << "Enter screen size: ";
    cin >> screenSize;
    system("cls");

    for (int i = 0; i < amountOfPhones; i++) {
        if (factor == phones[i].factor && screenSize == phones[i].screenSize) {
            cout << "Brand:        " << phones[i].brand << endl;
            cout << "Model:        " << phones[i].model << endl;
            cout << "Factor:       " << phones[i].factor << endl;
            cout << "Year:         " << phones[i].year << endl;
            cout << "Screen size:  " << phones[i].screenSize << endl;
            cout << "Price:        " << phones[i].price << " $" << endl << endl;
            isFindAnyone = true;
        }
    }
    if (isFindAnyone == false) cout << "There is no such phone." << endl;
    system("pause");
}

void maxQuantity(int amountOfPhones, Phone phones[]) {

    system("cls");
    cout << "Not finised" << endl;
    system("pause");
}

void topThreeScreenSize(int amountOfPhones, Phone phones[]) {

    system("cls");
    cout << "Not finised" << endl;
    system("pause");
}

void viewAll(int amountOfPhones, Phone phones[]) {

    system("cls");
    for (int i = 0; i < amountOfPhones; i++) {
        cout << "ID:           " << phones[i].id << endl;
        cout << "Brand:        " << phones[i].brand << endl;
        cout << "Model:        " << phones[i].model << endl;
        cout << "Factor:       " << phones[i].factor << endl;
        cout << "Year:         " << phones[i].year << endl;
        cout << "Screen size:  " << phones[i].screenSize << endl;
        cout << "Price:        " << phones[i].price << " $" << endl << endl;
    }
    system("pause");
}

void chooseRaport(int amountOfPhone, Phone phones[]) {

    bool isFindAnyone = false;
    char choice;
    string name, lastName;

    system("cls");
    cout << "1. Same brand\n" << "2. Same actor and screen size\n" << "3. Brand with maximum quantity of the phones\n" << "4. Top-3 screen size\n" << "5. View all" << endl;
    cout << "Choose searching by: ";
    cin >> choice;

    switch (choice) {
    case '1': showBrand(amountOfPhone, phones);
        break;
    case '2': sameFactorAndScreenSize(amountOfPhone, phones);
        break;
    case '3': maxQuantity(amountOfPhone, phones);
        break;
    case '4': topThreeScreenSize(amountOfPhone, phones);
        break;
    case '5': viewAll(amountOfPhone, phones);
        break;
    default: cout << "There is no such choice!";
    }
}

int addNewPhone(int amountOfPhones, Phone phones[]) {

    fstream file;
    system("cls");
    system("cls");

    cout << "Enter brand: ";
    phones[amountOfPhones].brand = getWholeLine(); 
    cout << "Enter model: ";
    phones[amountOfPhones].model = getWholeLine();
    cout << "Enter factor: ";
    phones[amountOfPhones].factor = getWholeLine();
    cout << "Enter year: ";
    phones[amountOfPhones].year = getWholeLine();
    cout << "Enter screen size: ";
    phones[amountOfPhones].screenSize = getWholeLine();
    cout << "Enter price: ";
    phones[amountOfPhones].price = getWholeLine();
    phones[amountOfPhones].id = amountOfPhones + 1;

    goUpper(amountOfPhones, phones); // Changing brand and model to upper
    toFile(amountOfPhones, phones);
    cout << endl << "Successful!" << endl;

    system("pasue");
    return amountOfPhones += 1;
}

void deletePhone(int amountOfPhones, Phone phones[]) {

    system("cls");
    cout << "Not finised" << endl;
    system("pause");
}

int main()
{
    Phone phones[1000];
    char choice;
    int amountOfPhones;

    amountOfPhones = fromFile(phones); //Loading data after fired up

    while (1) {

        system("cls");
        cout << "------------------\n" << "Book of phones\n" << "------------------\n\n";
        cout << "MAIN MENU:\n";
        cout << "1. Add new Phone\n";
        cout << "2. Delete phone\n";
        cout << "3. Raprot\n";
        cout << "0. End \n\n";
        cout << "Enter a choice: ";
        cin >> choice;

        switch (choice) {
        case '1': amountOfPhones = addNewPhone(amountOfPhones, phones);
            break;
        case '2': deletePhone(amountOfPhones, phones);
            break;
        case '3': chooseRaport(amountOfPhones, phones);
            break;
        case '0': exit(0);
            break;
        default: cout << "There is not such option";
            Sleep(1500);
        }
    }
    return 0;
}