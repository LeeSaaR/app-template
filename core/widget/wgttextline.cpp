#include "wgttextline.h"

#include <QHBoxLayout>
#include "propwgt.h"

WgtTextLine::WgtTextLine(QWidget *parent)
    : QWidget{parent}
{
    // WIDGET
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setContentsMargins(0,0,0,0);
    PropWgt::setHeight(this, 30);

    // LAYOUT
    QHBoxLayout *layout = new QHBoxLayout();
    setLayout(layout);
    layout->setContentsMargins(0,0,0,0);

    // LABEL
    label = new QLabel(this);
    PropWgt::setWidth(label, 150);
    layout->addWidget(label);

    // LINE EDIT
    line = new QLineEdit(this);
    line->setAccessibleDescription("text_line");
    layout->addWidget(line);
}

QString WgtTextLine::text()
{
    return line->text();
}

void WgtTextLine::setName(const QString &text)
{
    label->setText(text);
}

void WgtTextLine::setText(const QString &text)
{
    line->setText(text);
}
