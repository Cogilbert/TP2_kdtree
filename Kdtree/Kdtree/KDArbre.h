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

	//Getter et Setter
	KDNoeud* getRacine() { return racine; };
	void setRacine(KDNoeud* kdracine) { racine = kdracine; };

	//Fonctions
	KDNoeud* creerArbre(KDNoeud* racine, vector<Point> listePt, bool trieX);
	Point noeudVoisin(Point p, KDNoeud* racine);
	Point ppVoisin(Point centre, Point voisin, vector<Point> listePt);
	void afficherArbre(KDNoeud* racine);

private:
	KDNoeud* racine;
};