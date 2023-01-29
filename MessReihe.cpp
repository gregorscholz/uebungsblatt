#include "Messungen.h"
#include <vector>
#include <algorithm>
#include <iostream>


MESSREIHE::MESSREIHE(int anzahl) {
	messreihe.resize(anzahl);
	messwertPointer = &messreihe.front();
};

MESSREIHE::MESSREIHE(const MESSREIHE &m) {
	messreihe = m.messreihe;
	messwertPointer = &messreihe.front();
};

MESSREIHE::~MESSREIHE() {
	/** 
	 * TODO
	 * eigl muss nur der Pointer gelöscht werden, 
	 * vector und int werden eigl automatisch gelöscht
	 */
	delete messwertPointer;
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
	};
};

MESSWERT MESSREIHE::getMinMesswert() {
	MESSWERT min_messwert = messreihe.front();
	int min = 0;
	for (size_t i = 0; i < messreihe.size() - 1; i++) {
		MESSWERT mw1 = messreihe.at(i);
		mw1.normierung();
		MESSWERT mw2 = messreihe.at(i + 1);
		mw2.normierung();
		if (mw1.getWert() < mw2.getWert() &&
				mw1.getWert() < messreihe.at(min).getWert()) {
			min = i;
		} else if (mw2.getWert() < mw1.getWert() &&
				mw2.getWert() < messreihe.at(min).getWert()) {
			min = i + 1;
		};
	};
	return messreihe.at(min);
};

MESSWERT MESSREIHE::getMaxMesswert() {
	MESSWERT max_messwert = messreihe.front();
	int max = 0;
	for (size_t i = 0; i < messreihe.size() - 1; i++ ) {
		MESSWERT mw1 = messreihe.at(i);
		mw1.normierung();
		MESSWERT mw2 = messreihe.at(i + 1);
		mw2.normierung();
		if (mw1.getWert() > mw2.getWert() &&
				mw1.getWert() > messreihe.at(max).getWert()) {
			max = i;
		} else if (mw2.getWert() > mw1.getWert() &&
				mw2.getWert() > messreihe.at(max).getWert()) {
			max = i + 1;
		};
	};
	return messreihe.at(max);
};
