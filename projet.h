#ifndef PROJET
#define PROJET

#include "tacheunitaire.h"
#include "tachecomposite.h"
#include "tachepreemptable.h"
#include "tache.h"
#include "fabrique.h"
#include "qt.h"
#include "calendar.h"
#include "timing.h"

class ProjetException
{
    QString info;

public:
    ProjetException(const QString& s):info(s) {}
    QString& getInfo() { return info; }
};

class Projet : public Fabrique{
private:
     QString id;
     QString titre;
     QString description;
     Date dispo;
     Date echeance;
     vector<Tache*> taches;
     void addItem(Tache* t);
     Projet(const QString& i, const QString& ti, const QString& desc, const Date& d,const Date& ech):id(i), titre(ti),description(desc),dispo(d),echeance(ech),taches(0){}
     ~Projet();
     friend class ProjetManager;

public:

     TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
     TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
     TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline);
     void supprimerTache(const QString& ident);
     void afficherTaches() const;
     Tache& getTache(const QString& id);
     Tache* trouverTache(const QString& id)const;
     const Tache& getTache(const QString& id)const;
     QString getId() const {return id;}
     QString getTitre() const{return titre;}
     QString getDesc() const {return description;}
     Date getDispo()const {return dispo;}
     Date getEcheance() const {return echeance;}
     void setTitre(const QString& nom){titre = nom;}
     void setDispo(const Date& dateDispo){dispo  = dateDispo;}
     void setEcheance(const Date& ech){echeance  = ech;}
     void afficherPrecedence(const QString& id) const;
     /*size_t getSizeUnitaire(){return tachesUnitaires.size();}
     size_t getSizeComposite(){return tachesComposites.size();}
     size_t getSizePreemptable(){return tachesPreemptables.size();}*/
};

std::ostream& operator<<(std::ostream& f, const Projet& p);

#endif // PROJET

