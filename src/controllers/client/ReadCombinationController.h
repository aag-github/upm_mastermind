#ifndef SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_
#define SRC_CONTROLLERS_READCOMBINATIONCONTROLLER_H_

#include "CombinationController.h"

namespace Mastermind {

class ReadCombinationController : public CombinationController {
public:
    ReadCombinationController(Game &game) :
        CombinationController(game)
    {
    }

    virtual ~ReadCombinationController(){
    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

    void gameEnd(bool end) {
        assert(game.getState() == State::MAIN_MENU);

        game.setState(State::MAIN_MENU);
    }

    ProposedCombinationState setProposedCombination (const Combination& proposedCombination) {
        return game.setProposedCombination(proposedCombination);
    }

};

}

#endif
