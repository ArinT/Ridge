#ifndef RIDGE_VIEW_SDL_H
#define RIDGE_VIEW_SDL_H
#include <exception>
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

class SDLWrapper {
    public:
        SDLWrapper(Uint32 flags = 0) throw(InitError);
        virtual ~SDLWrapper();
};
#endif

