#include "get.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		cout << "Usage: " << argv[0] << " https://example.com" << "\n";
		return -1;
	}

	Response theRes = get(argv[1]);

	cout << theRes.dump() << "\n";

	return 0;
}