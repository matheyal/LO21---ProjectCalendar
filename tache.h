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
    QDateTime debut;
    QDateTime fin;
public:
    Tache(const QString& ident, const QString& t, const Date& d,const Date& ech): Evenement(ident,t,d,ech), tachesPrecedentes(0), debut(QDateTime::currentDateTime()), fin(QDateTime::currentDateTime()){std::cout<<"creation d'une tache\n";}
    virtual bool begun()=0;
    virtual bool terminated()=0;
    virtual void afficher(std::ostream& f)const =0;
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
    void addPrecedence(Tache* t){tachesPrecedentes.push_back(t);}
};

std::ostream& operator<<(std::ostream& f, const Tache& t);


#endif // TACHE

