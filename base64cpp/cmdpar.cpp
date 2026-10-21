#include "cmdpar.hpp"
#include <iostream>
using namespace base64cpp;
CmdPar::CmdPar()
{
	desc.add_options()
		("help,h", "display this help and exit")
		("version,v", "output version information and exit")
		("decode,d", "decode data")
		("ignore-garbage,i", "when decoding, ignore non-alphabet charachters")
		("wrap=COLS,w", "wrap encoded lines after COLS charachter (default 76).");
}

void CmdPar::parse(int argc, const char** argv)
{
	try
	{
		po::store(po::parse_command_line(argc, argv, desc), vm);
		
		if(vm.count("help"))
		{
			std::cout << desc;
		}
		
		if(vm.count("version"))
		{
			std::cout << "base64cpp version 0.1.0\n";
		}
		po::notify(vm);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
}
