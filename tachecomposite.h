#ifndef TACHECOMPOSITE
#define TACHECOMPOSITE

#include "timing.h"
#include "tache.h"
#include "tacheunitaire.h"
#include "tachepreemptable.h"
#include <vector>

class CompositeException
{
    QString info;

public:
    CompositeException(const QString& s):info(s) {}
    QString& getInfo() { return info; }
};

class TacheComposite : public Tache {
private:
    vector<Tache*> soustaches;

public:
    TacheComposite(const QString& ident, const QString& t, const Date& d,const Date& ech, bool b=false):Tache(ident,t,d,ech,b), soustaches(0){std::cout<<"\ncreation d'une tache composite\n";}
    //TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur, bool b=false);
    //TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur, bool b=false);
    //TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline,bool b=false);
    void ajouterSousTache(Tache * t){soustaches.push_back(t);}
    void supprimerSousTache(const QString& ident);
    void afficherSousTache() const ;
    void afficher(std::ostream& f)const {Evenement::afficher(f);}
    Duree getDuree() const{return 0;}
    Tache* trouverTache(const QString& id)const;
    void commencer();
    const vector<Tache*>* getSousTaches() const{return &soustaches;}
};

std::ostream& operator<<(std::ostream& fout, const TacheComposite& t);

#endif // TACHECOMPOSITE



