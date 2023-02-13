
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//clasa abstracta
class senzor {
private:
	const int id;
	char* detaliiTehnice;
	float durataViata;
	int timpInteractiune;
	static int unic;

public:
	senzor() :id(unic++) {
		detaliiTehnice = new char[strlen("necunoscute") + 1];
		strcpy_s(detaliiTehnice, strlen("necunoscute") + 1, "necunoscute");
		durataViata = NULL;
		timpInteractiune = NULL;
	}
	senzor(const char* detaliiTehnice, float durataViata, int timpInteractiune) :id(unic++) {
		this->detaliiTehnice = new char[strlen(detaliiTehnice) + 1];
		strcpy_s(this->detaliiTehnice, strlen(detaliiTehnice) + 1, detaliiTehnice);
		this->durataViata = durataViata;
		this->timpInteractiune = timpInteractiune;
	}
	//constructor de copiere
	senzor(const senzor& s) :id(unic++) {
		this->detaliiTehnice = new char[strlen(s.detaliiTehnice) + 1];
		strcpy_s(this->detaliiTehnice, strlen(s.detaliiTehnice) + 1, s.detaliiTehnice);
		this->durataViata = s.durataViata;
		this->timpInteractiune = s.timpInteractiune;
	}
	//operatorul =
	senzor& operator= (const senzor& s) {
		if (this->detaliiTehnice != NULL) { delete[]this->detaliiTehnice; }
		this->detaliiTehnice = new char[strlen(s.detaliiTehnice) + 1];
		strcpy_s(this->detaliiTehnice, strlen(s.detaliiTehnice) + 1, s.detaliiTehnice);
		this->durataViata = s.durataViata;
		this->timpInteractiune = s.timpInteractiune;
		return *this;
	}
	const int getid() {
		return id;
	}
	char* getdetaliiTehnice() {
		return detaliiTehnice;
	}
	void setdetaliiTehnice(char* detalii) {
		if (detalii != NULL) {
			delete[]this->detaliiTehnice;
		}
		this->detaliiTehnice = new char[strlen(detalii) + 1];
		for (int i = 0; i < strlen(detalii) + 1; i++)
		{
			this->detaliiTehnice[i] = detalii[i];
		}
	}
	//functie virtuala
	virtual float getdurataViata() {
		return durataViata;
	}
	virtual float durataViataCustom(float a) {
		durataViata = a;
		return durataViata;
	}

	void setdurataViata(float valoare) {
		if (valoare > 0) {
			this->durataViata = valoare;
		}
	}



	virtual int gettimpInteractiune()
	{
		return timpInteractiune;
	}
	//functie virtuala
	virtual int timpInteractiuneCustom(int b) {
		timpInteractiune = b;
		return timpInteractiune;
	}
	void settimpInteractiune(int valoare) {
		if (valoare > 0) {
			this->timpInteractiune = valoare;
		}
	}



	//operatorul<<
	friend ostream& operator<<(ostream& afisare, const senzor& s) {
		//afisare << endl << "--------------------------------------------------------" << endl;
		afisare << s.id << ". Detaliile tehnice ale senzorului sunt: " << s.detaliiTehnice
			<< " . Durata vietii ai acestuia este  " << s.durataViata << " ani, iar timpul de actionare este de   " << s.timpInteractiune << " milisecunde.";
		//afisare << endl << "--------------------------------------------------------" << endl;
		return afisare;
	}
	//operatorul>>
	friend istream& operator>>(istream& citire, senzor& s);
	//destructor
	~senzor() {
		delete[] this->detaliiTehnice;
	}

	//operatorul+
	senzor operator+(int timpTnteractiune) {
		senzor s = *this;
		s.timpInteractiune += timpInteractiune;
		return s;
	}

	//preincrementare++
	senzor operator++() {
		timpInteractiune++;
		return *this;
	}
	//postincrementare ++
	senzor operator++(int) {
		senzor aux = *this;
		aux.timpInteractiune++;
		return aux;
	}
	//operatorul *
	senzor operator*(int valoare) {
		senzor s = *this;
		s.timpInteractiune *= valoare;
		return s;
	}
	//operatorul+=
	senzor operator+=(const senzor& s) {
		this->timpInteractiune += s.timpInteractiune;
		return *this;
	}


};
int senzor::unic = 1;

istream& operator>>(istream& citire, senzor& s) {
	cout << "Detaliile tehnice ale senzorului sunt:";
	citire >> s.detaliiTehnice;
	cout << endl << "Durata vietii ai acestuia este";
	citire >> s.durataViata; cout << " ani.";
	cout << endl << "Timpul de actionare este de";
	citire >> s.timpInteractiune; cout << " milisecunde.";
	cout << "Detaliile tehnice : " << s.detaliiTehnice << " , dutata de viata este de " << s.durataViata << " ani" << " si timpul de actionare de " << s.timpInteractiune << " milisecunde.";
	return citire;
}



//clasa care va fi mostenita
class DateLocalizare {
private:
	string judet;
	string oras;
	string strada;
	int nrLocuinta;
public:
	DateLocalizare() {

		judet = "necunoscut";
		oras = "necunoscut";
		strada = "necunoscuta";
		nrLocuinta = NULL;
	}
	DateLocalizare(string judet, string oras, string strada, int nrLocuinta) {
		this->judet = judet;
		this->oras = oras;
		this->strada = strada;
		this->nrLocuinta = nrLocuinta;
	}
	//constructor de copiere
	DateLocalizare(const DateLocalizare& d) {
		this->judet = d.judet;
		this->oras = d.oras;
		this->strada = d.strada;
		this->nrLocuinta = d.nrLocuinta;
	}
	//operatorul =
	DateLocalizare operator=(const DateLocalizare& d) {
		this->judet = d.judet;
		this->oras = d.oras;
		this->strada = d.strada;
		this->nrLocuinta = d.nrLocuinta;
		return *this;
	}

	string getjudet() {
		return judet;
	}
	void setjudet(string judetnou) {
		if (judetnou.length() > 2) {
			this->judet = judetnou;
		}
	}
	string getoras() {
		return oras;
	}
	void setoras(string orasnou) {
		if (orasnou.length() > 2) {
			this->oras = orasnou;
		}
	}
	string getstrada() {
		return strada;
	}
	void setstrada(string  stradanou) {
		if (stradanou.length() > 2) {
			this->strada = stradanou;
		}
	}
	int getnrLocuinta() {
		return nrLocuinta;
	}
	void setnrLocuinta(int nrLocuintanou) {
		if (nrLocuintanou > 0) {
			this->nrLocuinta = nrLocuintanou;
		}

	}
	//operatorul<<
	friend ostream& operator<<(ostream& afisare, const DateLocalizare& d) {
		//afisare << endl << "--------------------------------------------------------" << endl;
		afisare << "Date de localizare: Judetul  " << d.judet << " , Orasul " << d.oras << " , Strada  " << d.strada << " , Nr. " << d.nrLocuinta;
		//afisare << endl << "--------------------------------------------------------" << endl;
		return afisare;
	}
	//operatorul>>
	friend istream& operator>>(istream& citire, DateLocalizare& d);

	//operatorul+
	DateLocalizare operator+(int nrLocuinta) {
		DateLocalizare d = *this;
		d.nrLocuinta += nrLocuinta;
		return d;
	}

	//preincrementare
	DateLocalizare operator++() {
		nrLocuinta++;
		return *this;
	}
	//postincrementare 
	DateLocalizare operator++(int) {
		DateLocalizare aux = *this;
		nrLocuinta++;
		return aux;
	}
	//operatorul/
	DateLocalizare operator/(int valoare) {
		DateLocalizare d = *this;
		d.nrLocuinta /= valoare;
		return d;
	}
	//operatorul-
	DateLocalizare operator-(int nr) {
		DateLocalizare d = *this;
		if (nr < d.nrLocuinta)
		{
			d.nrLocuinta -= nr;
		}
		else { d.nrLocuinta = 0; }
		return d;
	}


};
istream& operator>>(istream& citire, DateLocalizare& d) {
	cout << "Introduceti datele de localizare" << endl;
	cout << "Judetul: ";
	citire >> d.judet;
	cout << endl << "Orasul: ";
	citire >> d.oras;
	cout << endl << "strada: ";
	citire >> d.strada;
	cout << endl << "Nr: ";
	citire >> d.nrLocuinta; cout << endl;
	cout << "Date de localizare: Judetul  " << d.judet << " , Orasul " << d.oras << " , Strada  " << d.strada << " , Nr. " << d.nrLocuinta << endl;
	return citire;
}




class senzorincendiu :public senzor, private DateLocalizare {
private:
	int nrInteractiuni;
	int* nrResetariLuna;
	string locAmplasare;
	float distantaSenzori;
	bool conectare;
public:
	//functiile virtuale
	float durataNoua;
	int timpNou;
	float durataViataCustom(float a) {
		durataNoua = 2 * a;
		return durataNoua;
	}
	int timpInteractiuneCustom(int b) {
		timpNou = 2 * b;
		return timpNou;
	}
	senzorincendiu() :senzor(), DateLocalizare() {
		nrInteractiuni = 1;
		nrResetariLuna = new int[nrInteractiuni];
		for (int i = 0; i < nrInteractiuni; i++) {
			nrResetariLuna[i] = 1;
		}
		locAmplasare = "nrcunoscut";
		distantaSenzori = NULL;
		conectare = false;
	}
	senzorincendiu(int nrInteractiuni, int* nrResetariLuna, string locAmplasare, float distantaSenzori, bool conectare,
		const char* detaliiTehnice, float durataViata, int timpInteractiune,
		string judet, string oras, string strada, int nrLocuinta) :
		senzor(detaliiTehnice, durataViata, timpInteractiune),
		DateLocalizare(judet, oras, strada, nrLocuinta) {
		this->nrInteractiuni = nrInteractiuni;
		this->nrResetariLuna = new int[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++) {
			this->nrResetariLuna[i] = nrResetariLuna[i];
		}
		this->locAmplasare = locAmplasare;
		this->distantaSenzori = distantaSenzori;
		this->conectare = conectare;
	}
	int getnrInteractiuni() {
		return nrInteractiuni;
	}
	void setnrInteractiuni(int nr) {
		if (nr > 0) {
			this->nrInteractiuni = nr;
		}

	}

	int* getnrResetariLuna() {
		return nrResetariLuna;
	}
	void setnrResetariLuna(int nrInteractiuni, int* resetari) {
		setnrInteractiuni(nrInteractiuni);
		delete[]this->nrResetariLuna;
		if (resetari != nullptr) {
			this->nrResetariLuna = new int[nrInteractiuni];
			for (int i = 0; i < nrInteractiuni; i++) {
				this->nrResetariLuna[i] = resetari[i];
			}
		}
	}
	string getlocAmplasare() {
		return locAmplasare;
	}
	void setlocAmplasare(string Amplasare) {
		if (Amplasare.length() > 2) {
			this->locAmplasare = Amplasare;
		}
	}
	float getdistantaSenzori() {
		return distantaSenzori;
	}
	void setdistantaSenzori(float distanta) {
		if (distanta > 0) {
			this->distantaSenzori = distanta;
		}
	}
	bool getconectare() {
		return conectare;
	}
	void setconectare(bool c) {

		this->conectare = c;

	}
	~senzorincendiu() {
		delete[]this->nrResetariLuna;

	}
	//constructor copiere
	senzorincendiu(const senzorincendiu& si) :
		senzor(si), DateLocalizare(si) {
		this->nrInteractiuni = si.nrInteractiuni;
		this->nrResetariLuna = new int[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++) {
			this->nrResetariLuna[i] = si.nrResetariLuna[i];
		}
		this->locAmplasare = si.locAmplasare;
		this->distantaSenzori = si.distantaSenzori;
		this->conectare = si.conectare;
	}
	//operator=
	senzorincendiu operator=(const senzorincendiu& si) {
		senzor::operator=(si);
		DateLocalizare::operator=(si);
		delete[]this->nrResetariLuna;
		this->nrInteractiuni = si.nrInteractiuni;
		this->nrResetariLuna = new int[this->nrInteractiuni];
		for (int i = 0; i < this->nrInteractiuni; i++) {
			this->nrResetariLuna[i] = si.nrResetariLuna[i];
		}
		this->locAmplasare = si.locAmplasare;
		this->distantaSenzori = si.distantaSenzori;
		this->conectare = si.conectare;
		return *this;
	}
	friend ostream& operator<<(ostream& afisare, const senzorincendiu& si) {
		afisare << endl << "............................................................................................." << endl;
		afisare << (senzor)si; afisare << endl;
		afisare << (DateLocalizare)si; afisare << endl;
		afisare << "Numarul de interactiuni cu senzorul este  " << si.nrInteractiuni << " ori , iar intre interactiuni senzorul a fost resetat de ";
		for (int i = 0; i < si.nrInteractiuni; i++) {
			afisare << si.nrResetariLuna[i] << ", ";
		}
		afisare << " este amplasat in " << si.locAmplasare << " , iar distanta dintre el si ceilalti senzori este de " << si.distantaSenzori << endl;
		if (si.conectare == 1) {
			afisare << " Senzorul este conectat cu succces!";
		}
		else { afisare << "Senzorul nu este conectat, va rugam sa verificati conexiunea !"; }
		afisare << endl << ".............................................................................................";

		return afisare;
	}
	friend istream& operator>>(istream& citire, senzorincendiu& si);

	//operator+
	senzorincendiu operator+ (int nrInteractiuni) {
		senzorincendiu si = *this;
		delete[] si.nrResetariLuna;
		si.nrInteractiuni += nrInteractiuni;
		si.nrResetariLuna = new int[si.nrInteractiuni];
		for (int i = 0; i < nrInteractiuni; i++) {
			si.nrResetariLuna[i] = this->nrResetariLuna[i];
		}
		for (int i = this->nrInteractiuni; i < si.nrInteractiuni; i++) {
			si.nrResetariLuna[i] = 2;
		}
		return si;
	}


	//preincrementare++
	senzorincendiu operator++() {
		for (int i = 0; i < nrInteractiuni; i++) {
			nrResetariLuna[i]++;
		}
		return *this;
	}

	//postincrementare++
	senzorincendiu operator++(int) {
		senzorincendiu aux = *this;
		for (int i = 0; i < nrInteractiuni; i++) {
			nrResetariLuna[i]++;
		}
		return aux;
	}
	//preincrementare--
	senzorincendiu operator--() {
		for (int i = 0; i < nrInteractiuni; i++) {
			if (nrResetariLuna[i] >= 1) {
				nrResetariLuna[i]--;
			}
		}
		return *this;
	}

	//postincrementare--
	senzorincendiu operator--(int) {
		senzorincendiu aux = *this;
		for (int i = 0; i < nrInteractiuni; i++) {
			if (nrResetariLuna[i] >= 1) {
				nrResetariLuna[i]--;
			}
		}
		return aux;
	}
	//operator index=operator[]
	int& operator[](int index) {
		if (index >= 0 && index < nrInteractiuni) {
			return nrResetariLuna[index];
		}

	}
	static void citireListaSenzorInc(string numeFisier, senzorincendiu*& colectiesenzori, int& nrSenzori)
	{
		ifstream fisier(numeFisier, ios::in);
		if (!fisier.is_open()) {
			cout << endl << "Fisierul nu exista!";
		}
		else {
			fisier >> nrSenzori;
			if (colectiesenzori != nullptr) {
				delete[]colectiesenzori;
			}
			colectiesenzori = new senzorincendiu[nrSenzori];
			for (int i = 0; i < nrSenzori; i++) {
				fisier >> colectiesenzori[i].nrInteractiuni;
				for (int j = 0; j < colectiesenzori[i].nrInteractiuni; j++) {
					fisier >> colectiesenzori[i].nrResetariLuna[j];;
				}
				fisier >> colectiesenzori[i].distantaSenzori;
				fisier >> colectiesenzori[i].locAmplasare;
				fisier >> colectiesenzori[i].conectare;
			}
			fisier.close();

		}
	}
};
istream& operator>>(istream& citire, senzorincendiu& si) {
	cout << endl << "............................................................................................." << endl;
	citire >> (senzor&)si;
	cout << endl;
	citire >> (DateLocalizare&)si;
	cout << endl;
	cout << "Numarul de interactiuni cu senzorul este  ";
	citire >> si.nrInteractiuni;

	cout << " ori , iar intre interactiuni senzorul a fost resetat de ";
	delete[]si.nrResetariLuna;
	si.nrResetariLuna = new int[si.nrInteractiuni];
	for (int i = 0; i < si.nrInteractiuni; i++) {

		citire >> si.nrResetariLuna[i];
		cout << ", ";
	}
	cout << ", este amplasat in "; citire >> si.locAmplasare; cout << " , iar distanta dintre el si ceilalti senzori este de "; citire >> si.distantaSenzori; cout << " , starea conectarii este "; citire >> si.conectare;
	cout << endl << "...............................................................................................";

	return citire;
}

class senzortemperatura :public senzor, private DateLocalizare {
private:
	int nrRidicariTemperatura;
	float* Grade;
	string AmplasareTermometru;
	float distantaSenzori;
	float temperaturapotrivita;
	bool conectare;
public:
	float durataNoua;
	int timpNou;
	float durataViataCustom(float a) {
		durataNoua = 2 * a;
		return durataNoua;
	}
	int timpInteractiuneCustom(int b) {
		timpNou = 2 * b;
		return timpNou;
	}
	senzortemperatura() :senzor(), DateLocalizare() {
		nrRidicariTemperatura = 1;
		Grade = new float[nrRidicariTemperatura];
		for (int i = 0; i < nrRidicariTemperatura; i++) {
			Grade[i] = 25.6;
		}
		temperaturapotrivita = 0;
		AmplasareTermometru = "nrcunoscut";
		distantaSenzori = NULL;
		conectare = false;
	}
	senzortemperatura(int nrRidicariTemperatura, float* Grade, string AmplasareTermometru, float temperaturapotrivita, float distantaSenzori, bool conectare, const char* detaliiTehnice, float durataViata, int timpInteractiune,
		string judet, string oras, string strada, int nrLocuinta) :
		senzor(detaliiTehnice, durataViata, timpInteractiune),
		DateLocalizare(judet, oras, strada, nrLocuinta) {
		this->nrRidicariTemperatura = nrRidicariTemperatura;
		this->Grade = new float[this->nrRidicariTemperatura];
		for (int i = 0; i < this->nrRidicariTemperatura; i++) {
			this->Grade[i] = Grade[i];
		}
		this->temperaturapotrivita = temperaturapotrivita;
		this->AmplasareTermometru = AmplasareTermometru;
		this->distantaSenzori = distantaSenzori;
		this->conectare = conectare;
	}
	int getnrRidicariTemperatura() {
		return nrRidicariTemperatura;
	}
	void setnrRidicariTemperatura(int nr) {
		if (nr > 0) {
			this->nrRidicariTemperatura = nr;
		}

	}
	float* getGrade() {
		return Grade;
	}
	void setGrade(int nrRidicariTemperatura, int* resetari) {
		setnrRidicariTemperatura(nrRidicariTemperatura);
		delete[]this->Grade;
		if (resetari != nullptr) {
			this->Grade = new float[nrRidicariTemperatura];
			for (int i = 0; i < nrRidicariTemperatura; i++) {
				this->Grade[i] = resetari[i];
			}
		}
	}
	string getAmplasareTermometru() {
		return AmplasareTermometru;
	}
	void setAmplasareTermometru(string Amplasare) {
		if (Amplasare.length() > 2) {
			this->AmplasareTermometru = Amplasare;
		}
	}
	float gettemperaturapotrivita() {
		return temperaturapotrivita;
	}
	void settemperaturapotrivita(float temperatura) {
		if (temperatura > 0) { this->temperaturapotrivita = temperatura; }
	}
	float getdistantaSenzori() {
		return distantaSenzori;
	}
	void setdistantaSenzori(float distanta) {
		if (distanta > 0) {
			this->distantaSenzori = distanta;
		}
	}
	bool getconectare() {
		return conectare;
	}
	void setconectare(bool c) {

		this->conectare = c;

	}
	~senzortemperatura() {
		delete[]this->Grade;

	}
	//constructor copiere
	senzortemperatura(const senzortemperatura& st) :
		senzor(st), DateLocalizare(st) {
		this->nrRidicariTemperatura = st.nrRidicariTemperatura;
		this->Grade = new float[this->nrRidicariTemperatura];
		for (int i = 0; i < this->nrRidicariTemperatura; i++) {
			this->Grade[i] = st.Grade[i];
		}
		this->AmplasareTermometru = st.AmplasareTermometru;
		this->distantaSenzori = st.distantaSenzori;
		this->conectare = st.conectare;
		this->temperaturapotrivita = st.temperaturapotrivita;

	}
	//operator=
	senzortemperatura operator=(const senzortemperatura& st) {
		senzor::operator=(st);
		DateLocalizare::operator=(st);
		delete[]this->Grade;
		this->nrRidicariTemperatura = st.nrRidicariTemperatura;
		this->Grade = new float[this->nrRidicariTemperatura];
		for (int i = 0; i < this->nrRidicariTemperatura; i++) {
			this->Grade[i] = st.Grade[i];
		}
		this->temperaturapotrivita = st.temperaturapotrivita;
		this->AmplasareTermometru = st.AmplasareTermometru;
		this->distantaSenzori = st.distantaSenzori;
		this->conectare = st.conectare;
		return *this;
	}
	friend ostream& operator<<(ostream& afisare, const senzortemperatura& st) {
		afisare << endl << "............................................................................................." << endl;
		afisare << (senzor)st; afisare << endl;
		afisare << (DateLocalizare)st; afisare << endl;
		afisare << "Numarul de RidicariTemperatura este:   " << st.nrRidicariTemperatura << " ori , iar gradele la care a fost ridicat sunt ";
		for (int i = 0; i < st.nrRidicariTemperatura; i++) {
			afisare << st.Grade[i] << ", ";
		}
		afisare << "Temperatura potrivita selectata este : " << st.temperaturapotrivita << " grade C " << endl;
		afisare << ", este amplasat in " << st.AmplasareTermometru << " , iar distanta dintre el st ceilalti senzori este de " << st.distantaSenzori << endl;
		if (st.conectare == 1) {
			afisare << " Senzorul este conectat cu succces!";
		}
		else { afisare << "Senzorul nu este conectat, va rugam sa verificati conexiunea !"; }
		afisare << endl << "............................................................................................." << endl;

		return afisare;
	}
	friend istream& operator>>(istream& citire, senzortemperatura& st);

	//operator+
	senzortemperatura operator+ (int nrRidicariTemperatura) {
		senzortemperatura st = *this;
		delete[] st.Grade;
		st.nrRidicariTemperatura += nrRidicariTemperatura;
		st.Grade = new float[st.nrRidicariTemperatura];
		for (int i = 0; i < this->nrRidicariTemperatura; i++) {
			st.Grade[i] = this->Grade[i];
		}
		for (int i = this->nrRidicariTemperatura; i < st.nrRidicariTemperatura; i++) {
			st.Grade[i] = 25;
		}
		return st;
	}
	//preincrementare++
	senzortemperatura operator++() {
		for (int i = 0; i < nrRidicariTemperatura; i++) {
			Grade[i]++;
		}
		return *this;
	}

	//postincrementare++
	senzortemperatura operator++(int) {
		senzortemperatura aux = *this;
		for (int i = 0; i < nrRidicariTemperatura; i++) {
			Grade[i]++;
		}
		return aux;
	}
	//preincrementare--
	senzortemperatura operator--() {
		for (int i = 0; i < nrRidicariTemperatura; i++) {
			if (Grade[i] >= 1) {
				Grade[i]--;
			}
			return *this;
		}
	}

	//postincrementare--
	senzortemperatura operator--(int) {
		senzortemperatura aux = *this;
		for (int i = 0; i < nrRidicariTemperatura; i++) {
			if (Grade[i] >= 1) {
				Grade[i]--;
			}
		}
		return aux;
	}
	//operator index-operator[]
	float& operator[](int index) {
		if (index >= 0 && index < nrRidicariTemperatura) {
			return Grade[index];
		}

	}
	static void citireListaSenzorTemp(string numeFisier, senzortemperatura*& colectiesenzori, int& nrSenzori)
	{
		ifstream fisier(numeFisier, ios::in);
		if (!fisier.is_open()) {
			cout << endl << "Fisierul nu exista!";
		}
		else {
			fisier >> nrSenzori;
			if (colectiesenzori != nullptr) {
				delete[]colectiesenzori;
			}
			colectiesenzori = new senzortemperatura[nrSenzori];
			for (int i = 0; i < nrSenzori; i++) {
				fisier >> colectiesenzori[i].nrRidicariTemperatura;
				for (int j = 0; j < colectiesenzori[i].nrRidicariTemperatura; j++) {
					fisier >> colectiesenzori[i].Grade[j];;
				}
				fisier >> colectiesenzori[i].distantaSenzori;
				fisier >> colectiesenzori[i].temperaturapotrivita;
				fisier >> colectiesenzori[i].conectare;
			}
			fisier.close();

		}
	}
};
istream& operator>>(istream& citire, senzortemperatura& st) {
	cout << endl << "********************************************************************************************" << endl;
	citire >> (senzor&)st;
	cout << endl;
	citire >> (DateLocalizare&)st;
	cout << endl;
	cout << "Numarul de RidicariTemperatura este  ";
	citire >> st.nrRidicariTemperatura;

	cout << " ori , iar gradele la care a urcat sunt: ";
	delete[]st.Grade;
	st.Grade = new float[st.nrRidicariTemperatura];
	for (int i = 0; i < st.nrRidicariTemperatura; i++) {

		citire >> st.Grade[i];
		cout << ", ";
	}
	cout << " este amplasat in "; citire >> st.AmplasareTermometru; cout << " , iar distanta dintre el st ceilalti senzori este de "; citire >> st.distantaSenzori; cout << " , starea conectarii este "; citire >> st.conectare;
	cout << endl << "********************************************************************************************" << endl;

	return citire;
}
template<class T>
class profil {
private:
	T* colectieSenzori;
	int nrSenzori;
public:
	profil() {
		this->nrSenzori = 0;
		this->colectieSenzori = NULL;
	}
	profil(T* colectieSenzori, int nrSenzori) {
		this->nrSenzori = nrSenzori;
		this->colectieSenzori = new T[this->nrSenzori];
		for (int i = 0; i < this->nrSenzori; i++) {
			this->colectieSenzori[i] = colectieSenzori[i];
		}

	}

	profil(const profil& p) {
		this->nrSenzori = p.nrSenzori;
		this->colectieSenzori = new T[this->p.nrSenzori];
		for (int i = 0; i < this->p.nrSenzori; i++) {
			this->colectieSenzori[i] = p.colectieSenzori[i];
		}
	}
	profil& operator=(const profil& p) {
		delete[]this->colectieSenzori;
		this->nrSenzori = p.nrSenzori;
		this->colectieSenzori = new T[this->p.nrSenzori];
		for (int i = 0; i < this->p.nrSenzori; i++) {
			this->colectieSenzori[i] = p.colectieSenzori[i];
		}
		return *this;
	}

	~profil() {
		delete[]this->colectieSenzori;
	}
	float media() {
		float media = 0;
		for (int i = 0; i < this->nrSenzori; i++) {
			media += colectieSenzori[i];
		}
		return media / nrSenzori;
	}

	friend ostream& operator<<(ostream& afisare, const profil& p) {

		for (int i = 0; i < p.nrSenzori; i++) {
			afisare << p.colectieSenzori[i] << endl;
			afisare << endl;
		}
		return afisare;
	}

};




void main() {
	DateLocalizare d;
	DateLocalizare d1("Arges", "Topoloveni", "mihai mihail", 12);
	DateLocalizare d2;
	//cout << d;
	//cout << d1;
	//cout << d2;
	//senzor s;
	senzor s1("nou", 10.8, 4);
	//cout << s;
	//cout << s1;
	int* vector = new int[3] {1, 4, 3};
	senzorincendiu si(3, vector, "sufragerie", 10.5, true, "Senzor incendiu", 20, 5, " Valcea", "Ramnicu Valcea", "Calea pacanelelor", 8), si1;
	/*cout << si;
	cout << si1;*/
	float* temperatura = new float[3] {26.5, 24.4, 28};
	senzortemperatura st, st1(3, temperatura, "dormitor", 21.5, 20, true, "Senzor termometru", 20, 6, "Arges", "Pitesti", "Calea Bucuresti", 5);
	//cout << st;
	//cout << st1;

	cout << endl << "................................................" << endl;
	//operatorul=
	cout << "operatorul=" << endl;
	cout << "................................................" << endl;
	senzor s2 = s1;
	cout << s2;
	DateLocalizare d3 = d1;
	cout << d3;
	senzorincendiu si2 = si;
	cout << si2;
	senzortemperatura st2 = st1;
	cout << st2;
	cout << endl << "................................................" << endl;
	//operatorul+
	cout << "operatorul+" << endl;
	cout << "................................................" << endl;
	senzor s3 = s2 + 2;
	DateLocalizare d4 = d3 + 4;
	senzorincendiu si3 = si2 + 3;
	senzortemperatura st3 = st2 + 2;
	cout << s3 << endl << d4 << endl << si3 << endl << st3;

	cout << endl << "................................................" << endl;
	//operatorul-
	cout << "operatorul-" << endl;
	cout << "................................................" << endl;
	DateLocalizare d5 = d4 - 3;
	cout << d5;
	cout << endl << "................................................" << endl;
	//operatorul*
	cout << "operatorul*" << endl;
	cout << "................................................" << endl;
	senzor s4 = s3 * 2;
	cout << s4;
	cout << endl << "................................................" << endl;

	//operatorul/
	cout << "operatorul/" << endl;
	cout << "................................................" << endl;
	DateLocalizare d6 = d5 / 2;
	cout << d6;
	cout << endl << "................................................" << endl;
	//operatorul[]-index
	cout << "operatorul[]-index" << endl;
	cout << "................................................" << endl;
	cout << si3[2] << endl;
	cout << st3[3];
	cout << endl << "................................................" << endl;
	//preincrementare++
	cout << "preincrementare++" << endl;
	cout << "................................................" << endl;
	cout << ++d4;
	cout << endl << "................................................" << endl;
	//postincrementare++
	cout << "postincrementare++" << endl;
	cout << "................................................" << endl;
	cout << d4++;
	cout << endl << "................................................" << endl;
	//preincrementare--
	cout << "preincrementare--" << endl;
	cout << "................................................" << endl;
	cout << --si3;
	cout << endl << "................................................" << endl;
	//postincrementare--
	cout << "postincrementare--" << endl;
	cout << "................................................" << endl;
	cout << si3--;
	cout << endl << "................................................" << endl;
	//operatorul+=
	cout << "operatorul+=" << endl;
	cout << "................................................" << endl;
	senzor s5;
	s5 += s4;
	cout << s5;
	cout << endl << "................................................" << endl;

	//testare functie virtuala
	cout << endl << "................................................" << endl;
	cout << " functie virtuala" << endl;
	cout << "................................................" << endl;
	senzorincendiu i;
	senzortemperatura t;
	cout << i.durataViataCustom(7.5);
	cout << endl;
	cout << t.timpInteractiuneCustom(3);
	cout << endl << "................................................" << endl;

	//clasa template
	cout << endl << "................................................" << endl;
	cout << endl << "Clasa template - profil" << endl;
	cout << "................................................" << endl;
	int* colectie = new int[3] {1, 2, 3};
	profil<int>p(colectie, 3);
	cout << p << endl;
	cout << "Media: " << p.media() << endl;
	cout << endl;
	senzorincendiu vectorSI[] = { si1,si2 };
	profil<senzorincendiu>p2(vectorSI, 2);
	cout << p2 << endl;
	cout << endl << "................................................" << endl;

	cout << "................................................" << endl;
	cout << "Scriem obiectele de tip senzor in fisier" << endl;
	cout << "................................................" << endl;
	//ofstream fisier("senzori.txt",ios::out);
	//fisier << si<<endl;
	//
	///*fstream fisier2("senzori.txt", ios::in);
	//fisier2 >> s3;*/
	senzorincendiu* colectieSenzori = new senzorincendiu[3]{ si,si2,si3 };
	int nrSenzori = 3;
	//   /*cout << "senzori.txt"<<endl;
	   senzorincendiu::citireListaSenzorInc("senzor.txt", colectieSenzori, nrSenzori);
	profil<senzorincendiu >p3(colectieSenzori, nrSenzori);
	//fisier << p3<<endl;
	//fisier.close();
	/*string caleFisier;
	cout << "Introduceti numele fisierului:";
	cin >> caleFisier;
	ofstream fisier(caleFisier, ios::app);
	fisier << st << endl;
	fisier << p3 << endl;
	fisier.close();*/
	cout << endl << "Datele au fost introduse, verificati fisierul!" << endl;
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;


}