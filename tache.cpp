#include "tache.h"


/*std::ostream& operator<<(std::ostream& fout, const Tache& t){
    t.Tache::afficher(fout);
    return fout;
}*/

void Tache::addItem(Tache *t)
{
    for(std::size_t i=0; i<tachesPrecedentes.size(); i++)
    {
        if(t->getId()==tachesPrecedentes[i]->getId())
        {
            std::cout<<"tache deja présente dans la contrainte de precedence";
            return;
        }
    }
    if((this->getEcheance())<(t->getDate()))
    {
        std::cout<<"Tache précédente finie avant que notre tache commence";
        return;
    }
    tachesPrecedentes.push_back(t);
}

void Tache::afficherPrecedence()
{
    for(std::size_t i=0; i<tachesPrecedentes.size(); i++)
    {
        std::cout<<"\nID : "<<qPrintable(tachesPrecedentes[i]->getId())<<"\nTitre : "<<qPrintable(tachesPrecedentes[i]->getTitre())<<"\nDate dispo : "<<tachesPrecedentes[i]->getDate()<<"\nDate echeance : "<<tachesPrecedentes[i]->getEcheance()<<"\n";
    }
}
