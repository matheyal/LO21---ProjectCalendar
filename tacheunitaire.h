#ifndef TACHEUNITAIRE
#define TACHEUNITAIRE


/*!
 * \file tacheunitaire.h
 * \brief Fichier gerant les taches unitaire d'un projet
 */

#include "timing.h"
#include "tache.h"
#include "qt.h"

/*! \class TacheUnitaire
   * \brief classe representant une tache qui ne contient pas de sous taches
   *
   *  La classe TacheUnitaire spécialise la classe Tache
   *
   */
class TacheUnitaire : public Tache {
private:
<<<<<<< HEAD
    static const int DUREE_MAX = 12; /*!< Variable statique pour implémentée la contrainte de durée maximum d'une tacheu- unitaire : 12h */
    Duree duree; /*!< Duree de la tache Unitaire */

public:

    /*!
         *  \brief TacheUnitaire
         *
         *  Constructeur de la classe TacheUnitaire
         *
         * \param ident : identifiant de la tache unitaire
         * \param t : titre de la tache unitaire
         * \param d : date de disponibilite de la tache unitaire
         * \param ech : date d'écheance de la tache unitaire
         * \param du : duree d'execution de la tache unitaire
         *
         */
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):Tache(ident,t,d,ech),duree(du){std::cout<<"creation d'une tache unitaire\n";}

    /*!
         *  \brief getDuree
         *
         *  Accesseur en lecture de la duree de la tache unitaire
         */
    Duree getDuree() const{return duree;}

    /*!
         *  \brief begun
         *
         *  Methode qui ne fait rien mais qui permet de rendre la classe tachecomposite concrète
         *
         *
         */
    bool begun(){};

    /*!
         *  \brief terminated
         *
         *  Methode qui ne fait rien mais qui permet de rendre la classe tachecomposite concrète
         *
         *
         */
    bool terminated(){};

    /*!
         *  \brief afficher
         *
         *  Specialisation de la méthode afficher de Evenement pour afficher une tache unitaire
         *
         * \param f : flux de sortie sur lequel on affiche les informations de la tache unitaire
         *
         */
=======
    Duree duree;

public:
    TacheUnitaire(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du,bool b=false):Tache(ident,t,d,ech,b),duree(du){std::cout<<"\ncreation d'une tache unitaire\n";}
    Duree getDuree() const{return duree;}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    void afficher(std::ostream& f)const {Evenement::afficher(f);std::cout<<"\nDuree : "<<getDuree();}

    /*!
        *  \brief commencer
        *
        *  Methode pour "commencer" une tache
        *  Initialise le début et la fin de la tache
        *
        */
    void commencer();

    /*!
        *  \brief setDuree
        *
        *  Accesseur en écriture qui initialise la durée de la tache unitaire en question
        *
        */
    void setDuree(Duree d){duree=d;}
<<<<<<< HEAD

    /*!
        *  \brief getSousTaches
        *
        *  Déclaration de getSousTaches pour ne pas avoir de classe abstraite
        *
        */
=======
    //Définition de getSousTaches, afficherSousTache et ajouterSousTache pour ne pas avoir de classe abstraite
    void afficherSousTache()const {};
    void ajouterSousTache(Tache* ){};
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    const vector<Tache*>* getSousTaches() const{return 0;}

};

/*!
     *  \brief operator<<
     *
     *  Surcharge de l'opérator << pour permettre d'afficher les caractéristiques d'une tache unitaire sur le flux de sortie.
     *
     *  \param fout : Flux sur lequel on écrit
     *  \param t : Tache unitaire que l'on souhaite afficher
     *
     */
std::ostream& operator<<(std::ostream& fout, const TacheUnitaire& t);

#endif // TACHEUNITAIRE

