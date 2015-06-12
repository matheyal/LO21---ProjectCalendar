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
    TacheUnitaire(const QString& ident, const QString& t, const QDateTime& d,const QDateTime& ech,const Duree& du,bool b=false):Tache(ident,t,d,ech,b),duree(du){std::cout<<"\ncreation d'une tache unitaire\n";}

    /*!
         *  \brief getDuree
         *
         *  Accesseur en lecture de la duree de la tache unitaire
         */
    const Duree getDuree() const{return duree;}


    /*!
         *  \brief afficher
         *
         *  Specialisation de la méthode afficher de Evenement pour afficher une tache unitaire
         *
         * \param f : flux de sortie sur lequel on affiche les informations de la tache unitaire
         *
         */
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
    void setDuree(int d){duree=d;}

    /*!
        *  \brief getSousTaches
        *
        *  Déclaration de getSousTaches pour ne pas avoir de classe abstraite
        *
        */
    const vector<Tache*>* getSousTaches() const{return 0;}

    /*!
        *  \brief afficherSousTaches()
        *
        *  Méthode virtuelle pure pour permettre l'appel de afficherSousTache() sur une Tache
        *
        */
    void afficherSousTaches()const {}

    /*!
        *  \brief ajouterSousTache()
        *
        *  Méthode virtuelle pure pour permettre l'appel de ajouterSousTache() sur une Tache
        *
        */
    void ajouterSousTache(Tache* ){}


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

