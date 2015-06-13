#ifndef FENETRESUPMODPROGRAMMATION
#define FENETRESUPMODPROGRAMMATION

#include "qt.h"
#include "agenda.h"

class FenetreSupModProg : public QMainWindow{
    Q_OBJECT
public:
    FenetreSupModProg(QMainWindow* parent = 0);
private:
    QWidget *fenetreSupModProg;
    QGroupBox* groupeSupModProg;

    QComboBox* idEvenement;
    QLineEdit* titreEvenement;

    QDateTimeEdit* dispoEvenement;
    QDateTimeEdit* echeanceEvenement;
    QDateTimeEdit* dateHeureProg;

    QPushButton *modifierProg;
    QPushButton* supprimerProg;
    QPushButton* reinitProg;

    QFormLayout* layoutForm;
    QHBoxLayout* layoutButtons;
    QVBoxLayout* layout;
    QVBoxLayout* Vlayout1;

    vector<QString> listeTitresEvenements;
    vector<Evenement*> listeEvenements;
    vector<QDateTime> listeDisposEvenements;
    vector<QDateTime> listeEcheancesEvenements;
    vector<QDateTime> listeProgsEvenements;

public slots:
    void updateInfosEvenement();
    void supprimerProgrammation();
    void modifierProgrammtion();
};

#endif // FENETRESUPMODPROGRAMMATION

