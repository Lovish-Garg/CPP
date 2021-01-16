#include <cmath>
#include <string>
#include <limits>
#include <sstream>
#include <iostream>
#include <stdexcept>// for runtime error handling

// instead of importing the whole namespace including individual namespaces
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::stringstream;
using std::runtime_error;
using std::numeric_limits;

#define MAX 400
#define INT 48 // this will be used while converting char to int

class Num// for storing numbers
{
    public:
        int numbers[(int)MAX];// array declaration requires const value 
        int size;

        Num()
        {
            size = 0;
        }
};

// inline functions are better to use for small functions
inline bool isoperation(const char opt)
 { return (opt == '+' || opt == '-' || opt == '/' || opt == '*' || opt == '%') ? true : false; }

inline long int sum(long int num1, long int num2)
{ return num1 + num2; }

inline long int subtract(long int num1, long int num2)
{ return num1 - num2; }

inline long int multiply(long int num1, long int num2)
{ return num1 * num2; }

inline long int divide(long int num1, long int num2)// this is special for error handling because  division by 0 is undefined
{   if (num2 == 0)
    {
        throw runtime_error("Math error: Attempted to divide by Zero\n");
    }
    
    return num1 / num2; 
}

inline long int modulos(long int num1, long int num2)
{
    if (num2 == 0)
    {
        throw runtime_error("Math error: Attempted to modulous divide by Zero\n");
    }
     return num1 % num2; 
}

int main(void)
{
    
    do
    {
        string equation;
        equation[0] = '\0';
        Num data;
        int show = 0;

        getline(cin, equation);// taking input
        
        if (equation[0] != '\0')// this all is for case when user doesnot input anything and nothing should be printed even \n
            show = 1;
        else
        {
            system("clear");
            continue;
        } 
        // removing all white-spaces from string
        {
            string temp;
            stringstream str;
            str << equation;

            equation = "";
            
            while (!str.eof())
            {
                str >> temp;

                equation += temp;
            }
        }

        //checking which is number and ignoring all others
        for (int i = 0; equation[i] != '\0'; ++i)
        {
            
            if (equation[i] == '-')
            {
                if (equation[i] == equation[i + 1])
                {
                    data.numbers[data.size] = '+';// because - and - = +
                    ++data.size;
                    ++i;
                }

                else if (equation[i + 1] == '+')
                {
                    data.numbers[data.size] = '-';
                    ++data.size;
                }
                else if (data.size == 0 || isoperation(equation[i - 1]))
                {
                    ++i;
                    long int num = 0;
                    while (isdigit(equation[i]))
                    {
                        num = num * 10 + (equation[i] - INT);
                        ++i;
                    }
                    num *= -1;
                    data.numbers[data.size] = num;
                    ++data.size;
                    --i;
                }
                    
                else 
                {
                    data.numbers[data.size] = equation[i];
                    ++data.size;
                }
                    
            }
            else if (isdigit(equation[i]))
            {
                long int num = 0;
                while (isdigit(equation[i]))
                {
                    num = num * 10 + (equation[i] - INT);
                    ++i;
                }

                data.numbers[data.size] = num;
                ++data.size;
                --i;
            }
            else if (isoperation(equation[i]))
            {
                if (equation[i] == '-')
                {
                    if (equation[i + 1] == '+')
                    {
                        data.numbers[data.size] = '-';
                        ++data.size;   
                    }
                    else if (equation[i] == equation[i + 1]) {
                        data.numbers[data.size] = '+';// because - and - = +
                        ++data.size;
                        ++i;
                    }
                }
                else 
                {
                    data.numbers[data.size] = equation[i];
                    ++data.size;   
                }
            }
        }
        // performing operations and solving it
        int now = 1;
        int n = data.size;
        long int first = data.numbers[0];
        
        int index = 0;
        for (int i = 0; i < n; ++i)
        {
            long int num = data.numbers[index += 2];
            switch(data.numbers[now])
            {
                case '+':
                    first = sum(first, num);
                    break;

                case '-':
                    first = subtract(first, num);
                    break;

                case '*':
                    first = multiply(first, num);
                    break;

                case '/':
                    try
                    {
                        first = divide(first, num);
                    }
                    catch(runtime_error &e)
                    {
                        cout << "Exception Occured " << e.what();
                        show = 0;
                    }
                    break;
                
                case '%':
                    try
                    {
                        first = modulos(first, num);
                    }
                    catch(runtime_error &e)
                    {
                        cout << "Exception Occured " << e.what();
                        show = 0;
                    }
                    break;
            }
            now += 2;
        }
        if (show)
            cout  << first << endl;
        getchar();
        system("clear");
    }
    while (1);
}
