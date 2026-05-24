#pragma once

template <typename T>
class Observer {
public:
    virtual void onAdaugare(const T& elem) = 0;
    virtual ~Observer() = default;
};