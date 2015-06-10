#ifndef FENETRECOMPOSITE_H
#define FENETRECOMPOSITE_H

#include<QtWidgets>

class FenetreComposite : public QMainWindow
{
    Q_OBJECT
public :
    FenetreComposite(QWidget* parent=0);

private slots:
    void enregistrerTacheComposite();
    void checkDate(const QDate& d);

private:
    QWidget *tacheComposite;

    QLineEdit* titreComposite;
    QLineEdit *projetComposite;
    QLineEdit* idComposite;

    QDateEdit *dispoComposite;
    QDateEdit *echeanceComposite;

    QPushButton *enregistrerComposite;
    QPushButton* quitterComposite;

    QGroupBox* groupeComposite;

    QFormLayout *layoutTitreProjetDispoEcheanceDuree;
    QHBoxLayout* layoutEnregistrerQuitter;
    QVBoxLayout* layoutComposite;
    QVBoxLayout *layout;
};


#endif // FENETRECOMPOSITE_H

