#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

#include <iostream>
class Timestamp
{
private:
    int64_t microSecondsSinceEpoch_;

public:
    Timestamp();
    Timestamp(int microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString() const;

    ~Timestamp();
};





#endif