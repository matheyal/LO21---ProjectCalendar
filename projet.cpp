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

TacheUnitaire& Projet::ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    /*
    for(std::size_t i=0; i<taches.size(); ++i)
    {
        Date ech(taches[i]->getEcheance());
        std::cout<<"Date"<<ech;
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache unitaire\n";
            newt->addItem(taches[i]);
        }
    }*/
    addItem(newt);
    return *newt;
}

TachePreemptable& Projet::ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<taches.size(); ++i)
    {
        Date ech(taches[i]->getEcheance());
        if(ech<newt->getDate())
        {
            newt->addItem(taches[i]);
        }
    }
    addItem(newt);
    return *newt;
}


TacheComposite& Projet::ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline){

    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheComposite* newt=new TacheComposite(id,t,dispo,deadline);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<taches.size(); ++i)
    {
        Date ech(taches[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache unitaire";
            newt->addItem(taches[i]);
        }
    }
    addItem(newt);
    return *newt;
}

void Projet::supprimerTache(const QString& ident){
    for(std::size_t i=0;i<taches.size();++i) {
        if (ident==taches[i]->getId())
        {
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
    f<<p.getDispo()<<"\n";
    f<<p.getEcheance()<<"\n";
    f<<"\n";
    return f;
}

/*void Projet::afficherPrecedence(const QString& id) const
{
    for(std::size_t i=0;i<taches.size();++i) {
        if (id==taches[i]->getId())
        {
            taches[i]->afficherPrecedence();
            return;
        }
    }
}*/

