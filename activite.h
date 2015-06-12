#ifndef ACTIVITE
#define ACTIVITE

/*!
 * \file activite.h
 * \brief Fichier gerant les activités diverses presents dans l'agenda
 */

using namespace std;
#include "qt.h"
#include "timing.h"
#include "evenement.h"
#include "calendar.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <typeinfo>

/*! \class Activite
   * \brief classe representant une Activite traditionnelle
   *
   *  La classe Activite est un evenement ayant une duree
   *  specifiee ainsi qu'un lieu.
   */

class Activite : public Evenement {
protected:
    Duree duree;/*!< Duree de l'evenement*/
    QString lieu;/*!< Lieu de l'evenement*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Activite
         *
         *  \param ident : Identifiant de l'activite
         *  \param t : Titre de l'activite
         *  \param d : Date de disponibilite de l'activite
         *  \param ech : Date d'echeance de l'activite
         *  \param du : Duree de l'activite
         *  \param li : Lieu de l'activite
         *  \param b : Etat de programmation de l'evenement
         */
    Activite(const QString& ident, const QString& t, const QDateTime& d,const QDateTime& ech,const Duree& du,const QString& li,bool b=false): Evenement(ident,t,d,ech,b), duree(du),lieu(li){}

    /*!
         *  \brief getDuree
         *
         *  Accesseur en lecture de la duree de l'activite
         */

    const Duree getDuree()const{return duree;}

    /*!
         *  \brief getLieu
         *
         *  Accesseur en lecture du lieu de l'activite
         */
    const QString& getLieu()const{return lieu;}

    /*!
         *  \brief setLieu
         *
         *  Accesseur en écriture du lieu de l'activite
         *
         *  \param newLieu : nom du lieu avec lequel on veut initialiser le lieu de l'activité
         */
    void setLieu(QString newLieu) { lieu = newLieu; }

    /*!
         *  \brief setDuree
         *
         *  Accesseur en écriture de la duree de l'activite
         *
         *  \param newDuree : la duree avec lequelle on veut initialiser la duree de l'activité
         */
    void setDuree(Duree newDuree) { duree = newDuree; }

    /*!
         *  \brief Type
         *
         *  Methode qui retourne le type "Activite"
         */
    QString Type() const {return typeid(*this).name();}

    /*!
         *  \brief afficher
         *
         *  Permet d'afficher une activite avec tous ces parametres.
         *
         *  \param f : Flux sur lequel on écrit
         */
    void afficher(std::ostream& f) const {
         Evenement::afficher(f);
         f<<"\nDuree="<<duree<<"\nLieu="<<lieu.toStdString()<<"\n";
    }

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Activite
         */
    ~Activite() {}

    /*!
         *  \brief getInterlocuteur
         *
         *  Accesseur en lecture sur l'interlocuteur
         */

    virtual const QString getInterlocuteur() const { return 0; }

    /*!
         *  \brief setInterlocuteur
         *
         *  Accesseur en écriture sur l'interlocuteur
         *
         * \param interl : initialise notre interlocuteur avec ce nom
         */
    virtual void setInterlocuteur(const QString& ) {}
    /*!
         *  \brief getNbParticipants
         *
         *  Methode retournant le nombre de participants inscrit à la réunion
         */
    virtual int getNbParticipants() const {return 0;}

    /*!
         *  \brief ajouterParticipant
         *
         *  Permet d'ajouter un participant à la réunion
         *
         *  \param parti : nom du participant que l'on veut rajouter à la réunion
         */

    virtual void ajouterParticipant(const QString &){};

    virtual QString toString() const{ return "";}

    virtual const vector<QString>& getParticipants() const {vector<QString> v; return v;}

    virtual const QString getParticipant(int i) const {i++;return 0;}

    /*!
         *  \brief supprimmerParticipant
         *
         *  Permet de supprimer un participant de la réunion
         *
         *  \param parti : nom du participant que l'on veut supprimer de la réunion
         */
    virtual void supprimerParticipant(const QString & ){};

};


/*! \class Reunion
   * \brief classe representant une Activite spéciale : une Reunion
   *
   *  La classe Reunion est une activite ayant une liste de participants spécifiée.
   */

class Reunion : public Activite {
private:
    vector<QString> participants;/*!< Liste des participants à la reunion*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Reunion
         *
         *  \param ident : Identifiant de l'activite
         *  \param t : Titre de l'activite
         *  \param d : Date de disponibilite de l'activite
         *  \param ech : Date d'echeance de l'activite
         *  \param du : Duree de l'activite
         *  \param li : Lieu de l'activite
         *  \param b : Etat de programmation de l'evenement
         */
     Reunion(const QString& ident, const QString& t, const QDateTime& d,const QDateTime& ech,const Duree& du,const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b){}

    /*!
         *  \brief Type
         *
         *  Methode qui retourne le type "Reunion"
         */

    QString Type() const {return typeid(*this).name();}

    /*!
         *  \brief getNbParticipants
         *
         *  Methode retournant le nombre de participants inscrit à la réunion
         */
    int getNbParticipants() const {return static_cast<int>(participants.size());}

    /*!
         *  \brief getParticipants
         *
         *  Accesseur en lecture des participants de la réunion
         */
    const vector<QString>& getParticipants() const {return participants;}

    const QString getParticipant(int i) const {return participants[i];}

    QString toString() const{
        std::stringstream s;
        for (size_t i=0;i<participants.size();++i)
            s<<qPrintable(participants[i])<<" ";
        return QString::fromStdString(s.str());
    }
    /*!
         *  \brief ajouterParticipant
         *
         *  Permet d'ajouter un participant à la réunion
         *
         *  \param parti : nom du participant que l'on veut rajouter à la réunion
         */
    void ajouterParticipant(const QString & parti);

    /*!
         *  \brief supprimmerParticipant
         *
         *  Permet de supprimer un participant de la réunion
         *
         *  \param parti : nom du participant que l'on veut supprimer de la réunion
         */
    void supprimerParticipant(const QString & parti);

    /*!
         *  \brief afficher
         *
         *  Permet d'afficher une reunion avec tous ces parametres.
         *
         *  \param f : Flux sur lequel on écrit
         */

    void afficher(std::ostream& f) const {
         Activite::afficher(f);
         for (size_t i=0;i<participants.size();++i)
             f<<"Participants: "<<qPrintable(participants[i]);
    }

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Reunion
         */
     ~Reunion() {}
};


/*! \class Rdv
   * \brief classe representant une Activite spéciale : une Rdv
   *
   *  La classe Reunion est une activite ayant un interlocuteur spécifiée.
   */

class Rdv : public Activite{
private:
    QString personne;/*!< représente l'interlocuteur du rendez vous */
public: 
    /*!
         *  \brief Type
         *
         *  Methode qui retourne le type "Rendez-vous"
         */
    QString Type() const {return typeid(*this).name();}

    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Rendez-vous
         *
         *  \param ident : Identifiant de l'activite
         *  \param t : Titre de l'activite
         *  \param d : Date de disponibilite de l'activite
         *  \param ech : Date d'echeance de l'activite
         *  \param du : Duree de l'activite
         *  \param li : Lieu de l'activite
         *  \param pers : interlocuteur du rendez-vous
         *  \param b : Etat de programmation de l'evenement
         */
    Rdv(const QString& ident, const QString& t, const QDateTime& d,const QDateTime& ech,const Duree& du, const QString& pers, const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b),personne(pers){}

    /*!
         *  \brief getInterlocuteur
         *
         *  Accesseur en lecture sur l'interlocuteur
         */

    const QString getInterlocuteur() const { return personne; }

    /*!
         *  \brief setInterlocuteur
         *
         *  Accesseur en écriture sur l'interlocuteur
         *
         * \param interl : initialise notre interlocuteur avec ce nom
         */
    void setInterlocuteur(const QString& interl) { personne = interl; }

    /*!
         *  \brief afficher
         *
         *  Permet d'afficher un rendez-vous avec tous ces parametres.
         *
         *  \param f : Flux sur lequel on écrit
         */
    void afficher(std::ostream& f) const {
         Activite::afficher(f);
         f<<"Interlocuteur="<<personne.toStdString();
    }

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Rendez vous
         */
     ~Rdv() {}
};

#endif // ACTIVITE

