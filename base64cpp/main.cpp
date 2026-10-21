#include "cmdpar.hpp"
 
constexpr std::string_view table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

int main(int argc, const char** argv)
{
	base64cpp::CmdPar cmdparser;
	cmdparser.parse(argc, argv);
	return 0;
}
