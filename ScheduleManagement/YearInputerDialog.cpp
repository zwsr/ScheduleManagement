#include "YearInputerDialog.h"

YearInputerDialog::YearInputerDialog(QWidget *parent) :
    QDialog(parent)
{
    QLabel *buttonLabel = new QLabel(QObject::tr("请输入想要跳转到的年份:"));
    lineedit = new QLineEdit;
    confirm = new QPushButton(QObject::tr("确认"));
    year_text = "Invalid";

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(buttonLabel);
    layout->addWidget(lineedit);
    layout->addWidget(confirm);

    setLayout(layout);
    setWindowTitle(QObject::tr("年份跳转"));
    connect(confirm,SIGNAL(clicked()),this,SLOT(inputNewYear()));
    connect(confirm,SIGNAL(clicked()),this,SLOT(accept()));

}

void YearInputerDialog::inputNewYear()
{
    QString newyear_text = lineedit->text();

    if (newyear_text.toInt() == 0)
    {
        QMessageBox::information(this,QObject::tr("年份输入错误"),
                                 QObject::tr("请输入规范的年份(四位数数字)"));
        return;
    }
    else
    {
        year_text = newyear_text;
        lineedit->hide();
        hide();
    }
    return;

}

QString YearInputerDialog::getNewYearText()
{
    return year_text;
}
