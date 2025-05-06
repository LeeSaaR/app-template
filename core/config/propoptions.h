#ifndef PROPOPTIONS_H
#define PROPOPTIONS_H

#include <QString>

class PropOptions
{
private:
    PropOptions(){}

protected:
    static PropOptions* m_instance;

public:
    ~PropOptions();
    PropOptions(PropOptions &other) = delete;
    void operator=(const PropOptions &other) = delete;
    static PropOptions* GetInstance();

public:
    QList<QString> Themes() const;
    QList<QString> MenuPositions() const;
    QList<QString> Languages() const;
};

#endif // PROPOPTIONS_H
