#pragma once

#include <string>
#include <exception>

namespace cmd
{
	class option_not_found_exception : public std::exception
	{
	private:
		std::string message;
		std::string option_name;

	public:
		option_not_found_exception(const std::string& message, const std::string& option_name)
			: message(message), option_name(option_name)
		{
		}

		const char* what() const noexcept
		{
			return message.c_str();
		}

		const std::string& get_option_name() const noexcept
		{
			return option_name;
		}
	};
}