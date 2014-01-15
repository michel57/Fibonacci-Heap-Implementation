#include "TasFibo.h"
#include <math.h>
#include <stdlib.h>
#pragma warning(disable:4244)
using namespace std;

/*************************
		Element
*************************/

/*
	Constructeur par default element
*/

Element::Element(){
	this->frere_droit=NULL;
	this->frere_gauche=NULL;
	this->premier_fils=NULL;
	this->pere=NULL;
	this->marque=0;
	this->degre=0;
	this->cle=0;
	this->sommet=NULL;

}

/*
	Constructeur Element
*/

Element::Element(float x){
	this->frere_droit=NULL;
	this->frere_gauche=NULL;
	this->premier_fils=NULL;
	this->pere=NULL;
	this->marque=0;
	this->degre=0;
	this->cle=x;
	this->sommet=NULL;
}

/*
	Constructeur Element
*/

Element::Element(float x,Sommet* d){
	this->frere_droit=NULL;
	this->frere_gauche=NULL;
	this->premier_fils=NULL;
	this->pere=NULL;
	this->marque=0;
	this->degre=0;
	this->cle=x;
	this->sommet=d;

}

/*
	Constructeur par recopie element
*/

Element::Element(const Element & E){
	this->frere_droit=E.frere_droit;
	this->frere_gauche=E.frere_gauche;
	this->premier_fils=E.premier_fils;
	this->pere=E.pere;
	this->marque=E.marque;
	this->degre=E.degre;
	this->cle=E.cle;
	this->sommet=E.sommet;
}

/*
	Getteur pere
*/

Element* Element::getPere()const{
	return this->pere;
}

/*
	Getteur frere droit
*/

Element* Element::getFrereDroit()const{
	return this->frere_droit;
}

/*
	Getteur frere gauche
*/

Element* Element::getFrereGauche()const{
	return this->frere_gauche;
}

/*
	Getteur premier fils
*/

Element* Element::getPremierFils()const{
	return this->premier_fils;
}

/*
	Getteur  cle
*/

float Element::getCle()const{
	return this->cle;
}

/*
	Getteur marque
*/

int Element::getMarque() const{
	return this->marque;
}

/*
	Getteur degre
*/

int Element::getDegre() const{
	return this->degre;
}

/*
	Setteur pere
*/

void Element::setPere(Element* e){
	this->pere=e;
}

/*
	Getteur Sommet
*/

Sommet* Element::getSommet()const{
	return this->sommet;
}

/*
	Setteur frere droit
*/

void Element::setFrereDroit(Element* e){
	this->frere_droit=e;
}

/*
	Setteur frere gauche
*/

void Element::setFrereGauche(Element* e){
	this->frere_gauche=e;
}

/*
	Setteur premier fils
*/

void Element::setPremierFils(Element* e){
	this->premier_fils=e;
}

/*
	Setteur marque
*/

void Element::setMarque(int x){
	this->marque=x;
}

/*
	Setteur degre
*/

void Element::setDegre(int x){
	this->degre=x;
}

/*
	Setteur cle
*/

void Element::setCle(float x){
	this->cle=x;
}

/*
	DEBUG Affichage element
*/

void Element::Afficher()const{
	cout<<"[ ] Element:"<<this->getCle()<<" @:"<<this<<endl;	
	if(this->frere_droit) cout<<"Frere droit:"<<this->frere_droit->getCle()<<endl;
	else cout<<"Frere droit:"<<this->frere_droit<<endl;
	if(this->frere_gauche) cout<<"Frere gauche:"<<this->frere_gauche->getCle()<<endl;
	else cout<<"Frere gauche:"<<this->frere_gauche<<endl;
	if(this->pere) cout<<"Pere:"<<this->pere->getCle()<<endl;
	else cout<<"Pere:"<<this->pere<<endl;
	cout<<"marque:"<<this->marque<<endl;
	cout<<"degre:"<<this->degre<<endl;
	if(this->premier_fils) cout<<"Premier fils:"<<this->premier_fils->getCle()<<endl;
	else cout<<"Premier fils:"<<this->premier_fils<<endl;
	cout<<" Sommet : "<<this->sommet<<endl;	
}

/*
	Destructeur Element
*/

Element::~Element(){

}

/*************************
	Tas Fibonacci
*************************/


/*
	Constructeur par default
*/

TasFibo::TasFibo(){

	this->min=NULL;
	this->nbElement=0;
}

/*
	Test est_vide
*/

bool TasFibo::est_vide()const{
	return this->getNbElement()==0;
}

/*
	Inserer cle
*/

Element* TasFibo::Inserer(float p,Sommet* S){

	Element* E=new Element(p,S);

	if (min==NULL){
		min=E;
		E->setFrereDroit(min);
		E->setFrereGauche(min);
	}else{
		E->setFrereGauche(min->getFrereGauche());
		E->setFrereDroit(min);
		min->getFrereGauche()->setFrereDroit(E);
		min->setFrereGauche(E);
		if (E->getCle()<min->getCle()){
			min=E;
		}
	}
	this->nbElement=this->nbElement+1;
	return E;
}

/*
	Afficher Tas
*/

void TasFibo::AfficherTas(Element * r) const{

	if(r->getDegre()==0){		
		r->Afficher();
	}
	else{
		r->Afficher();
		Element* f=r->getPremierFils();
		for (int i=0;i<r->getDegre();i++){
			this->AfficherTas(f);
			f=f->getFrereDroit();			
		}
	}
}


/*
	DEBUG Affichage tas de fibo
*/

void TasFibo::Afficher()const{

	cout<<"**********************************"<<endl;
	cout<<"**********************************"<<endl;
	if (this->min!=NULL){
		Element* i=this->min;
		cout<<"min="<<this->min->getCle()<<endl;
		do{
			cout<<endl<<endl<<"\t debut Tas :"<<i->getCle()<<endl<<endl;
			this->AfficherTas(i);
			cout<<endl<<"\t fin Tas :"<<i->getCle()<<endl;
			i=i->getFrereDroit();

		}while(i!=this->min);
	}else{
		cout<<"Tas vide !"<<endl;
	}
	cout<<"**********************************"<<endl;
	cout<<"**********************************"<<endl;
}


/*
	Getteur min
*/

Element* TasFibo::getMin()const{
	return this->min;
}

/*
	Setteur min
*/

void TasFibo::setMin(Element * e){
	this->min=e;
}

/*
	Setteur nb element
*/

void TasFibo::setNbElement(int x){
	this->nbElement=x;
}

/*
	Getteur nb element
*/

int TasFibo::getNbElement()const{
	return this->nbElement;
}

/*
	Couper
*/

void TasFibo::couper(Element *E,Element* f){
	// on est le 1er fils
	
	if(f->getPremierFils()==E){
		// le seul fils

		if(f->getDegre()==1){
			f->setPremierFils(NULL);
		}else{
			// le 2eme frere devient 1er
			f->setPremierFils(E->getFrereDroit());
			
		}
	}

	E->getFrereGauche()->setFrereDroit(E->getFrereDroit());
	E->getFrereDroit()->setFrereGauche(E->getFrereGauche());

	// a la racine

	E->setFrereDroit(this->min);

	E->setFrereGauche(this->min->getFrereGauche());

	this->min->getFrereGauche()->setFrereDroit(E);
	this->min->setFrereGauche(E);

	
	//degre --
	f->setDegre(E->getPere()->getDegre()-1);
	E->setPere(NULL);
	E->setMarque(0);
	
}

/*
	Couper en cascade
*/

void TasFibo::couperEnCascade(Element* E){
	Element* father=NULL;
	if(E->getPere()!=NULL){
		if(!E->getMarque()){
			E->setMarque(1);
		}else{
			father=E->getPere();
			couper(E,father);
			couperEnCascade(father);
		}
	}
}

/*
	Diminuer cle
*/

void TasFibo::Diminuer_Cle(Element* E,float p){
	E->setCle(p);
	Element* f;

	// E inferieur au pere
	if(E->getPere()!=NULL && E->getCle()<E->getPere()->getCle()){
		f=E->getPere();
		// on coupe E
		this->couper(E,f);
		// on répare 
		this->couperEnCascade(f);		
	}

	if(E->getCle()<this->min->getCle()){
		this->min=E;
	}
}

/*
	Extraire min
*/

Element* TasFibo::extraireMin(){

	if(this->est_vide())
		return 0;

	//cout<<endl<<"\t--> Extraction de "<<this->min->getCle()<<endl<<endl;
	Element* savMin=this->min;

	//min tout seul

	if(this->min->getDegre()==0 && this->min == this->min->getFrereDroit()){
		this->setNbElement(0);
		return this->min;
	}

	// si il y a plusieur clé a la racine
	if(this->min != this->min->getFrereDroit()){

		this->min->getFrereDroit()->setFrereGauche(this->min->getFrereGauche());
		this->min->getFrereGauche()->setFrereDroit(this->min->getFrereDroit());

		
		// min a droite
		this->min=this->min->getFrereDroit();

		//on deplace les fils de l'ancien min a la racine
		if (savMin->getDegre()!=0){

			Element* e=savMin->getPremierFils();
			Element* suivant;
			for(int i=0;i<savMin->getDegre();i++){
				e->setPere(NULL);
				
				//Insertion a la racine

				e->setFrereGauche(min->getFrereGauche());
				suivant=e->getFrereDroit();
				e->setFrereDroit(min);
				min->getFrereGauche()->setFrereDroit(e);
				min->setFrereGauche(e);
				e=suivant;		
			}
		}
	// clé seul a la racine
	}else{
		
			this->min=this->min->getPremierFils();
			Element* u=this->min;
			do{
				u->setPere(0);
				u=u->getFrereDroit();
			}while(u!=this->min);
	}

	// un element de moin
	this->nbElement=this->nbElement-1;

	int n=(int) log((double) this->nbElement)/log((double) 2)+1;
	// on peut obtenir des arbre de plus haut degré que ceux deja ds le tas
	//+1 suffisant ?
	n=n+10;
	Element* x=this->min;
	Element* nxt=this->min->getFrereDroit();
	//Consolidation

	//Tableau intermediaire de consolidation

	Element** tabTmp=(Element**) malloc(sizeof(Element*)*n);
	//initialisation
	for(int y=0;y<n;y++){
		tabTmp[y]=NULL;
	}

	Element* z=this->min->getFrereDroit();
	int nbIteration=1;

	while(z!=this->min){
		z=z->getFrereDroit();
		nbIteration++;
	}

	//parcours des tas

	int again=0;

	// on applique l'algo sur chaque racine du tas donc nbiteration fois
	for(int i=0;i<nbIteration;i++){
		
		do{
				//variable indiquant si la fusion est optimale
				again=0;

			if (tabTmp[x->getDegre()]==NULL){

				tabTmp[x->getDegre()]=x;

			}else{

				//x fusionnable 
				//fusion
				//comparaison de la cle avec l'autre B
				Element* B=tabTmp[x->getDegre()];

				if (x->getCle()>B->getCle()){

				}else{
					Element* Tmp=x;
					x=B;
					B=Tmp;
				}
				//si B a un fils !

				if (B->getDegre()>0){

					//x = superieur B = inferieur => racine 
					//x disparait des racines et va sous BX

					x->getFrereDroit()->setFrereGauche(x->getFrereGauche());

					x->getFrereGauche()->setFrereDroit(x->getFrereDroit());			
					// x prend pour pere B

					x->setPere(B);

					//x pere sa marque
					x->setMarque(0);
						
					//x a pour frere droit le 1er fils
	
					x->setFrereDroit(B->getPremierFils());			
					//x a pour frere gauche le dernier fils
		
					x->setFrereGauche(B->getPremierFils()->getFrereGauche());
					// le dernier fils de B a pour frere droit x
				
					B->getPremierFils()->getFrereGauche()->setFrereDroit(x);
					//le prmier fils de B a pour nouveau frere gauche x		
				
					B->getPremierFils()->setFrereGauche(x);				
			
					//B a pour premier fils x
					B->setPremierFils(x);


				}else{
										
					x->getFrereDroit()->setFrereGauche(x->getFrereGauche());				
					x->getFrereGauche()->setFrereDroit(x->getFrereDroit());							
					B->setPremierFils(x);
					x->setPere(B);
					x->setFrereDroit(x);
					x->setFrereGauche(x);
				}
			
			
				// ++ degree
				B->setDegre(B->getDegre()+1);
				//B est maintenant de degre ++
				tabTmp[x->getDegre()]=NULL;
				
				//B et x forment un B++

				if(tabTmp[B->getDegre()]!=NULL){
					//B toujours fusionnable avec ...
					again=1;
					//Le tas créer est  encore fusionnable avec un autre tas de meme degré !
					// on réitere ce traitement sur le nouveau tas
					x=B;
				}
				else{
					tabTmp[B->getDegre()]=B;
				}
			}
				
		}while(again);

		// on passe au prochain
		x=nxt;
		//le prochain avance
		nxt=nxt->getFrereDroit();
	} 

	
	Element* e=x;

	//on remonte a la racine a partir du dernier x
	while(e->getPere()!=NULL){
		e=e->getPere();
	}

	// cette element devient le min 
	this->min=e;
	Element* minTmp=this->min;
	// on parcours tout les element de la racine afin d ameliorer le min
	do {
		if(e->getCle()<minTmp->getCle()){
			minTmp=e;			
		}
		e=e->getFrereDroit();
	}while(e!=this->min);
	

	this->min=minTmp;
	//cout<<"Nouveau min = "<<this->min->getCle()<<endl;

	// liberation memoire !!

	//Liberation memoire de tabTmp
	free(tabTmp);

	return savMin;
}

/*
	Destructeur Tas fibo
*/

TasFibo::~TasFibo(){

}