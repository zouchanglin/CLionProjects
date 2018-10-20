#include <iostream>

class Date{
  public:
    Date(int year = 1900, int month = 1, int day = 1){
      //runnain 
      if(year >= 0 && month <= 12 && month > 0 && (day > 0) && (day <= 30){
          this->_month = month;
          this->_year = year;
          this->_day = day;
        }else{
          perror("Date()...");
        }
    }
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);

    Date operator+(int day);
    Date& operator+=(int day);
    Date 
  private:
    int _year;
    int _month;
    int _day;
};
