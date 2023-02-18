#ifndef NONCOPYABLE_H_
#define NONCOPYABLE_H_

//基类，派生类对象不能进行拷贝构造和赋值操作
class noncopyable
{
public:
    noncopyable(noncopyable &) = delete;
    noncopyable &operator=(noncopyable &) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

#endif