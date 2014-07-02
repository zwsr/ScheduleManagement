#include "DayButton.h"

DayButton::DayButton(QWidget *parent, int y, int m, int d)
    :QPushButton(parent),year(y),month(m),day(d)
{
    QString content;
    content.setNum(day);
    setText(content);
    setFlat(true);
    setFixedSize(day_button_size,day_button_size);
}
