#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <stdexcept>


namespace base64cpp
{
	
		std::string encode(std::string_view input)
		{
				constexpr std::string_view alphabet =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"0123456789+/";


			std::string result;
			result.reserve(((input.size() + 2) / 3) * 4);

			for (std::size_t i = 0; i < input.size(); i += 3)
			{
				const auto a = static_cast<std::uint8_t>(input[i]);
				const auto b = i + 1 < input.size()
					? static_cast<std::uint8_t>(input[i + 1]) : 0;
				const auto c = i + 2 < input.size()
					? static_cast<std::uint8_t>(input[i + 2]) : 0;

				result += alphabet[a >> 2];
				result += alphabet[((a & 0x03) << 4) | (b >> 4)];

				result += i + 1 < input.size()
					? alphabet[((b & 0x0F) << 2) | (c >> 6)]
					: '=';

				result += i + 2 < input.size()
					? alphabet[c & 0x3F]
					: '=';
			}

			return result;
		}

		std::string decode(std::string_view input)
		{
			constexpr std::string_view alphabet =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"0123456789+/";


			if (input.size() % 4 != 0)
				throw std::invalid_argument("Invalid Base64 length");

			std::string result;
			result.reserve((input.size() / 4) * 3);

			for (std::size_t i = 0; i < input.size(); i += 4)
			{
				const auto a = alphabet.find(input[i]);
				const auto b = alphabet.find(input[i + 1]);

				const bool pad2 = input[i + 2] == '=';
				const bool pad3 = input[i + 3] == '=';

				const auto c = pad2 ? 0 : alphabet.find(input[i + 2]);
				const auto d = pad3 ? 0 : alphabet.find(input[i + 3]);

				if (a == alphabet.npos || b == alphabet.npos ||
					c == alphabet.npos || d == alphabet.npos ||
					(pad2 && !pad3) ||
					((pad2 || pad3) && i + 4 != input.size()))
				{
					throw std::invalid_argument("Invalid Base64 input");
				}

				result += static_cast<char>((a << 2) | (b >> 4));

				if (!pad2)
					result += static_cast<char>(((b & 0x0F) << 4) | (c >> 2));

				if (!pad3)
					result += static_cast<char>(((c & 0x03) << 6) | d);
			}

			return result;
		}
}

