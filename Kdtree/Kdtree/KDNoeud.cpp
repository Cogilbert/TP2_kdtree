#include "stdafx.h"
#include "KDNoeud.h"


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
