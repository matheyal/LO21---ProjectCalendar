#ifndef EVENEMENT
#define EVENEMENT

#include "timing.h"
#include <QString>
#include <QDate>
#include <QTextStream>

using namespace std;

using namespace TIME;


class Evenement {
private:
    QString id;
    QString titre;
    Date dispo;
    Date echeance;
public:
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech):id(ident),titre(t),dispo(d),echeance(ech){}
    QString getId() const{return id;}
    QString getTitre() const{return titre;}
    Date getDate() const{return dispo;}
    Date getEcheance() const{return echeance;}
    void setTitre(const QString& t) {titre = t;}
    void setDateDisponibilite(const Date& d) {dispo = d;}
    void setEcheance(const Date& ech) {echeance = ech;}
    virtual QTextStream& afficher(QTextStream& f)const{f<<id<<"\n"<<titre<<"\n"<<date<<"\n"<<echeance<<"\n"; return f;} //arranger l'affichage pour le polymorphisme + créer la fonction dans les classes filles
};

std::ostream& operator<<(std::ostream& fout, const Evenement& e);
bool operator ==(const Evenement& e1, const Evenement& e2);

#endif // EVENEMENT

