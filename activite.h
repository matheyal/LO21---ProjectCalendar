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
#include <vector>
#include <sstream>
#include <iostream>
#include <typeinfo>

class participants_iterator : public vector<QString>::const_iterator{
public:
    participants_iterator():vector<QString>::const_iterator(){}
    participants_iterator(vector<QString>::const_iterator it):vector<QString>::const_iterator(it){}
};

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
         *  \brief Destructeur
         *
         *  Destructeur de la classe Activite
         */
    ~Activite() {}
    Activite (const Activite&);
    Activite& operator=(const Activite&);
    friend class ActiviteManager;
public:

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
         *  \brief ajouterParticipant
         *
         *  Permet d'ajouter un participant à la réunion
         *
         *  \param parti : nom du participant que l'on veut rajouter à la réunion
         */

    virtual void ajouterParticipant(const QString &){};

    /*!
         *  \brief supprimmerParticipant
         *
         *  Permet de supprimer un participant de la réunion
         *
         *  \param parti : nom du participant que l'on veut supprimer de la réunion
         */
    virtual void supprimerParticipant(const QString & ){};

    virtual participants_iterator begin_participants() const {return participants_iterator();}
    virtual participants_iterator end_participants() const {return participants_iterator();}

    precedences_iterator begin_precedences() const {return precedences_iterator();}
    precedences_iterator end_precedences() const {return precedences_iterator();}

    bool withPrecedence() const { return false;}

};


/*! \class Reunion
   * \brief classe representant une Activite spéciale : une Reunion
   *
   *  La classe Reunion est une activite ayant une liste de participants spécifiée.
   */

class Reunion : public Activite {
private:
    vector<QString> participants;/*!< Liste des participants à la reunion*/
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
         *  \brief Destructeur
         *
         *  Destructeur de la classe Reunion
         */
     ~Reunion() {}
    Reunion (const Reunion&);
    Reunion& operator=(const Reunion&);
    friend class ActiviteManager;
public:

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


    participants_iterator begin_participants() const {return participants_iterator(participants.begin());}
    participants_iterator end_participants() const {return participants_iterator(participants.end());}
};


/*! \class Rdv
   * \brief classe representant une Activite spéciale : une Rdv
   *
   *  La classe Reunion est une activite ayant un interlocuteur spécifiée.
   */

class Rdv : public Activite{
private:
    QString personne;/*!< représente l'interlocuteur du rendez vous */
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
         *  \brief Destructeur
         *
         *  Destructeur de la classe Rendez vous
         */
     ~Rdv() {}
    Rdv (const Rdv&);
    Rdv& operator=(const Rdv&);
    friend class ActiviteManager;
public: 
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

};

#endif // ACTIVITE

