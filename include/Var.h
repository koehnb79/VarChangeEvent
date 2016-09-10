#ifndef VAR_H
#define VAR_H

#include <iostream>
#include <string>

#define Int Var<int>
#define String Var<string>

template <class T>
class Var
{
    public:
        Var(T defaultvalue) {
            mValue=defaultvalue;
        }
        virtual ~Var() {
        }
        T operator=(T newvalue)
        {
            if (mDelegate)
                mDelegate(true, mValue, newvalue);

            mValue=newvalue;

            return newvalue;
        }
        void setDelegate(void(*callback)(bool changed, T oldvalue, T value)) {
            mDelegate=callback;
        }
        void setValue(int newvalue) {
            mValue=newvalue;
        }
        T getValue() {
            return mValue;
        }
        friend std::ostream& operator<< (std::ostream &out, const Var<T>&value) {
            out << value.mValue;

            return out;
        }

    protected:

    private:
        T mValue;
        void (*mDelegate)(bool changed, T oldvalue, T value);
};

#endif // VAR_H
