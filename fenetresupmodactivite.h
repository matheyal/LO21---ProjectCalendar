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
    void checkDate(const QDate& d);
    void supprimer();
    void load();

private:
    QComboBox *idActivite;
    QLineEdit *titreActivite;

    QTextEdit* descriptionActivite;

    QDateEdit *dispoActivite;
    QDateEdit *echeanceActivite;

    QSpinBox *dureeActivite;
    QLineEdit *lieuActivite;

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

