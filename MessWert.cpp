#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <math.h>
#include "Messungen.h"

bool MESSWERT::einheitValid(std::string e) {
	switch (e.size()) {
		// Wenn keine einfachen zahlen, also nur "1" oder "2", 
		// als Messwerte zugelassen werden sollen
		// einfach den "case 0" mitsamt "return true" loeschen.
		case 0:
			return true;
		case 1:
			if (std::find(std::begin(basiseinheiten), 
					std::end(basiseinheiten), e.at(0))
					!= std::end(basiseinheiten)) {
				return true;
			};
		case 2:
			if (std::find(std::begin(vorsatzzeichen), 
					std::end(vorsatzzeichen), e.at(0))
					!= std::end(vorsatzzeichen)
				&& std::find(std::begin(basiseinheiten),
					std::end(basiseinheiten), e.at(1))
					!= std::end(basiseinheiten)) {
				return true;
			};
		default:
			throw std::invalid_argument(
				e + " wird als Einheit nicht unterstuetzt.");
	};
};

MESSWERT::MESSWERT()
	:wert(0), einheit("")
{};

MESSWERT::MESSWERT(double w, std::string e) {
	if (einheitValid(e)) {
		MESSWERT::setMesswert(w, e);
	};
};

MESSWERT::MESSWERT(const MESSWERT &m){
	setMesswert(m.wert, m.einheit);
};

void MESSWERT::setMesswert(double w, std::string e) {
	wert = w;
	einheit = e;
};

double MESSWERT::getWert() {
	return wert;
};

std::string MESSWERT::getEinheit() {
	return einheit;
};

void MESSWERT::print() {
	std::cout << wert << " " << einheit << std::endl;
};

void MESSWERT::normierung() {
	if (einheit.size() == 2) {
		switch (einheit.at(0)) {
			case 'n':
				wert *= pow(10, -9);
				break;
			case 'u':
				wert *= pow(10, -6);
				break;
			case 'm':
				wert *= pow(10, -3);
				break;
			case 'M':
				wert *= pow(10, 6);
				break;
			case 'k':
				wert *= pow(10, 3);
				break;
			default:
				break;
		};
		einheit = einheit.substr(1, 1);
	};
};
