#pragma once

#include <string>
#include <iostream>
#include <vector>

struct Point {
	int x;
	int y;

	Point() {};
	Point(int xx, int yy);
};

class KDNoeud
{
public:
	KDNoeud();
	KDNoeud(Point p, KDNoeud* kdnGauche, KDNoeud* kdnDroite);
	~KDNoeud();

	//getter & setter
	Point getPoint() { return point; };
	KDNoeud* getKDGauche() { return kdnGauche; };
	void setKDGauche(KDNoeud* g) { kdnGauche = g; };
	KDNoeud* getKDDroite() { return kdnDroite; };
	void setKDDroite(KDNoeud* d) { kdnDroite = d; };
//	vector<Point> getListePt() { return listePt; };
//	void setListePt(vector<Point> liste) { listePt = liste; };

private:
	Point point;
	KDNoeud* kdnGauche;
	KDNoeud* kdnDroite;
	//vector<Point> listePt;
};

