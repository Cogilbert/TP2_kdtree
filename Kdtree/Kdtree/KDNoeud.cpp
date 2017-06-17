#include "stdafx.h"
#include "KDNoeud.h"


Point::Point(int xx, int yy)
{
	x = xx;
	y = yy;
}


KDNoeud::KDNoeud()
{
	kdnGauche = NULL;
	kdnDroite = NULL;
}

KDNoeud::KDNoeud(Point p, KDNoeud* pa, KDNoeud* kdnG, KDNoeud* kdnD)
{
	point = p;
	parent = pa;
	kdnGauche = kdnG;
	kdnDroite = kdnD;
}

KDNoeud::~KDNoeud()
{
}
