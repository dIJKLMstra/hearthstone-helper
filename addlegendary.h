#ifndef ADDLEGENDARY_H
#define ADDLEGENDARY_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QInputDialog>
class AddLegendary : public QDialog
{
      Q_OBJECT

public:
    AddLegendary();
    ~AddLegendary();
private slots:
    void choose_sort();
    void input_name();
    void newORnot();
    void From_What();
    void save();
private:
    int legendaryCnt;
    QPushButton *chooseSort;
    QPushButton *inputName;
    QPushButton *new_or_not;
    QPushButton *from_what;
    QPushButton *OK;
    QGridLayout *mainLayout;
};

#endif // ADDLEGENDARY_H
