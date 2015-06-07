#ifndef TACHE
#define TACHE

#include "timing.h"
#include "evenement.h"
#include <vector>
#include "qt.h"

class Projet;

class Tache : public Evenement {
friend class Projet;
private:
    vector<Tache*> tachesPrecedentes;
public:
    Tache(const QString& ident, const QString& t, const Date& d,const Date& ech): Evenement(ident,t,d,ech), tachesPrecedentes(0){std::cout<<"creation d'une tache\n";}
    virtual bool begun()=0;
    virtual bool terminated()=0;
    virtual void afficher(std::ostream& f)const =0;
    //Déclarationde getDUree pour pouvoir accéder à cette méthode de la classe TacheUnitaire à partir d'un pointeur de Tache
    virtual Duree getDuree() const = 0;
    void addItem(Tache* t);
    void afficherPrecedence();
};

std::ostream& operator<<(std::ostream& f, const Tache& t);


#endif // TACHE

