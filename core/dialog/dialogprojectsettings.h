#ifndef DIALOGPROJECTSETTINGS_H
#define DIALOGPROJECTSETTINGS_H

#include <QDialog>

#include "projectdata.h"
#include "appstates.h"

namespace Ui {
class DialogProjectSettings;
}

class DialogProjectSettings : public QDialog
{
    Q_OBJECT
private:
    Ui::DialogProjectSettings *ui;

public:
    explicit DialogProjectSettings(QWidget *parent = nullptr);
    ~DialogProjectSettings();

private:
    void initDialog();
    void initUI();
    void initConnections();

private:


private:
    void load();
    void save();

private slots:
    void onClickedSave();

};

#endif // DIALOGPROJECTSETTINGS_H
