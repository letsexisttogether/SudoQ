#include <iostream>

#include "Print/Cmd/BoardCmdPrinter.hpp"
#include "Spawn/Default/DefaultBoardSpawner.hpp"
#include "Spawn/Random/RandomBoardSpawner.hpp"
#include "Check/BoardChecker.hpp"

std::int32_t main(std::int32_t argc, char** argv)
{
    std::cout << "Hello, SudoQ" << std::endl;

    std::unique_ptr<BoardSpawner> spawner{ new RandomBoardSpawner{} };

    const Board board{ spawner->SpawnBoard() };


    const BoardChecker checker{ board };
    const bool isBoadCorrect = checker.IsComplete();

    std::cout << ((isBoadCorrect) ? ("The board is fine") 
        : ("The board is wrong")) << std::endl;

    const BoardCmdPrinter printer
    { 
        board,
        {
            { 
                { true, true, true, true, true, true, false, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, },
                { true, true, true, true, true, true, true, true, true, }
            } 
        }
    };

    while(1)
    {
        printer.PrintBoard();

        Board::RCIndex i{};
        Board::RCIndex j{};
        std::uint32_t value{};

        std::cin >> i >> j >> value;
        
        if (board.GetCellValue(i, j) == value)
        {
            std::cout << "You get the value right";

            break;
        }
        
        std::cout << "You get the value wrong\nYou typed: "
            << static_cast<std::uint32_t>(value) << '\n';
    }

    return EXIT_SUCCESS;
}
