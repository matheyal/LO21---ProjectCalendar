#ifndef CALENDAR_h
#define CALENDAR_h

/*!
 * \file calendar.h
 * \brief Fichier gerant les exceptions liées au calendrier ainsi que la classe Duree
 */

#include "qt.h"

using namespace std;

/*! \class CalendarException
   * \brief classe permettant de gérer les exceptions liées au calendrier
   *
   *  La classe CalendarException est une classe qui renvoie une chaine de caractere
   *  pour informer l'utilisateur d'une éventuelle execption soulevée
   */
class CalendarException{
public:
    /*!
      *  \brief Constructeur
      *
      *  Constructeur de la classe AgendaException
      *
      *  \param message : le message d'erreur à afficher
      */
    CalendarException(const QString& message):info(message){}

    /*!
        *  \brief getInfo
        *
        *  Accesseur en lecture sur le message d'erreur à renvoyer lorsqu'une exception survient.
        *
        */
    QString getInfo() const { return info; }
private:
    QString info;/*!< Message texte renvoyé en cas d'exception reliée à l'Agenda */
};


/*! \class Duree
        \brief Classe permettant de manipuler des durees
        L'utilisation de cette classe n?cessite des dates valides au sens commun du terme.
        D?clenchement d'exception dans le cas contraire

class Duree{
public:
    //! Constructeur ? partir de heure et minute
    ! \param h heure avec h>=0
        \param m minute avec 0<=m<=59

    Duree(unsigned int h, unsigned int m):nb_minutes(h*60+m) {if (m>59) throw CalendarException("erreur: initialisation duree invalide");}
    //! Constructeur ? partir de minute
    ! \param m minute avec m>=0

    Duree(unsigned int m=0):nb_minutes(m) {}
    void setDuree(unsigned int minutes) { nb_minutes=minutes; }
    void setDuree(unsigned int heures, unsigned int minutes) { if (heures==0 && minutes>59) throw CalendarException("erreur: initialisation duree invalide"); nb_minutes=heures*60+minutes; }
    unsigned int getDureeEnMinutes() const { return nb_minutes; } //<!Retourne la duree en minutes
    double getDureeEnHeures() const { return double(nb_minutes)/60; } //<!Retourne la duree en heures
    unsigned int getMinute() const { return nb_minutes%60; }
    unsigned int getHeure() const { return nb_minutes/60; }
    void afficher(QTextStream& f) const; //<!Affiche la duree sous le format hhHmm
private:
    unsigned int nb_minutes;
};

QTextStream& operator<<(QTextStream& f, const Duree & d);
QTextStream& operator>>(QTextStream&, Duree&); //lecture format hhHmm*/


#endif
