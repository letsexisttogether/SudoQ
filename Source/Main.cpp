#include <iostream>

#include "Print/BoardCmdPrinter.hpp"
#include "Spawn/Default/DefaultBoardSpawner.hpp"
#include "Check/BoardChecker.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, SudoQ" << std::endl;

    std::unique_ptr<BoardSpawner> spawner{ new DefaultBoardSpawner{} };

    const Board board{ spawner->SpawnBoard() };

    const BoardCmdPrinter printer{ board };
    printer.Print();

    const BoardChecker checker{ board };
    const bool isBoadCorrect = checker.IsComplete();

    std::cout << ((isBoadCorrect) ? ("The board is fine") 
        : ("The board is wrong")) << std::endl;

    return EXIT_SUCCESS;
}
