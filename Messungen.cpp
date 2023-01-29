#include "Messungen.h"
#include <iostream>

MESSREIHE aufgabe_l() {
	/**
	 * Erzeugen Sie eine Messreihe mit 5 Elementen und belegen Sie diese
	 * mit folgenden Messwerten: 10 mA, 20 mA, 30 mA, 40 mA, 50 mA.
	 */
	MESSREIHE mr = MESSREIHE(5);
	for (int i = 1; i < mr.getAnzahlMesswerte() + 1; i++) {
		mr.setMesswertAtIndex(MESSWERT(10 * i, "mA"), i - 1);
	};
	
	return mr;
}

MESSREIHE aufgabe_m(MESSREIHE mr) {
	/**
	 * Erzeugen Sie mit dem Kopierkonstruktor eine Kopie dieser Messreihe.
	 * Skalieren Sie in dieser Kopie alle Messwerte mit dem Faktor 2.
	 * Verwenden Sie dafuer eine Schleife, die für beliebige Laengen der
	 * Messreihe korrekt funktioniert.
	 */
	MESSREIHE mr_kopie = mr;

	for (int i = 0; i < mr_kopie.getAnzahlMesswerte(); i++) {
		MESSWERT mw = MESSWERT(
				mr.getMesswertAtIndex(i).getWert() * 2, 
				mr.getMesswertAtIndex(i).getEinheit());
		mr_kopie.setMesswertAtIndex(mw, i);
	};

	return mr_kopie;
}

void aufgabe_n(MESSREIHE mr, MESSREIHE mr2) {
	/**
	 * Geben Sie die beiden Messreihen aus mittels der Methode aus i) aus.
	 */
	std::cout << "Messreihe 1:" << std::endl;
	mr.print();
	
	std::cout << std::endl;

	std::cout << "Messreihe 2:" << std::endl;
	mr2.print();
};

MESSREIHE aufgabe_o() {
	/**
	 * Erzeugen Sie eine dritte Messreihe mit 5 Elementen und belegen Sie
	 * diese mit den folgenden Werten: 5 V, 2.3 kV, 4.53 uV, 27 mV, 10 nV.
	 */
	MESSREIHE mr = MESSREIHE(5);
	mr.setMesswertAtIndex(MESSWERT(5, "V"), 0);
	mr.setMesswertAtIndex(MESSWERT(2.3, "kV"), 1);
	mr.setMesswertAtIndex(MESSWERT(4.53, "uV"), 2);
	mr.setMesswertAtIndex(MESSWERT(27, "mV"), 3);
	mr.setMesswertAtIndex(MESSWERT(10, "nV"), 4);
	
	return mr;
};

MESSREIHE aufgabe_p(MESSREIHE mr1, MESSREIHE mr2) {
	/**
	 * Erzeugen Sie eine vierte Messreihe mit 5 Elementen zur Aufnahme von
	 * Leistungswerten. Die einzelnen Leistungswerte berechnen sich aus den
	 * Elementen der Messreihen aus l) und o) mit jeweils gleichem Index.
	 * Sie können hierfür Ihre Funktion aus Übungsblatt 4, Aufgabe 4e)
	 * nutzen. 
	 * Kopieren Sie Ihre Funktion vor die main-Funktion in Messungen.cpp.
	 */
	MESSREIHE mr = MESSREIHE(5);

	for (int i = 0; i < mr.getAnzahlMesswerte(); i++) {
		MESSWERT mw1 = mr1.getMesswertAtIndex(i);
		mw1.normierung();
		MESSWERT mw2 = mr2.getMesswertAtIndex(i);
		mw2.normierung(); 
		mr.setMesswertAtIndex(MESSWERT(mw1.getWert() * mw2.getWert(), "W"), i);
	};

	return mr;
};

void aufgabe_q_max(MESSREIHE mr) {
	mr.getMaxMesswert().print();
};

void aufgabe_q_min(MESSREIHE mr) {
	mr.getMinMesswert().print();
};

int main() {
	MESSREIHE mr1 = aufgabe_l();
	MESSREIHE mr2 = aufgabe_m(mr1);
	aufgabe_n(mr1, mr2);
	MESSREIHE mr3 = aufgabe_o();
	MESSREIHE mr4 = aufgabe_p(mr1, mr3);
	std::cout << std::endl;
	std::cout << "Messreihe 4:" << std::endl;
	mr4.print();
	
	std::cout << "Minimaler Wert: ";
	aufgabe_q_min(mr4);

	std::cout << "Maximaler Wert: ";
	aufgabe_q_max(mr4);

	return 0;
}
