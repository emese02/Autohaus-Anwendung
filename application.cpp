#include "Repository/test_repository.h"
#include "Controller/test_controller.h"
#include "Controller/auto_controller.h"
#include "Repository/auto_repository.h"
#include "UI/auto_ui.h"
#include <memory>
#include <iostream>

using namespace electric_auto;
using namespace controller;
using namespace repo;
using namespace ui;

bool decide()
{
    int mode;
    cin >> mode;
    if (mode == 1)
        // persistent
        return true;
    else if (mode == 2)
        // in_memory
        return false;
    else
        exception();
}

string string_choice()
{
    return "Choose an option: \n1. Persistent\n2. In-memory\n";
}

int main()
{
    test_controller();
    test_repository();
    cout<<string_choice();
    bool save_mode = decide();

    if (save_mode)
    {
        // persistent -> CSV
        std::unique_ptr<CSV_File_Repository> auto_repo = std::make_unique<CSV_File_Repository>();
        auto_repo->initialize_repository();
        std::unique_ptr<Controller_CSV> auto_controller = std::make_unique<Controller_CSV>(*auto_repo);
        std::unique_ptr<UI_CSV> auto_ui  = std::make_unique<UI_CSV>(*auto_controller);
        auto_ui->get_user_choice();

    }
    else
    {
        std::unique_ptr<In_Memory_Repository> auto_repo = std::make_unique<In_Memory_Repository>();
        auto_repo->initialize_repository();
        std::unique_ptr<Controller_In_Memory> auto_controller = std::make_unique<Controller_In_Memory>(*auto_repo);
        std::unique_ptr<UI_In_Memory> auto_ui  = std::make_unique<UI_In_Memory>(*auto_controller);
        auto_ui->get_user_choice();
    }

    return 0;
}