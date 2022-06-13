#pragma once

#include <string_view>

namespace game_msg
{
    using namespace std::literals;

	inline constexpr std::string_view WELCOME_MESSAGE = "Welcome to Mastermind game!\n\n"
		"Try to guess the code! Code has 4 digits, which should be unique \n"
		"each other and also in range = [1,8]\n\n"
		"You have 10 attempts\n\n"
		"Let's start!";
	inline constexpr auto SEPARATOR				= "---------------------------------"sv;
	inline constexpr auto WIN_MESSAGE			= "CONGRATULATIONS!!YOU WIN!!!"sv;
	inline constexpr auto FAIL_MESSAGE			= "Sorry too many attempts! Game finished!"sv;
	inline constexpr auto AGAIN_MESSAGE			= "Wanna play a new game ?"sv;
	inline constexpr auto YN_CHOICE				= "[y / N]"sv;
	inline constexpr auto BYE_MESSAGE			= "See you later!"sv;
												
	inline constexpr auto LAST_GUESSES			= "your last guesses:"sv;
	inline constexpr auto ATTEMPT				= "Attempt "sv;
	inline constexpr auto WRITE_YOUR_GUESS		= "write your next guess:"sv;
	inline constexpr auto TYPE_AGAIN			= " Type your guess again !"sv;
	inline constexpr auto SOLUTION_IS			= "Solution is:"sv;
												
	inline constexpr auto CODE_WRONG_SIZE		= "Wrong size of code !"sv;
	inline constexpr auto CODE_OUT_OF_RANGE_L	= "Only digits from range [1, "sv;
	inline constexpr auto CODE_OUT_OF_RANGE_R	= "] are allowed !"sv;
	inline constexpr auto CODE_ONLY_DIGITS		= "Code should have only digits !"sv;
	inline constexpr auto CODE_UNIQUE_DIGITS	= "Code should have unique digits !"sv;
}