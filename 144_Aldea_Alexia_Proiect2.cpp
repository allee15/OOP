#include <iostream>
#include <vector>

using namespace std;

/// liniile 6-11 preluate din laboratorul 19.04.2022
class IOInterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};

class Persoana : public IOInterface
{
protected:
    string nume;
    string prenume;
    long long telefon;

public:
    ///constructorul fara parametri
    Persoana()
    {
        this->nume = "Anonim";
        this->prenume = "Anonim";
        this->telefon = 0;
    }

    ///constructorul cu toti parametrii
    Persoana(string nume, string prenume, long long telefon)
    {
        this->nume = nume;
        this->prenume = prenume;
        this->telefon = telefon;
    }

    ///copy-constructorul
    Persoana(const Persoana& p)
    {
        this->nume = p.nume;
        this->prenume = p.prenume;
        this->telefon = p.telefon;
    }

    ///operatorul =
    Persoana& operator=(const Persoana& p)
    {
        if (this != &p)
        {
            this->nume = p.nume;
            this->prenume = p.prenume;
            this->telefon = p.telefon;
        }
        return *this;
    }

    ///liniile 38-64 preluate din laboratorul 19.04.2022
    ///citire
    virtual istream& citire(istream& in)
    {
        cout << "Numele este: ";
        in >> this->nume;
        cout << "Prenumele este: ";
        in >> this->prenume;
        cout << "Numarul de telefon este: ";
        in >> this->telefon;

        return in;
    }

    friend istream& operator>>(istream& in, Persoana& p)
    {
        return p.citire(in);
    }

    ///afisare
    virtual ostream& afisare(ostream& out) const
    {
        out << "Numele este: " << this->nume << endl;
        out << "Prenumele este: " << this->prenume << endl;
        out << "Numarul de telefon este: " << this->telefon << endl;

        return out;
    }

    friend ostream& operator<<(ostream& out, const Persoana& p)
    {
        return p.afisare(out);
    }

    ///functionalitate
    virtual void schimbaTelefon() = 0;

    ~Persoana()
    {
        this->nume = "Anonim";
        this->prenume = "Anonim";
        this->telefon = 0;
    }
};

class Client : public virtual Persoana
{
protected:
    string adresaLivrare;

public:
    ///constructorul fara parametri
    Client() : Persoana()
    {
        this->adresaLivrare = "Anonim";
    }

    ///constructorul cu toti parametrii
    Client(string nume, string prenume, long long telefon, string adresaLivrare): Persoana( nume, prenume, telefon)
    {
        this->adresaLivrare = adresaLivrare;
    }

    ///copy-constructorul
    Client(const Client& p): Persoana(p)
    {
        this->adresaLivrare = p.adresaLivrare;
    }

    ///operatorul =
    Client& operator=(const Client& p)
    {
        if (this != &p)
        {
            Persoana::operator=(p);
            this->adresaLivrare = p.adresaLivrare;
        }
        return *this;
    }

    ///citire
    virtual istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout << "Adresa de livrare este: ";
        in >> this->adresaLivrare;
        return in;
    }

    /// afisare
    virtual ostream& afisare(ostream& out) const
    {
        Persoana::afisare(out);
        out << "Adresa de livrare este: " << this->adresaLivrare << endl;
        return out;
    }

    ///functionalitate
    void schimbaTelefon()
    {
        cout << "Numarul nou de telefon este: " << this->telefon + 5 << endl;
    }

    ///destructor
    ~Client()
    {
        this->adresaLivrare = "Anonim";
    }
};

class Vanzator : public virtual Persoana
{
protected:
    float rating;

public:
    ///constructorul fara parametri
    Vanzator() : Persoana()
    {
        this->rating = 0;
    }

    ///constructorul cu toti parametrii
    Vanzator(string nume, string prenume, long long telefon, float rating) : Persoana( nume, prenume, telefon)
    {
        this->rating = rating;
    }

    ///copy-constructorul
    Vanzator(const Vanzator& p) : Persoana(p)
    {
        this->rating = p.rating;
    }

    ///operatorul =
    Vanzator& operator=(const Vanzator& p)
    {
        if (this != &p)
        {
            Persoana::operator=(p);
            this->rating = p.rating;
        }
        return *this;
    }

    ///citire
    virtual istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout << "Ratingul artistului este: ";
        in >> this->rating;
        return in;
    }

    /// afisare
    virtual ostream& afisare(ostream& out) const
    {
        Persoana::afisare(out);
        out << "Ratingul artistului este: " << this->rating << endl;
        return out;
    }

    ///functionalitate
    void schimbaTelefon()
    {
        cout << "Numarul nou de telefon este: " << this->telefon + 10 << endl;
    }

    ///destructor
    ~Vanzator()
    {
        this->rating = 0;
    }
};

class ClientVanzator :public virtual Client,
    public virtual Vanzator
{
protected:
    float cheltuieli;
    float castiguri;

public:
    /// constructorul fara parametri
    ClientVanzator() :Client(), Vanzator(), Persoana()
    {
        this->cheltuieli = 0;
        this->castiguri = 0;
    }

    /// constructorul cu toti parametrii
    ClientVanzator(string nume, string prenume, long long telefon, string adresaLivrare, float rating, float cheltuieli, float castiguri) :Client(nume, prenume, telefon, adresaLivrare), Vanzator(nume, prenume, telefon, rating), Persoana(nume, prenume, telefon)
    {
        this->cheltuieli = cheltuieli;
        this->castiguri = castiguri;
    }

    ///copy-constructorul
    ClientVanzator(const ClientVanzator& p) : Client(p), Vanzator(p), Persoana(p)
    {
        this->cheltuieli = p.cheltuieli;
        this->castiguri = p.castiguri;
    }

    ///operatorul =
    ClientVanzator& operator=(const ClientVanzator& p)
    {
        if (this != &p)
        {
            Persoana::operator=(p);
            Client::operator=(p);
            Vanzator::operator=(p);
            this->cheltuieli = p.cheltuieli;
            this->castiguri = p.castiguri;
        }
        return *this;
    }

    ///citire
    virtual istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout << "Adresa de livrare este: ";
        in >> this->adresaLivrare;
        cout << "Ratingul artistului este: ";
        in >> this->rating;
        cout << "Cheltuielile sale de pana acum pe acest site sunt: ";
        in >> this->cheltuieli;
        cout << "Castigurile sale de pana acum de pe acest site sunt: ";
        in >> this->castiguri;
        return in;
    }

    /// afisare
    virtual ostream& afisare(ostream& out) const
    {
        Persoana::afisare(out);
        out << "Adresa de livrare este: " << this->adresaLivrare << endl;
        out << "Ratingul artistului este: " << this->rating << endl;
        out << "Cheltuielile sale de pana acum pe acest site sunt: " << this->cheltuieli << endl;
        out << "Castigurile sale de pana acum de pe acest site sunt: " << this->castiguri << endl;
        return out;
    }

    ///functionalitate
    void schimbaTelefon()
    {
        cout << "Numarul nou de telefon este: " << this->telefon + 12345 << endl;
    }

    ~ClientVanzator()
    {
        this->cheltuieli = 0;
        this->castiguri = 0;
    }
};

class Pictura : public IOInterface
{
private:
    string denumire;
    float pret;
    string descriere;

public:
    ///constructorul fara parametri
    Pictura()
    {
        this->denumire = "Anonim";
        this->pret = 0;
        this->descriere = "Anonim";
    }

    ///constructorul cu toti parametrii
    Pictura(string denumire, float pret, string descriere)
    {
        this->denumire = denumire;
        this->pret = pret;
        this->descriere = descriere;
    }

    ///copy-constructorul
    Pictura(const Pictura& p)
    {
        this->denumire = p.denumire;
        this->pret = p.pret;
        this->descriere = p.descriere;
    }

    ///operatorul =
    Pictura& operator=(const Pictura& p)
    {
        if (this != &p)
        {
            this->denumire = p.denumire;
            this->pret = p.pret;
            this->descriere = p.descriere;
        }
        return *this;
    }

    ///liniile 38-64 preluate din laboratorul 19.04.2022
    ///citire
    virtual istream& citire(istream& in)
    {
        cout << "Denumirea tabloului este: ";
        in >> this->denumire;
        cout << "Pretul acestuia este: ";
        in >> this->pret;
        cout << "O scurta descriere a tabloului: ";
        in >> this->descriere;

        return in;
    }

    friend istream& operator>>(istream& in, Pictura& p)
    {
        return p.citire(in);
    }

    ///afisare
    virtual ostream& afisare(ostream& out) const
    {
        out << "Denumirea tabloului este: " << this->denumire << endl;
        out << "Pretul acestuia este: " << this->pret << endl;
        out << "O scurta descriere a tabloului: " << this->descriere << endl;

        return out;
    }

    friend ostream& operator<<(ostream& out, const Pictura& p)
    {
        return p.afisare(out);
    }

    ///functionalitate
    void cresterePret()
    {
        cout << "Pretul final, dupa majorare, este: " << this->pret * 1.25 << endl;
    }

    ~Pictura()
    {
        this->denumire = "Anonim";
        this->pret = 0;
        this->descriere = "Anonim";
    }

};

int main()
{
    vector<Pictura*> listaPicturi = vector<Pictura*>();
    int livrare[100],c=0;
    bool ok = true;

    Pictura* p1 = new Pictura();
    cin >> *p1;
    listaPicturi.push_back(p1);
    livrare[c] = c % 5;
    c++;
    cout<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;

    Pictura* p2= new Pictura();
    cin>>*p2;
    listaPicturi.push_back(p2);
    livrare[c] = c % 5;

    c++;
    cout<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;

    Pictura* p3= new Pictura();
    cin>>*p3;
    listaPicturi.push_back(p3);
    livrare[c] = c % 5;
    c++;
    cout<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;

    Pictura* p4= new Pictura();
    cin>>*p4;
    listaPicturi.push_back(p4);
    livrare[c] = c % 5;
    c++;
    cout<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;

    Pictura* p5=new Pictura();
    cin>>*p5;
    listaPicturi.push_back(p5);
    livrare[c] = c % 5;
    c++;
    cout<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    while (ok==true)
    {
        int alegere;

        cout << "Apasa (1) daca vrei sa cumperi un tablou." << endl;
        cout << "Apasa (2) daca vrei sa vinzi un tablou." << endl;
        cout << "Apasa (3) daca vrei atat sa cumperi, cat sa si vinzi un tablou." << endl;
        cout << "Apasa (4) pentru a iesi." << endl;

        cout<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cin >> alegere;

        switch (alegere)
        {
        case 1:
        {
            Client c;
            cin >> c;
            cout<<"Vrei sa schimbi numarul de telefon?(1 pt da, 0 pt nu)"<<endl;
            int x;
            cin>>x;
            if(x==1)
                c.schimbaTelefon();
            cout << "Tasteaza indicele tabloului care iti place." << endl;
            for (int i = 0; i <listaPicturi.size(); i++)
                cout << i << " " << *listaPicturi[i] << endl;

            cout<<endl;
            int optiune;
            cin >> optiune;
            cout << "Comanda plasata! Optiunea dumneavoastra este: "<<endl;
            cout<<endl;
            cout << *listaPicturi[optiune] << endl;
            cout<<" si va fi livrata in " << livrare[optiune]+1 << " zile lucratoare." << endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            break;
        }
        case 2:
        {
            Vanzator v;
            cin >> v;
            cout<<"Vrei sa schimbi numarul de telefon?(1 pt da, 0 pt nu)"<<endl;
            int x;
            cin>>x;
            if(x==1)
                v.schimbaTelefon();
            Pictura* p=new Pictura();
            cin >> *p;
            listaPicturi.push_back(p);
            c++;
            livrare[c] = c % 5;
            cout<<endl;
            cout << "Tabloul a fost adaugat cu succes!" << endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            break;
        }
        case 3:
        {
            ClientVanzator cv;
            cin >> cv;
            cout<<"Vrei sa schimbi numarul de telefon?(1 pt da, 0 pt nu)"<<endl;
            int x;
            cin>>x;
            if(x==1)
                cv.schimbaTelefon();

            /// Alegem pictura pe care vrem s-o cumparam
            cout<<"Alege intai tabloul pe care vrei sa-l cumperi!"<<endl;
            cout<<endl;
            cout << "Tasteaza indicele tabloului care iti place." << endl;
            for (int i = 0; i <listaPicturi.size(); i++)
                cout << i << " " << *listaPicturi[i] << endl;

            cout<<endl;
            int optiune;
            cin >> optiune;
            cout << "Comanda plasata! Optiunea dumneavoastra este: "<<endl;
            cout<<endl;
            cout << *listaPicturi[optiune] << endl;
            cout<<" si va fi livrata in " << livrare[optiune]+1 << " zile lucratoare." << endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

            ///Adaugam pictura pe care vrem s-o vindem
            cout<<"Introdu datele picturii pe care vrei s-o adaugi pe site!"<<endl;
            cout<<endl;
            Pictura* p= new Pictura();
            cin >> *p;
            listaPicturi.push_back(p);
            c++;
            livrare[c] = c % 5;
            cout<<endl;
            cout << "Tabloul a fost adaugat cu succes!" << endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            break;
        }
        case 4:
        {
            ok = false;
            break;
        }
        }
    }

    return 0;
}

