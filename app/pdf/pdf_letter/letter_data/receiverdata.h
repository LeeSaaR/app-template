#ifndef RECEIVERDATA_H
#define RECEIVERDATA_H

#include "commonletterdata.h"
#include "receiveroptions.h"

class ReceiverData : public CommonLetterData
{
private:
    QString m_account;
    QString m_account_name;
    QString m_department;
    QString m_direct;
    QString m_reference;
    QString m_reference_name;

public:
    ReceiverData() : opt(new ReceiverOptions()){}
    ~ReceiverData(){delete opt;}
    ReceiverOptions* opt;

public:

    bool hasAccount() const {return !m_account.isEmpty();}
    bool hasDepartment() const {return !m_department.isEmpty();}
    bool hasDirect() const {return !m_direct.isEmpty();}
    bool hasReference() const {return !m_reference.isEmpty();}

    QString account() const { return m_account; }
    QString accountName() const { return m_account_name; }
    QString department() const { return m_department; }
    QString direct() const { return m_direct; }
    QString reference() const { return m_reference; }
    QString referenceName() const { return m_reference_name; }

    void account(const QString &accountName, const QString &account) { m_account_name = accountName; m_account = account;}
    void department(const QString &newValue) { m_department = newValue; }
    void direct(const QString &newValue) { m_direct = newValue; }
    void reference(const QString &referenceName, const QString &reference) { m_reference_name = referenceName; m_reference = reference;}
};

#endif // RECEIVERDATA_H
