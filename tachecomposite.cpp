#include "tachecomposite.h"


std::ostream& operator<<(std::ostream& fout, const TacheComposite& t){
    t.TacheComposite::afficher(fout);
    return fout;
};




Tache* TacheComposite::trouverTache(const QString& id)const{
    for(std::size_t i=0;i<soustaches.size();++i) {
        if (id==soustaches[i]->getId()) return soustaches[i];
    }
    return 0;
}


void TacheComposite::afficherSousTaches() const {
    for(std::size_t i=0;i<soustaches.size();++i) {
        std::cout<<"\nSous-Tache "<<i<<": "<<std::endl;
        soustaches[i]->afficher(std::cout);
        std::cout<<"\n";
    }
}

void TacheComposite::supprimerSousTache(const QString& ident){
    for(std::size_t i=0;i<soustaches.size();++i) {
        if (ident==soustaches[i]->getId())
        {
            soustaches.erase(soustaches.begin()+i);
            return;
        }
    }
}

void TacheComposite::commencer()
{
    setDebut(QDateTime::currentDateTime());
}

