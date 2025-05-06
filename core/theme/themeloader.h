#ifndef THEMELOADER_H
#define THEMELOADER_H

#include <QString>

class ThemeLoader
{
private:
    bool m_is_dark_theme;

private:
    ThemeLoader(){}

protected:
    static ThemeLoader* m_instance;

public:
    ~ThemeLoader(){};
    ThemeLoader(ThemeLoader &other) = delete; // copy
    void operator=(const ThemeLoader &other) = delete; // assign
    static ThemeLoader *GetInstance();

public:
    QString styleSheet();
    const bool isDarkTheme() &;
    void setDarkTheme(const QString &styleSheet);
    const QString setVariables(QString styleSheet);
};

#endif // THEMELOADER_H
