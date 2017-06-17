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

//Fonction permettant de cr�er un Kd-tree � partir d'une liste de point. Elle retourne la racine de cette arbre.
//Elle prend aussi un bool�en pour savoir si l'on fait une comparaison selon la compsante x (true) ou y (false) de Point
KDNoeud* KDArbre::creerArbre(KDNoeud* racine, vector<Point> listePt, bool trieX)
{
	KDNoeud* test = new KDNoeud();

	//On v�rifie si la liste est vide
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
			//On v�rifie si la racine est NULL
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL, NULL);
				test = new KDNoeud(listePt[(listePt.size() / 2) - 1], NULL, NULL, NULL);

				//On s�pare la liste de point en deux listes distinctes pour les enfants gauches et droites
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

				//R�cursivit�
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
				//On s�pare la liste de point en deux listes distinctes pour les enfants gauches et droites
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

				KDNoeud* n = new KDNoeud(listePt[(listePt.size() / 2) - 1], racine, NULL, NULL);

				//On regarde selon quelle composante de Points on compare le nouveau noeud pour savoir � quel enfant on l'attache 
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

				//R�cursivit�
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
			//On v�rifie si la racine est NULL
			if (racine == NULL)
			{
				racine = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL, NULL);
				test = new KDNoeud(listePt[floor(listePt.size() / 2)], NULL, NULL, NULL);

				//On s�pare la liste de point en deux listes distinctes pour les enfants gauches et droites
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

				//R�cursivit�
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
				//On s�pare la liste de point en deux listes distinctes pour les enfants gauches et droites
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

				KDNoeud* n = new KDNoeud(listePt[floor(listePt.size() / 2)], racine, NULL, NULL);

				//On regarde selon quelle composante de Points on compare le nouveau noeud pour savoir � quel enfant on l'attache 
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
				
				//R�cursivit�
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


//Fonction retournant le nouveau noeud inserer dans le kd-tree ayant comme point celui entr� par l'utilisateur
KDNoeud* KDArbre::insererNoeud(Point p, KDNoeud* racine)
{
	KDNoeud* newNoeud;

	//On compare d'abord selon x
	if (racine->getPoint().x < p.x)
	{
		//On regarde s'il existe un Noeud � droite de la racine
		if (racine->getKDDroite() != NULL)
		{
			//Si oui on compare selon y
			if (racine->getKDDroite()->getPoint().y < p.y)
			{
				//On regarde si il y a un parent � droite
				if (racine->getKDDroite()->getKDDroite() != NULL)
				{
					//Si oui r�cursivit�
					insererNoeud(p, racine->getKDDroite()->getKDDroite());
				}
				else
				{
					newNoeud = new KDNoeud(p, racine->getKDDroite(), NULL, NULL);
					racine->getKDDroite()->setKDDroite(newNoeud);
					return newNoeud;
				}
			}
			else
			{
				//On regarde si il y a un parent � gauche
				if (racine->getKDDroite()->getKDGauche() != NULL)
				{
					//Si oui r�cursivit�
					insererNoeud(p, racine->getKDDroite()->getKDGauche());
				}
				else
				{
					newNoeud = new KDNoeud(p, racine->getKDDroite(), NULL, NULL);
					racine->getKDDroite()->setKDGauche(newNoeud);
					return newNoeud;
				}
			}
		}
		else
		{
			newNoeud = new KDNoeud(p, racine, NULL, NULL);
			racine->setKDDroite(newNoeud);
			return newNoeud;
		}
	}
	else //On r�pete le m�me principe que pr�c�demment mais � gauche de la racine
	{
		if (racine->getKDGauche() != NULL)
		{
			if (racine->getKDGauche()->getPoint().y < p.y)
			{
				if (racine->getKDGauche()->getKDDroite() != NULL)
				{
					insererNoeud(p, racine->getKDGauche()->getKDDroite());
				}
				else
				{
					newNoeud = new KDNoeud(p, racine->getKDGauche(), NULL, NULL);
					racine->getKDGauche()->setKDDroite(newNoeud);
					return newNoeud;
				}
			}
			else
			{
				if (racine->getKDGauche()->getKDGauche() != NULL)
				{
					insererNoeud(p, racine->getKDGauche()->getKDGauche());
				}
				else
				{
					newNoeud = new KDNoeud(p, racine->getKDGauche(), NULL, NULL);
					racine->getKDGauche()->setKDGauche(newNoeud);
					return newNoeud;
				}
			}
		}
		else
		{
			newNoeud = new KDNoeud(p, racine, NULL, NULL);
			racine->setKDGauche(newNoeud);
			return newNoeud;
		}
	}
}


//Fonction retournant le Point plus proche voisin de celui de l'utilisateur
//Point p : point de l'utilisateur
//int dist : distance entre p et un autre point d'un noeud
//KDNoeud* racine : noeud racine du sous arbre
//KDNoeud* emetteur : noeud pr�cedent
//KDNoeud* enfant : noeud enfant de la branche o� nous nous situons du noeud racine
Point KDArbre::ppVoisin(Point p, int dist, KDNoeud* racine, KDNoeud* emetteur, KDNoeud* enfant)
{
	int rayon = 100000; 
		
	if (racine != NULL)
	{
		rayon = pow((p.x - racine->getPoint().x), 2) + pow((p.y - racine->getPoint().y), 2);
	}

	if (dist == 0)
	{
		dist = rayon;
		ppVoisin(p, dist, racine->getParent(), racine, racine);
	}
	else if (rayon < dist) //Si la nouvelle distance est plus petite que la pr�c�dente on descend dans l'autre branche
	{
		if ((racine->getKDGauche()->getPoint().x == enfant->getPoint().x) && (racine->getKDGauche()->getPoint().y == enfant->getPoint().y))
		{
			ppVoisinDescendant(p, rayon, racine->getKDDroite(), racine, racine);
		}
		else
		{
			ppVoisinDescendant(p, rayon, racine->getKDGauche(), racine, racine);
		}
	}
	else
	{
		return emetteur->getPoint();
	}	
}

//Fonction descendant dans une branche afin de trouver une distance plus petite
//Point p : point de l'utilisateur
//int dist : distance entre p et un autre point d'un noeud
//KDNoeud* racine : noeud racine du sous arbre
//KDNoeud* sortie : noeud parent du premier noeud o� on a commenc� � descendre dans la branche
//KDNoeud* emetteur : noeud pr�cedent
void KDArbre::ppVoisinDescendant(Point p, int dist, KDNoeud* racine, KDNoeud* sortie, KDNoeud* emetteur)
{
	int rayon = pow((p.x - racine->getPoint().x), 2) + pow((p.y - racine->getPoint().y), 2);

	if (rayon < dist)
	{
		if (racine->getKDGauche() != NULL)
		{ 
			ppVoisinDescendant(p, rayon, racine->getKDGauche(), sortie, racine);
		}
		if (racine->getKDDroite() != NULL)
		{
			ppVoisinDescendant(p, rayon, racine->getKDDroite(), sortie, racine);
		}
		
		ppVoisin(p, rayon, sortie->getParent(), racine, sortie);
	}
	else
	{
		ppVoisin(p, dist, sortie->getParent(), emetteur, sortie);
	}
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