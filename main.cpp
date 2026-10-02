#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

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
    std::srand(std::time(0));
    int r_num = 0;
    pid_t p1, p2;

    if (!f)
    {
        fprintf(stderr, "Nepodarilo se nacist soubor!\n");
        return -1;
    }

    int pipe_p1p2[2];
    if (pipe(pipe_p1p2) == -1)
    {
        fprintf(stderr, "Chyba pri vytvareni pipe!");
        return -1;
    }

    if ((p1 = fork()) < 0)
    {
        fprintf(stderr, "forkError!\n");
        return -1;
    }

    while (fgets(line, sizeof(line), f) != NULL)
    {
        messages.push_back(line);
    }

    if (p1 == 0)
    {
        close(pipe_p1p2[0]);

        for (size_t i = 0; i < static_cast<size_t>(atoi(argv[2])); i++)
        {
            r_num = std::rand() % atoi(argv[2]);
            // messages.at(r_num);
            printf("%\n", r_num);
        }
    }

    return 0;
}
