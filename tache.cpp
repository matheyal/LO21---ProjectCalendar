#include "tache.h"


std::ostream& operator<<(std::ostream& fout, const Tache& t){
    fout<<t.getId().toStdString()<<"\n";
    fout<<t.getTitre().toStdString()<<"\n";
    fout<<t.getDate()<<"\n";
    fout<<t.getEcheance()<<"\n";
    return fout;
}

