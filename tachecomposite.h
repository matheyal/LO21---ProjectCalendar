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
    TacheComposite(const QString& ident, const QString& t, const Date& d,const Date& ech):Tache(ident,t,d,ech),soustaches(0), tachesPrecedentes(0){}
    void ajouterSousTache(const QString& ident, const QString& t, const Date& d,const Date& ech);
    void supprimerSousTache(const Tache& t);
    bool begun(){};
    bool terminated(){};
    void addItem(Tache* t);
    void afficherPrecedence() const;

};

std::ostream& operator<<(std::ostream& fout, const TacheComposite& t);

#endif // TACHECOMPOSITE

