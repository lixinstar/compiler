#include <cstdlib>
#include <cctype>
#include "compiler.h"
using namespace std;

#define MY_DEBUG

// 导入保留字文件
vpsi import_reserved( void )
{
	// 打开保留字文件
	ifstream 	input( "reserved" );
	if (!input) {
		cout << "open reserved failed!" << endl;
		exit( 1 );
	}

	vpsi 	vec;
	string 	temp;
	pair<string, int> 	ptemp;
	int  	count = 1;
	
	// 把保留字表中的单词一一导入并编号 
	while (input >> temp) {
		ptemp = make_pair( temp, count );
		vec.push_back( ptemp );
		count++;
	}
	input.close();
	input.clear();

#ifdef MY_DEBUG_H
	vpsi::iterator iter = vec.begin();
	while (iter != vec.end()) {
	  	cout << iter->first << " " << iter->second;
		iter++;
	}
	cout << endl;
#endif

	return vec;
}

// 导入源文件
vector<string> import_s( char * filename )
{
	ifstream in(filename);
	if (!in) {
		cout << "file open failed!" << endl;
		exit(1);
	}

	// 从文件中逐行读取内容放入容器
	vector<string> 		source;
	string 		temp;
	while (getline(in, temp)) {
		source.push_back(temp);
	}

#ifdef 	MY_DEBUG_H
	vector<string>::const_iterator i = source.begin();
	while (i != source.end()) {
		cout << *i << endl;
		i++;
	}
#endif

	// 分词并去除注释
	vector<string>::const_iterator 	iter = source.begin();
	vector<string> 	new_source;
	string::const_iterator 	tail;

loop:	while (iter != source.end()) {
		tail = (*iter).begin();
		temp = "";
		while (tail != (*iter).end()) {
			// 如果是字母则一直向后遍历
			while (tail != (*iter).end()) {
				if (isalpha(*tail)) {
					temp += *tail;
				}
				else
				  break;
				++tail;
			}
			if (!temp.empty()) {
				new_source.push_back(temp);
				temp = "";
			}

			// 如果不是字母则进行判断，并去除注释
			while (tail != (*iter).end()) {
				if (!isalpha(*tail)) {
					// 去除注释
					if (*tail == '/' && *(tail + 1) == '*') {
						tail += 2;
						while (tail != (*iter).end()) {
							if (*tail == '*' && *(tail + 1) == '/')
							  tail += 2;
							else 
							  tail++;
						}
						continue;
					}
					if (*tail == '/' && *(tail + 1) == '/') {
						++iter;
						goto loop;
					}
					// 如果不是注释则将符号分开单独放入容器
					else {
						if (*tail == ' ' || *tail == '\t') {
							tail++;
							continue;
						}
						temp += *tail;
						if (!temp.empty()) {
							new_source.push_back(temp);
							temp = "";
						}
						tail++;
						continue;
					}
				}
				else
				  break;
				++tail;
			}
		}
		iter++;
	}

#ifdef 	MY_DEBUG
	vector<string>::const_iterator jter = new_source.begin();
	while (jter != new_source.end()) {
		cout << *jter << endl;
		jter++;
	}
#endif

	return new_source;
}
