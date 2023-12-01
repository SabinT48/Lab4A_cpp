#include <iostream>
#include <string>

using namespace std;

class Om {
protected:
    string nume;
    int varsta;

public:
    Om(const string& nume, int varsta) : nume(nume), varsta(varsta) {}

    // Supraincarcarea operatorului de intrare >>
    friend istream& operator>>(istream& input, Om& om) {
        cout << "Introduceti numele: ";
        input >> om.nume;
        cout << "Introduceti varsta: ";
        input >> om.varsta;
        return input;
    }

    // Supraincarcarea operatorului de iesire <<
    friend ostream& operator<<(ostream& output, const Om& om) {
        output << "Nume: " << om.nume << ", Varsta: " << om.varsta;
        return output;
    }

    // Constructor de copiere
    Om(const Om& other) : nume(other.nume), varsta(other.varsta) {}

    // Operator de atribuire
    Om& operator=(const Om& other) {
        if (this != &other) {
            nume = other.nume;
            varsta = other.varsta;
        }
        return *this;
    }
};

class Colaborator : public Om {
private:
    string post;
    double salariu;

public:
    // Constructor implicit pentru Colaborator
    Colaborator() : Om("", 0), post(""), salariu(0.0) {}

    Colaborator(const string& nume, int varsta, const string& post, double salariu)
        : Om(nume, varsta), post(post), salariu(salariu) {}

    // Supraincarcarea operatorului de intrare >>
    friend istream& operator>>(istream& input, Colaborator& colaborator) {
        input >> static_cast<Om&>(colaborator); // Citim partea Om
        cout << "Introduceti postul: ";
        input >> colaborator.post;
        cout << "Introduceti salariul: ";
        input >> colaborator.salariu;
        return input;
    }

    // Supraincarcarea operatorului de iesire <<
    friend ostream& operator<<(ostream& output, const Colaborator& colaborator) {
        output << static_cast<const Om&>(colaborator) << ", Post: " << colaborator.post
               << ", Salariu: " << colaborator.salariu;
        return output;
    }

    // Constructor de copiere
    Colaborator(const Colaborator& other) : Om(other), post(other.post), salariu(other.salariu) {}

    // Operator de atribuire
    Colaborator& operator=(const Colaborator& other) {
        if (this != &other) {
            Om::operator=(other);
            post = other.post;
            salariu = other.salariu;
        }
        return *this;
    }
};
