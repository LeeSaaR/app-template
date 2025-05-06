#ifndef PROP_H
#define PROP_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>

class Prop
{
private:
    static int height_control;
    static int spacing;
    static int margin;
public:
    static int btn_menu;
    static int btn_ctrl_w;
    static int btn_ctrl_h;
    static QString fontsize_title;
    static QString fontsize_h1;
    static QString fontsize_default;
    static QString fontsize_small;
    static QString fontsize_status;
    static QString back_main;
    static QString back_menubar;
    static QString back_menubar_sel;
    static QString back_menubar_hov;
    static QString color_menubar;
    static QString color_main;
    static QString color_main_dark;
    static QString color_text_status;

private:
    Prop(){};
public:
    static void init();
    static void setSpacing(QWidget *widget);
    static void setSpacing(QWidget *widget, const int& value);
    static void setMargin(QWidget *widget);
    static void setHeightControl(QWidget *widget);
    static void setButtonSquare(QWidget *widget);
    static void setButtonDoubleSquare(QWidget *widget);
    static void setButtonNormal(QPushButton *btn, const QString& tool_tip, const QString& icon = "");
    static void setButtonWide(QPushButton *btn, const QString& tool_tip, const QString& icon = "");
    static void setButtonBig(QPushButton *btn, const QString& tool_tip, const QString& icon = "");
    static void setButton(QPushButton *btn, const QString& tool_tip, const QString& icon = "");
    static void setIconSize(QPushButton *btn);
    static void setWidth(const int& width, QWidget *widget);
    static void setHeight(const int& width, QWidget *widget);
    static void removeMargin(QFrame *frame);
    static void setLabelTitle(QWidget *widget);
};

#endif // PROP_H
