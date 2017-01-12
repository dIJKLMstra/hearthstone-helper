#include "legendarycardlist.h"
#include <QFile>
#include <QTextStream>

LegendaryCardList::LegendaryCardList()
{
    QFile data("legendaryCnt.txt");
    data.open(QIODevice::ReadOnly);
    QTextStream in(&data);
    in >> LegendaryCnt;
    data.close();

    QFile data2("legendary data.txt");
    data2.open(QIODevice::ReadOnly);
    QTextStream in2(&data2);

    setWindowTitle("Legendary Cards List");
    QTableWidget *tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(100);
    tableWidget->setColumnCount(5);
    tableWidget->resize(550, 200);
    QStringList header;
    header << "Sort" << "Name" << "New Or Not"<<"From What"<<"Date";
    tableWidget->setHorizontalHeaderLabels(header);
    for(int i = 0;i < LegendaryCnt;i++)
    {
        LSort = in2.readLine();
        LName = in2.readLine();
        LNON = in2.readLine();
        LFrom = in2.readLine();
        LDate = in2.readLine();
        tableWidget->setItem(i,0,new QTableWidgetItem(LSort));
        tableWidget->setItem(i,1,new QTableWidgetItem(LName));
        tableWidget->setItem(i,2,new QTableWidgetItem(LNON));
        tableWidget->setItem(i,3,new QTableWidgetItem(LFrom));
        tableWidget->setItem(i,4,new QTableWidgetItem(LDate));
    }
}

LegendaryCardList::~LegendaryCardList()
{

}

