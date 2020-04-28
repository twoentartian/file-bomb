#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "auto_multi_thread.hpp"

const char* file_bomb_dir = "./file-bomb";


int main()
{
	int SizeOfEachFile, NumberOfFile;
	std::cout << "Please give {SizeOfEachFile}(b) and {NumberOfFile}, eg: 1 1" << std::endl;
	std::cin >> SizeOfEachFile >> NumberOfFile;
	
	std::filesystem::create_directory(file_bomb_dir);

	auto_multi_thread::ParallelExecution([&SizeOfEachFile](uint32_t index)
		{
			std::fstream file(std::string(file_bomb_dir) + "/" + std::to_string(index) + ".mkv", std::ios::out | std::ios::binary);
			std::default_random_engine e;
			std::random_device rd;
			e.seed(rd());
			std::uniform_int_distribution dis(0, 256);
			std::string data;
			data.resize(SizeOfEachFile);
			char* start_loc = data.data();
			for (int loc = 0; loc < SizeOfEachFile; ++loc)
			{
				start_loc[loc] = dis(e);
			}
			file << data;
			file.flush();
			file.close();
		}, NumberOfFile);

	std::cout << "Finish" << std::endl;
	return 0;
}