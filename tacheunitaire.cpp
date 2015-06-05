#include "tacheunitaire.h"


std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t){
    t.TacheUnitaire::afficher(fout);
    return fout;
};
