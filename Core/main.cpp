/*!
 * \file main.cc
 * \brief Main body responsible for menu showing
 * and image processing.
 * \author tkornuta
 * \date 11.09.2007
 */

#include <cstring>
#include <iostream>

#include <libxml/parser.h>
#include <libxml/xpath.h>

#include "FraDIAException.hpp"

#include "KernelManager.hpp"
#include "KernelFactory.hpp"
#include "Configurator.hpp"

using namespace std;
using namespace Common;
using namespace Core;

xmlDocPtr configuration;
char* configuration_filename;

/*!
 * Main body - creates two threads - one for window and and one
 * for images acquisition/processing.
 */
int main(int argc_, char** argv_)
{
	try {
		// FraDIA config filename.
		char *config_name;
		// Check whether other file wasn't pointed.
		if (argc_ == 2)
			config_name = argv_[1];
		else
			// Default configuration file.
			config_name = (char*)"config.xml";

		CONFIGURATOR.loadConfiguration(config_name);

		SOURCES_MANAGER.initializeKernelsList();
		PROCESSORS_MANAGER.initializeKernelsList();

		CONFIGURATOR.saveConfiguration();

	}//: try
	catch (exception& ex){
		cout << "Fatal error:\n";
		// If required print exception description.
		if (!strcmp(ex.what(), ""))
			cout << ex.what() << endl;
		exit(EXIT_FAILURE);
	}//: catch
}