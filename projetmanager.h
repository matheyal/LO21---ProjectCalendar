#ifndef PROJETMANAGER
#define PROJETMANAGER

#include "projet.h"

class ProjetManagerException
{
    QString info;

public:
    ProjetManagerException(const QString& s):info(s) {}
    QString& getInfo() { return info; }
};

class ProjetManager {
private:
    vector<Projet*> projets;
public:
    Projet* ajouterProjet(const QString& ti, const QString& desc, const Date& d,const Date& ech);
    void supprimerProjet(const QString& ti);
    Projet* trouverProjet(const QString &ti) const;
};//hello

#endif // PROJETMANAGER

