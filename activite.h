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
<<<<<<< HEAD
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
         *  \param estProg : Etat de programmation de l'evenement
         */
    Activite(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool estProg=false): Evenement(ident,t,d,ech), duree(du),lieu(li){}

    /*!
         *  \brief getDuree
         *
         *  Accesseur en lecture de la duree de l'activite
         */
=======
    Activite(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool b=false): Evenement(ident,t,d,ech,b), duree(du),lieu(li){}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    const Duree& getDuree()const{return duree;}

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
<<<<<<< HEAD
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
         *  \param estProg : Etat de programmation de l'evenement
         */
    Reunion(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool estProg=false):Activite(ident,t,d,ech,du,li){}

    /*!
         *  \brief Type
         *
         *  Methode qui retourne le type "Reunion"
         */
=======
    Reunion(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b){}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
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
    void supprimmerParticipant(const QString & parti);

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
<<<<<<< HEAD

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
         *  \param estProg : Etat de programmation de l'evenement
         */
    Rdv(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du, const QString& pers, const QString& li,bool estProg=false):Activite(ident,t,d,ech,du,li),personne(pers){}

    /*!
         *  \brief getInterlocuteur
         *
         *  Accesseur en lecture sur l'interlocuteur
         */
=======
    Rdv(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du, const QString& pers, const QString& li,bool b=false):Activite(ident,t,d,ech,du,li,b),personne(pers){}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    const QString& getInterlocuteur() const { return personne; }

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

