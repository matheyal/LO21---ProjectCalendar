#ifndef FENETRESUPPRIMERPROJET
#define FENETRESUPPRIMERPROJET

#include<QtWidgets>
#include"mainwindow.h"

class FenetreSupModProjet : public QMainWindow
{
    Q_OBJECT
public:
    FenetreSupModProjet(QMainWindow *parent=0);

private slots:
    void modifier();
    void checkDate(const QDateTime &d);
    void supprimer();
    void load();

private:
    QComboBox *idProjet;
    QLineEdit *titreProjet;

    QTextEdit* descriptionProjet;

    QDateTimeEdit *dispoProjet;
    QDateTimeEdit *echeanceProjet;

    QPushButton *supp;
    QPushButton* ann;
    QPushButton* mod;

    QGroupBox* groupeNouveauProjet;

    QHBoxLayout*horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouveauProjet;
    QHBoxLayout* layout;

    QWidget *fenetreProjet;
};

#endif // FENETRESUPPRIMERPROJET

