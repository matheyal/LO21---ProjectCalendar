#ifndef FENETREPROJET_H
#define FENETREPROJET_H

#include<QtWidgets>
#include"mainwindow.h"

class FenetreProjet : public QMainWindow
{
public:
    FenetreProjet(QWidget *parent=0);

private slots:
    void saveProjet();

private:
    QLineEdit *titreProjet;

    QTextEdit* descriptionProjet;

    QDateTime* dateActuelle;
    QDateTimeEdit *dispoProjet;
    QDateTimeEdit *echeanceProjet;

    QPushButton *enregistrerProjet;
    QPushButton* quitter;

    QGroupBox* groupeNouveauProjet;

    QHBoxLayout*horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouveauProjet;
    QHBoxLayout* layout;

    QWidget *fenetreProjet;
};

#endif // FENETREPROJET_H

