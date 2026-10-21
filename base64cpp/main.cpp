#include "cmdpar.hpp"
 
int main(int argc, const char** argv)
{
	base64cpp::CmdPar cmdparser;
	cmdparser.parse(argc, argv);
	return 0;
}
