#ifndef SRC_CONTROLLERS_QUITCONTROLLER_H_
#define SRC_CONTROLLERS_QUITCONTROLLER_H_

#include "ClientOperationController.h"

namespace Mastermind {

class QuitController: public ClientOperationController {
public:
    QuitController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~QuitController(){
    }

    void quit(bool quit) {
        assert(game.getState() == State::MAIN_MENU);

        if (quit) {
            game.setState(State::EXIT);
        } else {
            game.setState(State::MAIN_MENU);
        }

    }

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
