#ifndef DIALOGPREFERENCES_H
#define DIALOGPREFERENCES_H

#include <QCloseEvent>
#include <QDialog>

#include "propitemscontroller.h"
#include "appstates.h"

namespace Ui {
class DialogPreferences;
}

class DialogPreferences : public QDialog
{
    Q_OBJECT
private:
    Ui::DialogPreferences *ui;
    PropItemsController *itemCrtl;
    AppState exit_state = AppState::Cancel;

public:
    explicit DialogPreferences(QWidget *parent = nullptr);
    ~DialogPreferences();

public:
    AppState state() const;

private:
    // Initialize
    void initDialog();
    void initUI();
    void initConnections();
    void initItemController();

protected:
    virtual void initUiText();

private:
    // Ui Methods
    void addItemToUserInterface(QWidget* item);

private:
    // private: Methods
    void loadConfigDataItems();
    void load();
    void save();

private slots:
    // slots
    void onClickedSave();

protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // DIALOGPREFERENCES_H
