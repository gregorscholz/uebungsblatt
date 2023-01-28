#include <string>
#include <vector>

#pragma once
class MESSWERT {
	double wert;
	std::string einheit;

	char basiseinheiten[3] = {'V', 'A', 'W'};
	char vorsatzzeichen[5] = {'n', 'u', 'k', 'm', 'M'};

	bool einheitValid(std::string e);

	public:
		MESSWERT();
		MESSWERT(double w, std::string e);
		MESSWERT(const MESSWERT& m);
		void setMesswert(double w, std::string e);
		double getWert();
		std::string getEinheit();
		void print();
		void normierung();
};

#pragma once
class MESSREIHE {
	int anzahlMesswerte;
	MESSWERT* messwertPointer;
	std::vector<MESSWERT> messreihe;

	public:
		MESSREIHE(int anzahl);
		MESSREIHE(const MESSREIHE &m);
		~MESSREIHE();
		MESSWERT getMesswertAtIndex(int index);
		void setMesswertAtIndex(MESSWERT m, int index);
		int getAnzahlMesswerte();
		void print();
		MESSWERT getMinMesswert();
		MESSWERT getMaxMesswert();
};
