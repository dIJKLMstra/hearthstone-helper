#ifndef LEGENDARYCARDLIST_H
#define LEGENDARYCARDLIST_H
#include <QDialog>
#include <QLabel>
#include <QGridLayout>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
class LegendaryCardList : public QDialog
{
      Q_OBJECT

public:
    LegendaryCardList();
    ~LegendaryCardList();
private:
    int LegendaryCnt;
    QString LSort;
    QString LName;
    QString LNON;
    QString LFrom;
    QString LDate;
};

#endif // LEGENDARYCARDLIST_H
