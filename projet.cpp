#include "projet.h"

Tache* Projet::trouverTache(const QString& id)const{
    for(std::size_t i=0;i<taches.size();++i) {
        if (id==taches[i]->getId()) return taches[i];
    }
    return 0;
}

void Projet::afficherTaches(){
    for(std::size_t i=0;i<taches.size();++i) {
        std::cout<<*taches[i]<<std::endl;
    }
}

TacheUnitaire& Projet::ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur);
    addItemU(newt);
    return *newt;
}

TachePreemptable& Projet::ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur);
    addItemP(newt);
    return *newt;
}

TacheComposite& Projet::ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheComposite* newt=new TacheComposite(id,t,dispo,deadline);
    addItemC(newt);
    return *newt;
}

void Projet::supprimerTache(const QString& ident){
    for(std::size_t i=0;i<taches.size();++i) {
        if (ident==taches[i]->getId()) taches.erase(taches.begin()+i);
    }
}

Tache& Projet::getTache(const QString& id){
    Tache* t=trouverTache(id);
    if (!t) throw CalendarException("erreur, Projet, tache inexistante");
    return *t;
}

void Projet::addItemU(TacheUnitaire* t){
    taches.push_back(t);
}

void Projet::addItemP(TachePreemptable* t){
    taches.push_back(t);
}

void Projet::addItemC(TacheComposite* t){
    taches.push_back(t);
}
const Tache& Projet::getTache(const QString& id)const{
    return const_cast<Projet*>(this)->getTache(id);
}
