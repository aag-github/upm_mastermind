#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <assert.h>
#include "ClientOperationController.h"

namespace Mastermind {

class StartController: public ClientOperationController {
public:
    StartController(Game &game) :
        ClientOperationController(game)
    {
    }

    virtual ~StartController(){
    }

    void start() {
        assert(game.getState() == State::INITIAL);

        game.start();

        game.setState(State::MAIN_MENU);
    };

    virtual void accept(ClientOperationControllerVisitor *operationControllerVisitor) override final
    {
        assert(operationControllerVisitor != nullptr);

        operationControllerVisitor->visit(this);
    };

};

}

#endif
