#pragma once

#include <string>
#include <iostream>
#include <list>

#include "KDNoeud.h"

using namespace::std;

class KDArbre
{
public:
	KDArbre();
	KDArbre(KDNoeud* racine);
	~KDArbre();

	KDNoeud* getRacine() { return racine; };
	void setRacine(KDNoeud* kdracine) { racine = kdracine; };

	KDNoeud* creerArbre(KDNoeud* racine, vector<Point> listePt);
	void afficherArbre(KDNoeud* racine);

private:
	KDNoeud* racine;
	KDNoeud* kdprecedent;
};

