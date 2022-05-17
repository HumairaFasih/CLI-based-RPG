// Declaring appropriate header files

#include "Game.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Functions of class Game

// Function to display the initial animation
void Game::StartGameArt()
{

    cout << endl << endl << "\x1b[35m████████ ██   ██ ███████      █████  ██████  ██    ██ ███████ ███    ██ ████████ ██    ██ ██████  ███████     ██████  ███████  ██████  ██ ███    ██ ███████ " << endl;
    cout << "   ██    ██   ██ ██          ██   ██ ██   ██ ██    ██ ██      ████   ██    ██    ██    ██ ██   ██ ██          ██   ██ ██      ██       ██ ████   ██ ██      " << endl;
    sleep_for(seconds(1));
    cout << "   ██    ███████ █████       ███████ ██   ██ ██    ██ █████   ██ ██  ██    ██    ██    ██ ██████  █████       ██████  █████   ██   ███ ██ ██ ██  ██ ███████ " << endl;
    cout << "   ██    ██   ██ ██          ██   ██ ██   ██  ██  ██  ██      ██  ██ ██    ██    ██    ██ ██   ██ ██          ██   ██ ██      ██    ██ ██ ██  ██ ██      ██ " << endl;
    sleep_for(seconds(1));
    cout << "   ██    ██   ██ ███████     ██   ██ ██████    ████   ███████ ██   ████    ██     ██████  ██   ██ ███████     ██████  ███████  ██████  ██ ██   ████ ███████ \x1b[0m" << endl;

    sleep_for(seconds(2));

}

// Functions to display choices for player to select from at different points in the story
void Game::Choices_1()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     
    cout << "\x1b[36m            1. Go out and check what's happening" << endl;
    cout << "            2. Ask around" << endl;
    cout << "            3. Keep sleeping\x1b[0m " << endl;

 }

 void Game::Choices_2()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Go and check the alleyway" << endl;
    cout << "            2. Stay in the crowd \x1b[0m" << endl;
 }

 void Game::Choices_3()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Run away" << endl;
    cout << "            2. Look for some weapon " << endl;
    cout << "            3. Jump at the creature\x1b[0m " << endl;
 }

 void Game::Choices_4()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Volunteer to help" << endl;
    cout << "            2. Stay where you are\x1b[0m" << endl;
 }

 void Game::Choices_5()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Run Away" << endl;
    cout << "            2. Look for some weapon" << endl;
    cout << "            3. Stay where you are\x1b[0m" << endl;

 }

void Game::Choices_6()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Use the stairs" << endl;
    cout << "            2. Use the elevator\x1b[0m" << endl;
 } 

void Game::Choices_7()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Stop running" << endl;
    cout << "            2. Keep running\x1b[0m" << endl;
 } 

 void Game::Choices_8()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Examine the carcass" << endl;
    cout << "            2. Walk back to crowd\x1b[0m" << endl;
 } 

void Game::Choices_9()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Walk back to crowd" << endl;
    cout << "            2. Kick again\x1b[0m" << endl;
 } 

 void Game::Choices_10()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Hit the creature with rod" << endl;
    cout << "            2. Run upstairs\x1b[0m" << endl;
 } 

 void Game::Choices_11()
 {
    cout << endl << "\x1b[33;41m  Choices: \x1b[0m" << endl << endl;     // Give player choices to select from
    cout << "\x1b[36m            1. Run without him" << endl;
    cout << "            2. Run back and help\x1b[0m" << endl;
 } 


// Class Animation created to display black_hole ascii art and make code compact 

Animation::Animation() 
{
    cout << "\x1b[31m         :   :          ;     ;    .::           ;      ;    . :.              :            " << endl;
    cout << "             :                        ;.          :            .::        :                 " << endl;
    cout << "   : .     :          ;    .::.    ;          .;     :    .::.    ;.    . ;         :   :" << endl;
    cout << "     :. :         ;                  :    .;:.    :   .::    :      :     :           :      " << endl;
    cout << "  :        :.   .     .;:   .:;.   .; .  . :.   ;    ::    :     ;.     :       ::.        " << endl;
    cout << "  :    :          ; .           ::     : . ::: .  i .  i . .;:   ::   .::.   . ;             " << endl;
    cout << " :.          ::.   . :    .i:.  .::.  . ; :...;::.. i:.  i:. :i. .:;.   :     :        .::.  " << endl;
    cout << ":   .::.   .:     ; .     ::....:;   .:;:; .:;1i. 1L  ;C;. tt.. i   ::.    :    . :         " << endl;
    cout << "              ;:..  ..;:..  :: : . .:i ; . :tf :11:;i;;:1:i:ii1::;L;..;;.  :;.  . :              :" << endl;
    sleep_for(seconds(1));
    cout << "   ;     ;    ..::    :  :  .. ; ;:  . :iL;:i;;:; :.::   ::.::: ;i:i:;ft...;   .: :      :   :    " << endl;
    cout << "   .             :.   .  ;  ;  ..: ::if:;;; : :  :::. ::. ;:. ;  :;.:i:1 :it.   ; .      :        " << endl;
    cout << ".  ::.   .;: .   .;;.   .. ;.;; ;:1:;i; : :   ;:  ::. : . ; .::. ; .:: :ii1. .i .    :           " << endl;
    cout << "    .::   .  ;  ..  .;;.::.    :::ti:: :  .:: .::  : . :  :   :  ;:. ;  ; :;iti.   ;:.   .  :   : " << endl;
    cout << " ::.    :      : .::  .  .:;.i::;;fi::::  :::. ::.::.::. :  : .::  :   ; .;:.i:i; .:i.   . :  :    " << endl;
    cout << "  .::.   .;:. ..  ::. i  :  : ::i;;:::  :  . :  :  :  :  :  :  : . :.  : .::. ; ;i1t   . :.:       " << endl;
    cout << "    :       .:;  ...  :  i  i.;:i1::  :    :     :.:  :  :     :. : . ;.. ;..:;.;:i;.. ;      .   " << endl;
    cout << "   ;:  .  :: .;:. :.  . : ;:ti:::    :    : :  : : :  :.:  ;.  :.:   ::   ::.:; ;ii1  .    : .:: " << endl;
    sleep_for(seconds(1));
    cout << "        .:;. ..      i  i  ; :;i;::: : :        :   : : :      .;:. ::  ::..;:. ;:.i;t ..  ::.:  " << endl;
    cout << "  ;  .   :  ;:      .   .: ;;;1;::      : :  :  :           : :..::..:;..:;.   ;. ; ;: :;:        " << endl;
    cout << "    :  ..  :   i .:i. i.:: :i1::    :      :            :: . : :. ::..::   .:;. :; ;1ti           : " << endl;
    cout << "     :   :  ..  ..  .     ;:;:1;::              :   :   :   ;    :      :..:;. .:i. ;:;...  : .:    " << endl;
    cout << "     .  :; .:;. ::  ;:.i: ;.;iii: :            : : :  :  :: .:: .:   ; . ;   . i ..i: 1;::;    .  " << endl;
    cout << "  .;:.    ..     ::. : .   :11:: :            :::::: ::. ; .:: .;  .;  : .:;. . i .i:ti .  .  " << endl;
    cout << "       ;   :     ..  .::.;;. i:;t ;  :          ::;;;:; :;. ; .;   :  :   ;   . ; : : ;  .   : .:  " << endl;
    cout << " ::  .     ;   i   i  ::.. : i.:i:t;::  :        :::iL1::;.;  ;  ::. : .:;.    ;  ;   i :t;;:;.: " << endl;
    cout << "   ;     . .   .   ...;: i .:i.;;;t:; :      : ::iti:::.;  : .::  ;      ;  :   .i: ;;;1: . . " << endl;
    cout << "    :  :i   ;   ;   i  ;:.. i .:i.i:1iii:; :::::;i1;::;.::. :  : .:: .::.     . i . i.i: .  " << endl;
    cout << "    :  :i   ;   ;   i  ;:.. i .:i.i:1iii:; :::::;i1;::;.::. :  : .:: .::.     . i . i.i: .  " << endl;
    cout << "   :  :i   ;   ;   i  ;:.. i .:i.i:1iii:; :::::;i1;::;.::. :  : .:: .::.     . i . i.i: .  " << endl;
    cout << ";   . .     ;   ;      ..:i. .:: .i ;:i:1;1;iiiii;::::.::. ; . ;.  :     ::. i .. ; ::;f::::.:  " << endl;
    sleep_for(seconds(1));
    cout << ".  ;  ::.   .  ..    .;;.  .: ::.;:.:: ; ;:;::::: :  :; .:: .::..:;..:;..::  . ;  ; .i i  " << endl;
    cout << "; .. .:: .;;  :i  :i       .;:.  ;  i  ;.:: ;.: ::: ;   ;   :   :   :   ; . i  ; ..i ;; ..  " << endl;
    cout << "   ;  ..          ..    .:i....;;. ::  ;  ;.:;.;  : .:;.    ; . ; ..;:..; .    .;;.::if::::.:  : " << endl;
    cout << ":  :  ;   :   :  .;: .i:. .  i:. . i. ; .::  : .; .i   :.:;.. i . ; ..; . ; .;;. : :; ;:           "  << endl;
    cout << " ::.   .  ;   i   ;:  ..  ;  :   i .  : . ;. ;  :   :  ;  .;      ; . ; . :. .: .; :i...   " << endl;
    cout << "    ;  :  .   ..  .  .;:. ;  .   : . i.  ;.  ; .;;. ;   :  ;  .i:..:: .::..i .;:.; 1t:::    " << endl;
    cout << " ;;:  : .;: .;: .;;. ::. .  .;:.. :   . :   :     .: . ;  .;      : . :   : .:;.i: :     :   " << endl;
    cout << " . : ;.    .      .  .    i  ..   ;  .i:.  i.  i  .:   :   :   i   ;   ; .;:.::;1. .  .        :" << endl;
    cout << "    .   ::.:;  :   ;: .i:   ..  i  .      . :      ::. .;   :       ;   ;  :  i 11: :  " << endl;
    cout << "     :;::  : .::. : .   . .:;.   .  i .  i .  i  . ;  :   .;   i   : .::. i.;:..      :.  " << endl;
    sleep_for(seconds(1));
    cout << "      . : : .:..: . :  :i  ::..  i              .::. .;;. :   .:   ;  ::.i.it  " << endl;
    cout << "        .  ::;  ;   ; .   . .:;. : . .;;... i  ..::  : . .;:. i . i .:;.i: ::: :   " << endl;
    cout << "           ;; ; :  :. : . i  :: ...;;... ::.. .;;... i   ;.       :.;::t: .... " << endl;
    cout << "          .   : :;  :       . i:.     .::.   : . ; .   ; .:;. ;: i: :i::: " << endl;
    cout << "                 .:i::: ;.::.:;.    : .;;. .  i .   : .:i..:;. :i.i1    .  : : " << endl;
    cout << "                : .    :;:: ::.; .;:.    i . :.:;..::. :; ;;;:. ::: " << endl;
    cout << "                        .;: : : :;:: ::.;   :: ; : ;::i:; :.1i .  .   " << endl;
    cout << "                          .  .;; :   :i:; : :1::  .;1:.   . ::   " << endl;
    cout << "                                .   . ; .  . ; .   . :: \x1b[0m   " << endl;

                sleep_for(seconds(1));
}