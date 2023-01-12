#include <iostream>
#include<string.h>
#include <stdexcept>
#include <exception>
#include <cstring>
#include <list>
#include <vector>

using namespace std;
using std::runtime_error;

class IOInterface
{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};





class email_exception : public exception
{
    const char* what() {
        return "Emailul este invalid.";
    }

};

class telefon_exception : public exception
{
    const char* what() {
        return "Telefonul este invalid.";
    }

};

class varsta_exception : public exception
{
    const char* what() {
        return "Varsta este imposibila.";
    }

};

class procentReducere_exception : public exception
{
    const char* what() {
        return "Reducerea este invalida.";
    }

};

class comision_exception : public exception
{
    const char* what() {
        return "Comisionul este invalid";
    }

};

class pret_exception : public exception
{
    const char* what() {
        return "Pretul este invalid";
    }

};




class Persoana : public IOInterface
{
protected:
    string nume;
    string prenume;
    int varsta;
    string email;

public:
    ///cde
    Persoana();

    ///cc
    Persoana(const Persoana& p);

    ///cp
    Persoana(string, string, int, string);

    ///op=
    Persoana& operator=(const Persoana& p);

    ///op>>
    istream& citire(istream& in)
    {
        cout << "Numele persoanei este: ";
        in >> this->nume;
        cout << "Prenumele persoanei este: ";
        in >> this->prenume;
        while (this->varsta == 0)
        {
            cout << "Varsta persoanei este: ";
            in >> this->varsta;
            try
            {
                if (this->varsta > 150 || this->varsta <= 0)
                    throw varsta_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti o varsta existenta! (Felicitari, sunteti in cartea recordurilor:)" << endl;
                this->varsta = 0;
            }
        }

        while (this->email == "Anonim")
        {
            cout << "Emailul persoanei este: ";
            in >> this->email;
            try
            {
                int ok = 0;
                for (int i = 0;i < email[i] != '\0';i++)
                    if (email[i] == '@')
                        ok++;
                if (ok != 1)
                    throw email_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti un alt email!" << endl;
                this->email = "Anonim";
            }
        }

        return in;
    }
    friend istream& operator >> (istream& in, Persoana& p)
    {
        return p.citire(in);
    }

    ///op<<
    ostream& afisare(ostream& out) const
    {
        out << "Numele persoanei este: " << this->nume << endl;
        out << "Prenumele persoanei este: " << this->prenume << endl;
        out << "Varsta persoanei este: " << this->varsta << endl;
        out << "Emailul persoanei este: " << this->email << endl;

        return out;
    }
    friend ostream& operator << (ostream& out, Persoana& p)
    {
        return p.afisare(out);
    }

    ///getter
    string getemail()
    {
        return this->email;
    }

    ///destructor
    ~Persoana();
};

Persoana::Persoana()
{
    this->nume = "Anonim";
    this->prenume = "Anonim";
    this->varsta = 0;
    this->email = "Anonim";
}

Persoana::Persoana(const Persoana& p)
{
    this->nume = p.nume;
    this->prenume = p.prenume;
    this->varsta = p.varsta;
    this->email = p.email;
}

Persoana::Persoana(string nume, string prenume, int varsta, string email)
{
    this->nume = nume;
    this->prenume = prenume;
    this->varsta = varsta;
    this->email = email;
}

Persoana& Persoana:: operator=(const Persoana& p)
{
    if (this != &p)
    {
        this->nume = p.nume;
        this->prenume = p.prenume;
        this->varsta = p.varsta;
        this->email = p.email;
    }
    return *this;
}

Persoana::~Persoana()
{
    this->nume = "Anonim";
    this->prenume = "Anonim";
    this->varsta = 0;
    this->email = "Anonim";
}





class Client : public Persoana
{
protected:
    string adresaLivrare;

public:
    ///cd
    Client();

    ///cc
    Client(const Client& p);

    ///cp
    Client(string, string, int, string, string);

    ///op=
    Client& operator= (const Client& p);

    ///op>>
    istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout << "Adresa de livrare a clientului este: ";
        in >> this->adresaLivrare;

        return in;
    }

    ///op<<
    ostream& afisare(ostream& out) const
    {
        Persoana::afisare(out);
        out << "Adresa de livrare a clientului este: " << this->adresaLivrare << endl;

        return out;
    }

    ///destructor
    ~Client();
};

Client::Client() : Persoana()
{
    this->adresaLivrare = "Anonim";
}

Client::Client(const Client& p) : Persoana(p)
{
    this->adresaLivrare = p.adresaLivrare;
}

Client::Client(string nume, string prenume, int varsta, string email, string adresaLivrare) : Persoana(nume, prenume, varsta, email)
{
    this->adresaLivrare = adresaLivrare;
}

Client& Client ::operator=(const Client& p)
{
    if (this != &p)
    {
        Persoana::operator=(p);
        this->adresaLivrare = p.adresaLivrare;
    }

    return *this;
}

Client:: ~Client()
{
    this->adresaLivrare = "Anonim";
}





class ClientFidel : public Client
{
protected:
    float procentReducere;
    int aniVechime;

public:
    ///cd
    ClientFidel();

    ///cc
    ClientFidel(const ClientFidel& p);

    ///cp
    ClientFidel(string, string, int, string, string, float, int);

    ///op=
    ClientFidel& operator= (const ClientFidel& p);

    ///op>>
    virtual istream& citire(istream& in)
    {
        Client::citire(in);
        while (this->procentReducere == 0)
        {
            cout << "Procentul de reducere al clientului fidel este: ";
            in >> this->procentReducere;
            try
            {
                if (this->procentReducere > 70)
                    throw procentReducere_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti un procent de reducere valid!" << endl;
                this->procentReducere = 0;
            }
        }
        cout << "Anii vechime ai clientului fidel sunt: ";
        in >> this->aniVechime;

        return in;
    }

    ///op<<
    virtual ostream& afisare(ostream& out) const
    {
        Client::afisare(out);
        out << "Procentul de reducere al clientului este: " << this->procentReducere << endl;
        out << "Anii vechime ai acestuia pe site sunt: " << this->aniVechime << endl;

        return out;
    }

    ///setter
    void setReducere(float procentReducere);

    ///getter
    const float getReducere();

    ///destructor
    ~ClientFidel();
};

ClientFidel::ClientFidel() : Client()
{
    this->procentReducere = 0;
    this->aniVechime = 0;
}

ClientFidel::ClientFidel(const ClientFidel& p) : Client()
{
    this->procentReducere = p.procentReducere;
    this->aniVechime = p.aniVechime;
}

ClientFidel::ClientFidel(string nume, string prenume, int varsta, string email, string adresaLivrare, float procentReducere, int aniVechime) :
    Client(nume, prenume, varsta, email, adresaLivrare)
{
    this->procentReducere = procentReducere;
    this->aniVechime = aniVechime;
}

ClientFidel& ClientFidel ::operator=(const ClientFidel& p)
{
    if (this != &p)
    {
        Client::operator=(p);
        this->procentReducere = p.procentReducere;
        this->aniVechime = p.aniVechime;
    }

    return *this;
}

void ClientFidel::setReducere(float procentReducere)
{
    this->procentReducere = procentReducere;
}

const float ClientFidel::getReducere()
{
    return this->procentReducere;
}

ClientFidel:: ~ClientFidel()
{
    this->procentReducere = 0;
    this->aniVechime = 0;
}





class Vanzator : public Persoana
{
private:
    float rating;
    int comision;

public:
    ///cd
    Vanzator();

    ///cc
    Vanzator(const Vanzator& p);

    ///cp
    Vanzator(string, string, int, string, float, int);

    ///op=
    Vanzator& operator=(const Vanzator& p);

    ///op>>
    virtual istream& citire(istream& in)
    {
        Persoana::citire(in);
        cout << "Ratingul vanzatorului este: ";
        in >> this->rating;
        while (this->comision == 0)
        {
            cout << "Comisionul preluat de magazin este: ";
            in >> this->comision;
            try
            {
                if (this->comision > 50)
                    throw comision_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti un alt comision!" << endl;
                this->comision = 0;
            }
        }

        return in;
    }

    ///op<<
    virtual ostream& afisare(ostream& out)
    {
        Persoana::afisare(out);
        out << "Ratingul vanzatorului este: " << this->rating << endl;
        out << "Comisionul luat de magazin este: " << this->comision << endl;

        return out;
    }

    ///pre-incrementare
    const Vanzator& operator--();

    ///destructor
    ~Vanzator();
};

Vanzator::Vanzator() :Persoana()
{
    this->rating = 0;
    this->comision = 0;
}

Vanzator::Vanzator(const Vanzator& p) : Persoana(p)
{
    this->rating = p.rating;
    this->comision = p.comision;
}

Vanzator::Vanzator(string nume, string prenume, int varsta, string email, float rating, int comision) : Persoana(nume, prenume, varsta, email)
{
    this->rating = rating;
    this->comision = comision;
}

Vanzator& Vanzator:: operator=(const Vanzator& p)
{
    if (this != &p)
    {
        Persoana::operator=(p);
        this->rating = p.rating;
        this->comision = comision;
    }
    return *this;
}

const Vanzator& Vanzator::operator--()
{
    if (this->rating > 7)
        this->comision--;
    return *this;
}

Vanzator:: ~Vanzator()
{
    this->rating = 0;
    this->comision = 0;
}



class Picturi : public IOInterface
{
private:
    string denumire;
    float pret;
    int anCreare;

public:
    ///cd
    Picturi();

    ///cc
    Picturi(const Picturi& pi);

    ///cp
    Picturi(string, float, int);

    ///op=
    Picturi& operator=(const Picturi& pi);

    ///op>>
    istream& citire(istream& in)
    {
        cout << "Denumirea tabloului este: ";
        in >> this->denumire;

        while (this->pret == 0)
        {
            cout << "Pretul acestuia este: ";
            in >> this->pret;
            try
            {
                if (this->pret <= 0)
                    throw pret_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti un pret valid!" << endl;
                this->pret = 0;
            }
        }
        cout << "Anul crearii acestuia este: ";
        in >> this->anCreare;

        return in;
    }

    friend istream& operator>> (istream& in, Picturi& pi)
    {
        return pi.citire(in);
    }

    ///op<<
    ostream& afisare(ostream& out) const
    {
        out << "Denumirea tabloului este: " << this->denumire << endl;
        out << "Pretul acestuia este: " << this->pret << endl;
        out << "Anul crearii acestuia este: " << this->anCreare << endl;

        return out;
    }

    friend ostream& operator<< (ostream& out, Picturi& pi)
    {
        return pi.afisare(out);
    }

    ///pre-incrementare
    const Picturi& operator++();

    ///getter
    float getPret()
    {
        return this->pret;
    }

    string getdenumire() const
    {
        return this->denumire;
    }

    ///destructor
    ~Picturi();
};

Picturi::Picturi()
{
    this->denumire = "Anonim";
    this->pret = 0;
    this->anCreare = 0;
}

Picturi::Picturi(const Picturi& pi)
{
    this->denumire = pi.denumire;
    this->pret = pi.pret;
    this->anCreare = pi.anCreare;
}

Picturi::Picturi(string denumire, float pret, int anCreare)
{
    this->denumire = denumire;
    this->pret = pret;
    this->anCreare = anCreare;
}

Picturi& Picturi:: operator=(const Picturi& pi)
{
    if (this != &pi)
    {
        this->denumire = pi.denumire;
        this->pret = pi.pret;
        this->anCreare = pi.anCreare;
    }
    return *this;
}

const Picturi& Picturi::operator++()
{
    if (this->anCreare < 2015)
        this->pret++;
    return *this;
}

Picturi::~Picturi()
{
    this->denumire = "Anonim";
    this->pret = 0;
    this->anCreare = 0;
}





class MagazinPicturi : public IOInterface
{
private:
    string nume;
    string strada;
    int numar;
    long telefon;
    vector<Picturi> picturi;
    list<Persoana*> pers;

public:
    ///cd
    MagazinPicturi();

    ///cc
    MagazinPicturi(const MagazinPicturi& m);

    ///cp
    MagazinPicturi(string, string, int, long, vector<Picturi>, list<Persoana*>);

    ///op=
    MagazinPicturi& operator=(const MagazinPicturi& m);

    ///op>>
    istream& citire(istream& in)
    {
        cout << "Numele magazinului este: ";
        in >> this->nume;
        cout << "Strada unde se afla magazinul este: ";
        in >> this->strada;
        cout << "Numarul la care se afla magazinul este: ";
        in >> this->numar;
        while (this->telefon == 0)
        {
            cout << "Numarul de telefon al magazinului este: ";
            in >> this->telefon;
            try
            {
                long x = this->telefon;
                int c = 0;
                while (x > 0)
                {
                    x = x / 10;
                    c++;
                }
                if (c != 10)
                    throw telefon_exception();
            }
            catch (exception& e)
            {
                cout << e.what();
                cout << endl;
                cout << "Introduceti un numar de telefon valid!" << endl;
                this->telefon = 0;
            }
        }

        cout << "Introduceti numarul de picturi: ";
            int nr;
            in >> nr;
            for (int i = 1;i <= nr;i++)
            {
                Picturi pi;
                in >> pi;
                this->picturi.push_back(pi);
            }

            cout << "Introduceti numarul de persoane retinute in baza de date: "<<endl;
            int x;
            in >> x;
            int y;
            for (int i = 1;i <= x;i++)
            {
                cout << "Introduceti (1) daca este client, (2) daca este client fidel sau (3) daca este vanzator!" << endl;
                in >> y;
                if (y == 1)
                {
                    Persoana* p = new Client(); ///upcasting
                    in >>* p;
                    this->pers.push_back(p);
                }
                else
                {
                    if (y == 2)
                    {
                        Persoana* p = new ClientFidel(); ///upcasting
                        in >> *p;
                        this->pers.push_back(p);
                    }
                    else
                    {
                            Persoana* p = new Vanzator(); ///upcasting
                            in >> *p;
                            this->pers.push_back(p);
                    }
                }
            }


        return in;
    }

    friend istream& operator>>(istream& in, MagazinPicturi& m)
    {
        return m.citire(in);
    }

    ///op<<
    ostream& afisare(ostream& out) const
    {
        out << "Numele magazinului este: " << this->nume << endl;
        out << "Strada unde se afla magazinul este: " << this->strada << endl;
        out << "Numarul la care se afla magazinul este: " << this->numar << endl;
        out << "Numarul de telefon al magazinului este: " << this->telefon << endl;
        out << "Picturile inregistrate in magazin sunt: " << endl;
        vector<Picturi> ::const_iterator it; ///parcurgem vectorul cu acest iterator
        ///am folosit const ptc obiectul meu de tip magazin e constant(this e constant
        ///si this->picturi.begin(), pointerul este de tip constant, daca lasam simplu=>eroare
        for (it = this->picturi.begin(); it != this->picturi.end(); it++)
            (*it).afisare(out);

        list<Persoana*> ::const_iterator its;
        for (its = this->pers.begin(); its != this->pers.end(); its++)
            (*its)->afisare(out);

        return out;
    }

    friend ostream& operator<<(ostream& out, MagazinPicturi& m)
    {
        return m.afisare(out);
    }

    void adaugaPictura(Picturi p)
    {
        this->picturi.push_back(p);
    }

    Persoana* getPersoana(string email)
    {
        list<Persoana*> ::const_iterator its;
        for (its = this->pers.begin(); its != this->pers.end(); its++)
            if ((*its)->getemail() == email)
                return *its;
        return NULL;
    }

    Picturi getPictura(string pictura)
    {
        vector<Picturi> ::const_iterator it;
        for (it = this->picturi.begin(); it != this->picturi.end(); it++)
            if((*it).getdenumire() == pictura)
                return *it;


    }

    void addPers(Persoana* p)
    {
        this->pers.push_back(p);
    }

    void addPictura(Picturi* pi)
    {
        this->picturi.push_back(*pi);
    }

    void afisarePicturi()
    {
        vector<Picturi> ::const_iterator it;
        for (it = this->picturi.begin(); it != this->picturi.end(); it++)
            (*it).afisare(cout);
    }

    ///destructor
    ~MagazinPicturi();

};

MagazinPicturi::MagazinPicturi()
{
    this->nume = "Anonim";
    this->strada = "Anonim";
    this->numar = 0;
    this->telefon = 0;
    this->picturi.clear();
    this->pers.clear();
}

MagazinPicturi::MagazinPicturi(const MagazinPicturi& m)
{
    this->nume = m.nume;
    this->strada = m.strada;
    this->numar = m.numar;
    this->telefon = m.telefon;
    this->picturi = m.picturi;
    this->pers = m.pers;
}

MagazinPicturi::MagazinPicturi(string nume, string strada, int numar, long telefon, vector<Picturi> picturi, list<Persoana*> pers)
{
    this->nume = nume;
    this->strada = strada;
    this->numar = numar;
    this->telefon = telefon;
    this->picturi = picturi;
    this->pers = pers;
}

MagazinPicturi& MagazinPicturi:: operator=(const MagazinPicturi& m)
{
    if (this != &m)
    {
        this->nume = m.nume;
        this->strada = m.strada;
        this->numar = m.numar;
        this->telefon = m.telefon;
        this->picturi = m.picturi;
        this->pers = m.pers;
    }
    return *this;
}

MagazinPicturi::~MagazinPicturi()
{
    this->nume = "Anonim";
    this->strada = "Anonim";
    this->numar = 0;
    this->telefon = 0;
    this->picturi.clear();
    this->pers.clear();
}




class Meniu {

private:
    static Meniu* INSTANCE;
    Meniu() {}
    Meniu(const Meniu& meniu) {}

public:
    static Meniu* getInstance() {
        if (INSTANCE == NULL) {
            INSTANCE = new Meniu();
        }

        return INSTANCE;
    }

    void launch() ///meniul interactiv
    {
        MagazinPicturi M;
        bool ok = true;
        while (ok == true)
        {
            int alegere;

            cout << "Apasa (1) daca ai deja cont de client." << endl;
            cout << "Apasa (2) daca vrei sa-ti creezi cont de client." << endl;
            cout << "Apasa (3) daca vrei sa cumperi o pictura pe site." << endl;
            cout << "Apasa (4) daca vrei sa pui o pictura la vanzare pe site." << endl;
            cout << "Apasa (5) pentru a iesi." << endl;

            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin >> alegere;

            switch (alegere)
            {
            case 1:
            {
                cout << "Introdu email-ul pentru a te conecta!" << endl;
                string s;
                cin >> s;
                Persoana* p = M.getPersoana(s);
                if (p == NULL)
                    cout << "Esti prost sincer, nu ai cont!" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 2:
            {
                Persoana* C= new Client();
                cin >> *C;
                M.addPers(C);
                cout << "Apasa (1) daca vrei sa vezi picturile de vanzare, sau (0) daca vrei sa te intorci in meniul principal" << endl;
                int g; cin >> g;
                if (g == 1)
                    M.afisarePicturi();
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 3:
            {
                cout << "Apasa (1) daca ai cont de client fidel sau (0) in caz contrar." << endl;
                int h; cin >> h;

                    Persoana* p;
                    cin >> *p;
                    cout << "Introdu numele tabloului pe care vrei sa-l cumperi!" << endl;
                    string s; cin >> s;
                    Picturi pi=M.getPictura(s);
                    Picturi* pic;
                    int pretPict = pic->getPret();
                    if(h==1)
                    {
                    try
                    {
                        ClientFidel *cf=dynamic_cast<ClientFidel*>(p); ///downcasting
                        pretPict = pretPict - pretPict * cf->getReducere() / 100;
                    }
                    catch (...)
                    {
                        cout << "Sunteti client infidel, nu aveti reduceri :)" << endl;
                    }
                    }
                    cout << "Comanda plasata! Va vom anunta pe email cand va sosi comanda la dumneavoastra!" << endl;

                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 4:
            {
                Persoana* v = new Vanzator();
                cin >> *v;
                M.addPers(v);
                Picturi* pi;
                cin >> *pi;
                M.addPictura(pi);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 5:
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            }
        }
    }

    Meniu& operator=(const Meniu& meniu) {
        return *INSTANCE;
    }
};

Meniu* Meniu::INSTANCE = 0;





int main()
{

   Meniu::getInstance()->launch();

    return 0;
}
/// o clasa Template
/// 2 metode template
