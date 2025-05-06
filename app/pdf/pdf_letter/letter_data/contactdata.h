#ifndef CONTACTDATA_H
#define CONTACTDATA_H

#include <QString>

class ContactData
{
private:
    QString m_gender;
    QString m_title;
    QString m_name;
    QString m_email;
    QString m_telephone;
    QString m_mobile;

public:
    ContactData(){}
    ~ContactData(){}

    void gender(const QString &gender){m_gender = gender;}
    void title(const QString &title){m_title = title;}
    void name(const QString &new_gender, const QString &new_title, const QString &new_name)
    {gender(new_gender); title(new_title); name(new_name);}
    void name(const QString &new_name) {m_name = new_name;};
    void email(const QString &email){m_email = email;}
    void telephone(const QString &phone_number){m_telephone = phone_number;}
    void mobile(const QString &mobile){m_mobile = mobile;}

    QString gender()const{ return m_gender;}
    QString title()const{ return m_title;}
    QString name()const{ return m_name;}
    QString email()const{ return m_email;}
    QString telephone()const{ return m_telephone;}
    QString mobile()const{ return m_mobile;}

    bool hasGender() const {return !m_gender.isEmpty();}
    bool hasTitle() const {return !m_title.isEmpty();}
    bool hasName() const {return !m_name.isEmpty();}
    bool hasEmail() const {return !m_email.isEmpty();}
    bool hasTelephone() const {return !m_telephone.isEmpty();}
    bool hasMobile() const {return !m_mobile.isEmpty();}

    void setData(
        const QString &new_gender,
        const QString &new_title,
        const QString &new_name,
        const QString &new_email,
        const QString &phone_number,
        const QString &mobile_number)
    {
        name(new_gender, new_title, new_name);
        email(new_email);
        telephone(phone_number);
        mobile(mobile_number);
    }

    bool hasContact()
    {
        bool has_name = hasName();
        bool has_data = hasEmail() || hasTelephone() || hasMobile();
        return has_name && has_data;
    }
};

#endif // CONTACTDATA_H
