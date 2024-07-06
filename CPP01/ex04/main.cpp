#include <fstream>
#include <iostream>

int	main(int ac, char **av) {
	std::ifstream file(av[1]);

    if (!file) {
        std::cerr << "Unable to open file";
        return 1;
    }

    

    file.close();
    return 0;
}