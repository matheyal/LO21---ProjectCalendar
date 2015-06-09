#ifndef PROGRAMMATION
#define PROGRAMMATION

/*!
 * \file programmation.h
 * \brief Fichier gerant l'ensemble des programmations des évenements
 */

#include "timing.h"
#include "evenement.h"

using namespace TIME;

/*! \class Programmation
   * \brief classe gérant la programmation des évenements
   *
   *  Les évenements sont soit des taches soit des activités
   */
class Programmation {
private:
<<<<<<< HEAD
    Date date;/*!< Date de la programmation*/
    Horaire heure;/*!< Horaire de la programmation */
    const Evenement* event;/*!< Pointeur constant sur l'évenement à programmer */

    /*!
         *  \brief Constructeur
         *
         *  Constructeur privé de la classe Programmation
         *
         *  \param d : Date de la programmation
         *  \param h : Horaire de la programmation
         *  \param e : Evenement à programmer
         */
    Programmation(const Date& d, const Horaire& h, const Evenement& e):date(d),heure(h),event(&e){}

    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Programmation
         */
=======
    Date date;
    Horaire heure;
    Evenement* event;
    Programmation(const Date& d, const Horaire& h, Evenement* e):date(d),heure(h),event(e){}
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
    ~Programmation();

    friend class Agenda; /*!< Classe Agenda amie de Programmation : seul Agenda pourra construire des programmations*/
public:
    /*!
         *  \brief getDate
         *
         *  Accesseur en lecture sur la date de la programmation
         */
    Date getDate() const {return date;}

    /*!
         *  \brief getHoraire
         *
         *  Accesseur en lecture sur l'horaire de la programmation
         */
    Horaire getHoraire() const {return heure;}
<<<<<<< HEAD

    /*!
         *  \brief getEvenement
         *
         *  Accesseur en lecture sur l'évenement à programmer
         */
    const Evenement& getEvenement() const {return *event;}

=======
    Evenement* getEvenement() const {return event;}
    void afficher(std::ostream& f) const;
>>>>>>> 2437e5e898810d94ad7b99fb0b5888bb8c0eadc6
};

#endif // PROGRAMMATION

