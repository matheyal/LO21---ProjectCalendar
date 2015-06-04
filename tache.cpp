#include "tache.h"


std::ostream& operator<<(std::ostream& fout, const Tache& t){
    t.Tache::afficher();
    return fout;
}

