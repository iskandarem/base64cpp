#include "cmdpar.hpp"
#include "base64.hpp"
#include <iostream>
#include <iterator>

using namespace base64cpp;

constexpr std::string_view version_description = R"(base64cpp (iskandarem's corehobbies) 0.1.0

Written by Iskandar Emomzoda.
)";

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
			return;
		}
		
		if(vm.count("version"))
		{
			std::cout << version_description;
			return;
		}
		if(vm.size() == 0)
		{
			std::string content{
				std::istreambuf_iterator<char>{std::cin},
				std::istreambuf_iterator<char>{}
		
			};
			std::cout << base64cpp::encode(content) << '\n';
			return;
		} 
		if(vm.count("decode"))
		{
			std::string content;
			std::getline(std::cin, content);
			std::cout << base64cpp::decode(content) << '\n';
			return;
		}
		
		po::notify(vm);
	}
	catch(std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}
}
