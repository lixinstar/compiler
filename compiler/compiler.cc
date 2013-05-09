#include "compiler.h"
#include <cstdlib>
using namespace std;

int main( int argc, char *argv[] )
{
	vpsi 	rsv_table;
	// 导入保留字表
	rsv_table = import_reserved();
	
	// 检测命令行参数
	if (argc < 2) {
		cout << "arguments error!" << endl;
		exit (1);
	}
	vector<string> 		source;
	source = import_s( argv[1] );
}
