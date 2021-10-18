#ifndef DYNAMIC_H
#define DYNAMIC_H

template <typename T>
class Dynamic{
public:
    virtual ~Dynamic() {};
    virtual T get() const = 0;
};

#endif