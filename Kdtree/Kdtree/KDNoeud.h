#pragma once

#include <string>
#include <iostream>
#include <vector>

//Structure définissant un point avec son constructeur
struct Point {
	int x;
	int y;

	Point() {};
	Point(int xx, int yy);
};

//Structure permettant de surcharger un operateur pour le faire uniquement comparer les composantes x du Point
struct Xgreater
{
	bool operator()(const Point& lx, const Point& rx) const {
		return lx.x < rx.x;
	}
};

//Structure permettant de surcharger un operateur pour le faire uniquement comparer les composantes y du Point
struct Ygreater
{
	bool operator()(const Point& ly, const Point& ry) const {
		return ly.y < ry.y;
	}
};


class KDNoeud
{
public:
	KDNoeud();
	KDNoeud(Point p, KDNoeud* kdnGauche, KDNoeud* kdnDroite);
	~KDNoeud();

	//Getter & Setter
	Point getPoint() { return point; };
	KDNoeud* getKDGauche() { return kdnGauche; };
	void setKDGauche(KDNoeud* g) { kdnGauche = g; };
	KDNoeud* getKDDroite() { return kdnDroite; };
	void setKDDroite(KDNoeud* d) { kdnDroite = d; };

private:
	Point point;
	KDNoeud* kdnGauche;
	KDNoeud* kdnDroite;
};