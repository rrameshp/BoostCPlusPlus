//============================================================================
// Name        : Boost_Test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Experiment with the C++ Boost Library
//============================================================================

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/lambda/bind.hpp>

int main()
{
	using namespace boost::filesystem;
	using namespace boost::lambda;

	path the_path( "/home/Work/EBooks" );

	int cnt = std::count_if (
			directory_iterator(the_path),
			directory_iterator(),
			bind( static_cast<bool(*)(const path&)>(is_regular_file),
			bind ( &directory_entry::path, _1) ) );

	std::cout << cnt << std::endl;
	return 0;
}
