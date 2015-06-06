#include "tachecomposite.h"


std::ostream& operator<<(std::ostream& fout, const TacheComposite& t){
    t.TacheComposite::afficher(fout);
    return fout;
};


void TacheComposite::addItem(Tache* t){
    tachesPrecedentes.push_back(t);
}

void TacheComposite::afficherPrecedence() const
{
    for(std::size_t i=0;i<tachesPrecedentes.size();++i) {
        std::cout<<"\nID : "<<qPrintable(tachesPrecedentes[i]->getId())<<"\nTitre : "<<qPrintable(tachesPrecedentes[i]->getTitre());
    }
}

TacheUnitaire& TacheComposite::ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans la tache composite");
    TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech(tachesUnitaires[i]->getEcheance());
        std::cout<<"Date"<<ech;
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache unitaire\n";
            newt->addItem(tachesUnitaires[i]);
        }
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech(tachesComposites[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache composite \n";
            newt->addItem(tachesComposites[i]);
        }
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech(tachesPreemptables[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache preemptable";
            newt->addItem(tachesPreemptables[i]);
        }
    }
    addItemU(newt);
    return *newt;
}

TachePreemptable& TacheComposite::ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans la tache composite");
    TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech(tachesUnitaires[i]->getEcheance());
        if(ech<newt->getDate())
        {
            newt->addItem(tachesUnitaires[i]);
        }
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech(tachesComposites[i]->getEcheance());
        if(ech<newt->getDate())
        {
            newt->addItem(tachesComposites[i]);
        }
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech(tachesPreemptables[i]->getEcheance());
        if(ech<newt->getDate())
        {
            newt->addItem(tachesPreemptables[i]);
        }
    }
    addItemP(newt);
    return *newt;
}


TacheComposite& TacheComposite::ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline){
    if (trouverTache(id)) throw ProjetException("erreur, tache deja existante dans la tache composite");
    TacheComposite* newt=new TacheComposite(id,t,dispo,deadline);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<tachesUnitaires.size(); ++i)
    {
        Date ech(tachesUnitaires[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache unitaire";
            newt->addItem(tachesUnitaires[i]);
        }
    }
    for(std::size_t i=0; i<tachesComposites.size(); ++i)
    {
        Date ech(tachesComposites[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache composite";
            newt->addItem(tachesComposites[i]);
        }
    }
    for(std::size_t i=0; i<tachesPreemptables.size(); ++i)
    {
        Date ech(tachesPreemptables[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache preemptable";
            newt->addItem(tachesPreemptables[i]);
        }
    }
    addItemC(newt);
    return *newt;
}
