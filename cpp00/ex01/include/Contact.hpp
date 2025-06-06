#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
    public:
            Contact(void);
            ~Contact(void);

            //getter et setter

            bool setInfo(const std::string& Info, std::string type);
            std::string getInfo(std::string Info) const;
            //tester le setter et le getter generale
            
    private:
            std::string first_name;
            std::string  last_name;
            std::string nick_name;
            std::string phone_number;
            std::string darkest_secret;
            
};

#endif 