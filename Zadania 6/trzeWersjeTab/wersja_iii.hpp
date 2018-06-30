#ifndef WERSJA_III_HPP_INCLUDED
#define WERSJA_III_HPP_INCLUDED

class IntTab_III
{
    private:
        int rozmiar_;
        int* wsk_tab_;

    public:
        explicit IntTab_III(int rozmiar=0);
        IntTab_III(const IntTab_III& a);
        IntTab_III operator=(const IntTab_III& a);

        virtual ~IntTab_III();
        virtual int size() const;
        virtual void swap(IntTab_III& a) noexcept;
        virtual int operator[](int a) const;
//        a może:
//        virtual int& operator[](int a) const;
        virtual int& operator[](int a);
};

void swap(IntTab_III& a, IntTab_III& b);


#endif // WERSJA_III_HPP_INCLUDED
