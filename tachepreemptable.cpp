#include "tachepreemptable.h"

std::ostream& operator<<(std::ostream& fout, const TachePreemptable& t){
    fout<<t.getId().toStdString()<<"\n";
    fout<<t.getTitre().toStdString()<<"\n";
    fout<<t.getDate()<<"\n";
    fout<<t.getEcheance()<<"\n";
    fout<<t.getDuree()<<"\n";
    return fout;
};
