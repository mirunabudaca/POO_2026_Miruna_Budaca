#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum TipContact
{
    PRIETEN,
    CUNOSTINTA,
    COLEG
};


class Contact
{

protected:
    string nume;

public:
    Contact(string nume)
    {
        this->nume = nume;
    }

    virtual ~Contact() {}

    string getNume()
    {
        return nume;
    }


    virtual TipContact getTip() = 0;


    virtual void afisare() = 0;
};


class Prieten : public Contact
{

private:
    string dataNasterii;
    string nrTelefon;
    string adresa;

public:
    Prieten(string nume, string dataNasterii, string numarTelefon, string adresa): Contact(nume)
    {
        this->dataNasterii = dataNasterii;
        this->nrTelefon = numarTelefon;
        this->adresa = adresa;
    }

    TipContact getTip()
    {
        return PRIETEN;
    }

    void afisare()
    {
        cout << "Prieten: " << nume << endl;
        cout << "Data nasterii: " << dataNasterii << endl;
        cout << "Telefon: " << nrTelefon << endl;
        cout << "Adresa: " << adresa << endl;
    }
};


class Cunostinta : public Contact
{

private:
    string nrTelefon;

public:
    Cunostinta(string nume, string numarTelefon): Contact(nume)
    {
        this->nrTelefon = numarTelefon;
    }

    TipContact getTip()
    {
        return CUNOSTINTA;
    }

    void afisare()
    {
        cout << "Cunostinta: " << nume << endl;
        cout << "Telefon: " << nrTelefon << endl;
    }
};


class Coleg : public Contact
{

private:
    string nrTelefon;
    string firma;
    string adresa;

public:
    Coleg(string nume, string numarTelefon, string firma, string adresa): Contact(nume)
    {
        this->nrTelefon = numarTelefon;
        this->firma = firma;
        this->adresa = adresa;
    }

    TipContact getTip()
    {
        return COLEG;
    }

    void afisare()
    {
        cout << "Coleg: " << nume << endl;
        cout << "Telefon: " << nrTelefon << endl;
        cout << "Firma: " << firma << endl;
        cout << "Adresa: " << adresa << endl;
    }
};


class Agenda
{

private:
    vector<Contact*> contacte;

public:
    ~Agenda()
    {
        for (int i = 0; i < contacte.size(); i++)
            delete contacte[i];
    }

    void adaugaContact(Contact* contact)
    {
        contacte.push_back(contact);
    }

    Contact* cautaContact(string nume)
    {
        for (int i = 0; i < contacte.size(); i++)
            if (contacte[i]->getNume() == nume)
                return contacte[i];

        return NULL;
    }

    vector<Contact*> listaPrieteni()
    {
        vector<Contact*> prieteni;

        for (int i = 0; i < contacte.size(); i++)
            if (contacte[i]->getTip() == PRIETEN)
                prieteni.push_back(contacte[i]);

        return prieteni;
    }

    void stergeContact(string nume)
    {
        for (int i = 0; i < contacte.size(); i++)
            if (contacte[i]->getNume() == nume)
            {
                delete contacte[i];
                contacte.erase(contacte.begin() + i);
                cout << "Contactul a fost sters." << endl;
                return;
            }

        cout << "Contactul nu a fost gasit." << endl;
    }

    void afiseazaToateContactele()
    {
        for (int i = 0; i < contacte.size(); i++)
        {
            contacte[i]->afisare();
            cout << endl;
        }
    }
};


int main()
{
    Agenda agenda;

    agenda.adaugaContact(new Prieten("Ana", "12.05.2004", "0711111111", "Iasi"));
    agenda.adaugaContact(new Cunostinta("Maria", "0722222222"));
    agenda.adaugaContact(new Coleg("Andrei", "0733333333", "Bitdefender", "Bucuresti"));
    agenda.adaugaContact(new Prieten("Ioana", "20.08.2005", "0744444444", "Cluj"));

    cout << "Toate contactele:" << endl;
    agenda.afiseazaToateContactele();

    cout << "Cautare contact dupa nume:" << endl;
    Contact* contactGasit = agenda.cautaContact("Ana");

    if (contactGasit != NULL)
        contactGasit->afisare();

    else
    {
        cout << "Contactul nu a fost gasit" << endl;
    }

    cout << endl;

    cout << "Lista de prieteni:" << endl;
    vector<Contact*> prieteni = agenda.listaPrieteni();

    for (int i = 0; i < prieteni.size(); i++)
    {
        prieteni[i]->afisare();
        cout << endl;
    }

    cout << "Stergere contact Maria:" << endl;
    agenda.stergeContact("Maria");

    cout << endl;

    cout << "Contactele ramase:" << endl;
    agenda.afiseazaToateContactele();

    return 0;
}