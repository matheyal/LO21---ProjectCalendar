#include "tacheunitaire.h"


std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t){
    t.TacheUnitaire::afficher(fout);
    return fout;
};

void TacheUnitaire::addItem(Tache *t){
    tachesPrecedentes.push_back(t);
}

void TacheUnitaire::afficherPrecedence() const
{
    for(std::size_t i=0;i<tachesPrecedentes.size();++i) {
        std::cout<<*tachesPrecedentes[i]<<std::endl;
        std::cout<<"hello";
    }
}
