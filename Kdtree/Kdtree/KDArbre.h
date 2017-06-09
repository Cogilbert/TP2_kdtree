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
	KDArbre(list<Point> listePt);
	~KDArbre();

private:
	KDNoeud* racine;
};

