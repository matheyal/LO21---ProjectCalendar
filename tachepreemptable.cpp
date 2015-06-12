#include "tachepreemptable.h"

std::ostream& operator<<(std::ostream& fout, const TachePreemptable& t){
    t.TachePreemptable::afficher(fout);
    return fout;
};

void TachePreemptable::commencer()
{
    setDebut(QDate::currentDate());
    setFin(getDebut().addDays(getDuree()));
    setEnCours(true);
}

void TachePreemptable::interruption()
{
    if (getEnCours()==false)
    {
        //QMessageBox::warning(this,"error", "tache pas commencée");
        return;
    }
    setEnCours(false);
    int diff = getDebut().daysTo(QDate::currentDate());
    setReste(getDuree() - diff);
}

void TachePreemptable::reprise()
{
    if (getEnCours()==true)
    {
        std::cout<<"Tache déja en cours";
        return;
    }
    setEnCours(true);
    setFin(QDate::currentDate().addDays(getReste()));
}

