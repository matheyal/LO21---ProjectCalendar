#ifndef FENETREUNITAIRE
#define FENETREUNITAIRE

#include "qt.h"

class FenetreUnitaire : public QMainWindow
{
    Q_OBJECT
public :
    FenetreUnitaire(QMainWindow* parent=0);

private slots:
    void enregistrerTacheUnitaire();
    void checkDate(const QDateTime &d);
    void load();

private:
    QWidget *fenetreUnitaire;

    QLineEdit* idUnitaire;
    QLineEdit* titreUnitaire;
    QComboBox* idProjet;
    QComboBox* idComposite;

    QDateTimeEdit *dispoUnitaire;
    QDateTimeEdit *echeanceUnitaire;
    QTimeEdit* dureeUnitaire;
    QCheckBox* preemptive;

    QPushButton *enregistrerUnitaire;
    QPushButton* quitterUnitaire;

    QGroupBox* groupeUnitaire;

    QFormLayout *layoutTitreProjetDispoEcheanceDuree;
    QHBoxLayout* layoutEnregistrerQuitter;
    QVBoxLayout* layoutUnitaire;
    QVBoxLayout *layout;

};


#endif // FENETREUNITAIRE

