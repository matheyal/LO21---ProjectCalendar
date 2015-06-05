#include "projet.h"

Tache* Projet::trouverTache(const QString& id)const{
    for(std::size_t i=0;i<tachesUnitaires.size();++i) {
        if (id==tachesUnitaires[i]->getId()) return tachesUnitaires[i];
    }
    for(std::size_t i=0;i<tachesComposites.size();++i) {
        if (id==tachesComposites[i]->getId()) return tachesComposites[i];
    }
    for(std::size_t i=0;i<tachesPreemptables.size();++i) {
        if (id==tachesPreemptables[i]->getId()) return tachesPreemptables[i];
    }
    return 0;
}

void Projet::afficherTaches() const {
    if(tachesUnitaires.size())std::cout<<"\nTaches Unitaires :";
    for(std::size_t i=0;i<tachesUnitaires.size();++i) {
        std::cout<<*tachesUnitaires[i]<<std::endl;
    }
    if(tachesComposites.size())std::cout<<"\nTaches Composites :";
    for(std::size_t i=0;i<tachesComposites.size();++i) {
        std::cout<<*tachesComposites[i]<<std::endl;
    }
    if(tachesPreemptables.size())std::cout<<"\nTaches Preemptables : ";
    for(std::size_t i=0;i<tachesPreemptables.size();++i) {
        std::cout<<*tachesPreemptables[i]<<std::endl;
    }
}

TacheUnitaire& Projet::ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech = tachesUnitaires[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesUnitaires[i]);
        //}
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech = tachesComposites[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesComposites[i]);
        //}
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech = tachesPreemptables[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesPreemptables[i]);
        //}
    }
    addItemU(newt);
    return *newt;
}

TachePreemptable& Projet::ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech = tachesUnitaires[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesUnitaires[i]);
        //}
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech = tachesComposites[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesComposites[i]);
        //}
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech = tachesPreemptables[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesPreemptables[i]);
        //}
    }
    addItemP(newt);
    return *newt;
}

TacheComposite& Projet::ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans le projet");
    TacheComposite* newt=new TacheComposite(id,t,dispo,deadline);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech = tachesUnitaires[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesUnitaires[i]);
        //}
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech = tachesComposites[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesComposites[i]);
        //}
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech = tachesPreemptables[i]->getDate();
        //if(ech<newt->getDate())
        //{
            std::cout<<"MArceau YAAAAYE";
            newt->addItem(tachesPreemptables[i]);
        //}
    }
    addItemC(newt);
    return *newt;
}

void Projet::supprimerTache(const QString& ident){
    for(std::size_t i=0;i<tachesUnitaires.size();++i) {
        if (ident==tachesUnitaires[i]->getId())
        {
            tachesUnitaires.erase(tachesUnitaires.begin()+i);
            return;
        }
    }
    for(std::size_t i=0;i<tachesComposites.size();++i) {
        if (ident==tachesComposites[i]->getId())
        {
            tachesComposites.erase(tachesComposites.begin()+i);
            return;
        }
    }
    for(std::size_t i=0;i<tachesPreemptables.size();++i) {
        if (ident==tachesPreemptables[i]->getId())
        {
            tachesPreemptables.erase(tachesPreemptables.begin()+i);
            return;
        }
    }
}

Tache& Projet::getTache(const QString& id){
    Tache* t=trouverTache(id);
    if (!t) throw CalendarException("erreur, Projet, tache inexistante");
    return *t;
}

void Projet::addItemU(TacheUnitaire* t){
    tachesUnitaires.push_back(t);
}

void Projet::addItemC(TacheComposite* t){
    tachesComposites.push_back(t);
}

void Projet::addItemP(TachePreemptable* t){
    tachesPreemptables.push_back(t);
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

void Projet::afficherPrecedence(const QString& id) const
{
    for(std::size_t i=0;i<tachesUnitaires.size();++i) {
        if (id==tachesUnitaires[i]->getId())
        {
            tachesUnitaires[i]->afficherPrecedence();
            return;
        }
    }
    for(std::size_t i=0;i<tachesComposites.size();++i) {
        if (id==tachesComposites[i]->getId())
        {
            tachesComposites[i]->afficherPrecedence();
            return;
        }
    }
    for(std::size_t i=0;i<tachesPreemptables.size();++i) {
        if (id==tachesPreemptables[i]->getId())
        {
            tachesPreemptables[i]->afficherPrecedence();
            return;
        }
    }
}

