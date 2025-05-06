#include "appwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    int exit_code = 0;
    do {
        QApplication a(argc, argv);
        AppWindow w;
        w.show();
        exit_code = a.exec();
    } while (exit_code == AppWindow::AppExitCode::Restart);

    return exit_code;
}
