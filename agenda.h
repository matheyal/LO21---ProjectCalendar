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
   struct Handler{
       Agenda* instance;
       Handler():instance(0){}
       // destructeur appelé la fin du programme
       ~Handler(){ if (instance) delete instance; }
   };
   static Handler handler;

public:

   Programmation* trouverProgrammation(Evenement* e) const;
   static Agenda& getInstance();
   static void libererInstance();
   Programmation& ajouterProg(Evenement* e, const Date& d, const Horaire& h);
   void supprimerProg(Evenement* e);
   void afficherProg();

};

#endif // AGENDA

