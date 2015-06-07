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
    TacheComposite(const QString& ident, const QString& t, const Date& d,const Date& ech):Tache(ident,t,d,ech), soustaches(0){std::cout<<"creation d'une tache composite\n";}
    TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
    TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
    TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline);
    void supprimerSousTache(const QString& ident);
    void afficherSousTaches() const ;
    void afficher(std::ostream& f)const {Evenement::afficher(f);}
    bool begun(){};
    bool terminated(){};
    //Définition de getDuree() pour éviter que la classe soit abstraite mais n'a pas rellement de sens
    Duree getDuree() const{return 0;};
    Tache* trouverTache(const QString& id)const;
    void commencer();
    Duree getDuree() const{return 0;}
};

std::ostream& operator<<(std::ostream& fout, const TacheComposite& t);

#endif // TACHECOMPOSITE



