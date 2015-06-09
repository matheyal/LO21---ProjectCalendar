#include "tachecomposite.h"


std::ostream& operator<<(std::ostream& fout, const TacheComposite& t){
    t.TacheComposite::afficher(fout);
    return fout;
};




Tache* TacheComposite::trouverTache(const QString& id)const{
    for(std::size_t i=0;i<soustaches.size();++i) {
        if (id==soustaches[i]->getId()) return soustaches[i];
    }
    return 0;
}

/*TacheUnitaire& TacheComposite::ajouterTacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur,bool b){
    if (trouverTache(id)) throw CompositeException("erreur, tache deja existante dans la tache composite");
    TacheUnitaire* newt=new TacheUnitaire(id,t,dispo,deadline, dur, b);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<soustaches.size(); ++i)
    {
        QDate ech(soustaches[i]->getEcheance());
        std::cout<<"Date"<<ech;
        if(ech<newt->getDate())
        {
            newt->addItem(soustaches[i]);
        }
    }
    addItem(newt);
    return *newt;
}

TachePreemptable& TacheComposite::ajouterTachePreemptable(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur,bool b){
    if (trouverTache(id)) throw CompositeException("erreur, tache deja existante dans la tache composite");
    TachePreemptable* newt=new TachePreemptable(id,t,dispo,deadline, dur, b);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<soustaches.size(); ++i)
    {
        QDate ech(soustaches[i]->getEcheance());
        if(ech<newt->getDate())
        {
            newt->addItem(soustaches[i]);
        }
    }
    addItem(newt);
    return *newt;
}


TacheComposite& TacheComposite::ajouterTacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, bool b){
    if (trouverTache(id)) throw CompositeException("erreur, tache deja existante dans la atche composite");
    TacheComposite* newt=new TacheComposite(id,t,dispo,deadline, b);
    //Ajouter les taches precedentes
    for(std::size_t i=0; i<soustaches.size(); ++i)
    {
        QDate ech(soustaches[i]->getEcheance());
        if(ech<newt->getDate())
        {
            std::cout<<"Ajout tache unitaireSALADE";
            newt->addItem(soustaches[i]);
        }
    }
    addItem(newt);
    return *newt;
}*/

void TacheComposite::afficherSousTaches() const {
    for(std::size_t i=0;i<soustaches.size();++i) {
        std::cout<<"\nSous-Tache "<<i<<": "<<std::endl;
        soustaches[i]->afficher(std::cout);
        std::cout<<"\n";
    }
}

void TacheComposite::supprimerSousTache(const QString& ident){
    for(std::size_t i=0;i<soustaches.size();++i) {
        if (ident==soustaches[i]->getId())
        {
            soustaches.erase(soustaches.begin()+i);
            return;
        }
    }
}

void TacheComposite::commencer()
{
    setDebut(QDateTime::currentDateTime());
}

