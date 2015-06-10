#include "programmation.h"

void Programmation::afficher(std::ostream& f) const{
    event->afficher(cout);
    f<<"\nDate : "<<qPrintable(date.toString(Qt::ISODate))<<"\nHeure : "<<heure<<std::endl;
}
