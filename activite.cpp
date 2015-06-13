

#include "activite.h"

void Reunion::ajouterParticipant(const QString & parti){
    participants.push_back(parti);
}

void Reunion::supprimerParticipant(const QString & parti){
    vector<QString>::iterator ite = participants.begin();
    while(ite != participants.end()){
        if((*ite) == parti){
            participants.erase(ite);
            return;
        }
        ++ite;
    }
}
