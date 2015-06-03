#ifndef ACTIVITE
#define ACTIVITE

#include "timing.h"
#include "evenement.h"

class Activite : public Evenement {
private:
    Duree duree;
public:
    Duree getDuree(){return duree;}
};

#endif // ACTIVITE

