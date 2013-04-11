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
#include <cstdlib>
#include <locale>
#include <exception>

int
main(int argc, char *argv[]) try 
{
	std::locale::global(std::locale(""));
	bindtextdomain( PACKAGE, LOCALEDIR );
	textdomain( PACKAGE );
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
