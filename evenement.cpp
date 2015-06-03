#include <string>
#include <iostream>
#include "evenement.h"


std::ostream& operator<<(std::ostream& fout, const Evenement& e){
    fout<<e.getId().toStdString()<<"\n";
    fout<<e.getTitre().toStdString()<<"\n";
    fout<<e.getDate()<<"\n";
    fout<<e.getEcheance()<<"\n";
    return fout;
}
