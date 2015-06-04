#include"projetmanager.h"

Projet* ProjetManager::trouverProjet(const QString &ti) const
{
    for(std::size_t i=0;i<projets.size();++i) {
        if (ti==projets[i]->getTitre()) return projets[i];
    }
    return 0;
}


Projet* ProjetManager::ajouterProjet(const QString &ti, const QString &desc, const Date &d, const Date &ech)
{
    Projet* newP = new Projet(ti, desc, d, ech);
    if(trouverProjet(ti))
        throw ProjetManagerException("Projet deja existant");
    else projets.push_back(newP);
}

void ProjetManager::supprimerProjet(const QString& ti)
{
    for(std::size_t i=0; i< projets.size(); ++i)
    {
        if(trouverProjet(ti)) projets.erase(projets.begin()+i);
        return;
    }
    throw ProjetManagerException("Projet inexistant");

}
