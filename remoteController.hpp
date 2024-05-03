#ifndef __remoteController__
#define __remoteController__

class remoteController
{
public:
    virtual void OnOff() = 0;
    virtual void soundOff() = 0;
    virtual void changeMode() = 0;
    virtual void Ok() = 0;
    virtual void arrowUp() = 0;
    virtual void arrowDown() = 0;
    virtual void arrowLeft() = 0;
    virtual void arrowRight() = 0;
};

#endif //__remoteController__