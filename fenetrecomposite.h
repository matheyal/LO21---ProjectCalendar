#ifndef FENETRECOMPOSITE_H
#define FENETRECOMPOSITE_H

#include<QtWidgets>

class FenetreComposite : public QMainWindow
{
    Q_OBJECT
public :
    FenetreComposite(QMainWindow *parent=0);

private slots:
    void enregistrerTacheComposite();
    void checkDate(const QDateTime &d);
    void load();
    void checkModifier();

private:
    QWidget *tacheComposite;

    QLineEdit* titreComposite;
    QComboBox* idProjet;
    QComboBox* idSousCompo;
    QLineEdit* idComposite;

    QDateTimeEdit *dispoComposite;
    QDateTimeEdit *echeanceComposite;

    QPushButton *enregistrerComposite;
    QPushButton* quitterComposite;

    QGroupBox* groupeComposite;

    QFormLayout *layoutTitreProjetDispoEcheanceDuree;
    QHBoxLayout* layoutEnregistrerQuitter;
    QVBoxLayout* layoutComposite;
    QVBoxLayout *layout;
};


#endif // FENETRECOMPOSITE_H

