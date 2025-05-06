#ifndef LETTEROPTIONS_H
#define LETTEROPTIONS_H

class LetterOptions
{
private:
    bool m_abbreviation   = false;
    bool m_background     = true;
    bool m_bank_data      = false;
    bool m_contact        = true;
    bool m_custom_date    = false;
    bool m_email          = true;
    bool m_footer         = true;
    bool m_horizontal     = true;
    bool m_logo           = true;
    bool m_mobile         = true;
    bool m_telephone      = true;
    bool m_vat            = true;
    bool m_website        = true;

public:
    LetterOptions(){}
    ~LetterOptions(){}

    bool useAbbreviation() const {return m_abbreviation;}
    bool useBackground() const {return m_background;}
    bool useBank() const {return m_bank_data;}
    bool useContact() const {return m_contact;}
    bool useDate() const {return m_custom_date;}
    bool useEmail() const {return m_email;}
    bool useFooter() const {return m_footer;}
    bool useHorizontal() const {return m_horizontal;}
    bool useLogo() const {return m_logo;}
    bool useMobile() const {return m_mobile;}
    bool useTelephone() const {return m_telephone;}
    bool useVAT() const {return m_vat;}
    bool useWebsite() const {return m_website;}

    void useAbbreviation(const bool &useIt){m_abbreviation = useIt;}
    void useBackground(const bool &useIt){m_background = useIt;}
    void useBank(const bool &useIt){m_bank_data = useIt;}
    void useContact(const bool &useIt){m_contact = useIt;}
    void useDate(const bool &useIt){m_custom_date = useIt;}
    void useEmail(const bool &useIt){m_email = useIt;}
    void useFooter(const bool &useIt){m_footer = useIt;}
    void useHorizontal(const bool &useIt){m_horizontal = useIt;}
    void useLogo(const bool &useIt){m_logo = useIt;}
    void useMobile(const bool &useIt){m_mobile = useIt;}
    void useTelephone(const bool &useIt){m_telephone = useIt;}
    void useVAT(const bool &useIt){m_vat = useIt;}
    void useWebsite(const bool &useIt){m_website = useIt;}
};

#endif // LETTEROPTIONS_H
