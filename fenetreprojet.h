#ifndef FENETREPROJET_H
#define FENETREPROJET_H

#include<QtWidgets>
#include"mainwindow.h"
#include "projetmanager.h"

class FenetreProjet : public QMainWindow
{
    Q_OBJECT

public:
    FenetreProjet(QMainWindow *parent=0);

private slots:
    void saveProjet();
    void cancel();
    void checkDate(const QDateTime &d);
    void checkModifier();

private:
    QLineEdit *idProjet;
    QLineEdit *titreProjet;

    QTextEdit* descriptionProjet;

    QDateTimeEdit *dispoProjet;
    QDateTimeEdit *echeanceProjet;

    QPushButton *enregistrerProjet;
    QPushButton* annuler;

    QGroupBox* groupeNouveauProjet;

    QHBoxLayout*horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouveauProjet;
    QHBoxLayout* layout;

    QWidget *fenetreProjet;
};

#endif // FENETREPROJET_H

