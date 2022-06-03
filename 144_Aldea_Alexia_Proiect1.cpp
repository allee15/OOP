#include <iostream>
#include <cstring>

using namespace std;

class Pictura {
private:
    string denumire, pictor, CurentArtistic;
    int AnCreare, NrCamera;
    static int contor;
    const int IDPictura;

public:
    //constructor fara parametrii
    Pictura();

    //constructor cu toti parametrii
    Pictura(string, string, string, int, int);

    //constructor cu 3 parametrii (Presupunem ca nu stim in ce camera se afla pictura)
    Pictura(string, string, int);

    //copy-constructor
    Pictura(const Pictura&);

    //supraincarcarea operatorului == pt obiecte de tip Pictura
    Pictura& operator = (const Pictura&);

    //supraincarcarea operatorului  >> pt obiecte de tip Pictura
    friend istream& operator >> (istream& in, Pictura&);

    //supraincarcarea operatorului  << pt obiecte de tip Pictura
    friend ostream& operator << (ostream& out, const Pictura&);

    //Supraincarcarea operatorului ++ pentru obiecte de tip Pictura
    Pictura& operator ++ ();

    //supraincarcarea operatorului == pt obiecte de tip Pictura
    bool operator==(const Pictura& p)
    {
        if (this->denumire == p.denumire && this->pictor == p.pictor && this->CurentArtistic == p.CurentArtistic && this->AnCreare == p.AnCreare && this->NrCamera == p.NrCamera)
            return true;
        return false;
    }

    //supraincarcarea operatorului < pt obiecte de tip Pictura
    bool operator<(const Pictura& p)
    {

        if (this->AnCreare < p.AnCreare)
            return true;
        return false;

    }
    //supraincarcarea operatorului >= pt obiecte de tip Pictura
    bool operator>=(const Pictura& p)
    {

        if (this->AnCreare >= p.AnCreare)
            return true;
        return false;
    }

    //operatorul cast explicit
    explicit operator int()
    {

        return (int)this->NrCamera;
    }

    //setter pentru denumire, pictor, curent artistic
    void setDenPictorCurent(string denumire, string pictor, string CurentArtistic)
    {

        if (this->denumire != "" && this->pictor != "" && this->CurentArtistic != "")
        {
            this->denumire = "";
            this->pictor = "";
            this->CurentArtistic = "";
        }
        this->denumire=denumire;
        this->pictor = pictor;
        this->CurentArtistic = CurentArtistic;
    }

    //getter pentru denumirea picturii
    string getDenumire()
    {
        return denumire;

    }

    //cream o functionalitate
    void categoriePictura(int AnCreare);

    //destructor
    ~Pictura();
};

int Pictura::contor = 0; //incepem numaratoarea de la 0

//constructor cu toti parametrii
Pictura::Pictura(string denumire, string pictor, string CurentArtistic, int AnCreare, int NrCamera) :IDPictura(contor++)
{
    this->denumire = denumire;
    this->pictor = pictor;
    this->CurentArtistic = CurentArtistic;
    this->AnCreare = AnCreare;
    this->NrCamera = NrCamera;
}

//constructor cu 3 parametrii (Presupunem ca nu stim in ce camera se afla pictura)
Pictura::Pictura(string denumire, string pictor, int NrCamera) :IDPictura(contor++)
{
    this->denumire = denumire;
    this->pictor = pictor;
    this->NrCamera = NrCamera;
}

//copy-constructor
Pictura::Pictura(const Pictura& pictura) : IDPictura(contor++)
{
    this->denumire = pictura.denumire;
    this->pictor = pictura.pictor;
    this->CurentArtistic = pictura.CurentArtistic;
    this->AnCreare = pictura.AnCreare;
    this->NrCamera = pictura.NrCamera;
}

//supraincarcarea operatorului = pt obiecte de tip Pictura
Pictura& Pictura:: operator = (const Pictura& pictura)
{
    if (this != &pictura)
    {
        this->denumire = pictura.denumire;
        this->pictor = pictura.pictor;
        this->CurentArtistic = pictura.CurentArtistic;
        this->AnCreare = pictura.AnCreare;
        this->NrCamera = pictura.NrCamera;
    }
    return *this;
}

//Constructor fara parametrii
Pictura::Pictura() :IDPictura(contor++) {
    this->denumire = "";
    this->pictor = "";
    this->CurentArtistic = "";
    this->AnCreare = 0;
    this->NrCamera = 0;
}

//supraincarcarea operatorului  >> pt obiecte de tip Pictura
istream& operator >> (istream& in, Pictura& p)
{
    cout << "Denumirea tabloului este: ";
    in >> p.denumire;
    cout << "Numele artistului este: ";
    in >> p.pictor;
    cout << "Curentul artistic din care face parte tabloul este: ";
    in >> p.CurentArtistic;
    cout << "Anul crearii este: ";
    in >> p.AnCreare;
    cout << "Numarul camerei unde se afla tabloul este: ";
    in >> p.NrCamera;

    return in;
}

//supraincarcarea operatorului  << pt obiecte de tip Pictura
ostream& operator << (ostream& out, const Pictura& p)
{
    out << "Denumirea tabloului este : " << p.denumire << endl;
    out << "Numele artistului este : " << p.pictor << endl;
    out << "Curentul artistic din care face parte tabloul este : " << p.CurentArtistic << endl;
    out << "Anul crearii este: " << p.AnCreare << endl;
    out << "Numarul camerei unde se afla tabloul este: " << p.NrCamera << endl;

    return out;
}

//Supraincarcarea operatorului ++ pentru obiecte de tip Pictura
Pictura& Pictura:: operator ++ ()//pre
{
    this->NrCamera++;
    return *this;
}

//destructor
Pictura::~Pictura()
{
    this->denumire = "";
    this->pictor = "";
    this->CurentArtistic = "";
    this->AnCreare = 0;
    this->NrCamera = 0;
}

//cream o functionalitate
void Pictura::categoriePictura(int AnCreare)
{
    if (AnCreare >= 2000)
        cout << "Pictura neomodernista.";
}






class Artist {
private:
    string nume;
    string prenume;
    int AnNastere, NrTablouriCreate, NrTablouriPremiate;
    char Traieste; //traieste sau nu?
    static int contor;
    const int IDArtist;

public:
    //constructor fara parametrii
    Artist();

    //constructor cu toti parametrii
    Artist(string, string, int, int, int, char);

    //constructor cu 5 parametrii (Presupunem ca nu stim daca autorul este in viata sau nu)
    Artist(string, string, int, int, int);

    Artist(string, string, int);

    //copy-constructor
    Artist(const Artist&);

    //supraincarcarea operatorului == pt obiecte de tip Artist
    Artist& operator = (const Artist&);

    //supraincarcarea operatorului  >> pt obiecte de tip Artist
    friend istream& operator >> (istream& in, Artist&);

    //supraincarcarea operatorului  << pt obiecte de tip Artist
    friend ostream& operator << (ostream& out, const Artist&);

    //Supraincarcarea operatorului ++ pentru obiecte de tip Artist
    Artist& operator ++ ();

    //supraincarcarea operatorului == pt obiecte de tip Artist
    bool operator==(const Artist& a)
    {
        if (this->nume == a.nume && this->prenume == a.prenume && this->AnNastere == a.AnNastere && this->NrTablouriCreate == a.NrTablouriCreate && this->NrTablouriPremiate == a.NrTablouriPremiate && this->Traieste == a.Traieste)
            return true;
        return false;
    }

    //supraincarcarea operatorului < pt obiecte de tip Artist
    bool operator<(const Artist& a)
    {

        if (this->NrTablouriCreate < a.NrTablouriCreate)
            return true;
        return false;

    }

    //supraincarcarea operatorului >= pt obiecte de tip Artist
    bool operator>=(const Artist& a)
    {

        if (this->NrTablouriCreate >= a.NrTablouriCreate)
            return true;
        return false;
    }

    //operatorul cast explicit
    explicit operator int() {

        return (int)this->NrTablouriCreate;
    }

    //cream o functionalitate
    void categorieArtist(int NrTablouriPremiate);

    //destructor
    ~Artist();
};

int Artist::contor = 0; //incepem numaratoarea de la 0

//constructor cu toti parametrii
Artist::Artist(string nume, string prenume, int AnNastere, int NrTablouriCreate, int NrTablouriPremiate, char Traieste) :IDArtist(contor++)
{
    this->nume = nume;
    this->prenume = prenume;
    this->AnNastere = AnNastere;
    this->NrTablouriCreate = NrTablouriCreate;
    this->NrTablouriPremiate = NrTablouriPremiate;
    this->Traieste = Traieste;
}

//constructor cu 5 parametrii (Presupunem ca nu stim daca autorul este in viata sau nu)
Artist::Artist(string nume, string prenume, int AnNastere) :IDArtist(contor++)
{
    this->nume = nume;
    this->prenume = prenume;
    this->AnNastere = AnNastere;
}

///copy-constructor
Artist::Artist(const Artist& artist) : IDArtist(contor++)
{
    this->nume = artist.nume;
    this->prenume = artist.prenume;
    this->AnNastere = artist.AnNastere;
    this->NrTablouriCreate = artist.NrTablouriCreate;
    this->NrTablouriPremiate = artist.NrTablouriPremiate;
    this->Traieste = artist.Traieste;
}

//supraincarcarea operatorului = pt obiecte de tip Artist
Artist& Artist:: operator = (const Artist& artist)
{
    if (this != &artist)
    {
        this->nume = artist.nume;
        this->prenume = artist.prenume;
        this->NrTablouriCreate = artist.NrTablouriCreate;
        this->NrTablouriPremiate = artist.NrTablouriPremiate;
        this->Traieste = artist.Traieste;
    }
    return *this;
}

//Constructor fara parametrii
Artist::Artist() :IDArtist(contor++) {
    this->nume = "";
    this->prenume = "";
    this->AnNastere = 0;
    this->NrTablouriCreate = 0;
    this->NrTablouriPremiate = 0;
}

//supraincarcarea operatorului  >> pt obiecte de tip Artist
istream& operator >> (istream& in, Artist& p)
{
    cout << "Numele artistului este: ";
    in >> p.nume;
    cout << "Prenumele artistului este: ";
    in >> p.prenume;
    cout << "Anul nasterii artistului este: ";
    in >> p.AnNastere;
    cout << "Numarul de tablouri create este: ";
    in >> p.NrTablouriCreate;
    cout << "Numarul de tablouri premiate este: ";
    in >> p.NrTablouriPremiate;
    cout << "Este inca in viata? (y sau n)";
    in >> p.Traieste;

    return in;
}

//supraincarcarea operatorului  << pt obiecte de tip Artist
ostream& operator << (ostream& out, const Artist& p)
{
    out << "Numele artistului este : " << p.nume << endl;
    out << "Prenumele artistului este : " << p.prenume << endl;
    out << "Anul nasterii artistului este : " << p.AnNastere << endl;
    out << "Numarul de tablouri create este: " << p.NrTablouriCreate << endl;
    out << "Numarul de tablouri premiate este: " << p.NrTablouriPremiate << endl;
    out << "Este inca in viata? (y sau n)" << p.Traieste << endl;

    return out;
}

//Supraincarcarea operator=ului ++ pentru obiecte de tip Artist
Artist& Artist:: operator ++ ()
{
    this->NrTablouriPremiate++;
    return *this;
}

//destructor
Artist::~Artist()
{
    this->nume = "";
    this->prenume = "";
    this->AnNastere = 0;
    this->NrTablouriCreate = 0;
    this->NrTablouriPremiate = 0;
    this->Traieste = false;
}

//cream o functionalitate
void Artist::categorieArtist(int NrTablouriPremiate)
{
    if (NrTablouriPremiate >= 50)
        cout << "Artist de mare valoare pentru omenire.";
}




class Muzeu {
private:
    string nume, adresa, ProgramFunctionare;
    float bilet;
    static int contor;
    const int IDMuzeu;

public:
    //constructor fara parametrii
    Muzeu();

    //constructor cu toti parametrii
    Muzeu(string, string, string, float);

    //constructor cu 2 parametrii (Presupunem ca nu stim pretul biletului de intrare)
    Muzeu(string, float);

    //copy-constructor
    Muzeu(const Muzeu&);

    //supraincarcarea ului == pt obiecte de tip Muzeu
    Muzeu& operator = (const Muzeu&);

    //supraincarcarea operatorului  >> pt obiecte de tip Muzeu
    friend istream& operator >> (istream& in, Muzeu&);

    //supraincarcarea operatorului  << pt obiecte de tip Muzeu
    friend ostream& operator << (ostream& out, const Muzeu&);

    //Supraincarcarea operatorului ++ pentru obiecte de tip Muzeu
    Muzeu& operator ++ ();

    //supraincarcarea operatorului == pt obiecte de tip Muzeu
    bool operator==(const Muzeu& m)
    {
        if (this->nume == m.nume && this->adresa == m.adresa && this->ProgramFunctionare == m.ProgramFunctionare && this->bilet == m.bilet)
            return true;
        return false;
    }

    //supraincarcarea operatorului < pt obiecte de tip Muzeu
    bool operator<(const Muzeu& m)
    {

        if (this->bilet < m.bilet)
            return true;
        return false;

    }
    //supraincarcarea operatorului >= pt obiecte de tip Muzeu
    bool operator>=(const Muzeu& m)
    {

        if (this->bilet >= m.bilet)
            return true;
        return false;
    }

    //operatorul cast explicit
    explicit operator int() {

        return (int)this->bilet;
    }

    //cream o functionalitate
    void tipMuzeu(float bilet);

    //destructor
    ~Muzeu();
};

int Muzeu::contor = 0; //incepem numaratoarea de la 0

//constructor cu toti parametrii
Muzeu::Muzeu(string nume, string adresa, string ProgramFunctionare, float bilet) :IDMuzeu(contor++)
{
    this->nume = nume;
    this->adresa = adresa;
    this->ProgramFunctionare = ProgramFunctionare;
    this->bilet = bilet;
}

//constructor cu 2 parametrii (Presupunem ca nu stim pretul biletului de intrare)
Muzeu::Muzeu(string nume, float bilet) :IDMuzeu(contor++)
{
    this->nume = nume;
    this->bilet = bilet;
}

//copy-constructor
Muzeu::Muzeu(const Muzeu& muzeu) : IDMuzeu(contor++)
{
    this->nume = muzeu.nume;
    this->adresa = muzeu.adresa;
    this->ProgramFunctionare = muzeu.ProgramFunctionare;
    this->bilet = muzeu.bilet;
}

//supraincarcarea operatorului = pt obiecte de tip Muzeu
Muzeu& Muzeu:: operator = (const Muzeu& muzeu)
{
    if (this != &muzeu)
    {
        this->nume = muzeu.nume;
        this->adresa = muzeu.adresa;
        this->ProgramFunctionare = muzeu.ProgramFunctionare;
        this->bilet = muzeu.bilet;
    }
    return *this;
}

//Constructor fara parametrii
Muzeu::Muzeu() :IDMuzeu(contor++) {
    this->nume = "";
    this->adresa = "";
    this->ProgramFunctionare = "";
    this->bilet = 0;
}

//supraincarcarea operatorului  >> pt obiecte de tip Muzeu
istream& operator >> (istream& in, Muzeu& m)
{
    cout << "Numele muzeului este: ";
    in >> m.nume;
    cout << "Adresa muzeului este: ";
    in >> m.adresa;
    cout << "Programul de functionare al muzeului este: ";
    in >> m.ProgramFunctionare;
    cout << "Pretul unui bilet este: ";
    in >> m.bilet;

    return in;
}

//supraincarcarea operatorului  << pt obiecte de tip Muzeu
ostream& operator << (ostream& out, const Muzeu& m)
{
    out << "Numele muzeului este: " << m.nume << endl;
    out << "Adresa muzeului este: " << m.adresa << endl;
    out << "Programul de functionare al muzeului este: " << m.ProgramFunctionare << endl;
    out << "Pretul unui bilet este: " << m.bilet << endl;

    return out;
}

//Supraincarcarea operatorului ++ pentru obiecte de tip Muzeu
Muzeu& Muzeu:: operator ++ ()
{
    this->bilet++;
    return *this;
}

//destructor
Muzeu::~Muzeu()
{
    this->nume = "";
    this->adresa = "";
    this->ProgramFunctionare = "";
    this->bilet = 0;
}

//cream o functionalitate
void Muzeu::tipMuzeu(float bilet)
{
    if (bilet >= 30)
        cout << "Intrarea la muzeu este scumpa.";
}



class Vizita{
private:
    string perioada;
    bool ghid;
    int NrPersoane;
    static int contor;
    const int IDVizita;

public:
    //constructor fara parametrii
    Vizita();

    //constructor cu toti parametrii
    Vizita(string, int, bool);

    //constructor cu 1 parametru (Presupunem ca nu stim daca vrem ghid)
    Vizita( bool);

    //copy-constructor
    Vizita(const Vizita&);

    //supraincarcarea operatorului == pt obiecte de tip Vizita
    Vizita& operator = (const Vizita&);

    //supraincarcarea operatorului  >> pt obiecte de tip Vizita
    friend istream& operator >> (istream& in, Vizita&);

    //supraincarcarea operatorului  << pt obiecte de tip Vizita
    friend ostream& operator << (ostream& out, const Vizita&);

    //Supraincarcarea operatorului ++ pentru obiecte de tip Vizita
    Vizita operator ++();



    //supraincarcarea operatorului == pt obiecte de tip Vizita
    bool operator==(const Vizita& e)
    {
        if (this->perioada == e.perioada && this->ghid == e.ghid && this->NrPersoane == e.NrPersoane)
            return true;
        return false;
    }

    //supraincarcarea operatorului < pt obiecte de tip Vizita
    bool operator<(const Vizita& e)
    {

        if (this->NrPersoane != e.NrPersoane)
            return true;
        return false;

    }

    bool operator>=(const Vizita& v)
    {

        if (this->NrPersoane >= v.NrPersoane)
            return true;
        return false;
    }

    //operatorul cast explicit
    explicit operator int() {

        return (int)this->NrPersoane;
    }

    //setter pentru perioada, ghid, nr de persoane
    void setPerGhidNrPers(string perioada, bool ghid, int NrPersoane)
    {

        if (this->perioada != "" && this->ghid != false && this->NrPersoane != 0)
        {
            this->perioada = "";
            this->ghid = false;
            this->NrPersoane = 0;
        }
        this->perioada = perioada;
        this->ghid = ghid;
        this->NrPersoane = NrPersoane;
    }

    //getter pentru perioada vizitei
    string getPerioada()
    {
        return perioada;

    }

    //cream o functionalitate
    void tipVizita(int NrPersoane);

    //destructor
    ~Vizita();
};

int Vizita::contor = 0; //incepem numaratoarea de la 0

//constructor cu toti parametrii
Vizita::Vizita(string perioada, int NrPersoane, bool ghid) :IDVizita(contor++)
{
    this->perioada = perioada;
    this->NrPersoane = NrPersoane;
    this->ghid = ghid;
}

//constructor cu 1 parametru (Presupunem ca nu stim daca vrem ghid)
Vizita::Vizita( bool ghid) :IDVizita(contor++)
{
    this->ghid = ghid;
}

//copy-constructor
Vizita::Vizita(const Vizita& viz) : IDVizita(contor++)
{
    this->perioada = viz.perioada;
    this->NrPersoane = viz.NrPersoane;
    this->ghid = viz.ghid;
}

//supraincarcarea operatorului = pt obiecte de tip Vizita
Vizita& Vizita:: operator = (const Vizita& viz)
{
    if (this != &viz)
    {
        this->perioada = viz.perioada;
        this->NrPersoane = viz.NrPersoane;
        this->ghid = viz.ghid;
    }
    return *this;
}

//Constructor fara parametrii
Vizita::Vizita() :IDVizita(contor++)
{
    this->perioada = "";
    this->NrPersoane = 0;
    this->ghid = false;
}

//supraincarcarea operatorului  >> pt obiecte de tip Vizita
istream& operator >> (istream& in, Vizita& e)
{
    cout << "Perioada vizitei este: ";
    in >> e.perioada;
    cout << "Vrei ghid? (0 sau 1)";
    in >> e.ghid;
    cout << "Numarul de persoane care vin este: ";
    in >> e.NrPersoane;

    return in;
}

//supraincarcarea operatorului  << pt obiecte de tip Vizita
ostream& operator << (ostream& out, const Vizita& e)
{
    out <<"Perioada vizitei este: " << e.perioada << endl;
    out << "Vrei ghid? (0 sau 1)" << e.ghid << endl;
    out << "Numarul de persoane care vin este: " << e.NrPersoane << endl;

    return out;
}

//Supraincarcarea operatorului ++ pentru obiecte de tip Vizita

Vizita Vizita::operator++(){
    NrPersoane++;
    return *this;

}


//destructor
Vizita::~Vizita()
{
    this->perioada = "";
    this->NrPersoane = 0;
    this->ghid = false;
}

//cream o functionalitate
void Vizita::tipVizita(int NrPersoane)
{
    if (NrPersoane >=3)
        cout << "Grup numeros.";
}

int main()
{
    int alegere;
    bool ok = true;
    Vizita vizita;
    Muzeu muzeu;
    Artist artist;
    Pictura pictura;

    while (ok == true)
    {
        cout << endl;
        cout << "Apasa (1) pentru a programa o vizita. " << endl;
        cout << "Apasa (2) pentru a alege muzeul la care vrei sa mergi. " << endl;
        cout << "Apasa (3) pentru a alege artistul la care vrei sa mergi." << endl;
        cout << "Apasa (4) pentru a alege pictura pe care vrei sa o vezi. " << endl;
        cout << "Apasa (5) pentru a afisa vizita planificata. " << endl;
        cout << "Apasa (6) pentru a afisa muzeul ales. " << endl;
        cout << "Apasa (7) pentru a afisa artistul ales." << endl;
        cout << "Apasa (8) pentru a afisa tabloul ales." << endl;
        cout << "Apasa (9) pentru a primi optiuni pentru programarea unei vizite." << endl;
        cout << "Apasa (10) pentru a primi optiuni pentru alegerea unui muzeu." << endl;
        cout << "Apasa (11) pentru a primi optiuni pentru alegerea unui artist." << endl;
        cout << "Apasa (12) pentru a primi optiuni pentru alegerea unei picturi." << endl;
        cout << "Apasa (13) pentru a iesi din program." << endl;
        cout << "Optiunea dumneavoastra este:";
        cin >> alegere;
        cout << endl;

        /*
        case1: nu am nr de vizite ->doar una
        case2: case1 pt artist
        case3: case1 pt muzeu
        case4: afisez vizita cout<<v
        case5: case4 pt muzeu
        case5: case4 pt artist
        case6: case4 pt pictura
        case7: case1 pt pictura
        case8: case4 pt pictura
        case9: iesi din program
        apoi creez case uri pt restul de constructori--- fac 4 case uri in care apelez toti constructorii pt fiecare clasa
        si bag  ca descriere "apasa aici pentru a primi optiuni pre-made"
        */

        switch (alegere)
        {
        case 1:
        {
            cin >> vizita;
            break;
        }
        case 2:
        {
            cin >> muzeu;
            break;
        }
        case 3:
            {
                cin >> artist;
                break;
            }
        case 4:
        {
            cin >> pictura;
            break;
        }
        case 5:
        {
            cout << vizita;
            break;
        }
        case 6:
        {
            cout << muzeu;
            break;
        }
        case 7:
        {
            cout << artist;
            break;
        }
        case 8:
        {
            cout << pictura;
            break;
        }

        case 9:
        {
            Vizita v1("10-04", true, 5); //constr cu toti param
            Vizita v2("8-04", false, 2); //la fel
            Vizita v3(true); //constr cu 1 param
            Vizita v4(v1); //copy-constr pt v1

            Vizita v5;
            v5 = v1; //supraincarcarea operatorului =

            if (v1 == v2)
            {
                v2 = v5;
                v5.setPerGhidNrPers("10-04", true, 5);
                string x = v5.getPerioada();
                cout << x << endl;
            }
            else
                if (v1 < v2)
                {
                    v1.tipVizita(5);
                }
                else
                    if (v1 >= v2)
                    {
                        ++v2;
                    }
            cout<<v1;
            cout<<v2;
            break;
        }
        case 10:
        {

            Muzeu m1("Muzeul de Arta Contemporana", "Bd Magheru 18", "L-V 10-20", 30.5); //constr cu toti param
            Muzeu m2("Muzeul de Arta Nationala", "Bd Victoriei 20", "L-V 10-18", 20); //la fel
            Muzeu m3("Muzeul Satului", 15); //constr cu 2 param
            Muzeu m4(m1); //copy-constr pt m1

            Muzeu m5;
            m5 = m1; //supraincarcarea operatorului =

            if (m1 == m2 || m1 < m2) //supr op == si a op <
            {
                m1.tipMuzeu(30.5);
            }
            else
                if (m1 >= m2)
                {
                    ++m2;
                }
            cout<<m1;
            cout<<m2;
            break;
        }
        case 11:
        {
            Artist a1("Aldea"," Alexia", 2002, 45, 0,'y'); //constr cu toti param
            Artist a2("Nicolae", "Grigorescu", 1838, 200, 10,'n'); //la fel
            Artist a3("Nicolae" ,"Grigorescu", 1838); //constr cu 3 param
            Artist a4(a1); //copy-constr pt a1

            Artist a5;
            a5 = a1; //supraincarcarea operatorului =

            if (a1 == a2 || a1<a2) //supr op == si a op <
            {
                a1.categorieArtist(10);
            }
            else
                 if (a1 >= a2)
                 {
                     ++a2;
                 }
            cout<<a1;
            cout<<a2;
            break;
        }
        case 12:
        {
            Pictura p1("Iarna", "Aldea Alexia", "Neomodernism", 2021, 69); //constr cu toti param
            Pictura p2("Carul cu boi", "Nicolae Grigorescu", "Modernism", 1899, 60); //la fel
            Pictura p3("Tiganca de la Ghergani", "Nicolae Grigorescu", 70); //constr cu 3 param
            Pictura p4(p1); //copy-constr pt p1

            Pictura p5;
            p5 = p1; //supraincarcarea operatorului =

            if (p1 == p2)
            {
                p2 = p5;
                p5.setDenPictorCurent("Crizanteme si dumitrite", "Stefan Luchian", "Arta statica");
                string x = p5.getDenumire();
                cout << x << endl;
            }
            else
                if (p1 < p2)
                {
                    p1.categoriePictura(2021);
                }
                else
                    if (p1 >= p2)
                    {
                        ++p2;
                    }
            cout<<p1;
            cout<<p2;
            break;
        }
        case 13:
        {
            ok = false;
            break;
        }
        }

    }
    return 0;
}

///nota 6
