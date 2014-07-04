#ifndef YEARINPUTERDIALOG_H
#define YEARINPUTERDIALOG_H

#include <QDialog>
#include <QPushButton>

#include <QLineEdit>
#include <QLayout>
#include <QMessageBox>
#include <QLabel>

class YearInputerDialog : public QDialog
{
    Q_OBJECT
public:
    YearInputerDialog(QWidget *parent = 0);
    QString getNewYearText();
    
signals:
    
public slots:
    void inputNewYear();

private:
    QPushButton *confirm;
    QLineEdit *lineedit;
    QString year_text;
    
};

#endif // YEARINPUTERDIALOG_H
