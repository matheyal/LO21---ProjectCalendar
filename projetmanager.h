#ifndef PROJETMANAGER
#define PROJETMANAGER

#include "projet.h"

class ProjetManager {
private:
    vector<Projet*> projets;
public:
    void ajouterProjet(const QString& ti, const QString& desc, const Date& d,const Date& ech);
    void supprimerProjet(const QString& ti);
};

#endif // PROJETMANAGER

