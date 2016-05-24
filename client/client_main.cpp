#include "client_Client.h"
#include <iostream>

int main(int argc, char **argv) {
	Client client;
	client.start();
	std::cout << "Finished." << std::endl;
}
