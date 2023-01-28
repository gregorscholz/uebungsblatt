#include "Messungen.h"
#include <vector>
#include <algorithm>

MESSREIHE::MESSREIHE(int anzahl) {
	messreihe.resize(anzahl);
	messwertPointer = &messreihe.front();
};

MESSREIHE::MESSREIHE(const MESSREIHE &m) {
	messreihe = m.messreihe;
	messwertPointer = &messreihe.front();
};

MESSREIHE::~MESSREIHE() {
	// TODO
};

MESSWERT MESSREIHE::getMesswertAtIndex(int index) {
	return messreihe.at(index);
};

void MESSREIHE::setMesswertAtIndex(MESSWERT m, int index) {
	messreihe[index] = m;
};

int MESSREIHE::getAnzahlMesswerte() {
	return messreihe.size();
};

void MESSREIHE::print() {
	for (size_t i = 0; i < messreihe.size(); i++) {
		messreihe.at(i).print();
	}
};

MESSWERT MESSREIHE::getMinMesswert() {
	// TODO vergleichsoperator für MESSWERT
	MESSWERT min_messwert = messreihe.front();
	for (size_t i = 0; i < messreihe.size() - 1; i++) {
		if (messreihe.at(i).getWert() < messreihe.at(i + 1).getWert()) {
			//min_messwert = messreihe.at(i);
		}
	};
	return min_messwert;
};

MESSWERT MESSREIHE::getMaxMesswert() {
	MESSWERT max_messwert = messreihe.front();
	for (size_t i = 0; i < messreihe.size() - 1; i++ ) {
		if (messreihe.at(i).getWert() > messreihe.at(i + 1).getWert()) {
			//max_messwert = messreihe.at(i);
		}
	};
	return max_messwert;
};
