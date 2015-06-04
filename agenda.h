#ifndef AGENDA
#define AGENDA

using namespace std;
#include <vector>
#include "timing.h"
#include "programmation.h"
#include "evenement.h"

using namespace TIME;

class AgendaException
{
    QString info;

public:
    AgendaException(const QString& s):info(s) {}
    QString& getInfo() { return info; }
};

class Agenda {
private:
   vector<Programmation*> progs;
   void addItem(Programmation* p);
   Agenda();
   ~Agenda();
   Agenda(const Agenda& a);
   Agenda& operator=(const Agenda& a);

public:
   struct Handler{
       Agenda* instance;
       Handler():instance(0){}
       // destructeur appelé la fin du programme
       ~Handler(){ if (instance) delete instance; }
   };
   Programmation* trouverProgrammation(const Evenement& e) const;
   Agenda& getInstance();
   void libererInstance();
   static Handler handler;
   Programmation& ajouterProg(const Evenement& e, const Date& d, const Horaire& h);
   void supprimerProg(const Evenement& e);
   void afficherProg();

};

#endif // AGENDA

