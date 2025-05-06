#include "prop.h"

#include <QLayout>
#include <QGuiApplication>
#include <QScreen>

int Prop::height_control = 32;
int Prop::spacing        = 2;
int Prop::margin         = 8;
int Prop::btn_menu       = 40;
int Prop::btn_ctrl_w     = 80;
int Prop::btn_ctrl_h     = 32;
QString Prop::fontsize_title   = "20px";
QString Prop::fontsize_h1      = "18px";
QString Prop::fontsize_default = "16px";
QString Prop::fontsize_small   = "10px";
QString Prop::fontsize_status  = "8px";

QString Prop::back_main         = "#1f1f1f";
QString Prop::back_menubar      = "#252525";
QString Prop::back_menubar_sel  = "#323232";
QString Prop::back_menubar_hov  = "#3c3c3c";
QString Prop::color_menubar     = "#eff4fc";
QString Prop::color_main        = "#556aab";
QString Prop::color_main_dark   = "#454957";
QString Prop::color_text_status = "#aaaaaa";

void Prop::init()
{
    qDebug() << __FUNCTION__;
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    qDebug() << width << height;

    // width = 1366;
    if (width >= 1920)
    {
        qDebug() << "width >= 1920";
        fontsize_title   = "22px";
        fontsize_h1      = "20px";
        fontsize_default = "16px";
        fontsize_small   = "10px";
        fontsize_status  = "12px";
        height_control = (int)round( width * double( 32.0  /1920.0) );
    }
    else if (width < 1920 && width >= 1600)
    {
        qDebug() << "width < 1920 && width >= 1600";
        height_control = (int)round( width * double( 32.0  /1920.0) );
        fontsize_title   = "18px";
        fontsize_h1      = "16px";
        fontsize_default = "12px";
        fontsize_small   = "9px";
        fontsize_status   = "7px";
    }

    else if (width < 1600)
    {
        qDebug() << "width < 1600";
        height_control   = 24;
        fontsize_title   = "16px";
        fontsize_h1      = "14px";
        fontsize_default = "12px";
        fontsize_small   = "8px";
        fontsize_status   = "6px";
    }
}

void Prop::setSpacing(QWidget *widget)
{
    widget->layout()->setSpacing(spacing);
}

void Prop::setSpacing(QWidget *widget, const int &value)
{
    widget->layout()->setSpacing( value );
}

void Prop::setMargin(QWidget *widget)
{
    widget->setContentsMargins(margin, 0, margin, 0);
}

void Prop::setHeightControl(QWidget *widget)
{
    widget->setMinimumHeight(height_control);
    widget->setMaximumHeight(height_control);
}

void Prop::setButtonSquare(QWidget *widget)
{
    widget->setMinimumWidth(height_control);
    widget->setMaximumWidth(height_control);
    widget->setMinimumHeight(height_control);
    widget->setMaximumHeight(height_control);
}

void Prop::setButtonDoubleSquare(QWidget *widget)
{
    widget->setMinimumWidth(height_control*2);
    widget->setMaximumWidth(height_control*2);
    widget->setMinimumHeight(height_control);
    widget->setMaximumHeight(height_control);
}

void Prop::setButtonNormal(QPushButton *btn, const QString &tool_tip, const QString &icon)
{
    setButtonSquare(btn);
    setButton(btn, tool_tip, icon);
}

void Prop::setButtonWide(QPushButton *btn, const QString &tool_tip, const QString &icon)
{
    setButtonDoubleSquare(btn);
    setButton(btn, tool_tip, icon);
}

void Prop::setButtonBig(QPushButton *btn, const QString &tool_tip, const QString &icon)
{
    btn->setMinimumWidth(height_control*4);
    btn->setMaximumWidth(height_control*4);
    btn->setMinimumHeight(height_control);
    btn->setMaximumHeight(height_control);
    btn->setIconSize(QSize(height_control*0.7, height_control*0.7));
    btn->setIcon(QIcon(icon));
    btn->setToolTip(tool_tip);
}

void Prop::setButton(QPushButton *btn, const QString &tool_tip, const QString &icon)
{
    setIconSize(btn);
    if (!icon.isEmpty())
        btn->setIcon(QIcon(icon));
    btn->setToolTip(tool_tip);
    btn->setFocusPolicy( Qt::NoFocus );
}

void Prop::setIconSize(QPushButton *btn)
{
    btn->setIconSize(QSize(height_control*0.7, height_control*0.7));
}

void Prop::setWidth(const int &width, QWidget *widget)
{
    widget->setMinimumWidth(width);
    widget->setMaximumWidth(width);
}

void Prop::setHeight(const int &width, QWidget *widget)
{
    widget->setMinimumHeight(width);
    widget->setMaximumHeight(width);
}

void Prop::setLabelTitle(QWidget *widget)
{
    widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    widget->setMinimumHeight(height_control);
    widget->setMaximumHeight(height_control);
}

void Prop::removeMargin(QFrame *frame)
{
    frame->layout()->setContentsMargins(0,0,0,0);
}




