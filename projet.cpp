#include "projet.h"

void Projet::ajouterTache(const QString& ident, const QString& t, const Date& d,const Date& ech){
    if(d<ech){
        Tache* tache = new Tache(ident,t,d,ech);
        taches.push_back(tache);
    } else throw ProjetException("Erreur les dates ne concordent pas");
};
