  #include <iostream>
  #include <fstream>
  #include <string.h>
  #include <vector>
  #include "nlohmann/json.hpp"

  using namespace std;
  using namespace nlohmann;

  enum mancare {principal = 1, garnitura = 2, ciorba = 3,  desert = 4,  bautura = 5};


  // Felurile diferite de mancare
  class Portie {
      string nume;
      int tip;
      int pret;
      int gramaj;

  public:

      // Constructor gol
      Portie() {
          nume = "";
          tip = 0;
          pret = 0;
          gramaj = 0;
      }

      // Constructor normal
      Portie(string n, int t, int p, int g) {
          nume = n;
          tip = t;
          pret = p;
          gramaj = g;
      }

      // Copy constructor
      Portie(const Portie &p) {
          nume = p.getNume();
          tip = p.getTip();
          pret = p.getPret();
          gramaj = p.getGramaj();
      }

      // Destructor
      ~Portie() {
          // Ce pot distruge aici?
          nume = "";
          tip = 0;
          pret = 0;
          gramaj = 0;
      }

      string getNume() const{
          return nume;
      }

      int getTip() const{
          return tip;
      }

      int getPret() const{
          return pret;
      }

      int getGramaj() const{
          return gramaj;
      }

      void setNume(string n) {
          nume = n;
      }

      void setTip(int t) {
          tip = t;
      }

      void setPret(int p) {
          pret = p;
      }

      void setGramaj(int g) {
          gramaj = g;
      }

      // Overload la operatori
      friend ostream &operator << (ostream &os, const Portie &p) {
          os << p.getNume() << " - " << p.getPret() << "lei - " << p.getGramaj() << "g" << endl;
          return os;
      }

      friend istream &operator >> (istream &is, Portie &p) {
          string n; int t, pr, g;

          getline(is, n);
          is >> t >> pr >> g;

          p.setNume(n); p.setTip(t); p.setPret(pr); p.setGramaj(g);
          return is;
      }

      virtual Portie &operator = (const Portie &p) {
          setNume(p.getNume()); setTip(p.getTip()); setPret(p.getPret()); setGramaj(p.getGramaj());
          return *this;
      }
  };


  // Clasa derivata FelPrincipal
  class FelPrincipal : public Portie {
      bool deVita;
      string catDeRaraCarnea;

  public:

      FelPrincipal() {
          deVita = false;
          catDeRaraCarnea = "";
      }

      FelPrincipal(string n, int t, int p, int g, bool v, string c) : Portie(n, t, p, g) {
          deVita = v;
          catDeRaraCarnea = c;
      }

      FelPrincipal(Portie p, bool v, string c) : Portie(p) {
          deVita = v;
          catDeRaraCarnea = c;
      }

      FelPrincipal(const FelPrincipal &fp) : Portie(fp) {
          deVita = fp.getDeVita();
          catDeRaraCarnea = fp.getCatDeRaraCarnea();
      }

      ~FelPrincipal() {
          deVita = true;
          catDeRaraCarnea = "";
      }

      bool getDeVita() const{
          return deVita;
      }

      string getCatDeRaraCarnea() const{
          return catDeRaraCarnea;
      }

      void setDeVita(bool dv) {
          deVita = dv;
      }

      void setCatDeRaraCarnea(string raritate) {
          catDeRaraCarnea = raritate;
      }

      FelPrincipal &operator = (const FelPrincipal &fp) {
          setNume(fp.getNume()); setTip(fp.getTip()); setPret(fp.getPret()); setGramaj(fp.getGramaj());
          setDeVita(fp.getDeVita()); setCatDeRaraCarnea(fp.getCatDeRaraCarnea());
          return *this;
      }
  };


  // Clasa derivata garnitura
  class Garnitura : public Portie {
  public :
        Garnitura() : Portie() {};
        Garnitura(string n, int t, int p, int g) : Portie(n, t, p, g) {};
        Garnitura(Portie p) : Portie(p) {};
        ~Garnitura() {};
  };


  // Clasa derivata Ciorba
  class Ciorba : public Portie {
      bool areArdei;
      bool areSmantana;

  public:

      Ciorba() {
          areArdei = false;
          areSmantana = false;
      }

      Ciorba(string n, int t, int p, int g, bool ardei, bool smantana) : Portie(n, t, p, g) {
          areArdei = ardei;
          areSmantana = smantana;
      }

      Ciorba(Portie p, bool ardei, bool smantana) : Portie(p) {
          areArdei = ardei;
          areSmantana = smantana;
      }

      Ciorba(const Ciorba &c) : Portie(c) {
          areArdei = c.getAreArdei();
          areSmantana = c.getAreSmantana();
      }

      ~Ciorba() {
          areArdei = false;
          areSmantana = false;
      }

      bool getAreArdei() const{
          return areArdei;
      }

      bool getAreSmantana() const{
          return areSmantana;
      }

      void setAreArdei(bool ardei) {
          areArdei = ardei;
      }

      void setAreSmantana(bool smantana) {
          areSmantana = smantana;
      }

      Ciorba &operator = (const Ciorba &c) {
          setNume(c.getNume()); setTip(c.getTip()); setPret(c.getPret()); setGramaj(c.getGramaj());
          setAreArdei(c.getAreArdei()); setAreSmantana(c.getAreSmantana());
          return *this;
      }
  };


  // Clasa derivata Desert
  class Desert : public Portie {
      bool eInghetata;
      int numarCupe;

  public:

      Desert() {
          eInghetata = false;
          numarCupe = 0;
      }

      Desert(string n, int t, int p, int g, bool inghetata, int nrCupe) : Portie(n, t, p, g) {
          eInghetata = inghetata;
          numarCupe = nrCupe;
      }

      Desert(Portie p, bool inghetata, int nrCupe) : Portie(p) {
          eInghetata = inghetata;
          numarCupe = nrCupe;
      }

      Desert(const Desert &d) : Portie(d) {
          eInghetata = d.getEInghetata();
          numarCupe = d.getNumarCupe();
      }

      ~Desert() {
          eInghetata = false;
          numarCupe = 0;
      }

      bool getEInghetata() const{
          return eInghetata;
      }

      bool getNumarCupe() const{
          return numarCupe;
      }

      void setEInghetata(bool e) {
          eInghetata = e;
      }

      void setNumarCupe(int nr) {
          numarCupe = nr;
      }

      Desert &operator = (const Desert &i) {
          setNume(i.getNume()); setTip(i.getTip()); setPret(i.getPret()); setGramaj(i.getGramaj());
          setEInghetata(i.getEInghetata()); setNumarCupe(i.getNumarCupe());
          return *this;
      }
  };

  // Clasa derivata bautura
  class Bautura : public Portie {
  public :
      Bautura() : Portie() {};
      Bautura(string n, int t, int p, int g) : Portie(n, t, p, g) {};
      Bautura(Portie p) : Portie(p) {};
      ~Bautura() {};
  };

  // Clasa pentru o masa
  class Masa {
      int capacitate;
      bool esteOcupata;

  public:

      Masa() {
          capacitate = 0;
          esteOcupata = true;
      }

      Masa(int n) {
          capacitate = n;
          esteOcupata = false;
      }

      Masa(int n, bool eOcupata) {
          capacitate = n;
          esteOcupata = eOcupata;
      }

      ~Masa() {
          capacitate = 0;
          esteOcupata = false;
      }

      int getCapacitate() const {
          return capacitate;
      }

      bool getEsteOcupata() const {
          return esteOcupata;
      }

      void setCapacitate(int n) {
          capacitate = n;
      }

      void setEsteOcupata(bool e) {
          esteOcupata = e;
      }

      void ocupa() {
          esteOcupata = true;
      }

      void elibereaza() {
          esteOcupata = false;
      }

       // Overload la operatori
      friend ostream &operator << (ostream &os, const Masa &m) {
          os << "Aceasta masa are capacitate de " << m.getCapacitate() << " persoane!" << endl;
          return os;
      }

      friend istream &operator >> (istream &is, Masa &m) {
          int n;
          is >> n;
          m.setCapacitate(n);

          return is;
      }

      Masa &operator = (const Masa &m) {
          setCapacitate(m.getCapacitate()); setEsteOcupata(m.getEsteOcupata());
          return *this;
      }
  };

  // Clasa Restaurant
  class Restaurant {
      vector<Masa> mese;
      vector<FelPrincipal> feluriPrincipale;
      vector<Garnitura> garnituri;
      vector<Ciorba> ciorbe;
      vector<Desert> deserturi;
      vector<Bautura> bauturi;

      int numarMese;
      int numarPortii;

  public:

      Restaurant() {
          numarMese = 0;
          numarPortii = 0;
      }

      Restaurant(int n, int m, int *vectormese, Portie *vectormenu) {
          numarMese = n;
          numarPortii = m;

          for (int i = 0; i < n; i++) {
              Masa masa(vectormese[i]);
              mese.push_back(masa);
          }

          // Impartirea menu-ului pe categorii
          for (int i = 0; i < m; i++) {
              switch (vectormenu[i].getTip()) {
                  case 1: feluriPrincipale.push_back(FelPrincipal(vectormenu[i], false, "")); break;
                  case 2: garnituri.push_back(Garnitura(vectormenu[i])); break;
                  case 3: ciorbe.push_back(Ciorba(vectormenu[i], false, false)); break;
                  case 4: deserturi.push_back(Desert(vectormenu[i], false, 0)); break;
                  case 5: bauturi.push_back(Bautura(vectormenu[i])); break;
                  default: cout << "NU ESTE BINE";
              }
          }
      }

      ~Restaurant() {
          numarMese = 0;
          numarPortii = 0;
          vector<Masa>().swap(mese);
          vector<FelPrincipal>().swap(feluriPrincipale);
          vector<Ciorba>().swap(ciorbe);
          vector<Desert>().swap(deserturi);
          vector<Garnitura>().swap(garnituri);
          vector<Bautura>().swap(bauturi);
      }

      int getNumarMese() {
          return numarMese;
      }

      int getNumarPortii() {
          return numarPortii;
      }

      Masa getMasa(int index) {
          return mese[index];
      }

      vector<FelPrincipal> getFeluriPrincipale() {
          return feluriPrincipale;
      }

      vector<Garnitura> getGarnituri() {
          return garnituri;
      }

      vector<Ciorba> getCiorbe() {
          return ciorbe;
      }

      vector<Desert> getDeserturi() {
          return deserturi;
      }

      vector<Bautura> getBauturi() {
          return bauturi;
      }

      void setNumarMese(int n) {
          numarMese = n;
      }

      void setNumarPortii(int n) {
          numarPortii = n;
      }

      void setMasa(int index, Masa newMasa) {
          mese[index] = newMasa;
      }

      void afisareFeluriPrincipale() {
          for (int i = 0; i < feluriPrincipale.size(); i++){
              cout << feluriPrincipale[i];
          }
      }

      void afisareGarnituri() {
          for (int i = 0; i < garnituri.size(); i++){
              cout << garnituri[i];
          }
      }

      void afisareCiorbe() {
          for (int i = 0; i < ciorbe.size(); i++){
              cout << ciorbe[i];
          }
      }

      void afisareDeserturi() {
          for (int i = 0; i < deserturi.size(); i++){
              cout << deserturi[i];
          }
      }

      void afisareBauturi() {
          for (int i = 0; i < bauturi.size(); i++){
              cout << bauturi[i];
          }
      }

      void afisareMenu() {
          cout << "In total sunt " << numarPortii << " optiuni in Menu!" << endl;
          cout << endl << "Feluri Principale:" << endl; afisareFeluriPrincipale();
          cout << endl << "Garnituri:" << endl; afisareGarnituri();
          cout << endl << "Ciorbe:" << endl; afisareCiorbe();
          cout << endl << "Deserturi:" << endl; afisareDeserturi();
          cout << endl << "Bauturi:" << endl; afisareBauturi();
      }
  }; Restaurant R;

  // Clasa pentru o persoana
  class Persoana {
      int cheltuieli;
      Portie principal;
      Portie secundar;
      Portie bautura;
      Portie desert;

  public:

      Persoana() {
          cheltuieli = 0;
      }

      Persoana(int n) {
          cheltuieli = n;
      }

      int getCheltuieli() {
          return cheltuieli;
      }

      void setCheltuieli(int n) {
          cheltuieli = n;
      }

      void addCheltuieli(int n) {
          cheltuieli += n;
      }

      void platesteIndividual() {return;}

      void comanda() {

          string raspunsComandaDaNu;

          cout << endl << "Doriti sa comandati? (da/nu)" << endl;
          cin >> raspunsComandaDaNu;

          if(raspunsComandaDaNu != "da" && raspunsComandaDaNu != "Da") { cout << "O zi buna!" << endl; return; }

          // Citire fel principal
          string raspunsFelPrincipal;
          cout << endl << "Doriti felul principal? (da/nu)" << endl;
          cin >> raspunsFelPrincipal;

          if(raspunsFelPrincipal == "da" || raspunsFelPrincipal == "Da") {
              string raspuns;
              cout << endl << "Ce va pot aduce, avem:" << endl; R.afisareFeluriPrincipale();
              cin.ignore();
              getline(cin, raspuns);

              for (auto& i : R.getFeluriPrincipale()) {
                  if (i.getNume() == raspuns) {
                      addCheltuieli(i.getPret());
                  }
              }

              if(raspuns == "Chateaubriand") {
                  string raspuns2;
                  cout << endl << "Cat de facuta sa fie carnea? (putin/foarte)" << endl;
                  getline(cin, raspuns2);
              }
              cout << endl;
          } else {cout << endl;}

          // Citire garnitura
          string raspunsGarnitura;
          cout << "Doriti garnitura? (da/nu)" << endl;
          cin >> raspunsGarnitura;

          if(raspunsGarnitura == "da" || raspunsGarnitura == "Da") {
              string raspuns;
              cout << endl <<"Ce va pot aduce, avem:" << endl; R.afisareGarnituri();
              cin.ignore();
              getline(cin, raspuns);

              for (auto& i : R.getGarnituri()) {
                  if (i.getNume() == raspuns) {
                      addCheltuieli(i.getPret());
                  }
              }

              cout << endl;
          } else {cout << endl;}

          // Citire ciorba
          string raspunsCiorba;
          cout << "Doriti ciorba? (da/nu)" << endl;
          cin >> raspunsCiorba;

          if(raspunsCiorba == "da" || raspunsCiorba == "Da") {
              string raspuns;
              cout << endl << "Ce va pot aduce, avem:" << endl; R.afisareCiorbe();
              cin.ignore();
              getline(cin, raspuns);

              for (auto& i : R.getCiorbe()) {
                  if (i.getNume() == raspuns) {
                      addCheltuieli(i.getPret());
                  }
              }

              string raspunsCiorba2;
              cout << endl << "Doriti ardei? (da/nu)" << endl;

              //cin.ignore();
              getline(cin, raspunsCiorba);

              cout << endl << "Doriti smantana? (da/nu)" << endl;

              //cin.ignore();
              getline(cin, raspunsCiorba);

              cout << endl;
          } else {cout << endl;}

          // Citire desert
          string raspunsDesert;
          cout << "Doriti desert? (da/nu)" << endl;
          cin >> raspunsDesert;

          if(raspunsDesert == "da" || raspunsDesert == "Da") {
              string raspuns;
              cout << endl <<"Ce va pot aduce, avem:" << endl; R.afisareDeserturi();
              cin.ignore();
              getline(cin, raspuns);

              for (auto& i : R.getDeserturi()) {
                  if (i.getNume() == raspuns) {
                      addCheltuieli(i.getPret());
                  }
              }

              if (raspuns == "Inghetata") {
                  string raspuns2;
                  cout << endl << "Cate cupe doriti (3/4/5)" << endl;
                  getline(cin, raspuns2);
                  if (raspuns2 == "4") addCheltuieli(3);
                  if (raspuns2 == "5") addCheltuieli(2);
              }

              cout << endl;
          } else {cout << endl;}

          // Citire bautura
          string raspunsBautura;
          cout << "Doriti de baut? (da/nu)" << endl;
          cin >> raspunsBautura;

          if(raspunsBautura == "da" || raspunsBautura == "Da") {
              string raspuns;
              cout << endl <<"Ce va pot aduce, avem:" << endl; R.afisareBauturi();
              cin.ignore();
              getline(cin, raspuns);

              for (auto& i : R.getBauturi()) {
                  if (i.getNume() == raspuns) {
                      addCheltuieli(i.getPret());
                  }
              }

              cout << endl;
          } else {cout << endl;}

          cout << "Multumesc!" << endl << endl;
      }
  };

  // Clasa pentru un grup de persoane
  class GrupPersoane {
      int totalCheltuieli;
      int ceMasaOcupa;
      int nrpersoane;
      vector<Persoana> persoane;

  public:

      GrupPersoane() {
          nrpersoane = 0;
          ceMasaOcupa = -1;
          totalCheltuieli = 0;
      }

      GrupPersoane(int n) {
          nrpersoane = n;
          ceMasaOcupa = -1;
          totalCheltuieli = 0;
          for(int i = 0; i < n; i++) {
              Persoana p(0);
              persoane.push_back(p);
          }
      }

      GrupPersoane(int n, int m) {
          nrpersoane = n;
          ceMasaOcupa = m;
          totalCheltuieli = 0;
      }

      ~GrupPersoane() {
          nrpersoane = 0;
          ceMasaOcupa = -1;
          totalCheltuieli = 0;
          vector<Persoana>().swap(persoane);
      }

      void ocupaMasa(Restaurant r) {
          for (int i = 0; i < r.getNumarMese(); i++) {
              if (nrpersoane <= r.getMasa(i).getCapacitate() && r.getMasa(i).getEsteOcupata() == false) {
                  ceMasaOcupa = i;
                  r.getMasa(i).ocupa();
                  return;
              }
          }
          cout << "Ne pare rau, nu avem o masa suficient de mare! (" << nrpersoane << " persoane)" << endl;
      }

      void elibereazaMasa(Restaurant r) {
          if (ceMasaOcupa != -1) {
              r.getMasa(ceMasaOcupa).elibereaza();
              ceMasaOcupa = -1;
          } else {
              cout << "Nu ocupati nicio masa momentan." << endl;
          }
      }

      void comandaToti() {
          cout << endl << "Comanda la masa " << ceMasaOcupa;
          for (int i = 0; i < nrpersoane; i++) {
              persoane[i].comanda();
          }
          cout << "Revenim imediat cu mancarea!" << endl;
      }

      void platesteNotaToti() {
          calculeazaCheluieli();
          for (int i = 0; i < nrpersoane; i++) {
              persoane[i].platesteIndividual();
          }
          cout << "A fost platita nota de " << totalCheltuieli << "lei la masa " << ceMasaOcupa << "!";

      }

      void calculeazaCheluieli() {
          totalCheltuieli = 0;
          for (int i = 0; i < nrpersoane; i++) {
              totalCheltuieli += persoane[i].getCheltuieli();
          }
      }

      int getNumarPersoane() const{
          return nrpersoane;
      }

      int getCeMasaOcupa() const{
          return ceMasaOcupa;
      }

      void setNumarPersoane (int n) {
          nrpersoane = n;
      }

      void setCeMasaOcupa (int m) {
          ceMasaOcupa = m;
      }
  };



  int main() {

      ifstream jsonin("mancaruri.json");
      ifstream fin("date.in");

      int nrmese;
      fin >> nrmese;

      // Citire date Restaurant (numar mese + capacitate) + ordonare
      int v[nrmese];
      for (int i = 0; i < nrmese; i++) {
          fin >> v[i];
      }

      for (int i = 0; i < nrmese - 1; i++) {
          for (int j = i + 1; j < nrmese; j++) {
              if (v[i] > v[j]) {
                  int aux = v[i];
                  v[i] = v[j];
                  v[j] = aux;
              }
          }
      }

      // Citire numar grupuri
      int nrgrupuri;
      fin >> nrgrupuri;
      vector<GrupPersoane> grupuriPersoane;

      int g[nrgrupuri];
      for (int i = 0; i < nrgrupuri; i++) {
          fin >> g[i];
          GrupPersoane gp(g[i]);
          grupuriPersoane.push_back(gp);
      }

      // Citire feluri de mancare din menu (din json)
      json j;
      jsonin >> j;

      int index, nrportii = j.size();

      Portie menu[nrportii];

      index = 0;
      for (auto& pr : j.items()) {
          string nume = pr.value()["nume"];
          int tip = pr.value()["tip"];
          int pret = pr.value()["pret"];
          int gramaj = pr.value()["gramaj"];

          menu[index] = Portie(nume, tip, pret, gramaj);
          index++;
      }

      // Crearea unui restaurant
      R = Restaurant(nrmese, nrportii, v, menu);
      R.afisareMenu();

      for (int i = 0; i < nrgrupuri; i++) {
          grupuriPersoane[i].ocupaMasa(R);
      }

      for (int i = 0; i < nrgrupuri; i++) {
          if (grupuriPersoane[i].getCeMasaOcupa() >= 0) {
              grupuriPersoane[i].comandaToti();
          }
      }
      cout << endl << "Toate comenzile au fost luate!" << endl << endl;

      for (int i = 0; i < nrgrupuri; i++) {
          if (grupuriPersoane[i].getCeMasaOcupa() >= 0) {
              grupuriPersoane[i].platesteNotaToti();
          }
      }

      cout << endl << endl << "Toate mesele au fost platite!" << endl;

      return 0;
  }
