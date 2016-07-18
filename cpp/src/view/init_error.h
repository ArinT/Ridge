#ifndef RIDGE_VIEW_INIT_ERROR_H
#define RIDGE_VIEW_INIT_ERROR_H
#include <string>

class InitError: public std::exception {
    public:
        InitError();
        InitError(const std::string&);
        virtual ~InitError() throw();
        virtual const char* what() const throw();
    private:
        std::string msg;
};
#endif
