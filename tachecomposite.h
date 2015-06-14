#ifndef TACHECOMPOSITE
#define TACHECOMPOSITE

/*!
 * \file tachecomposite.h
 * \brief Fichier gerant les taches composites d'un projet et leurs exceptions
 */

#include "timing.h"
#include "tache.h"
#include "tacheunitaire.h"
#include "tachepreemptable.h"
#include <vector>


/*! \class CompositeException
   * \brief classe permettant de gérer les exceptions liées aux taches composites
   *
   *  La classe CompositeException est une classe qui renvoie une chaine de caractere
   *  pour informer l'utilisateur d'une éventuelle execption soulevée
   */
class CompositeException
{
    QString info; /*!< Message texte renvoyé en cas d'exception reliée à une tache composite */

public:

    /*!
      *  \brief Constructeur
      *
      *  Constructeur de la classe CompositeException
      *
      *  \param s : le message d'erreur à afficher
      */
    CompositeException(const QString& s):info(s) {}

    /*!
        *  \brief getInfo
        *
        *  Accesseur en lecture sur le message d'erreur à renvoyer lorsqu'une exception survient.
        *
        */
    QString& getInfo() { return info; }

};

/*! \class TacheComposite
   * \brief classe representant une tache composées d'autres taches
   *
   *  La classe TacheComposite spécialise la classe Tache
   *
   */
class TacheComposite : public Tache {
private:
    vector<Tache*> soustaches; /*!< Tableau de taches représentant les sous taches d'une tache composite */

public:

    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe TacheComposite
         *
         * \param ident : identifiant de la tache composite
         * \param t : titre de la tache composite
         * \param d : date de disponibilite de la tache composite
         * \param ech : date d'écheance de la tache composite
         *
         */
    TacheComposite(const QString& ident, const QString& t, const QDateTime& d,const QDateTime& ech, bool b=false):Tache(ident,t,d,ech,b), soustaches(0){std::cout<<"\ncreation d'une tache composite\n";}

    /*!
         *  \brief ajouterTacheUnitaire
         *
         *  Ajoute une tache unitaire comme sous tache de la tache composite en question
         *
         * \param ident : identifiant de la tache unitaire à ajouter
         * \param t : titre de la tache unitaire à ajouter
         * \param d : date de disponibilite de la tache unitaire à ajouter
         * \param ech : date d'écheance de la tache unitaire à ajouter
         *
         */
    //TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur);

    /*!
         *  \brief ajouterTachePreemptable
         *
         *  Ajoute une tache préemptable comme sous tache de la tache composite en question
         *
         * \param ident : identifiant de la tache préemptable à ajouter
         * \param t : titre de la tache préemptable à ajouter
         * \param d : date de disponibilite de la tache préemptable à ajouter
         * \param ech : date d'écheance de la tache préemptable à ajouter
         * \param dur : duree de la tache préemptable à ajouter
         *
         */
    //TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur);

    /*!
         *  \brief ajouterTacheComposite
         *
         *  Ajoute une tache composite comme sous tache de la tache composite en question
         *
         * \param ident : identifiant de la tache composite à ajouter
         * \param t : titre de la tache composite à ajouter
         * \param d : date de disponibilite de la tache composite à ajouter
         * \param ech : date d'écheance de la tache composite à ajouter
         *
         */
    //TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline);

    /*!
         *  \brief ajouterSousTache
         *
         *  Permet d'ajouter une sous tache au tableau des sous taches d'une tache composite
         *
         * \param t : pointeur sur la tache à ajouter
         *
         */
    void ajouterSousTache(Tache * t){soustaches.push_back(t);}

    /*!
         *  \brief supprimerSousTache
         *
         *  Supprime une sous tache du tableau des sous taches d'une tache composite
         *
         * \param ident : identifiant de la tache à supprimer
         *
         */
    void supprimerSousTache(const QString& ident);

    /*!
         *  \brief afficherSousTaches
         *
         *  Affiche le tableau des sous taches d'une tache composite
         *
         *
         */

    void afficherSousTaches() const ;

    /*!
         *  \brief afficher
         *
         *  Appelle la méthode de Evenement pour afficher une tache composite (n'affiche pas les sous taches)
         *
         * \param f : flux de sortie sur lequel on affiche les informations de la tache composite
         *
         */
    void afficher(std::ostream& f)const {Evenement::afficher(f);}



    /*!
         *  \brief getDuree
         *
         *  Methode qui ne fait rien mais qui permet de rendre la classe tachecomposite concrète
         *
         *
         */
    const Duree getDuree() const{return Duree(0,0);}



    /*!
         *  \brief trouverTache
         *
         *  Methode qui permet de trouver une tache parmis les sous taches de la tache en question à partir de son identifiant
         *
         * \param id : identifiant de la tache que l'on souhaite trouver dans le tableau des sous taches
         */
    Tache* trouverTache(const QString& id)const;

    /*!
        *  \brief commencer
        *
        *  Methode pour "commencer" une tache
        *  Appel de la méthode setDebut(d)
        *
        */
    void commencer();

    soustaches_iterator begin_soustaches() const{return soustaches_iterator(soustaches.begin());}
    soustaches_iterator end_soustaches() const {return soustaches_iterator(soustaches.end());}
};

/*!
     *  \brief operator<<
     *
     *  Surcharge de l'opérator << pour permettre d'afficher les caractéristiques d'une tache composite sur le flux de sortie.
     *
     *  \param f : Flux sur lequel on écrit
     *  \param t : Tache composite que l'on souhaite afficher
     *
     */
std::ostream& operator<<(std::ostream& fout, const TacheComposite& t);

#endif // TACHECOMPOSITE



