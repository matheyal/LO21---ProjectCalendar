#ifndef IMPORT_H
#define IMPORT_H


/*!
 * \file import.h
 * \brief Fichier gerant l'import de données à partir d'un fichier au format XML
 */

#include "projetmanager.h"
#include "calendar.h"
#include "qt.h"

/*! \class ImportStrategy
   * \brief classe permettant ...
   *
   *  Classe abstraite.
   *  Utilisation du design pattern Strategy
   */
class ImportStrategy {
public: 
    /*!
         *  \brief load
         *
         *  Methode virtuelle pure mise en place pour l'application du design pattern strategy
         *
         *  \param f : ...
         */
    virtual void load (const QString& f) = 0;
};

/*! \class ImportXML
   * \brief classe permettant l'import des evenements à partir d'un fichier XML
   *
   */
class ImportXML : public ImportStrategy{
public: 
    /*!
         *  \brief load
         *
         *  Redéfinition de la méthode load pour ...
         *
         *  \param f : ...
         */
    void load(const QString &f);
};

#endif // IMPORT_H

