#pragma once
#include <boost/log/core.hpp> // for global setings
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp> // for severity level
#include <boost/log/utility/setup/file.hpp> // for add_file_log
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/attributes.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace attrs = boost::log::attributes;

namespace AcrScn {
	class logger{
	public:
		logger();
		void log_trace(std::wstring s);
		void log_debug(std::wstring s);
		void log_info(std::wstring s);
		void log_warning(std::wstring s);
		void log_error(std::wstring s);
		void log_fatal(std::wstring s);
	private:
	};
}

AcrScn::logger::logger() {

	boost::shared_ptr< logging::core > core = logging::core::get();
	core->add_global_attribute("LineID", attrs::counter<unsigned int>(1));
	core->add_global_attribute("TimeStamp", attrs::local_clock());

	logging::add_file_log(
		keywords::file_name = "sample.log",
		keywords::rotation_size = 10 * 1024 * 1024,
		keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
		keywords::format = "[%TimeStamp%]: %Message%"
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::trace
	);
}

void AcrScn::logger::log_trace(std::wstring s) {
	BOOST_LOG_TRIVIAL(trace) << s;
}

void AcrScn::logger::log_debug(std::wstring s) {
	BOOST_LOG_TRIVIAL(debug) << s;
}

void AcrScn::logger::log_info(std::wstring s) {
	BOOST_LOG_TRIVIAL(info) << s;
}

void AcrScn::logger::log_warning(std::wstring s) {
	BOOST_LOG_TRIVIAL(warning) << s;
}

void AcrScn::logger::log_error(std::wstring s) {
	BOOST_LOG_TRIVIAL(error) << s;
}

void AcrScn::logger::log_fatal(std::wstring s) {
	BOOST_LOG_TRIVIAL(fatal) << s;
}
