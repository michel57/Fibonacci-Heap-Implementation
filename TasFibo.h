#ifndef __TASFIBO
#define __TASFIBO

#include <iostream>


using namespace std;

class Sommet;

class Element {
	float cle;
	Element* frere_gauche;
	Element* frere_droit;
	Element* premier_fils;
	Element* pere;
	Sommet* sommet;
	int marque;
	int degre;
public:
	Element();
	Element(float);
	Element(float,Sommet*);
	Element(const Element &);
	Element* getPere()const;
	Element* getFrereDroit()const;
	Element* getFrereGauche()const;
	Element* getPremierFils()const;
	void setPere(Element*);
	void setFrereDroit(Element*);
	void setFrereGauche(Element*);
	void setPremierFils(Element*);
	void setMarque(int);
	void setDegre(int);
	void setCle(float);
	float getCle()const;
	int getMarque() const;
	int getDegre() const;
	Sommet* getSommet()const;
	void Afficher()const;
	~Element();
};

class TasFibo {
	Element * min;
	int nbElement;
public:
	TasFibo();
	Element* Inserer(float,Sommet*);
	void AfficherTas(Element *)const;
	void Afficher()const;
	Element* getMin()const;
	int getNbElement()const;
	void setMin(Element *);
	void setNbElement(int);
	bool est_vide()const;
	void Diminuer_Cle(Element*,float);
	void couper(Element*,Element*);
	void couperEnCascade(Element*);
	Element* extraireMin();
	~TasFibo();
};

#endif