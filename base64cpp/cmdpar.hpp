#pragma once
#include <boost/program_options.hpp>

namespace po = boost::program_options;

namespace base64cpp
{
	constexpr std::string_view description = 
R"(Usage: base64cpp [OPTION]... [FILE]
Base64cpp encode or decode FILE, or standard input, to standard output.

With no FILE, or when FILE is -, read standard input.

Mandatory argument to long options are mandatory for short options too.
)";
	struct CmdPar{
	private:
		po::options_description desc{description.data()};
		po::variables_map vm;
	public:
		CmdPar();
		void parse(int argc, const char** argv);
	};
}
