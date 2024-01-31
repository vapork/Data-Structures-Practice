#include<iostream>
#include <ctime>

using namespace std;

class JulianDate {
private:
    static int EPOCH;
    double mm,dd,yy,h,min,s;
    //	int mon, day, year, hour, min, second;
    // this representation would make difference VERY UGLY
    // diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
    double jd; // number of days since epoch
public:
    JulianDate::JulianDate(double y=0,double m=0,double d=0,double a=0,double b=0,double c=0):yy(y),mm(m),dd(d),h(a),min(b),s(c){
        if( y==0 && m==0 && d==0)
        {
            time_t now = time(0);
            tm *ltm = localtime(&now);

            // print various components of tm structure.
            yy = 1900 + ltm->tm_year;
            mm = 1 + ltm->tm_mon;
            dd = ltm->tm_mday;
            h = ltm->tm_hour;
            min = 1 + ltm->tm_min;
            s = 1 + ltm->tm_sec;
        }
        jd=0;
        calc();
    }
    double getYear()
    {return yy;}
    double getMonth()
    {return mm;}
    double getDay()
    {return dd;}
    double getHour()
    {return h;}
    double getMin()
    {return min;}
    double getSec()
    {return s;}
    void calc()
    {
        for(int i=EPOCH;i<yy;i++)
            jd=jd+365+leap(i);
        for(int i=1;i<mm;i++) {
            jd = jd + dim(i, yy);
        }
        double t=(h*3600+min*60+s)/86400;
        jd=jd+dd+t;
    }
    double dim(double month, double year){

        double days = 0;

        if (month == 2) {
            days = 28 + leap(year);  // function leap returns 1 for leap years
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            days = 30;
        }
        else {
            days = 31;
        }

        return days;
    }

    double leap(double yr)
    {
        int year=int(yr);
        if (year % 400 == 0)
            return 1;
        else if (year % 100 != 0 && year % 4 == 0)
            return 1;
        else
            return 0;
    }
    friend double operator - (JulianDate i, JulianDate j) {
        double days= i.jd-j.jd;
        return days;
    }
    friend JulianDate operator + (JulianDate i, double j) {
        i.jd+=j;
        double md=i.dim(i.mm,i.yy);
        if((i.dd+j)>md)
        {
            while((i.dd+j)>md)
            {
                j=j-md;
                if(i.mm<12)
                    ++i.mm;
                else
                {
                    i.mm=1;
                    ++i.yy;
                }
                md=i.dim(i.mm,i.yy);
            }
            i.dd+=j;
        }
        else
            i.dd+=j;
        return i;
    }

    friend ostream& operator <<(ostream& s, const JulianDate& V) {
        return s << V.yy<< "/" << V.mm << "/" << V.dd<< " (" << V.h<< " :" << V.min << " :" << V.s << ") jd: "<<V.jd<<" \n";
    }
};

/*
	how many days in a year? 365
	leap year: if year MOD 4 == 0 LEAP EXCEPT
	           if year MOD 100 == 0 NOT LEAP YEAR Except
						 if year MOD 400 == 0 LEAP
Leap years:
 NO 1900
 YES 1904
 YES 1908
 YES 2000
 NO 2100
 YES 2400
    days since EPOCH = 365 * (year - 2000) + years/4 - ....
2018 - 2000 = 18
seconds in a day = 24*60*60 = 86400
hh:mm:ss
00:00:00  0.0
12:00:00  0.5
http://aa.usno.navy.mil/faq/docs/JD_Formula.php
http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf
 */



int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
    JulianDate newyear(2018, 1, 1, 0,0,0);
    JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5
    JulianDate today; // get it from the system time: time(nullptr)
    // localtime

    double days = valentine - newyear;   // not dispalying dates because it was said no changes to main
    JulianDate due = today + 7;
    cout << due << '\n';

    cout << "\nyear: " << newyear.getYear()
         << "\nmonth: " << newyear.getMonth()
         << "\nday: " << newyear.getDay()
         << "\nhour: " << newyear.getHour()
         << "\nmin: " << newyear.getMin()
         << "\nsec: " << newyear.getSec() << '\n';
    JulianDate d1(2019, 1, 1, 0,0,0);
    for (int i = 0; i < 100; i++)
        cout << d1 + i;

}