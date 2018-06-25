#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    long long ccnumber = get_long_long("type a number to check if it's a valid cc number  ");
    string company;
// 16 digits: MASTERCARD or VISA
    if (ccnumber < 10000000000000000 &&
        ccnumber > 999999999999999)
    {
        // if ccnumber starts with 51, 52, 53, 54 or 55: MASTERCARD
        if (
            ccnumber / 100000000000000 > 50 &&
            ccnumber / 100000000000000 < 56)
        {
            company = "MASTERCARD";
        }
        // if ccnumber starts with 4: VISA
        else if (ccnumber / 1000000000000000 == 4)
        {
            company = "VISA";
        }
        else
        {
            company = "INVALID";
        }
    }
// 15 digits AMEX
    else if (ccnumber < 1000000000000000 &&
             ccnumber > 99999999999999)
    {
// if ccnumber starts with 34 or 37: AMEX
        if (ccnumber / 10000000000000 == 34 ||
            ccnumber / 10000000000000 == 37)
        {
            company = "AMEX";
        }
        else
        {
            company = "INVALID";
        }
    }
// 13 digits VISA
    else if (ccnumber < 10000000000000 &&
             ccnumber > 999999999999)
    {
// if ccnumber starts with 4: VISA
        if (ccnumber / 1000000000000 == 4)
        {
            company = "VISA";
        }
        else
        {
            company = "INVALID";
        }
    }
// if ccnumber is not correct length: INVALID
    else
    {
        company = "INVALID";
    }

    int sum = 0;

    do
    {
        //get last number and add to sum_rest
        sum = sum + ccnumber % 10;
        //get second to last number, multiply by 2, add to result
        int result = ccnumber % 100 / 10 * 2;
        if (result < 10)
            //add result to sum_digits
        {
            sum = sum + result;
        }
        else
        {
            sum = sum + result % 10 + result % 100 / 10;
        }
        //remove last 2 digits
        ccnumber = ccnumber / 100;
    }
    while (ccnumber > 0);
    if (sum % 10 == 0)
    {
        printf("%s\n", company);
    }
    else
    {
        printf("INVALID\n");
    }
}