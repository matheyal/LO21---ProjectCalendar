#ifndef TACHECOMPOSITE
#define TACHECOMPOSITE

#include "timing.h"
#include "tache.h"
#include <vector>

class TacheComposite : public Tache {
private:
    vector<Tache*> soustaches;
    TacheComposite(const QString& ident, const QString& t, const Date& d,const Date& ech):Tache(ident,t,d,ech),soustaches(0){}
public:
    void ajouterSousTache(const QString& ident, const QString& t, const Date& d,const Date& ech);
    void supprimerSousTache(const Tache& t);

};

#endif // TACHECOMPOSITE

