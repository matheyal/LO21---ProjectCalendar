#ifndef EVENEMENT
#define EVENEMENT

/*!
 * \file evenement.h
 * \brief Fichier gerant les evenements diverses presents dans l'agenda
 */

#include "timing.h"
#include "qt.h"

using namespace std;
using namespace TIME;

/*! \class Evenement
   * \brief classe representant les evenements.
   *
   *  La classe gere la creation d'evenements diverses et que l'on pourrait avoir a l'interieur de notre agenda.
   *  Cela pourrait etre un rendez vous ou autre mais ne peut pas être une tache.
   */

class Evenement {
protected:
<<<<<<< HEAD
    QString id;/*!< Identifiant de l'evenement*/
    QString titre;/*!< Titre de l'evenement*/
    Date dispo;/*!< Date de disponibilite de l'evenement*/
    Date echeance;/*!< Date d'echeance de l'evenement*/
    bool estProg;/*!< Booleen permettant de savoir si un evenement est programmé*/
public: 
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Evenement
         *
         *  \param ident : Identifiant de l'evenement
         *  \param t : Titre de l'evenement
         *  \param d : Date de disponibilite de l'evenement
         *  \param ech : Date d'echeance de l'evenement
         *  \param estProg : Etat de programmation de l'evenement
         */
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech, bool estProg=false):id(ident),titre(t),dispo(d),echeance(ech){std::cout<<"creation d'un evenement";}

    /*!
         *  \brief getId
         *
         *  Accesseur en lecture de l'identifiant de l'evenement
         */
=======
    QString id;
    QString titre;
    Date dispo;
    Date echeance;
    bool estProg;
public:
    Evenement(const QString& ident, const QString& t, const Date& d,const Date& ech, bool b=false):id(ident),titre(t),dispo(d),echeance(ech), estProg(b){std::cout<<"\ncreation d'un evenement";}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    QString getId() const{return id;}

    /*!
         *  \brief getStauts
         *
         *  Accesseur en lecture de l'etat de l'evenement : programmé ou non
         */
    bool getStatus()const {return estProg;}

    /*!
         *  \brief getTitre
         *
         *  Accesseur en lecture du titre de l'evenement
         */
    QString getTitre() const{return titre;}

    /*!
         *  \brief getDate
         *
         *  Accesseur en lecture de la date de disponibilite de l'evenement
         */
    Date getDate() const{return dispo;}

    /*!
         *  \brief getEcheance
         *
         *  Accesseur en lecture de la date d'écheance de l'evenement
         */
    Date getEcheance() const{return echeance;}

    /*!
         *  \brief setTitre
         *
         *  Accesseur en écriture du titre de l'evenement
         *
         *  \param t : nom du titre avec lequel on veut initialiser le titre de l'evenement
         */
    void setTitre(const QString& t) {titre = t;}

    /*!
         *  \brief setDateDisponibilite
         *
         *  Accesseur en écriture de la date de disponibilite de l'evenement
         *
         *  \param d : date avec laquelle on veut initialiser la date de disponibilite de l'evenement
         */
    void setDateDisponibilite(const Date& d) {dispo = d;}

    /*!
         *  \brief setEcheance
         *
         *  Accesseur en écriture de la date d'écheance de l'evenement
         *
         *  \param ech : date avec laquelle on veut initialiser la date d'echeance de l'evenement
         */
    void setEcheance(const Date& ech) {echeance = ech;}
<<<<<<< HEAD

    /*!
         *  \brief setEffectue
         *
         *  Accesseur en écriture du status de l'evenement (programme ou non)
         *
         *  \param effect : valeur avec laquelle on veut changer le status de l'evenement (vrai ou faux)
         */
    virtual void setEffectue(bool effect) {estProg=effect;}

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Evenement
         */
=======
    void setEffectue(bool effect){estProg=effect;}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    virtual ~Evenement() {}

    /*!
         *  \brief Type
         *
         *  Methode qui retourne le type "Evenement"
         */
    virtual QString Type() const=0;

    /*!
         *  \brief afficher
         *
         *  Permet d'afficher un evenement avec tous ces parametres
         *  Methode virtuelle pure : la classe Evenement est abstraite
         *
         *  \param f : Flux sur lequel on écrit
         */
    virtual void afficher(std::ostream& f) const{
        f<<"\n\nID : "<<qPrintable(id)<<"\nTitre : "<<qPrintable(titre)<<"\nDispo : "<<dispo<<"\nEcheance : "<<echeance<< " \nEst programme:";
        if (estProg) f<<"vrai";
        else f<<"faux";
    }

    /*!
         *  \brief operator<
         *
         *  Surcharge de l'operateur < pour comparer deux evenements entre eux : savoir lequel est antérieur à l'autre
         *
         *  \param e : Evenement avec lequel on souhaite comparer notre objet
         */
    bool operator<(const Evenement& e)const
    {
        return dispo<e.dispo && echeance<e.echeance;
    }
<<<<<<< HEAD

=======
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
};

/*!
     *  \brief operator<<
     *
     *  Surcharge de l'opérator << pour permettre d'afficher un evenement sur le flux de sortie.
     *
     *  \param fout : Flux sur lequel on écrit
     *  \param e : Evenement que l'on souhaite afficher
     *
     */
std::ostream& operator<<(std::ostream& fout, const Evenement& e);

/*!
     *  \brief operator==
     *
     *  Surcharge de l'opérator == pour permettre de comparer deux evenements entre eux
     *
     *  \param e1 : Premier evenement que l'on souhaite comparer
     *  \param e2 : Second evenement que l'on compare avec le premier
     *
     */
bool operator ==(const Evenement& e1, const Evenement& e2);


#endif // EVENEMENT

