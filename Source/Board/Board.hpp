#pragma once

#include <cstdint>
#include <vector>

class Board
{
public:
    using CellValue = std::uint16_t;
    using RowColumn = std::vector<CellValue>;
    using Grid = std::vector<RowColumn>;

    using RCIndex = RowColumn::size_type;

public:
    Board() = default;
    Board(const Board&) = default;
    Board(Board&&) = default;

    Board(const Grid& grid);
    Board(Grid&& grid);

    ~Board() = default;

    CellValue GetCellValue(const RCIndex row, const RCIndex column)
        const noexcept;
    void SetCellValue(const RCIndex row, const RCIndex column,
        const CellValue value) noexcept;

    const Grid& GetRawGrid() const noexcept;

    Board& operator = (const Board&) = default;
    Board& operator = (Board&&) = default;

private:
    bool IsInBoundries(const RCIndex row, const RCIndex column)
        const noexcept;

public:
    static constexpr RCIndex GridMaxIndex{ 9 };
    static constexpr RCIndex TripleMaxIndex{ 3 };

private:
    Grid m_Grid{ GridMaxIndex, RowColumn(GridMaxIndex, CellValue{}) };
};
