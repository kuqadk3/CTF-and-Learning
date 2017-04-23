#include <fstream>
#include <iterator>
#include <vector>

int main()
{
	std::ifstream input( "test.bin", std::ios::binary );
	std::ofstream outfile("test.png",std::ofstream::binary);
	// copies all data into buffer
	std::vector<char> buffer((
		std::istreambuf_iterator<char>(input)), 
		(std::istreambuf_iterator<char>()));
	std::reverse(buffer.begin(), buffer.end());
	for(int i = 0; i < buffer.size(); i++){
		outfile << buffer[i];
	}


}