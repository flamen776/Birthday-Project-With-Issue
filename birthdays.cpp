

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 * 
 * 
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {
    printHeading();
    getMenuChoice();
    determineDayOfBirth();
    print10LeapYears();
    printCloser();

    return;

}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    int y;
    cin >> y;
   
    while (y == 1 || y == 2 || y == 3) {
        if (y == 1) {
            determineDayOfBirth();
        }
        else if (y == 2) {
            print10LeapYears();
        }
        else if(y == 3){
            cout << "Finished";
            return 0;

        }
        else
        {
            cout << "Invalid menu choice" << endl;
            printMenu();
        }
    }
    return 0;
}

bool isGregorianDate(int month, int day, int year) {
    // TODO: implement
   
    if ( day > 14 && month > 8 && year > 1752)
    {
        day = true;
        month = true;
        year = true;
    }
    else
    {
        day = false;
        month = false;
        year = false;
    }
    // returning false to avoid compile error
    return false;
}

bool isLeapYear(int year) {
    // TODO: implement
    if (year % 4 == 0)
    {
        year = true;
    }
    else if (year % 100 == 0 && year %400 == 0)
    {
        year = true;
    }
    else
    {
        year = false;
    }
    // returning false to avoid compile error
    return false;
}


bool isValidDate(int month, int day, int year) {
    // TODO: implement
    isGregorianDate(month, day, year);
    isLeapYear(year);
    while ( month == true && day == true && year == true)
    {
        if (month == 1) {
            (day <= 31);
            (day >= 1);
}
        else if (month == 2)
        {
            if(year == true)
            {
                (day <= 28);
                (day >= 1);
            }
            else
            {
                (day <= 29);
                (day >= 1);
            }
        }
        else if (month == 3) {
            (day <= 31);
            (day >= 1);
        }
        else if (month == 4) {
            (day <= 30);
            (day >= 1);
        }
        else if (month == 5) {
            (day <= 31);
            (day >= 1);
        }
        else if (month == 6) {
            (day <= 30);
            (day >= 1);
        }
        else if (month == 7) {
            (day <= 31);
            (day >= 1);
        }
        else if (month == 8) {
            (day <= 31);
            (day >= 1);
        }
        else if (month == 9) {
            (day <= 30);
            (day >= 1);
        }
        else if (month == 10) {
            (day <= 31);
            (day >= 1);
        }
        else if (month == 11) {
           (day <= 30);
            (day >= 1);
        }
        else if (month == 12) {
            (day <= 31);
            (day >= 1);
        }
        else
        {
            year = false;
        }
    }
    return false;
}


int determineDay(int month, int day, int year) {
 
    if (month == 1) {
        month = 13;

    }
    if (month == 2) {
        month = 14;
    }
    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;
    int h;
      h  = q + 13 * (m + 1) / 5 + k + k / 4 +
        j / 4 + 5 * j;
    h = h % 7;
    day = h;
    return 0;
}


void printDayOfBirth(int day) {
    if (day == 0)
    {
        cout <<  "Saturday" << endl;
    }
    else if (day == 1)
    {
        cout << "Sunday" << endl;
    }
    else if (day == 2)
    {
        cout << "Monday" << endl;
    }
    else if (day == 3)
    {
        cout << "Tuesday" << endl;
    }
    else if (day == 4)
    {
        cout << "Wednesday" << endl;
    }
    else if (day == 5)
    {
        cout << "Thursday" << endl;
    }
    else if (day == 6)
    {
        cout << "Friday" << endl;
    }

    
    return;
}


void determineDayOfBirth() {

    int month;
        int day;
        int year;

    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->"; 
    cin >> month;
    cin >> day;
    cin >> year;
    isValidDate(month, day, year);
    if (month == true && day == true && year == true) {
        determineDay(month, day, year);
       
        cout << "You were born on a: ";
        printDayOfBirth(day);
        cout << endl;
            cout << "Have a great birthday!!!" << endl;
    }
    else
    {
        cout << "Invalid date" << endl;
    }


    return;
}

void print10LeapYears() {
   
    int year;
    int i;
    int newYear;

    cout << "Enter year-- > ";
    
    cin >> year;


    for (i = 0; i <= 10; i++)
    {
        isLeapYear(i);
        if (i == true)
        {
            newYear = year + i;
            cout << "Leap year is" << newYear << " " << endl;
        }
    }

    return;
}



