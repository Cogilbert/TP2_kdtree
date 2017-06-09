#pragma once

#include <string>
#include <iostream>

struct Point {
	int x;
	int y;
};

class KDNoeud
{
public:
	KDNoeud();
	KDNoeud(Point p, KDNoeud* kdnGauche, KDNoeud* kdnDroite);
	~KDNoeud();

	//getter
	Point getPoint() { return point; };
	KDNoeud* getKDGauche() { return kdnGauche; };
	KDNoeud* getKDDroite() { return kdnDroite; };

private:
	Point point;
	KDNoeud* kdnGauche;
	KDNoeud* kdnDroite;
};

