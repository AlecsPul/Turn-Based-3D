#pragma once

#include <vector>
#include <memory>

class Unit;
class Renderer;

class TurnSystem {
public:
    TurnSystem() = default;
    ~TurnSystem() = default;

    void Update(float deltaTime) {
        // TODO: Update turn-based logic
        // - Process current turn
        // - Handle turn transitions
        // - Update unit states
    }

    void Render(Renderer* renderer) {
        // TODO: Render turn-based UI elements
        // - Current turn indicator
        // - Unit action previews
    }

    void AddUnit(std::shared_ptr<Unit> unit) {
        // TODO: Add unit to turn order
    }

    void NextTurn() {
        // TODO: Advance to next turn
    }

private:
    std::vector<std::shared_ptr<Unit>> m_Units;
    int m_CurrentTurnIndex = 0;
};
