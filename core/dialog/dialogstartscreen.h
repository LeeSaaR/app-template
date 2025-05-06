#ifndef DIALOGSTARTSCREEN_H
#define DIALOGSTARTSCREEN_H

#include "appstates.h"

#include <QDialog>

namespace Ui {
class DialogStartScreen;
}

class DialogStartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStartScreen(QWidget *parent = nullptr);
    ~DialogStartScreen();

private:
    Ui::DialogStartScreen *ui;
    AppState exit_state = AppState::Exit;

private:
    void init();
    void initConnections();
    void initWindow();
    void handleStartAction();
    void blockSignalsAppWindow(const bool &block_signal);

private:
    void enableButtonOpen(bool enable);
public:
    AppState startAction() const;
    AppState state() const;
private slots:
    void onNew();
    void onOpen();
    void onExit();
    void onCancel();
    void onApply();
public slots:
    void onClose(const AppState &exit_state);
};

#endif // DIALOGSTARTSCREEN_H
