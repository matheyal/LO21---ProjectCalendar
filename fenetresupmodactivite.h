#ifndef FENETRESUPMODACTIVITE
#define FENETRESUPMODACTIVITE

#include<QtWidgets>
#include"mainwindow.h"

class FenetreSupModActivite : public QMainWindow
{
    Q_OBJECT
public:
    FenetreSupModActivite(QMainWindow *parent=0);

private slots:
    void modifier();
    void checkDate(const QDateTime &d);
    void supprimer();
    void load();

private:
    QComboBox *idActivite;
    QLineEdit *titreActivite;

    QTextEdit* descriptionActivite;

    QDateTimeEdit *dispoActivite;
    QDateTimeEdit *echeanceActivite;

    QTimeEdit *dureeActivite;
    QLineEdit *lieuActivite;
    QLineEdit *personne;
    QLineEdit *participant;
    QLineEdit *ajoutParticipant;
    QLineEdit *supprimerParticipant;

    QPushButton *supp;
    QPushButton* ann;
    QPushButton* mod;

    QGroupBox *groupeActivite;

    QHBoxLayout *horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouvelleActivite;
    QHBoxLayout *layout;

    QWidget *fenetreActivite;
};


#endif // FENETRESUPMODACTIVITE

