#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QDialog>

namespace Ui {
class DialogAbout;
}

class DialogAbout : public QDialog
{
    Q_OBJECT
private:
    Ui::DialogAbout *ui;

public:
    explicit DialogAbout(QWidget *parent = nullptr);
    ~DialogAbout();

private:
    void initDialog();

private:
    void setData();

};

#endif // DIALOGABOUT_H
