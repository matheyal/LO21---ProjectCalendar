#ifndef PROJET
#define PROJET

#include "tacheunitaire.h"
#include "tachecomposite.h"
#include "tachepreemptable.h"
#include "tache.h"
#include "fabrique.h"
#include <QString>
#include <QDate>
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
     QString titre;
     QString description;
     Date dispo;
     Date echeance;
     vector<Tache*> taches;
     void addItem(Tache* t);

public:
     Projet(const QString& ti, const QString& desc, const Date& d,const Date& ech):titre(ti),description(desc),dispo(d),echeance(ech),taches(0){}
     ~Projet();
     TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
     TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const Date& dispo, const Date& deadline, const Duree& dur);
     TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const Date& dispo, const Date& deadline);
     void supprimerTache(const QString& ident);
     void afficherTaches();
     Tache& getTache(const QString& id);
     Tache* trouverTache(const QString& id)const;
     const Tache& getTache(const QString& id)const;
     QString getTitre(){return titre;}
     QString getDesc() {return description;}
     Date getDispo(){return dispo;}
     void setTitre(const QString& nom){titre = nom;}
     void setDispo(const Date& dateDispo){dispo  = dateDispo;}
     void setEcheance(const Date& ech){echeance  = ech;}
};

#endif // PROJET

