#include "tachepreemptable.h"

std::ostream& operator<<(std::ostream& fout, const TachePreemptable& t){
    t.TachePreemptable::afficher(fout);
    return fout;
};

void TachePreemptable::addItem(Tache* t){
    tachesPrecedentes.push_back(t);
}

void TachePreemptable::afficherPrecedence() const
{
    for(std::size_t i=0;i<tachesPrecedentes.size();++i) {
        std::cout<<*tachesPrecedentes[i]<<std::endl;
    }
}
