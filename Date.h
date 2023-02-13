#ifndef DATE_H_
#define DATH_H_

#include <string>

class Date
{
  private:
   // private member variables w/ default initialization
    int month {1}, day {1}, year {1900};
  public:
    Date() = default;
    Date(int m, int d, int y) : month{m}, day{d}, year{y} {}
    
    std::string static const MONTHS[12];    // public member variable MONTHS[]
    
    void setMonth(int);   // mutator prototypes
    void setDay(int);
    void setYear(int);
    
    int getMonth() const;   // accessor prototypes
    int getDay() const;
    int getYear() const;
    
    std::string print();   // function prototypes
    static bool compare(const Date&, const Date&);
};

#endif