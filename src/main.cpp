/*
 * main.cpp
 *
 *  Created on: 11.04.2013
 *      Author: igor
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "gettext.h"
#define _(string) gettext(string)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <locale>
#include <exception>
#include <gmpxx.h>


int
main(int argc, char *argv[]) try 
{
    std::locale::global(std::locale(""));
    bindtextdomain( PACKAGE, LOCALEDIR );
    textdomain( PACKAGE );
    mpz_class a(_("12345678901234567890232346458769879783523523455465675674674"));
    mpz_class b(_("-56789012345678901234567890546458769780784562456347648568976456547567"));
    std::cout << _("First term: ") << a << std::endl;
    std::cout << _("Second term: ") << b << std::endl;
    std::cout << _("Sum: ") << a + b  << std::endl;
    std::cout << _("Absolute value: ") << abs(a + b) << std::endl;
    mpq_class d(2);
    mpq_class e(3);
    std::cout << _("Dividend: ") << d << std::endl;
    std::cout << _("Divisor: ") << e << std::endl;
    std::cout << _("Quotient: ") << d / e << std::endl;
    mpq_class a1(_("3/5"));
    mpq_class b1(_("7/8"));
    std::cout << _("First term: ") << a1 << std::endl;
    std::cout << _("Second term: ") << b1 << std::endl;
    std::cout << _("Sum: ") << a1 + b1 << std::endl;
    mpf_class d1(_("2.34123432453464575678876897978978987e12345"), 1000);
    mpf_class e1(_("3.456457568768964634645756783567356756e45235"), 1000);
    std::cout << std::setprecision(100);
    std::cout << _("First multiplier: ")<< d1 << std::endl;
    std::cout << _("Second multiplier: ") << e1 << std::endl;
    std::cout << _("Product: ") << d1 * e1 << std::endl;
    return EXIT_SUCCESS;
}
catch(const std::exception& err)
{
	std::cerr << _("An exception occurred : ") << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch(...) 
{
    std::cerr << _("Unknown exception") << std::endl;
	return EXIT_FAILURE;
}
