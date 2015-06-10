#ifndef FENETRESUPPRIMERPROJET
#define FENETRESUPPRIMERPROJET

#include<QtWidgets>
#include"mainwindow.h"

class FenetreSupModProjet : public QMainWindow
{
    Q_OBJECT
public:
    FenetreSupModProjet(QWidget *parent=0);

private slots:
    void modifier();
    void cancel();
    void checkDate(const QDate& d);
    void supprimer();
    void load();

private:
    QComboBox *idProjet;
    QLineEdit *titreProjet;

    QTextEdit* descriptionProjet;

    QDateEdit *dispoProjet;
    QDateEdit *echeanceProjet;

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

