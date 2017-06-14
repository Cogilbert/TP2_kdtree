// Kdtree.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "KDNoeud.h"
#include "KDArbre.h"


int main()
{
	Point p1(1,10);
	Point p2(2, 5);
	Point p3(3, 7);
	Point p4(4, 4);
	Point p5(5, 9);
	Point p6(6, 1);
	//Point p7(7, 4);

	vector<Point> listePt;
	listePt.push_back(p1);
	listePt.push_back(p2);
	listePt.push_back(p3);
	listePt.push_back(p4);
	listePt.push_back(p5);
	listePt.push_back(p6);
	//listePt.push_back(p7);

	KDArbre* a = new KDArbre();

	cout << "Creation d'arbre" << endl;
	KDNoeud* test = a->creerArbre(a->getRacine(), listePt);
	cout << "Arbre cree" << endl << endl;
	if (test->getKDDroite() == NULL)
	{
		cout << "la racine est null" << endl;
	}
	/*else
	{
		cout << "x : " << test->getPoint().x << " ||| y : " << test->getPoint().y << endl;
	}*/
	a->afficherArbre(test);
	system("PAUSE");

}

