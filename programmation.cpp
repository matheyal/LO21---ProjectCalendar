#include "programmation.h"

void Programmation::afficher(std::ostream& f) const{
    event->afficher(cout);
    f<<"\nDate : "<<date<<"\nHeure : "<<heure<<std::endl;
}
