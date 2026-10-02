#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Zadali jste nizky pocet argumentu!\n");
        return -1;
    }
    char line[1024];
    std::vector<std::string> messages;
    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        fprintf(stderr, "Nepodarilo se nacist soubor!\n");
        return -1;
    }

    while (fgets(line, sizeof(line), f) != NULL)
    {
        messages.push_back(line);
    }

    std::srand(std::time(0));
    int r_num = 0;

    for (size_t i = 0; i < atoi(argv[2]); i++)
    {
        r_num = std::rand() % atoi(argv[2]);
        // messages.at(r_num)
    }

    return 0;
}