#ifndef PROJET
#define PROJET


/*!
 * \file projet.h
 * \brief Fichier gerant l'ensemble des projets et donc les taches qui le composent
 */

#include "tacheunitaire.h"
#include "tachecomposite.h"
#include "tachepreemptable.h"
#include "tache.h"
#include "qt.h"
#include "calendar.h"
#include "timing.h"

/*! \class ProjetException
   * \brief classe permettant de gérer les exceptions liées au projet
   *
   *  La classe ProjetException est une classe qui renvoie une chaine de caractere
   *  pour informer l'utilisateur d'une éventuelle execption soulevée
   */
class ProjetException
{
    QString info; /*!< Message texte renvoyé en cas d'exception reliée à un projet */

public:
    /*!
      *  \brief Constructeur
      *
      *  Constructeur de la classe ProjetException
      *
      *  \param s : le message d'erreur à afficher
      */
    ProjetException(const QString& s):info(s) {}

    /*!
        *  \brief getInfo
        *
        *  Accesseur en lecture sur le message d'erreur à renvoyer lorsqu'une exception survient.
        *
        */
    QString& getInfo() { return info; }
};

/*! \class Projet
   * \brief classe representant un Projet
   *
   *  La classe Projet permet de gérer un projet avec l'ensemble des taches le composant
   *
   */
class Projet {
private:
     QString id;/*!< Identifiant du projet */
     QString titre;/*!< Titre du projet */
     QString description;/*!< Description du projet */
     QDate dispo;/*!< Date de disponibilite du projet */
     QDate echeance;/*!< Date d'echeance du projet */
     vector<Tache*> taches;/*!< Tableau de taches reliées au projet */

     /*!
         *  \brief addItem
         *
         *  Methode qui ajoute une tache à la fin du vector des taches concernant le projet
         *
         *  \param t : la tache à ajouter au projet
         */
     void addItem(Tache* t);

     /*!
          *  \brief Constructeur
          *
          *  Constructeur privé de la classe Projet.
          *  Seul le ProjetManager peut gérer les projets.
          *
          * \param i : identifiant du projet
          * \param ti : titre du projet
          * \param desc : description du projet
          * \param d : date de disponibilite du projet
          * \param ech : date d'écheance du projet
          *
          */
     Projet(const QString& i, const QString& ti, const QString& desc, const QDate& d,const QDate& ech):id(i), titre(ti),description(desc),dispo(d),echeance(ech),taches(0){}

     /*!
          *  \brief Destructeur
          *
          *  Destructeur privé de la classe Projet
          */
     ~Projet();

     friend class ProjetManager; /*!< Classe ProjetManager amie de Projet : seul ProjetManager pourra construire des programmations*/

public:
     /*!
          *  \brief ajouterTacheUnitaire
          *
          *  Permet d'ajouter une tache unitaire à la fin du vector des taches concernant le projet
          *  Instancie la tache et fait appel à la méthode addItem
          *
          *
          *   \param id : Identifiant de la tache unitaire à ajouter
          *   \param t : Titre de la tache unitaire à ajouter
          *   \param dispo : Date de disponibilite de la tache unitaire à ajouter
          *   \param deadline : Date d'echeance de la tache unitaire à ajouter
          *   \param dur : Duree de la tache unitaire à ajouter
          *   \param b: Booleen représentant l'état de la tache unitaire à ajouter (par défaut non programmée)
          *
          */
     TacheUnitaire& ajouterTacheUnitaire(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, bool b=false);

     /*!
          *  \brief ajouterTachePreemptable
          *
          *  Permet d'ajouter une tache preemptable à la fin du vector des taches concernant le projet
          *  Instancie la tache et fait appel à la méthode addItem
          *
          *
          *   \param id : Identifiant de la tache preemptable à ajouter
          *   \param t : Titre de la tache preemptable à ajouter
          *   \param dispo : Date de disponibilite de la tache preemptable à ajouter
          *   \param deadline : Date d'echeance de la tache preemptable à ajouter
          *   \param dur : Duree de la tache preemptable à ajouter
          *   \param b: Booleen représentant l'état de la tache unitaire à ajouter (par défaut non programmée)
          *
          */
     TachePreemptable& ajouterTachePreemptable(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, const Duree& dur, bool b=false);

     /*!
          *  \brief ajouterTacheComposite
          *
          *  Permet d'ajouter une tache composite à la fin du vector des taches concernant le projet
          *  Instancie la tache et fait appel à la méthode addItem
          *
          *
          *   \param id : Identifiant de la tache composite à ajouter
          *   \param t : Titre de la tache composite à ajouter
          *   \param dispo : Date de disponibilite de la tache composite à ajouter
          *   \param deadline : Date d'echeance de la tache composite à ajouter
          *   \param b: Booleen représentant l'état de la tache unitaire à ajouter (par défaut non programmée)
          *
          */
      TacheComposite& ajouterTacheComposite(const QString& id, const QString& t, const QDate& dispo, const QDate& deadline, bool b=false);


     /*!
          *  \brief supprimerTache
          *
          *  Permet de supprimer une tache du tableau des taches d'un projet
          *
          *  \param ident : Identifiant de la tache à supprimer
          */

     void supprimerTache(const QString& ident);


     /*!
          *  \brief afficherTaches
          *
          *  Parcours du tableau des taches pour afficher toutes les taches reliées au projet en question
          */
     void afficherTaches() const;

     /*!
          *  \brief getTache
          *
          *  Accesseur en lecture qui retourne la tache correspondant à l'identifiant passé en paramètre
          *
          * \param id : Identifiant de la tache que l'on veut récupérer
          *
          */
     Tache& getTache(const QString& id);

     /*!
          *  \brief trouverTache
          *
          *  Retourne la tache correspondant à l'identifiant passé en paramètre
          *  Retourne une référence sur la tache : permet la modification
          *
          * \param id : Identifiant de la tache que l'on CHERCHE
          *
          */
     Tache* trouverTache(const QString& id)const;

     /*!
          *  \brief getTache
          *
          *  Accesseur en lecture qui retourne la tache correspondant à l'identifiant passé en paramètre
          *  Retourne une référence constante sur la tache : ne permet pas de modification
          *
          * \param id : Identifiant de la tache que l'on veut récupérer
          *
          */
     const Tache& getTache(const QString& id)const;

     /*!
          *  \brief getId
          *
          *  Accesseur en lecture de l'identifiant du projet
          */
     QString getId() const {return id;}

     /*!
          *  \brief getTitre
          *
          *  Accesseur en lecture du titre du projet
          */
     QString getTitre() const{return titre;}

     /*!
          *  \brief getDesc
          *
          *  Accesseur en lecture de la description du projet
          */
     QString getDesc() const {return description;}

     /*!
          *  \brief getDispo
          *
          *  Accesseur en lecture de la date de disponibilite du projet
          */
     QDate getDispo()const {return dispo;}

     /*!
          *  \brief getEcheance
          *
          *  Accesseur en lecture de la date d'échéance du projet
          */
     QDate getEcheance() const {return echeance;}

     /*!
          *  \brief setTitre
          *
          *  Accesseur en écriture du titre du projet
          *
          *  \param nom : nom du titre avec lequel on veut initialiser le titre du projet
          */
     void setTitre(const QString& nom){titre = nom;}

     /*!
          *  \brief setDispo
          *
          *  Accesseur en écriture de la date de disponibilite du projet
          *
          *  \param dateDispo : date avec laquelle on veut initialiser la date de disponibilite du projet
          */
     void setDispo(const QDate& dateDispo){dispo  = dateDispo;}

     /*!
          *  \brief setEcheance
          *
          *  Accesseur en écriture de la date d'écheance du projet
          *
          *  \param ech : date avec laquelle on veut initialiser la date d'echeance du projet
          */
     void setEcheance(const QDate& ech){echeance  = ech;}

     /*!
          *  \brief getTaches
          *
          *  Accesseur en lecture du tableau de taches d'un projet
          *
          */
     const vector<Tache*>* getTaches() const{return &taches;}

};

/*!
     *  \brief operator<<
     *
     *  Surcharge de l'opérator << pour permettre d'afficher les caractéristiques d'un projet sur le flux de sortie.
     *
     *  \param f : Flux sur lequel on écrit
     *  \param p : Projet que l'on souhaite afficher
     *
     */
std::ostream& operator<<(std::ostream& f, const Projet& p);

#endif // PROJET

