#ifndef TACHECOMPOSITE
#define TACHECOMPOSITE

#include "timing.h"
#include "tache.h"
#include <vector>

class TacheComposite : public Tache {
private:
    vector<Tache*> tachesPrecedentes;
    vector<Tache*> soustaches;
public:
    TacheComposite(const QString& ident, const QString& t, const Date& d,const Date& ech):Tache(ident,t,d,ech), tachesPrecedentes(0), soustaches(0){std::cout<<"creation d'une tache composite\n";}
    void ajouterSousTache(const QString& ident, const QString& t, const Date& d,const Date& ech);
    void supprimerSousTache(const Tache& t);
    void afficher(std::ostream& f)const {Evenement::afficher(f);}
    bool begun(){};
    bool terminated(){};
    void addItem(Tache* t);
    void afficherPrecedence() const;

};

std::ostream& operator<<(std::ostream& fout, const TacheComposite& t);

#endif // TACHECOMPOSITE

