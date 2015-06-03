#ifndef PROJET
#define PROJET

#include "tache.h"
#include "fabrique.h"
#include <QString>


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
public:
     Projet(const QString& ti, const QString& desc, const Date& d,const Date& ech):titre(ti),description(desc),dispo(d),echeance(ech),taches(0){}
     void ajouterTache(const QString& ident, const QString& t, const Date& d,const Date& ech);
     void supprimerTache(const QString& ident, const QString& t, const Date& d,const Date& ech);
     Tache& getTache(int ident);
     Tache& creation(const QString& ident, const QString& t, const Date& d,const Date& ech){Tache(ident,t,d,ech);}
     QString getTitre(){return titre;}
     QString getDesc() {return description;}
     Date getDispo(){return dispo;}
     void setTitre(const QString& nom){titre = nom;}
     void setDispo(const Date& dateDispo){dispo  = dateDispo;}
     void setEcheance(const Date& ech){echeance  = ech;}
};

#endif // PROJET

