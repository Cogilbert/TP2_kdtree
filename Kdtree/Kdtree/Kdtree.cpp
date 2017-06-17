// Kdtree.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "KDNoeud.h"
#include "KDArbre.h"


//Fonction testant si l'utilisateur a bien entrée un chiffre existant
bool testEntree(int debut, int fin, int &entree)
{
	while (!(cin >> entree) || entree < debut || entree > fin)
	{
		if (cin.eof())
		{
			return false;
		}
		else if (cin.fail())
		{
			cout << "ERREUR : Saisie incorrecte, recommencez : ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			cout << "ERREUR : Le chiffre n'est pas entre " << debut << " et " << fin << ", recommencez : ";
		}
	}
	return true;
}

//Fonction affichant le titre de l'exercice
void afficherTitre() {
	std::cout << "------------------------------------------------------\n"
		<< "---                EXERCICE 1 : KD-TREE            ---\n"
		<< "------------------------------------------------------\n"
		<< endl;
};

//Fonction affichant le menu du ppvoisin et retournant le point choisi par le joueur
Point menuPPVoisin(KDNoeud* racine)
{
	int x, y;
	cout << "Définissez le point pour lequel vous voulez chercher le plus proche voisin : " << endl;
	cout << "Choisissez des valeurs entières entre -50 et 50 : " << endl;
	cout << "\tComposante x : ";
	if (testEntree(-50, 50, x))
	{
		cout << "\tComposante y : ";
		if (testEntree(-50, 50, y))
		{
			Point voisin(x, y);
			return voisin;
		}
	}
}

int main()
{
	//Liste 1
	Point p1(1,10);
	Point p2(2, 5);
	Point p3(3, 7);
	Point p4(4, 4);
	Point p5(5, 9);
	Point p6(6, 1);

	vector<Point> listePt1;
	listePt1.push_back(p1);
	listePt1.push_back(p2);
	listePt1.push_back(p3);
	listePt1.push_back(p4);
	listePt1.push_back(p5);
	listePt1.push_back(p6);

	KDArbre* a = new KDArbre();
	KDNoeud* test = a->creerArbre(a->getRacine(), listePt1, true);

	//Liste 2
	Point q1(12, 8);
	Point q2(6, 5);
	Point q3(4, 8);
	Point q4(9, 4);
	Point q5(0, 16);
	Point q6(8, 8);
	Point q7(7, 1);

	vector<Point> listePt2;
	listePt2.push_back(q1);
	listePt2.push_back(q2);
	listePt2.push_back(q3);
	listePt2.push_back(q4);
	listePt2.push_back(q5);
	listePt2.push_back(q6);
	listePt2.push_back(q7);

	KDArbre* b = new KDArbre();
	KDNoeud* test2 = b->creerArbre(b->getRacine(), listePt2, true);

	afficherTitre();

	int rep;
	do
	{
		cout << "-> Que voulez-vous faire: " << endl;
		cout << "1. Afficher le KD-Tree" << endl;
		cout << "2. Chercher le plus proche voisin d'un point" << endl;
		cout << "0. Fermer" << endl << endl;

		cout << "Taper le chiffre correspondant : ";
		if (testEntree(0, 2, rep))
		{
			Point centre;
			switch (rep)
			{
			case 1:
				int rep2;
				system("cls");
				cout << "Quel liste voulez-vous afficher?" << endl;
				cout << "1. [(1,10),(2,5),(3,7),(4,4),(5,9),(6,1)]" << endl;
				cout << "2. [(12,8),(6,5),(4,8),(9,4),(0,16),(8,8),(7,1)]" << endl;
				if (testEntree(1, 2, rep2))
				{
					if (rep2 == 1)
					{
						system("cls");
						a->afficherArbre(test);
					}
					else
					{
						system("cls");
						a->afficherArbre(test2);
					}
				}
				break;

			case 2:
				int rep3;
				system("cls");
				cout << "Dans quel liste voulez-vous chercher le plus proche voisin?" << endl;
				cout << "1. [(1,10),(2,5),(3,7),(4,4),(5,9),(6,1)]" << endl;
				cout << "2. [(12,8),(6,5),(4,8),(9,4),(0,16),(8,8),(7,1)]" << endl;
				if (testEntree(1, 2, rep3))
				{
					if (rep3 == 1)
					{
						Point voisin;
						system("cls");
						centre = menuPPVoisin(test);
						voisin = a->ppVoisin(centre, a->noeudVoisin(centre, test), listePt1);
						system("cls");
						cout << "Le voisin le plus proche de (" << centre.x << "," << centre.y << ") dans [(1,10),(2,5),(3,7),(4,4),(5,9),(6,1)] est (";
						cout << voisin.x << "," << voisin.y << ")" << endl << endl;
					}
					else
					{
						Point voisin;
						system("cls");
						centre = menuPPVoisin(test2);
						voisin = a->ppVoisin(centre, a->noeudVoisin(centre, test2), listePt2);
						system("cls");
						cout << "Le voisin le plus proche de (" << centre.x << "," << centre.y << ") dans [(12,8),(6,5),(4,8),(9,4),(0,16),(8,8),(7,1)] est (";
						cout << voisin.x << "," << voisin.y << ")" << endl << endl;
					}
				}
				break;

			default:
				break;
			}
		}
	} while (rep < 10);

	system("PAUSE");
}