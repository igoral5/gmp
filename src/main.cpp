/*
 * main.cpp
 *
 *  Created on: 11.04.2013
 *      Author: igor
 */

#include <iostream>
#include <cstdlib>
#include <locale>
#include <exception>

int
main(int argc, char *argv[]) try 
{
	std::locale::global(std::locale(""));

	return EXIT_SUCCESS;
}
catch(const std::exception& err)
{
	std::cerr << "An exception occurred : " << err.what() << std::endl;
	return EXIT_FAILURE;
}
catch(...) 
{
    std::cerr << "Unknown exception" << std::endl;
	return EXIT_FAILURE;
}
