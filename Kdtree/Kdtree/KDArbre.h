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
	KDNoeud* insererNoeud(Point p, KDNoeud* racine);
	Point ppVoisin(Point p, int dist, KDNoeud* emetteur, KDNoeud* racine, KDNoeud* enfant);
	void ppVoisinDescendant(Point p, int dist, KDNoeud* racine, KDNoeud* depart, KDNoeud* emetteur);
	void afficherArbre(KDNoeud* racine);

private:
	KDNoeud* racine;
};