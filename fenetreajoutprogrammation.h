#ifndef FENETREAJOUTPROGRAMMATION
#define FENETREAJOUTPROGRAMMATION

#include "qt.h"
#include "agenda.h"
#include "projetmanager.h"
#include "projet.h"
#include"activitemanager.h"
#include "activite.h"

class FenetreAjoutProgTache : public QMainWindow{
    Q_OBJECT
public:
    FenetreAjoutProgTache(QMainWindow* parent=0);
private:
    QWidget *fenetreAjoutProgTache;

    QComboBox* idProjet;
    QComboBox* idTache;
    QLineEdit* titreTache;

    QDateTimeEdit *dateHeureTache;

    QPushButton *enregistrerProgTache;
    QPushButton* quitterProgTache;

    QFormLayout *layoutChoixProjetTache;
    QHBoxLayout* layoutEnregistrerQuitter;
    QVBoxLayout* Vlayout;

public slots:
    void updateIdTache(QString s);
    void updateTitreTache(QString s);
    void saveProg();
};

class FenetreAjoutProgActivite : public QMainWindow{
    Q_OBJECT
public:
    FenetreAjoutProgActivite(QMainWindow* parent=0);
private:
    QWidget *fenetreAjoutProgActivite;

    QComboBox* idActivite;
    QLineEdit* titreActivite;

    QDateTimeEdit *dateHeureActivite;

    QPushButton *enregistrerProgActivite;
    QPushButton* quitterProgActivite;

    QFormLayout *layoutChoixActivite;
    QHBoxLayout* layoutEnregistrerQuitter;
    QVBoxLayout* Vlayout;

public slots:
    void updateTitreActivite(QString s);
    void saveActivite();
};

#endif // FENETREAJOUTPROGRAMMATION

