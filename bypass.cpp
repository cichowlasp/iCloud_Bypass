#include <iostream>
#include <string>
#include <vector>

void checkra1ncli(){
    for (;;){
        system("clear");
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "        Put your device into dfu mode        " << std::endl;
        std::cout << "            Then tap 0 to continue           "<< std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        char enter = 1;
        system("/bin/stty raw");
        enter = getchar();
        system("/bin/stty cooked");
        if (enter == '0'){
            break;
        }
    }
    system("/Applications/checkra1n.app/Contents/MacOS/checkra1n --cli");
}

void bypass(std::string path){
    for (;;){
        system("clear");
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "So now jailbreak your device using checkra1n!" << std::endl;
        std::cout << "            Then tap 0 to continue           "<< std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        char enter = 1;
        system("/bin/stty raw");
        enter = getchar();
        system("/bin/stty cooked");
        if (enter == '0'){
            break;
        }
    }

    std::string chmod = std::string("chmod +x ") + path + std::string("/files/bash2.sh");
    std::string run = path + std::string("/files/bash2.sh");
    std::cout << path << std::endl;
    const char * command = new char; 
    command = chmod.c_str();
    system(command);
    command = run.c_str();
    system(command);
    for(;;){
        std::cout << "----------------------------------" << std::endl;
        std::cout << "|           Bypassed :)          |" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "         tap 0 to continue        "<< std::endl;
        char enter = 1;
        system("/bin/stty raw");
        enter = getchar();
        system("/bin/stty cooked");
        if (enter == '0'){
            break;
        }
    }
}

void iTunesPatch(std::string path){

    std::string chmod = std::string("chmod +x ") + path + std::string("/files/bash3.sh");
    std::string run = path + std::string("/files/bash3.sh");
    const char * command = new char; 
    command = chmod.c_str();
    system(command);
    command = run.c_str();
    system(command);
    system("clear");
    for(;;){
        std::cout << "----------------------------------" << std::endl;
        std::cout << "|        iTunes Patched :)       |" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "         tap 0 to continue        " << std::endl;
        char enter = 1;
        system("/bin/stty raw");
        enter = getchar();
        system("/bin/stty cooked");
        if (enter == '0'){
            break;
        }
    }
}

void preparetobypass(std::string path){
    std::string chmod = std::string("chmod +x ") + path + std::string("/files/bash1.sh");
    std::string run = std::string(".") + path + std::string("/files/bash1.sh");
    const char * command = new char; 
    command = chmod.c_str();
    system(command);
    command = run.c_str();
    system(command);
    std::cout << "...dependencies installed :)..." << std::endl;
}

int menu(std::string path){
    for(;;){
        system("clear");
        std::cout << "     Tool made by @cichowlasp     " << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "|     What do you want to do?    |" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "[1] Install require dependencies  " << std::endl;
        std::cout << "[2] Bypass iCloud on iOS 13.x and " << std::endl;
        std::cout << "    iTunes Patch(Sync and Restore)" << std::endl;
        std::cout << "[3] checkra1n cli                 " << std::endl;
        std::cout << "[0] Exit                          " << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "   All credits go to @iRogerosx   " << std::endl;
        int chosen_option;
        std::cout << "Option: "; std::cin >> chosen_option; 
        switch (chosen_option){
        case 1:
            preparetobypass(path);
            break;
        case 2:
            bypass(path);
            iTunesPatch(path);   
            break;
        case 3:
            checkra1ncli();
            break;
        case 0:
            exit(0);
            break;    
        default:
            break;
        }
    }
}

int main(int const argc, const char* const argv[], char* envv[]){
    std::string path = std::string(argv[0]);
    for(int i = 0;i<14;i++){
        path.pop_back();
    }
    menu(path);
    return 0;
}