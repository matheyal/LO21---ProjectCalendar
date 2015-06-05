#include "tachecomposite.h"


std::ostream& operator<<(std::ostream& fout, const TacheComposite& t){
    t.TacheComposite::afficher(fout);
    return fout;
};

void TacheComposite::addItem(Tache* t){
    tachesPrecedentes.push_back(t);
}

void TacheComposite::afficherPrecedence() const
{
    for(std::size_t i=0;i<tachesPrecedentes.size();++i) {
        std::cout<<*tachesPrecedentes[i]<<std::endl;
    }
}
