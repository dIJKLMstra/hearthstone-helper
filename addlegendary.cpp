#include "addlegendary.h"
#include <QFile>
#include <QTextStream>

void AddLegendary::choose_sort()
{
    QStringList sortItems;
    sortItems << tr("Classic") << tr("Old Gods") << tr("The Grand Tournament") << tr("Mean Street of Gadgetzan");
    bool ok;
    QString sortItem = QInputDialog::getItem(this,tr("choose the sort of pack"),tr(""),sortItems,0,false,&ok);
    if(ok)
    {
        QFile data("legendary data.txt");
        data.open(QIODevice::Text|QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&data);
        out << sortItem <<endl;
        data.close();
    }
}

void AddLegendary::input_name()
{
    bool ok;
    QString name = QInputDialog::getText(this,tr("Please input the name of your new legendary card"),tr("The exact name is not necessary"),QLineEdit::Normal,"",&ok);
    if(ok && !name.isEmpty())
    {
        QFile data("legendary data.txt");
        data.open(QIODevice::Text|QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&data);
        out << name <<endl;
        data.close();
    }
}

void AddLegendary::newORnot()
{
    QStringList items;
    items << tr("NEW!") << tr("I'VE HAD IT");
    bool ok;
    QString item = QInputDialog::getItem(this,tr("Is that new ?"),tr(""),items,0,false,&ok);
    if(ok)
    {
        QFile data("legendary data.txt");
        data.open(QIODevice::Text|QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&data);
        out << item <<endl;
        data.close();
    }
}

void AddLegendary::From_What()
{
    QStringList items;
    items << tr("Packs") << tr("Create");
    bool ok;
    QString item = QInputDialog::getItem(this,tr("Where is it come from ?"),tr(""),items,0,false,&ok);
    if(ok)
    {
        QFile data("legendary data.txt");
        data.open(QIODevice::Text|QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&data);
        out << item <<endl;
        data.close();
    }
}

void AddLegendary::save()
{

        QFile data("legendaryCnt.txt");
        data.open(QIODevice::ReadOnly);
        QTextStream in(&data);
        in >> legendaryCnt;
        data.close();
        legendaryCnt++;
        QFile data2("legendaryCnt.txt");
        data2.open(QIODevice::WriteOnly);
        QTextStream out(&data2);
        out << legendaryCnt;
        data2.close();

        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd");
        QFile data3("legendary data.txt");
        data3.open(QIODevice::Text|QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out2(&data3);
        out2 << str  <<endl;
        data3.close();
}

AddLegendary::AddLegendary()
{
    setWindowTitle(tr("New Legendary ?!"));

    QFont font("Consolas",11,60);
    chooseSort = new QPushButton;
    chooseSort -> setFixedSize(QSize(250,40));
    chooseSort -> setFont(font);
    chooseSort -> setText(tr("STEP 1 : Choose the Sort"));
    connect(chooseSort,SIGNAL(clicked()),this,SLOT(choose_sort()));

    inputName = new QPushButton;
    inputName -> setFixedSize(QSize(250,40));
    inputName -> setFont(font);
    inputName -> setText("STEP 2 : Input the Name");
    connect(inputName,SIGNAL(clicked()),this,SLOT(input_name()));

    new_or_not = new QPushButton;
    new_or_not -> setFixedSize(QSize(250,40));
    new_or_not -> setFont(font);
    new_or_not -> setText(tr("STEP 3 : Is that New ?"));
    connect(new_or_not,SIGNAL(clicked()),this,SLOT(newORnot()));

    from_what = new QPushButton;
    from_what -> setFixedSize(QSize(250,40));
    from_what -> setFont(font);
    from_what ->setText(tr("STEP 4 : From Where ?"));
    connect(from_what,SIGNAL(clicked()),this,SLOT(From_What()));

    OK = new QPushButton;
    OK -> setFixedSize(QSize(250,40));
    OK -> setFont(font);
    OK -> setText(tr("FINALLY , OK ~"));
    connect(OK,SIGNAL(clicked()),this,SLOT(save()));

    mainLayout = new QGridLayout(this);
    mainLayout -> setMargin(15);
    mainLayout -> setSpacing(15);
    mainLayout -> addWidget(chooseSort,0,0);
    mainLayout -> addWidget(inputName,1,0);
    mainLayout -> addWidget(new_or_not,2,0);
    mainLayout -> addWidget(from_what,3,0);
    mainLayout -> addWidget(OK,4,0);
}

AddLegendary::~AddLegendary()
{

}

