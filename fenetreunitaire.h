#ifndef FENETREUNITAIRE
#define FENETREUNITAIRE

#include<QtWidgets>

class FenetreUnitaire : public QMainWindow
{
    Q_OBJECT
public :
    FenetreUnitaire(QMainWindow* parent=0);

private slots:
    void enregistrerTacheUnitaire();
    void checkDate(const QDate& d);

private:
    QWidget *fenetreUnitaire;

    QLineEdit* idUnitaire;
    QLineEdit* titreUnitaire;
    QLineEdit *projetUnitaire;

    QDateEdit *dispoUnitaire;
    QDateEdit *echeanceUnitaire;
    QSpinBox* dureeUnitaire;
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

