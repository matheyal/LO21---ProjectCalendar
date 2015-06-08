#ifndef TACHE
#define TACHE

#include "timing.h"
#include "evenement.h"
#include <vector>
#include "qt.h"
#include <typeinfo>

class Projet;

class Tache : public Evenement {
friend class Projet;
private:
    vector<Tache*> tachesPrecedentes;
    QDateTime debut;
    QDateTime fin;
public:
    QString Type() const {return typeid(*this).name();}
    Tache(const QString& ident, const QString& t, const Date& d,const Date& ech, bool b=false): Evenement(ident,t,d,ech,b), tachesPrecedentes(0), debut(QDateTime::currentDateTime()), fin(QDateTime::currentDateTime()){std::cout<<"\ncreation d'une tache";}
    void addItem(Tache* t);
    void afficherPrecedence();
    virtual void commencer()=0;
    void setDebut(QDateTime d){debut=d;}
    QDateTime getDebut() const {return debut;}
    void setFin(QDateTime f){fin=f;}
    QDateTime getFin() const{return fin;}
    //méthode virtuelle pour permettre l'appel de getDuree() sur un pointeur de Tache
    virtual Duree getDuree() const =0;
    //méthode virtuelle pour permettre l'appel de getSousTaches() sur un pointeur de Tache
    virtual const vector<Tache*>* getSousTaches() const = 0;
    const vector<Tache*>* getTachesPrecedentes() const{return &tachesPrecedentes;}
};

std::ostream& operator<<(std::ostream& f, const Tache& t);


#endif // TACHE

