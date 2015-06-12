#include "projet.h"

Tache* Projet::trouverTache(const QString& id)const{
    for(std::size_t i=0;i<taches.size();++i) {
        if (id==taches[i]->getId()) return taches[i];
    }
    return 0;
}

void Projet::afficherTaches() const {
    for(std::size_t i=0;i<taches.size();++i) {
        std::cout<<"Tache "<<i<<": "<<std::endl;
        taches[i]->afficher(std::cout);
        std::cout<<"\n\n";
    }
}


TacheUnitaire& Projet::ajouterTacheUnitaire(const QString& id, const QString& t, const QDateTime &dispo, const QDateTime &deadline, const Duree &dur, bool b){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");

    if (dispo<deadline && dur<Duree(12,0)){
        TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur, b);
        addItem(newt);
        return *newt;
    }else throw ProjetException("erreur, les dates ne concordent pas");
}

TachePreemptable& Projet::ajouterTachePreemptable(const QString& id, const QString& t, const QDateTime& dispo, const QDateTime& deadline, const Duree& dur, bool b){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    if (dispo<deadline){
        TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur, b);
        addItem(newt);
        return *newt;
    }else throw ProjetException("erreur, les dates ne concordent pas");
}


TacheComposite& Projet::ajouterTacheComposite(const QString& id, const QString& t, const QDateTime &dispo, const QDateTime &deadline, bool b){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    if (dispo<deadline){
        TacheComposite* newt=new TacheComposite(id,t,dispo,deadline, b);
        addItem(newt);
        return *newt;
    }else throw ProjetException("erreur, les dates ne concordent pas");
}

void Projet::supprimerTache(const QString& ident){
    for(std::size_t i=0;i<taches.size();++i) {
        if (ident==taches[i]->getId())
        {
            if (taches[i]->getStatus()){
                throw CalendarException("erreur, supprimer d'abord la programmation de cette tache");
            }
            taches.erase(taches.begin()+i);
            return;
        }
    }
}

Tache& Projet::getTache(const QString& id){
    Tache* t=trouverTache(id);
    if (!t) throw CalendarException("erreur, Projet, tache inexistante");
    return *t;
}

void Projet::addItem(Tache* t){
    taches.push_back(t);
}

const Tache& Projet::getTache(const QString& id)const{
    return const_cast<Projet*>(this)->getTache(id);
}


std::ostream& operator<<(std::ostream& f, const Projet& p){
    f<<p.getId().toStdString()<<"\n";
    f<<p.getTitre().toStdString()<<"\n";
    f<<p.getDesc().toStdString()<<"\n";
    f<<qPrintable(p.getDispo().toString(Qt::ISODate))<<"\n";
    f<<qPrintable(p.getEcheance().toString(Qt::ISODate))<<"\n";
    f<<"\n";
    return f;
}



