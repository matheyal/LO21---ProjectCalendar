#include "tacheunitaire.h"


std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t){
    t.TacheUnitaire::afficher(fout);
    return fout;
};

void TacheUnitaire::commencer()
{
    setDebut(QDateTime::currentDateTime());
    int min=duree.getDureeEnMinutes();
    setFin(getDebut().addSecs(min*60));
    std::cout<<"tout va bien";
}
