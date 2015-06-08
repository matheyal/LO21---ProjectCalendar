#include "tachepreemptable.h"

std::ostream& operator<<(std::ostream& fout, const TachePreemptable& t){
    t.TachePreemptable::afficher(fout);
    return fout;
};

void TachePreemptable::commencer()
{
    setDebut(QDateTime::currentDateTime());
    int min=getDuree().getDureeEnMinutes();
    setFin(getDebut().addSecs(min*60));
    setEnCours(true);
}

void TachePreemptable::interruption()
{
    if (getEnCours()==false)
    {
        std::cout<<"Tache pas commencee";
        return;
    }
    setEnCours(false);
    int diff = getDebut().secsTo(QDateTime::currentDateTime());
    std::cout<<diff;
    Duree ecoulee(diff/60);
    int r = getDuree().getDureeEnMinutes() - ecoulee.getDureeEnMinutes();
    setReste(r);
    getReste().afficher();
}

void TachePreemptable::reprise()
{
    if (getEnCours()==true)
    {
        std::cout<<"Tache déja en cours";
        return;
    }
    setEnCours(true);
    int min=getReste().getDureeEnMinutes();
    setFin(QDateTime::currentDateTime().addSecs(min*60));
}
