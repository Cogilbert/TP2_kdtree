#include "stdafx.h"
#include <vector>
#include "KDArbre.h"


KDArbre::KDArbre()
{
	racine = NULL;
}

KDArbre::KDArbre(KDNoeud* kdracine)
{
	racine = kdracine;
}

KDArbre::~KDArbre()
{
}


KDNoeud* KDArbre::creerArbre(KDNoeud* racine, vector<Point> listePt)
{
	KDNoeud* test = new KDNoeud();

	if (listePt.size() != 0)
	{
		//Si la liste est paire
		if (listePt.size() % 2 == 0)
		{
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL);
				test = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL);
				cout << "coucou: racine : x " << racine->getPoint().x << " |||||| y : " << racine->getPoint().y << endl;

				vector<Point> listeGauche, listeDroite;
				for (int i = 0; i < listePt.size(); i++)
				{
					if (i < floor(listePt.size() / 2) - 1)
					{
						listeGauche.push_back(listePt[i]);
					}
					else if (i > floor(listePt.size() / 2) - 1)
					{
						listeDroite.push_back(listePt[i]);
					}
				}

				if (listeGauche.size() != 0)
				{
					creerArbre(racine, listeGauche);
					creerArbre(test, listeGauche);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(racine, listeDroite);
					creerArbre(test, listeDroite);
				}
			}
			else
			{
				cout << "pair : " << racine->getPoint().x << endl;
				vector<Point> listeGauche, listeDroite;
				for (int i = 0; i < listePt.size(); i++)
				{
					if (i < floor(listePt.size() / 2) - 1)
					{
						listeGauche.push_back(listePt[i]);
					}
					else if (i > floor(listePt.size() / 2) - 1)
					{
						listeDroite.push_back(listePt[i]);
					}
				}

				KDNoeud* n = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL);

				if (listePt[(listePt.size() / 2) - 1 ].x < racine->getPoint().x)
				{
					racine->setKDGauche(n);
				}
				else
				{
					racine->setKDDroite(n);
				}

				if (listeGauche.size() != 0)
				{
					creerArbre(n, listeGauche);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(n, listeDroite);
				}
			}
		}

		//Si la liste est impaire
		if (listePt.size() % 2 == 1)
		{
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL);
				vector<Point> listeGauche, listeDroite;
				for (int i = 0; i < listePt.size(); i++)
				{
					if (i < floor(listePt.size() / 2))
					{
						listeGauche.push_back(listePt[i]);
					}
					else if (i > floor(listePt.size() / 2))
					{
						listeDroite.push_back(listePt[i]);
					}
				}

				if (listeGauche.size() != 0)
				{
					creerArbre(racine, listeGauche);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(racine, listeDroite);
				}
			}
			else
			{
				cout << "impaire : " << racine->getPoint().x << endl;
				vector<Point> listeGauche, listeDroite;
				for (int i = 0; i < listePt.size(); i++)
				{
					if (i < floor(listePt.size() / 2))
					{
						listeGauche.push_back(listePt[i]);
					}
					else if (i > floor(listePt.size() / 2))
					{
						listeDroite.push_back(listePt[i]);
					}
				}

				KDNoeud* n = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL);

				if (listePt[listePt.size() / 2].x < racine->getPoint().x)
				{
					racine->setKDGauche(n);
				}
				else
				{
					racine->setKDDroite(n);
				}

				if (listeGauche.size() != 0)
				{
					creerArbre(n, listeGauche);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(n, listeDroite);
				}
			}
		}
	}
	return test;
}

void KDArbre::afficherArbre(KDNoeud* racine)
{
	if (racine != NULL)
	{
		cout << "x : " << racine->getPoint().x << " ||| y : " << racine->getPoint().y << endl;
	}	
	
	if (racine->getKDGauche() != NULL)
	{
		afficherArbre(racine->getKDGauche());
	}
	if (racine->getKDDroite() != NULL)
	{
		afficherArbre(racine->getKDDroite());
	}
}