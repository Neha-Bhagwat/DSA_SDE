//1185. Given a date, return the corresponding day of the week for that date.

// The input is given as three integers representing the day, month and year respectively.

// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

// Note: January 1, 1971 was a Friday.

 

// Example 1:

// Input: day = 31, month = 8, year = 2019
// Output: "Saturday"
// Example 2:

// Input: day = 18, month = 7, year = 1999
// Output: "Sunday"
// Example 3:

// Input: day = 15, month = 8, year = 1993
// Output: "Sunday"


class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // calculate the number of days
        int noLeap = (year-1972)/4;
        vector<int> daysInMonthMod7 = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
        vector<string> daysOfWeek = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

        // days diff due to year
        int days = noLeap + (year-1971)*365;
        // convert to remainder of 7
        days = days % 7;

        // days diff due to month
        for(int i = 0; i <= month-2; i++)
        {
            days += daysInMonthMod7[i];
        }
        days %= 7;

        //days diff due to day
        days += day%7;

        // for the case of it being leap year and before 1st March
        if(year %4 == 0 && month < 3) days -= 1;
        // since 2100 is not a leap year for some stupid reason, all dates after 1st march are pushed one day back
        if(year == 2100 && month >= 3) days -= 1;

        // find days%7
        days %= 7;

        // add that to Friday
        return daysOfWeek[days];
    }
};
