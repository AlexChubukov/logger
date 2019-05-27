// log.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "logger.h"

int main()
{
	std::wstring trace = L"A trace severity message",
				debug = L"A debug severity message",
				info = L"An informational severity message",
				warning = L"A warning severity message",
				error = L"An error severity message",
				fatal = L"A fatal severity message";

	AcrScn::logger logger;
	logger.log_trace(trace);
	logger.log_debug(debug);
	logger.log_info(info);
	logger.log_warning(warning);
	logger.log_error(error);
	logger.log_fatal(fatal);
	/*BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
	BOOST_LOG_TRIVIAL(info) << "An informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
	BOOST_LOG_TRIVIAL(error) << "An error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";*/

}

