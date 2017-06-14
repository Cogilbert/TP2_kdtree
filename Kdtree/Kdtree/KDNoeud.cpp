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

KDNoeud::KDNoeud(Point p, KDNoeud* kdnG, KDNoeud* kdnD)
{
	point = p;
	kdnGauche = kdnG;
	kdnDroite = kdnD;
}

KDNoeud::~KDNoeud()
{
}
