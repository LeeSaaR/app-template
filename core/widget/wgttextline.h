#ifndef WGTTEXTLINE_H
#define WGTTEXTLINE_H

#include <QLabel>
#include <QLineEdit>
#include <QWidget>

class WgtTextLine : public QWidget
{
    Q_OBJECT
private:
    QLabel* label;
    QLineEdit* line;

public:
    explicit WgtTextLine(QWidget *parent = nullptr);

signals:

public:
    QString text();

public:
    void setName(const QString& text);
    void setText(const QString& text);

};

#endif // WGTTEXTLINE_H
