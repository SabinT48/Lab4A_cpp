#include <iostream>
#include "Header.h"
using namespace std;


int main() {
    string st1, st2;
    int nr1, nr2, op;
    cout << "Introdu datele de baza\nNumele - ";
    cin >> st1;
    cout << "Varsta - ";
    cin >> nr1;
    cout << "Postul - ";
    cin >> st2;
    cout << "Salariu - ";
    cin >> nr2;
    cout << endl << endl;

    Colaborator col(st1, nr1, st2, nr2);

    while(1){
        cout << "----------------------\n";
        cout << "|0. Iesire           |\n";
        cout << "|1. Introdu date noi |\n";
        cout << "|2. Copiere datelor  |\n";
        cout << "----------------------\n->";
        cin >> op;

        switch(op){
            case 0:{
                cout << "Sfarsit de program\n\n";
                exit(0);
            }
                break;
            case 1:{
                Colaborator col2;
                cout << "Introduceti informatii pentru noul colaborator:\n";
                cin >> col2;
                cout << "\nInformatii despre noul colaborator:\n";
                cout << col2 << "\n\n";
            }
                break;
            case 2:{
                Colaborator col2;
                col2 = col;
                cout << "\nInformatii despre colaborator:\n";
                cout << col2 << "\n\n";
            }
                break;
            default:{
                cout << "Nu exista asa optiune\n\n";
            }
                break;
        }
    }
    return 0;
}
