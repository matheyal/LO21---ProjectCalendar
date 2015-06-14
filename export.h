#ifndef EXPORT_H
#define EXPORT_H

/*!
 * \file export.h
 * \brief Fichier gerant l'export de données au format XML
 */

#include "qt.h"

/*! \class ExportStrategy
   * \brief classe permettant ...
   *
   *  Classe abstraite.
   *  Implémentation design pattern Strategy
   */
class ExportStrategy {
public:

    /*!
         *  \brief save
         *
         *  Methode virtuelle pure mise en place pour l'application du design pattern strategy
         *
         *  \param f : ...
         */
    virtual void save(const QString& f) = 0;
};

/*! \class ExportXML
   * \brief classe permettant l'export des evenements programmés dans un fichier XML
   *
   */
class ExportXML : public ExportStrategy {
public:
    /*!
         *  \brief save
         *
         *  Redéfinition de la méthode save pour ...
         *
         *  \param f : ...
         */
    void save(const QString& f);
};

#endif // EXPORT_H
