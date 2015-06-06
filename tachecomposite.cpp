#include "tachecomposite.h"


std::ostream& operator<<(std::ostream& fout, const TacheComposite& t){
    t.TacheComposite::afficher(fout);
    return fout;
};

void ajouterSousTache(const QString& ident, const QString& t, const Date& d,const Date& ech)
{

}

void TacheComposite::addItem(Tache* t){
    tachesPrecedentes.push_back(t);
}

void TacheComposite::afficherPrecedence() const
{
    for(std::size_t i=0;i<tachesPrecedentes.size();++i) {
        std::cout<<"\nID : "<<qPrintable(tachesPrecedentes[i]->getId())<<"\nTitre : "<<qPrintable(tachesPrecedentes[i]->getTitre());
    }
}
