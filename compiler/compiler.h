#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <vector>

typedef std::pair<std::string, int> 	psi;
typedef std::vector< std::pair<std::string, int> > 	vpsi;

vpsi import_reserved( void );
std::vector<std::string> import_s( char * );

#endif
