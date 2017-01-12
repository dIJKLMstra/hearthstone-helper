#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H
#include <QLabel>
#include <QGridLayout>
#include <QDialog>
class OutputData : public QDialog
{
    Q_OBJECT
public:
    OutputData(QWidget* parent = 0);
    ~OutputData();
private:
    int common;
    int rare;
    int epic;
    int legendary;
    int Gcommon;
    int Grare;
    int Gepic;
    int Glegendary;
    QLabel *upperWord;
    QLabel *packsCnt;
    QLabel *commonLabel;
    QLabel *rareLabel;
    QLabel *epicLabel;
    QLabel *legendaryLabel;
    QLabel *commonRate;
    QLabel *rareRate;
    QLabel *epicRate;
    QLabel *legendaryRate;
    QLabel *GcommonLabel;
    QLabel *GrareLabel;
    QLabel *GepicLabel;
    QLabel *GlegendaryLabel;
    QLabel *GcommonRate;
    QLabel *GrareRate;
    QLabel *GepicRate;
    QLabel *GlegendaryRate;
    QGridLayout *mainLayout;
};

#endif // OUTPUTDATA_H
