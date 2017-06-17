#include "stdafx.h"
#include <vector>
#include <algorithm>
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

//Fonction permettant de créer un Kd-tree à partir d'une liste de point. Elle retourne la racine de cette arbre.
//Elle prend aussi un booléen pour savoir si l'on fait une comparaison selon la compsante x (true) ou y (false) de Point
KDNoeud* KDArbre::creerArbre(KDNoeud* racine, vector<Point> listePt, bool trieX)
{
	KDNoeud* test = new KDNoeud();

	//On vérifie si la liste est vide
	if (listePt.size() != 0)
	{
		//On trie la liste selon la composante x ou y de Point
		if (trieX == true)
		{
			sort(listePt.begin(), listePt.end(), Xgreater());
			trieX = false;
		}
		else
		{
			sort(listePt.begin(), listePt.end(), Ygreater());
			trieX = true;
		}
		

		//Si la liste de point est paire
		if (listePt.size() % 2 == 0)
		{
			//On vérifie si la racine est NULL
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL);
				test = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL);

				//On sépare la liste de point en deux listes distinctes pour les enfants gauches et droites
				vector<Point> listeGauche, listeDroite;
				for (unsigned int i = 0; i < listePt.size(); i++)
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

				//Récursivité
				if (listeGauche.size() != 0)
				{
					creerArbre(test, listeGauche, trieX);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(test, listeDroite, trieX);
				}
			}
			else
			{
				//On sépare la liste de point en deux listes distinctes pour les enfants gauches et droites
				vector<Point> listeGauche, listeDroite;
				for (unsigned int i = 0; i < listePt.size(); i++)
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

				//On regarde selon quelle composante de Points on compare le nouveau noeud pour savoir à quel enfant on l'attache 
				if (trieX == true)
				{
					if (listePt[(listePt.size() / 2) - 1].x < racine->getPoint().x)
					{
						racine->setKDGauche(n);
					}
					else
					{
						racine->setKDDroite(n);
					}
				}
				else
				{
					if (listePt[(listePt.size() / 2) - 1].y < racine->getPoint().y)
					{
						racine->setKDGauche(n);
					}
					else
					{
						racine->setKDDroite(n);
					}
				}

				//Récursivité
				if (listeGauche.size() != 0)
				{
					creerArbre(n, listeGauche, trieX);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(n, listeDroite, trieX);
				}
			}
		}

		//Si la liste est impaire
		if (listePt.size() % 2 == 1)
		{
			//On vérifie si la racine est NULL
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL);
				test = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL);

				//On sépare la liste de point en deux listes distinctes pour les enfants gauches et droites
				vector<Point> listeGauche, listeDroite;
				for (unsigned int i = 0; i < listePt.size(); i++)
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

				//Récursivité
				if (listeGauche.size() != 0)
				{
					creerArbre(test, listeGauche, trieX);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(test, listeDroite, trieX);
				}
			}
			else
			{
				//On sépare la liste de point en deux listes distinctes pour les enfants gauches et droites
				vector<Point> listeGauche, listeDroite;
				for (unsigned int i = 0; i < listePt.size(); i++)
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

				//On regarde selon quelle composante de Points on compare le nouveau noeud pour savoir à quel enfant on l'attache 
				if (trieX == true)
				{
					if (listePt[listePt.size() / 2].x < racine->getPoint().x)
					{
						racine->setKDGauche(n);
					}
					else
					{
						racine->setKDDroite(n);
					}
				}
				else
				{
					if (listePt[listePt.size() / 2].y < racine->getPoint().y)
					{
						racine->setKDGauche(n);
					}
					else
					{
						racine->setKDDroite(n);
					}
				}
				
				//Récursivité
				if (listeGauche.size() != 0)
				{
					creerArbre(n, listeGauche, trieX);
				}
				if (listeDroite.size() != 0)
				{
					creerArbre(n, listeDroite, trieX);
				}
			}
		}
	}
	return test;
}

//Fonction retournant le point le plus proche du point que l'on lui entre en paramètre
Point KDArbre::noeudVoisin(Point p, KDNoeud* racine)
{
	//On compare d'abord selon x
	if (racine->getPoint().x <= p.x)
	{
		//On regarde s'il existe un Noeud à droite de la racine
		if (racine->getKDDroite() != NULL)
		{
			//Si oui on compare selon y
			if (racine->getKDDroite()->getPoint().y <= p.y)
			{
				//On regarde si il y a un parent à droite
				if (racine->getKDDroite()->getKDDroite() != NULL)
				{
					//Si oui récursivité
					noeudVoisin(p, racine->getKDDroite()->getKDDroite());
				}
				else
				{
					return racine->getKDDroite()->getPoint();
				}
			}
			else
			{
				//On regarde si il y a un parent à gauche
				if (racine->getKDDroite()->getKDGauche() != NULL)
				{
					//Si oui récursivité
					noeudVoisin(p, racine->getKDDroite()->getKDGauche());
				}
				else
				{
					return racine->getKDDroite()->getPoint();
				}
			}
		}
		else
		{
			return racine->getPoint();
		}
	}
	else //On répete le même principe que précédemment mais à gauche de la racine
	{
		if (racine->getKDGauche() != NULL)
		{
			if (racine->getKDGauche()->getPoint().y <= p.y)
			{
				if (racine->getKDGauche()->getKDDroite() != NULL)
				{
					noeudVoisin(p, racine->getKDGauche()->getKDDroite());
				}
				else
				{
					return racine->getKDGauche()->getPoint();
				}
			}
			else
			{
				if (racine->getKDGauche()->getKDGauche() != NULL)
				{
					noeudVoisin(p, racine->getKDGauche()->getKDGauche());
				}
				else
				{
					return racine->getKDGauche()->getPoint();
				}
			}
		}
		else
		{
			return racine->getPoint();
		}
	}
}

Point KDArbre::ppVoisin(Point centre, Point voisin, vector<Point> listePt)
{
	float rayon = sqrt((centre.x - voisin.x)*(centre.x - voisin.x) + (centre.y - voisin.y)*(centre.y - voisin.y));
	Point ppvoisin = voisin;

	for (int i = 0; i < listePt.size(); i++)
	{
		float dist = sqrt((centre.x - listePt[i].x)*(centre.x - listePt[i].x) + (centre.y - listePt[i].y)*(centre.y - listePt[i].y));
		if (dist < rayon)
		{
			rayon = sqrt((centre.x - listePt[i].x)*(centre.x - listePt[i].x) + (centre.y - listePt[i].y)*(centre.y - listePt[i].y));
			ppvoisin = listePt[i];
		}
	}
	return ppvoisin;
}

//Fonction affichant l'arbre en pre-order
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