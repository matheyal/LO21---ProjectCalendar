#ifndef PROJETMANAGER
#define PROJETMANAGER

#include "projet.h"
#include "export.h"

class ProjetManagerException
{
    QString info;

public:
    ProjetManagerException(const QString& s):info(s) {}
    QString& getInfo() { return info; }
};

class ProjetManager {
private:
    vector<Projet*> projets;
    ProjetManager();
    ~ProjetManager();
    ProjetManager(const ProjetManager& pm);
    ProjetManager& operator=(const ProjetManager& pm);
    struct Handler{
        ProjetManager* instance;
        Handler():instance(0){}
        // destructeur appelé la fin du programme
        ~Handler(){ if (instance) delete instance; }
    };
    static Handler handler;

public:

    static ProjetManager& getInstance();
    static void libererInstance();
    Projet* ajouterProjet(const QString& id, const QString& ti, const QString& desc, const Date& d,const Date& ech);
    void supprimerProjet(const QString& id);
    Projet* trouverProjet(const QString &id) const;
    void afficherProjets() const;
    unsigned int size() const {return projets.size();};
    const vector<Projet*>* getProjets() const{return &projets;}
    void save(ExportStrategy *strategy ,const QString& f){strategy->save(f);}
};

#endif // PROJETMANAGER

