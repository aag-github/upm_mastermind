#ifndef SRC_VIEWS_LOADGAMEVIEW_H_
#define SRC_VIEWS_LOADGAMEVIEW_H_

#include "LoadGameController.h"
#include "ViewConst.h"
#include "ui/AvailableGamesView.h"

namespace Mastermind {

class LoadGameView {
public:
    LoadGameView(){
    };

    virtual ~LoadGameView(){
    };

    void interact(LoadGameController* controller){
        assert(controller != nullptr);

        AvailableGamesView(controller->getAvailableGames()).show();

        if (controller->getAvailableGames().size() == 0) {
            controller->noGamesAvailable();
        } else {
            std::string name = IO::DialogReadString("\nGame name to load: ").read();

            if (0 != controller->load(name) && name != "") {
                std::cout << "\n** Error loading file '" << name << "' **\n";
            }
        }
    }
};

}
#endif
