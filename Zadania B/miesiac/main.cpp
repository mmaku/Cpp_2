#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <sstream>


#define Mpair(m) {m, #m}            // pomysl z http://www.cplusplus.com/forum/general/2949/
#define Mpairinv(m) {#m, m}

enum Month {January = 1, February, March, April, May, June, July, August, September, October, November, December};

std::string toProper(std::string in)
{
    std::string out;

    for(unsigned int i = 0; i < in.length(); i++)
    {
        i == 0 ? out += toupper(in[i]) : out += tolower(in[i]);
    }

    return out;
}

struct monthDictionary
{
    std::map<Month, std::string> month2str_;
    std::map<std::string, Month> str2month_;

    monthDictionary()
        :month2str_(std::map<Month, std::string> {Mpair(January), Mpair(February),
        Mpair(March), Mpair(April), Mpair(May),
        Mpair(June), Mpair(July), Mpair(August),
        Mpair(September), Mpair(October),
        Mpair(November), Mpair(December)
    }),
    str2month_(std::map<std::string, Month> {Mpairinv(January), Mpairinv(February),
               Mpairinv(March), Mpairinv(April), Mpairinv(May),
               Mpairinv(June), Mpairinv(July), Mpairinv(August),
               Mpairinv(September), Mpairinv(October),
               Mpairinv(November), Mpairinv(December)
                                            })
    {
    }

    auto proper(std::string in) const -> bool
    {
        auto check = [=](std::pair<Month, std::string> foo)
        {
            return std::get<1>(foo) == toProper(in);
        };
        return (find_if(std::begin(month2str_), std::end(month2str_), check) != std::end(month2str_));
    }
};

monthDictionary monthDict = monthDictionary();


auto operator<<(std::ostream& out, Month M) -> std::ostream&
{
    out << monthDict.month2str_[M];
    return out;
}


auto operator>>(std::istream& in, Month& M) -> std::istream&
{
    std::string month;
    in >> month;
    if (in)
    {
        if (monthDict.proper(month))
        {
            M = monthDict.str2month_[toProper(month)];
        }
        else
        {
            if (in)
                in.setstate(std::ios::failbit);
        }
    }
    return in;
}

template<typename T>
auto ForEachMonth(T funktor) -> void
{
    for (int i = 1; i <= 12; ++i)
    {
//        funktor(Month(i));
        funktor(static_cast<Month>(i));
    }
}

template<typename T>
auto ForEachMonthReverse(T funktor) -> void
{
    for (int i = 12; i >= 1; --i)
    {
//        funktor(Month(i));
        funktor(static_cast<Month>(i));
    }
}

auto testMonth() -> void
{
    Month a = April;
    Month b = January;
    std::cout << a << '\n';
    std::istringstream in0("January");
    in0 >> b;
    if (!std::cin)
    {
        std::cerr << "Error!\n";
    }
    else {
        std::cout << b << '\n';
    }

    std::ostringstream out;
    ForEachMonthReverse([&](Month m)
    {
        out << m << "\n";
    });
    std::istringstream in(out.str());
    std::vector<Month> v;
    std::copy(std::istream_iterator<Month>(in),std::istream_iterator<Month>(),std::back_inserter(v));
    assert(v.size()==12);
    int i=12;
    ForEachMonth([&v,&i](Month m)
    {
        assert(m == v[--i]);
    });
}

int main(void)
{
    testMonth();
    std::cerr << "testMonth ok!\n";
    return 0;
}
