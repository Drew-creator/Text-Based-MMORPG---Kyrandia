#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cctype>

using namespace std;

/*
This game is a text-based action RPG. The goal of the game
is to clear all 3 of the floors in order to reach the king.
The different classes will have different special skill attacks.
Each class has strong special attacks and weaker special
attacks, but even the weaker special attacks will be stronger
than the regular attacks.Each floor has a boss you need to
clear in order to get to the next. Player has options to
train by fighting mobs. The monsters that show up, as
well as their level depend on your character level.
Each type of monster has different damage output. Character
damage is currently turned up for testing and grading purposes.
The same goes with the "rest" function.
*/

void newLine()
{
    char c, d;

    do
    {
        cin.get(c);

    } while (c != '\n');
}

//PRINTS 2D ARRAY
void print2DArray(char theMatrix[][21], int NumberUsed)
{
    cout << "=========================================\n";
    cout << "(W,S,A,D TO MOVE)\n";

    for(int i = 0; i < NumberUsed; i++)
    {
        for(int j = 0; j < 21; j++)
        {
            cout << theMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=========================================\n";
}

//INPUT VALIDATION!
void doInput (char& direction)
{
    bool isValid = true;

    do
    {
        cout << "Enter a direction: ";
        cin >> direction;

        if (cin.fail())
        {
            isValid = false;
            cin.clear();
        }
        else
        {
            isValid = true;

        }
        newLine();
    } while (!isValid);
}
// CHARACTER DAMAGE OUTPUT
int characterDamage (int& characterLevel)
{
    int damage = characterLevel * 20;
    return damage;
}
// CHARACTER HEALTH
int characterHealth (int& characterLevel)
{
    int playerHealth = characterLevel * 40;
    return playerHealth;

}

// ORIGNAL PLAYER HEALTH
int originalHealth(int playerLevel)
{
    int originalHP = playerLevel * 40;
    return originalHP;
}

// MENU FOR CLASS SKILLS. RETURNS A STRING VALUE FOR THE INPUT.
string specialMoves(int playerClass)
{
    int moveSelection = 0;

    if(playerClass == 1)
    {
        cout << "    |    [1] Soaring Strike             |\n";
        cout << "    |    [2] Quick Dash                 |\n";
        cout << "    |    [3] Charge Blade               |\n";
        cout << "    |    [4] Breakout                   |\n";
        cout << "    ------------------------------------\n";

        do
        {
            cout << "\nSELECTION: ";
            cin >> moveSelection;
        } while(moveSelection > 4);
        cout << endl;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> moveSelection;
        }


        if(moveSelection == 1)
            return "Soaring Strike";
        if (moveSelection == 2)
            return "Quick Dash";
        if(moveSelection == 3)
            return "Charge Blade";
        if (moveSelection == 4)
            return "Breakout";
    }

    if(playerClass == 2)
    {
        cout << "    |    [1] Flame Shot                 |\n";
        cout << "    |    [2] Arrow Eruption             |\n";
        cout << "    |    [3] Poison Arrow               |\n";
        cout << "    |    [4] Piercing Eye               |\n";
        cout << "    ------------------------------------\n";
        do
        {
            cout << "\nSELECTION: ";
            cin >> moveSelection;
        } while(moveSelection > 4);
        cout << endl;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> moveSelection;
        }

        if(moveSelection == 1)
            return "Flame Shot";
        if(moveSelection == 2)
            return "Arrow Eruption";
        if(moveSelection == 3)
            return "Poison Arrow";
        if(moveSelection == 4)
            return "Piercing Eye";
    }

    if(playerClass == 3)
    {
        cout << "    |    [1] Ray of Frost               |\n";
        cout << "    |    [2] Arcane Wave                |\n";
        cout << "    |    [3] Orb of Fire                |\n";
        cout << "    |    [4] Blood Wind                 |\n";
        cout << "    ------------------------------------\n";
        do
        {
            cout << "\nSELECTION: ";
            cin >> moveSelection;
        } while(moveSelection > 4);
        cout << endl;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> moveSelection;
        }

        if(moveSelection == 1)
            return "Ray of Frost";
        if(moveSelection == 2)
            return "Arcane Wave";
        if(moveSelection == 3)
            return "Orb of Fire";
        if(moveSelection == 4)
            return "Blood Wind";
    }

    if(playerClass == 4)
    {
        cout << "    |    [1] Backstab                   |\n";
        cout << "    |    [2] Bleed                      |\n";
        cout << "    |    [3] Fan of Knives              |\n";
        cout << "    |    [4] Agile Hunter               |\n";
        cout << "    ------------------------------------\n";
        do
        {
            cout << "\nSELECTION: ";
            cin >> moveSelection;
        } while(moveSelection > 4);
        cout << endl;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> moveSelection;
        }

        if(moveSelection == 1)
            return "Backstab";
        if(moveSelection == 2)
            return "Bleed";
        if(moveSelection == 3)
            return "Fan of Knives";
        if(moveSelection == 4)
            return "Agile Hunter";
    }
}

// TAKES THE STRING VALUE OF THE FUNCTION ABOVE AND GIVES IT DAMAGE.
int specialMoveDamage(int characterLevel, string specialMoveName)
{
    int moveDamage;

    if(specialMoveName == "Soaring Strike" )
    {
        moveDamage = characterLevel * 25;
        return moveDamage;
    }
    if(specialMoveName == "Quick Dash" )
    {
        moveDamage = characterLevel * 23;
        return moveDamage;
    }
    if(specialMoveName == "Charge Blade" )
    {
        moveDamage = characterLevel * 24;
        return moveDamage;
    }
    if(specialMoveName == "Breakout" )
    {
        moveDamage = characterLevel * 22;
        return moveDamage;
    }

    if(specialMoveName == "Flame Shot" )
    {
        moveDamage = characterLevel * 21;
        return moveDamage;
    }
    if(specialMoveName == "Arrow Eruption" )
    {
        moveDamage = characterLevel * 24;
        return moveDamage;
    }
    if(specialMoveName == "Poison Arrow" )
    {
        moveDamage = characterLevel * 22;
        return moveDamage;
    }
    if(specialMoveName == "Piercing Eye" )
    {
        moveDamage = characterLevel * 25;
        return moveDamage;
    }
    if(specialMoveName == "Ray of Frost" )
    {
        moveDamage = characterLevel * 22;
        return moveDamage;
    }
    if(specialMoveName == "Arcane Wave" )
    {
        moveDamage = characterLevel * 24;
        return moveDamage;
    }
    if(specialMoveName == "Orb of Fire" )
    {
        moveDamage = characterLevel * 22;
        return moveDamage;
    }
    if(specialMoveName == "Blood Wind" )
    {
        moveDamage = characterLevel * 25;
        return moveDamage;
    }
    if(specialMoveName == "Backstab" )
    {
        moveDamage = characterLevel * 22;
        return moveDamage;
    }
    if(specialMoveName == "Bleed" )
    {
        moveDamage = characterLevel * 21;
        return moveDamage;
    }
    if(specialMoveName == "Fan of Knives" )
    {
        moveDamage = characterLevel * 24;
        return moveDamage;
    }
    if(specialMoveName == "Agile Hunter" )
    {
        moveDamage = characterLevel * 25;
        return moveDamage;
    }

}

// FUNCTION FOR POTIONS
int amountOfPotionBottles(int potionBottles)
{
   ++potionBottles;

    return potionBottles;
}

// RANDOMIZED MONSTER LEVEL.
int monsterRandomLevel(int characterLevel)
{
    int monsterLevel = 0;
    int whichOne = 0;
    srand(time(0));

    whichOne = rand() % 1;

    if (characterLevel <= 4)
        monsterLevel = rand() % 3 + characterLevel;

    if (characterLevel > 4)
    {
        if (whichOne == 0)
            monsterLevel = rand() % 4 + characterLevel;
        if (whichOne == 1 && characterLevel >= 7)
            monsterLevel = rand() % (characterLevel - 7) + characterLevel;
    }
    return monsterLevel;
}

// RETURNS THE A MONSTERS NAME WHEN CALLED. MONSTERS ARE CALLED RANDOMLY DEPENDING ON CHARACTER LEVEL.
string theTypeOfMonster(int characterLevel)
{
    int whichMonster = 0;

    srand(time(0));

    if (characterLevel < 5)
    {
        whichMonster = rand() % 3;

        if(whichMonster == 0)
            return "Blood Lizard";
        if(whichMonster == 1)
            return "Wyvern";
        if (whichMonster == 2)
            return "Bandit";
    }
    if (characterLevel >= 5 && characterLevel < 10)
    {
        whichMonster = rand() % 3;

        if(whichMonster == 0)
            return "Ice Dragon";
        if(whichMonster == 1)
            return "Azure Golem";
        if (whichMonster == 2)
            return "Giant";
    }
    if (characterLevel >= 10)
    {
        whichMonster = rand() % 3;

        if(whichMonster == 0)
            return "Giant Skeleton";
        if(whichMonster == 1)
            return "Ancient Golem";
        if (whichMonster == 2)
            return "Behemoth";
    }
}

// DEPENDING ON STRING VALUE RETURNED ABOVE, THIS FUNCTION WILL RETURN A DAMAGE VALUE FOR WHATEVER THE MONSTER IS.
int monstersDamage (int monsterLevel, int characterLevel, string typeOfMonster)
{
    int monsterDamage = 0;

    srand(time(0));

    //typeOfMonster = theTypeOfMonster(characterLevel);
    //monsterLevel = monsterRandomLevel(characterLevel);

    if (typeOfMonster == "Blood Lizard")
    {
        monsterDamage = rand() % (monsterLevel * 1) + 1;
        return monsterDamage;
    }
    if (typeOfMonster == "Wyvern")
    {
        monsterDamage = rand() % (monsterLevel * 1) + 1;
        return monsterDamage;
    }
    if (typeOfMonster == "Bandit")
    {
        monsterDamage = rand() % (monsterLevel * 1) + 1;
        return monsterDamage;
    }

    if (typeOfMonster == "Ice Dragon")
    {
        monsterDamage = rand() % (monsterLevel * 4) + monsterLevel;
        return monsterDamage;
    }

    if (typeOfMonster == "Azure Golem")
    {
        monsterDamage = rand() % (monsterLevel * 2) + monsterLevel;
        return monsterDamage;
    }

    if (typeOfMonster == "Giant")
    {
        monsterDamage = rand() % (monsterLevel * 3) + monsterLevel;
        return monsterDamage;
    }

    if (typeOfMonster == "Giant Skeleton")
    {
        monsterDamage = rand() % (monsterLevel * 4) + monsterLevel;
        return monsterDamage;
    }

    if (typeOfMonster == "Ancient Golem")
    {
        monsterDamage = rand() % (monsterLevel * 2) + monsterLevel;
        return monsterDamage;
    }


    if (typeOfMonster == "Behemoth")
    {
        monsterDamage = rand() % (monsterLevel * 5) + monsterLevel;
        return monsterDamage;
    }
}

// FUNCION FOR PLAYER EXP. EACH MONSTER GIVES DIFFERENT AMOUNTS OF EXP.
int playerExp (string typeOfMonster, int monsterLevel)
{
    int playerExpGained = 0;

    if (typeOfMonster == "Blood Lizard")
    {
        playerExpGained = monsterLevel * 2;
        return playerExpGained;
    }
    if (typeOfMonster == "Wyvern")
    {
       playerExpGained = monsterLevel * 3;
       return playerExpGained;
    }
    if (typeOfMonster == "Bandit")
    {
       playerExpGained = monsterLevel * 3;
       return playerExpGained;
    }

    if (typeOfMonster == "Ice Dragon")
    {
        playerExpGained = monsterLevel * 3;
        return playerExpGained;
    }

    if (typeOfMonster == "Azure Golem")
    {
        playerExpGained = monsterLevel * 2;
        return playerExpGained;
    }

    if (typeOfMonster == "Giant")
    {
        playerExpGained = monsterLevel * 3;
        return playerExpGained;
    }

    if (typeOfMonster == "Giant Skeleton")
    {
        playerExpGained = monsterLevel * 4;
        return playerExpGained;
    }

    if (typeOfMonster == "Ancient Golem")
    {
        playerExpGained = monsterLevel * 4;
        return playerExpGained;
    }

    if (typeOfMonster == "Behemoth")
    {
        playerExpGained = monsterLevel * 5;
        return playerExpGained;
    }
}

// THE TOTAL AMOUNT OF EXP THE PLAYER NEEDS TO LEVEL UP
int characterExpTotal (int& characterLevel, int playerExpGained)
{
    int expTotal;
    expTotal += (playerExpGained * 0.4);

    return expTotal;
}

//THIS FUNCTION HOLDS THE CHOICES MENU, FOR DIFFERENT OPTIONS DURING THE GAME.
void choices(int& characterLevel, int monsterLevel, int& characterHealth, int characterDamage, int monsterDamage, string typeOfMonster, int playerExpGained, int characterExpTot, int& amountOfPotions, int originalHP, string characterName, int playerClass, string specialMoveName, int potionBottles)
{
    int choice = 0;
   // string typeOfMonster = theTypeOfMonster(characterLevel);
    //monsterLevel = monsterRandomLevel(characterLevel);
    int monsterHealth = monsterLevel * 10;
    char attack;
    char shopSelection;
    int playerPotions = 0;
    int expTotal = 0;
    int counter = 0;
    int specialDamage = 0;

    if (characterLevel < 5)
        monsterHealth = monsterLevel * 7;

    //cout << monsterHealth << " " << monsterLevel << " " << typeOfMonster << endl;

    cout << "\n__________________________________________\n";
    cout << "\n\nCurrent Character Level: " << characterLevel;
    cout << "\nCharacter HP: " << characterHealth << "/" << originalHP << endl;

    cout << "\nWhat would you like to do?\n\n";
    cout << "    |    1) Train by fighting mobs     |\n";
    cout << "    |    2) Shop                       |\n";
    cout << "    |    3) Use a potion               |\n";
    cout << "    |    4) Rest                       |\n";
    cout << "    ------------------------------------\n";
    cout << "SELECTION: ";
    cin >> choice;

    while(!cin)
    {
        cout << "Invalid Input!\n\nSELECTION: ";
        cin.clear();
        cin.ignore();
        cin >> choice;
    }

    switch(choice)
    {
        case 1: cout << "============================================================================\n";
             cout << "\nYou run into a level " << monsterLevel << " " << typeOfMonster << ".\n\n";
             while (monsterHealth > 0 && characterHealth > 0)
                {
                    cout << typeOfMonster << "HP: " << monsterHealth << endl;
                    cout << "Character HP: " << characterHealth << "/" << originalHP << endl;
                    cout << endl;
                    /*if (attack == 'a' || attack == 'A')
                    {
                        monsterHealth -= characterDamage;
                        characterHealth = characterHealth - monsterDamage;
                    }*/

                    cout << "===========================\n";
                    cout << "[a] Normal Attack\n";
                    cout << "[s] Special Move Menu\n";
                    cout << "===========================\n";
                    cout << "SELECTION: ";
                    cin >> attack;
                    cout << endl;

                    switch(attack)
                    {
                        case 'a':
                        case 'A': monsterHealth -= characterDamage;
                                  characterHealth = characterHealth - monsterDamage;

                                  cout << characterName << " does " << characterDamage << " damage.\n";
                                  cout << typeOfMonster << " does " << monsterDamage << " damage.\n\n";
                                  break;
                        case 's':
                        case 'S':   specialMoveName = specialMoves(playerClass);
                                    specialDamage = specialMoveDamage(characterLevel, specialMoveName);

                                    monsterHealth -= specialDamage;
                                    characterHealth = characterHealth - monsterDamage;

                                    cout << characterName << " does " << specialDamage << " damage.\n";
                                    cout << typeOfMonster << " does " << monsterDamage << " damage.\n\n";
                                    break;


                    }

                }

                if(characterHealth > monsterHealth)
                {
                    cout << typeOfMonster << " defeated!\n";
                    cout << playerExpGained << " EXP gained.\n";

                    expTotal = characterExpTotal(characterLevel, playerExpGained);

                    if (expTotal > characterLevel * 2)
                    {
                        characterLevel += 1;
                        cout << "Level up! You are now level " << characterLevel << ". ";

                    }

                    // add money as well.
                }
                else
                {
                    cout << R"(


                                      YOU DIED!

                                     /#######
                                   #######  ###*          %
                                    ####.     ###/      .***
                                   ####        @##     ,***  ,,
                                  ###@@(@@ .@@,@    (%   **  .,
                                  ###%@@% *. %@@##   .%      **  *
                                   *####&@&&@@###/   %         **  *
                                      (########.    (,          **  *
                                    ##############  %             ** *
                                   ,###########%###%/              ,* .
                                   ############@###%                 * ,
                                  ###@############%###                * *
                                 ####@#########.,. ####                *
                                 ###@@#########(.*,@##*     ...         *,
                                 #####&%%%#%%#%##%@@@%%######  .#*       *.
                                 ,#######%%%%%%%##@@@@@@%#.,(#            *
                                   ##, ,/.%%%%%%%%#########               *
                                   (#@/  ((####%%%%%##. .
                                     #%%%###%%%###%%%%%%
                                    %#/#(   (#%%%%%,   *%(
                                  %#          %%%#%##%
                               *%.              */
                             %%
                          /% )" << endl;

                    cout << "\nYou revive on the same floor\n";

                    characterHealth = originalHP;

                }

                break;

        case 2: cout << "\n\nYou find a merchant inside of the castle.\n";
                cout << "Would you like to ask for a potion? (Y/N)\n";
                cout << "SELECTION: ";
                cin >> shopSelection;

                if (shopSelection == 'y' || shopSelection == 'Y')
                {
                    amountOfPotions = amountOfPotionBottles(potionBottles);
                    //counter++;

                    cout << "Potions: " << amountOfPotions << endl;
                }
                break;

        case 3: if (amountOfPotions >= 1 && characterHealth < characterLevel * 40)
                {
                    if(characterHealth + 20 < originalHP)
                    {
                        characterHealth += 20;
                        cout << "+20 HP recovered!\n" << "CHARACTER HP: " << characterHealth << "/" << originalHP << endl;
                        amountOfPotions -= 1;
                    }
                    else
                        characterHealth = originalHP;
                }
                else if(amountOfPotions < 1)
                    cout << "Out of potions!\n";
                /*else if(characterHealth + 20 > originalHP)
                    characterHealth = originalHP;*/
                else
                    cout << "HP is full!\n";

                break;

        case 4: characterHealth = originalHP;
                cout << "\nYou rest inside of a room to recover.\n";
                cout << "CHARACTER HP: " << characterHealth << "/" << originalHP << endl;
                break;

    }


}

// THE FIRST FLOOR BOSS
bool firstFloorBoss (int& characterLevel, int& characterHealth, int playerAttack, int originalHP, int playerClass, string specialMoveName, string characterName)
{
    char choice;
    char attack;
    int bossOneHealth = 100;
    int bossOneAttack = 0;
    int specialDamage = 0;

    srand(time(0));

    bossOneAttack = rand() % 11 + 10;

    if (characterLevel >= 5)
    {
        cout << "\n\n=====================================================================================================================================\n";
        cout << "\n\nYou find Coldreaver, one of the kings generals guarding the path to the next floor. He is one of the high ranking commanders under the king.\n";
        cout << "Fight the boss? (Y/N)\n";
        cout << "SELECTION: ";
        cin >> choice;
        cout << "=====================================================================================================================================\n";

        if (choice == 'Y' || choice == 'y')
        {

            while(characterHealth > 0 && bossOneHealth > 0)
            {
                cout << "\nColdreaver HP: " << bossOneHealth << endl;
                cout << "Character HP: " << characterHealth << "/" << originalHP << endl;

                cout << "===========================\n";
                cout << "[a] Normal Attack\n";
                cout << "[s] Special Move Menu\n";
                cout << "===========================\n";
                cout << "SELECTION: ";
                cin >> attack;
                cout << endl;

                switch(attack)
                {
                    case 'a':
                    case 'A': bossOneHealth -= playerAttack;
                              characterHealth -= bossOneAttack;

                              cout << characterName << " does " << playerAttack << " damage.\n";
                              cout <<"Coldreaver does " << bossOneAttack << " damage.\n\n";
                              break;
                    case 's':
                    case 'S':   specialMoveName = specialMoves(playerClass);
                                specialDamage = specialMoveDamage(characterLevel, specialMoveName);

                                bossOneHealth -= specialDamage;
                                characterHealth -= bossOneAttack;

                                cout << characterName << " does " << specialDamage << " damage.\n";
                                cout <<"Coldreaver does " << bossOneAttack << " damage.\n\n";
                                break;


                }



            }

            if (bossOneHealth <= 0)
            {
                cout << "\nYou have defeated the commander Coldreaver!\nYou then proceed to the next floor.\n";
                return false;
            }
            else if(bossOneHealth <= 0 && characterHealth <= 0)
            {
                cout << "\nDraw! Both you and the Coldreaver have fallen, but you revive. Some soldiers inside the castle that were loyal to your family have found you and treated you.\n";
                characterHealth = originalHP;
                return false;
            }
            else
            {
                cout << R"(


                                      YOU DIED!

                                     /#######
                                   #######  ###*          %
                                    ####.     ###/      .***
                                   ####        @##     ,***  ,,
                                  ###@@(@@ .@@,@    (%   **  .,
                                  ###%@@% *. %@@##   .%      **  *
                                   *####&@&&@@###/   %         **  *
                                      (########.    (,          **  *
                                    ##############  %             ** *
                                   ,###########%###%/              ,* .
                                   ############@###%                 * ,
                                  ###@############%###                * *
                                 ####@#########.,. ####                *
                                 ###@@#########(.*,@##*     ...         *,
                                 #####&%%%#%%#%##%@@@%%######  .#*       *.
                                 ,#######%%%%%%%##@@@@@@%#.,(#            *
                                   ##, ,/.%%%%%%%%#########               *
                                   (#@/  ((####%%%%%##. .
                                     #%%%###%%%###%%%%%%
                                    %#/#(   (#%%%%%,   *%(
                                  %#          %%%#%##%
                               *%.              */
                             %%
                          /% )" << endl;

                    cout << "\nYou revive on the same floor\n";

                characterHealth = originalHP;

                return true;
            }

        }
    }
}

//make random num generator to generate monster name as well. for all monsters, add rand() % (monsterLevel * 3) or something like that for different damage for each monster.

// SECOND FLOOR BOSS
bool secondFloorBoss (int& characterLevel, int& characterHealth, int playerAttack, int originalHP, int playerClass, string specialMoveName, string characterName)
{
    char choice;
    char attack;
    int bossTwoHealth = 300;
    int bossTwoAttack = 0;
    int specialDamage = 0;

    srand(time(0));

    bossTwoAttack = rand() % 16 + 35;

    if (characterLevel >= 10)
    {
        cout << "\n\n=====================================================================================\n";
        cout << "The king's personal guard, Jourgen Skyslayer is in front of the stairs leading up to the third floor.\n";
        cout << "Fight the boss? (Y/N)\n";
        cout << "SELECTION: ";
        cin >> choice;
        cout << "=====================================================================================\n";


        if (choice == 'Y' || choice == 'y')
        {

            while(characterHealth > 0 && bossTwoHealth > 0)
            {
                cout << "\nSkyslayer: " << bossTwoHealth << endl;
                cout << "Character HP: " << characterHealth << "/" << originalHP << endl;

                cout << "===========================\n";
                cout << "[a] Normal Attack\n";
                cout << "[s] Special Move Menu\n";
                cout << "===========================\n";
                cout << "SELECTION: ";
                cin >> attack;
                cout << endl;

                switch(attack)
                {
                    case 'a':
                    case 'A': bossTwoHealth -= playerAttack;
                              characterHealth -= bossTwoAttack;

                              cout << characterName << " does " << playerAttack << " damage.\n";
                              cout <<"Skyslayer does " << bossTwoAttack << " damage.\n\n";
                              break;
                    case 's':
                    case 'S':   specialMoveName = specialMoves(playerClass);
                                specialDamage = specialMoveDamage(characterLevel, specialMoveName);

                                bossTwoHealth -= specialDamage;
                                characterHealth -= bossTwoAttack;

                                cout << characterName << " does " << specialDamage << " damage.\n";
                                cout << "Skyslayer does " << bossTwoAttack << " damage.\n\n";
                                break;


                }


            }

            if (bossTwoHealth <= 0)
            {
                cout << "\nYou have defeated Skyslayer!\nYou then proceed to the next floor.\n";
                return false;
            }
            else if(bossTwoHealth <= 0 && characterHealth <= 0)
            {;
                cout << "\nDraw! Both you and Skyslayer have fallen, but you revive. Some soldiers inside the castle that were loyal to your family have found you and treated you.\n";
                characterHealth = originalHP;
                return false;
            }
            else
            {
                cout << R"(


                                      YOU DIED!

                                     /#######
                                   #######  ###*          %
                                    ####.     ###/      .***
                                   ####        @##     ,***  ,,
                                  ###@@(@@ .@@,@    (%   **  .,
                                  ###%@@% *. %@@##   .%      **  *
                                   *####&@&&@@###/   %         **  *
                                      (########.    (,          **  *
                                    ##############  %             ** *
                                   ,###########%###%/              ,* .
                                   ############@###%                 * ,
                                  ###@############%###                * *
                                 ####@#########.,. ####                *
                                 ###@@#########(.*,@##*     ...         *,
                                 #####&%%%#%%#%##%@@@%%######  .#*       *.
                                 ,#######%%%%%%%##@@@@@@%#.,(#            *
                                   ##, ,/.%%%%%%%%#########               *
                                   (#@/  ((####%%%%%##. .
                                     #%%%###%%%###%%%%%%
                                    %#/#(   (#%%%%%,   *%(
                                  %#          %%%#%##%
                               *%.              */
                             %%
                          /% )" << endl;

                    cout << "\nYou revive on the same floor\n";

                    characterHealth = originalHP;

                return true;
            }

        }
    }
}

// FINAL BOSS
bool thirdFloorBoss (int& characterLevel, int& characterHealth, int playerAttack, int originalHP, int playerClass, string specialMoveName, string characterName)
{
    char choice;
    char attack;
    int bossThreeHealth = 700;
    int bossThreeAttack = 0;
    int specialDamage = 0;

    srand(time(0));

    bossThreeAttack = rand() % 16 + 55;

        while(characterHealth > 0 && bossThreeHealth > 0)
        {
            cout << "\nBOSS 3 Health: " << bossThreeHealth << endl;
            cout << "Character HP: " << characterHealth << "/" << originalHP << endl;

            cout << "===========================\n";
            cout << "[a] Normal Attack\n";
            cout << "[s] Special Move Menu\n";
            cout << "===========================\n";
            cout << "SELECTION: ";
            cin >> attack;
            cout << endl;

            switch(attack)
            {
                case 'a':
                case 'A': bossThreeHealth -= playerAttack;
                          characterHealth -= bossThreeAttack;

                          cout << characterName << " does " << playerAttack << " damage.\n";
                          cout << "King Skullmane does " << bossThreeAttack << " damage.\n\n";
                          break;
                case 's':
                case 'S':   specialMoveName = specialMoves(playerClass);
                            specialDamage = specialMoveDamage(characterLevel, specialMoveName);

                            bossThreeHealth -= specialDamage;
                            characterHealth -= bossThreeAttack;

                            cout << characterName << " does " << specialDamage << " damage.\n";
                            cout << "King Skullmane does " << bossThreeAttack << " damage.\n\n";
                            break;


            }


        }

        if (bossThreeHealth <= 0)
            return false;

        else if(bossThreeHealth <= 0 && characterHealth <= 0)
        {
            cout << "\nDraw! Both you and king Skullmane have fallen, but you revive. Some soldiers inside the castle that were loyal to your family have found you and treated you.\n";
            characterHealth = originalHP;
            return false;
        }
        else
        {
            cout << R"(


                                  YOU DIED!

                                 /#######
                               #######  ###*          %
                                ####.     ###/      .***
                               ####        @##     ,***  ,,
                              ###@@(@@ .@@,@    (%   **  .,
                              ###%@@% *. %@@##   .%      **  *
                               *####&@&&@@###/   %         **  *
                                  (########.    (,          **  *
                                ##############  %             ** *
                               ,###########%###%/              ,* .
                               ############@###%                 * ,
                              ###@############%###                * *
                             ####@#########.,. ####                *
                             ###@@#########(.*,@##*     ...         *,
                             #####&%%%#%%#%##%@@@%%######  .#*       *.
                             ,#######%%%%%%%##@@@@@@%#.,(#            *
                               ##, ,/.%%%%%%%%#########               *
                               (#@/  ((####%%%%%##. .
                                 #%%%###%%%###%%%%%%
                                %#/#(   (#%%%%%,   *%(
                              %#          %%%#%##%
                           *%.              */
                         %%
                      /% )" << endl;

                cout << "\nYou revive on the same floor\n";

                characterHealth = originalHP;

            return true;
        }
}


int main()
{
    //remember to add another switch menu for main menu before character creation. For options make character creation. load game. exit game using exit(1);
    ifstream inputFile;
    ofstream outputFile;
    char outFile[100];
    string characterName;
    char welcomeArray[20] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', ' ', 'T', 'O', ' ', 'K', 'Y', 'R', 'A', 'N', 'D', 'I', 'A'};
    int characterRace = 0;
    int mainMenuChoice = 0;
    int startingClass = 0;
    int characterLevel = 1, monsterLevel = 0;
    int charactersHealth = 0, charactersDamage = 0, monsterDamage = 0, playerExpGained = 0, originalHp = 0;
    int characterExpTot = 0;
    int potionBottles = 0;
    int cup1 = 0, cup2 = 0, cup3 = 0, miniGameGuess = 0;
    int whichCupRandomNum = 0;
    int amountOfPotions = 0;
    string specialMoveName;
    string typeOfMonster;
    char theMatrix[21][21] = { {"xxxxMxxxxMxxxxMxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"MxxxxxxxxxxxxxxxxxxM"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxxxxxxxxxxxxx"},
                            {"xxxxxxxxAxxxxxxxxxxx"},
                        };

    cout << "========================\n";
    cout << "   ";
    for (int i = 0; i < 19; i++)
    {
        cout << welcomeArray[i];
        Sleep(80);
    }

    cout << "  |";
    cout << "\n========================\n";

    cout << R"(                _
               ( )
               |=|
               |=|
           /|__|_|__|\
          (    ( )    )
           \|\/\|/\/|/
             |  |  |
             |  |  |
             |  |  |
            _|  |  |
         __/ |  |  |\\
        /  \ |  |  |  \\
           __|  |  |   |
        /\/  |  |  |   |\
         /   .\ |  |\ />  \
         | >   + \  | \    |
                + \|.  \  < \
          (|)      +    |    )
           |             \  /\
         ( | )   (|)      \/  )
        _\\|/__( | )______)_/
                \\|./  )" << endl;;







    cout << "[1] Start New Game\n" << "[2] Exit Game\n\n" << "SELECTION: ";
    cin >> mainMenuChoice;

    switch(mainMenuChoice)
    {
        case 1: cout << R"(                          (                    (           )          (  )       )
       (    ( /(   (      )\ )    (        (     *   )      )\ )     (    )\ )       (       *   ) )\ )  ( /(   ( /(
       )\   )\())  )\    (()/(    )\       )\  ` )  /( (   (()/(     )\  (()/( (     )\    ` )  /((()/(  )\())  )\())
     (((_) ((_)\((((_)(   /(_))((((_)(   (((_)  ( )(_)))\   /(_))  (((_)  /(_)))\ ((((_)(   ( )(_))/(_))((_)\  ((_)\
     )\___  _((_))\ _ )\ (_))   )\ _ )\  )\___ (_(_())((_) (_))    )\___ (_)) ((_) )\ _ )\ (_(_())(_))    ((_)  _((_)
    ((/ __|| || |(_)_\(_)| _ \  (_)_\(_)((/ __||_   _|| __|| _ \  ((/ __|| _ \| __|(_)_\(_)|_   _||_ _|  / _ \ | \| |
     | (__ | __ | / _ \  |   /   / _ \   | (__   | |  | _| |   /   | (__ |   /| _|  / _ \    | |   | |  | (_) || .` |
      \___||_||_|/_/ \_\ |_|_\  /_/ \_\   \___|  |_|  |___||_|_\    \___||_|_\|___|/_/ \_\   |_|  |___|  \___/ |_|\_| )" << endl;

                break;
        case 2: break;
        case 3: exit(1);
                break;
    }

    cout << "_______________________________________________________________________________________________________________________\n";

    if (mainMenuChoice == 1)
    {
        cout << "\nPlease enter your character name: ";
        cin >> characterName;
        cout << "\n_______________________________________________________________\n";
        cout << "Choose your character race. (Select the corresponding numbers)\n\n" << "     -----------------\n";
        cout << "    |    [1] Human     |\n";
        cout << "    |    [2] Elf       |\n";
        cout << "    |    [3] Orc       |\n";
        cout << "    |    [4] Half-Elf  |\n";
        cout << "    |    [5] Halfling  |\n";
        cout << "     -----------------\n";
        cout << "SELECTION: ";
        cin >> characterRace;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> characterRace;
        }

        switch(characterRace)
        {
            case 1: cout << "You chose: Human\n";
                    break;
            case 2: cout << "You chose: Elf\n";
                    break;
            case 3: cout << "You chose: Orc\n";
                    break;
            case 4: cout << "You chose: Half-Elf\n";
                    break;
            case 5: cout << "You chose: Halfling\n";
                    break;
        }

        cout << "\n_______________________________________________________________\n";
        cout << "Choose your starting class.(Select the corresponding numbers)\n\n" << "     -----------------\n";
        cout << "    |    [1] Warrior  |\n";
        cout << "    |    [2] Archer   |\n";
        cout << "    |    [3] Mage     |\n";
        cout << "    |    [4] Rouge    |\n";
        cout << "     -----------------\n";
        cout << "SELECTION: ";
        cin >> startingClass;

        while(!cin)
        {
            cout << "Invalid Input!\n\nSELECTION: ";
            cin.clear();
            cin.ignore();
            cin >> startingClass;
        }

        switch (startingClass)
        {
            case 1: cout << "Starting Class: Warrior\n";
                    break;
            case 2: cout << "Starting Class: Archer\n";
                    break;
            case 3: cout << "Starting Class: Mage\n";
                    break;
            case 4: cout << "Starting Class: Rogue\n";
                    break;
        }
        //outputFile.open(outFile, ios::app);

        cout << "\nEnter a name for your save file (end the name with .txt): ";
        cin >> outFile;

        outputFile.open(outFile);

        cout << "======================================================\n";

        cout << "\nCharacter Name: " << characterName << "\n" << "Starting Race: " << characterRace << "\n" << "Starting Class: " << startingClass << "\n";
        outputFile << "Character Name: " << characterName << "\n" << "Starting Race: " << characterRace << "\n" << "Starting Class: " << startingClass << "\n";
        outputFile.close();
        cout << "\nThe new high king of Kyrandia has overthrown your family and assassinated them.\nYou were away from your family during all of this chaos.\n";
        cout << "Clear all the floors in order to defeat the high king and his men in order to reclaim the throne and restore your family's name.\n";

        cout << "\nYou are currently in the capital city of Khaehport\n";
        cout <<  "You enter the first floor of the castle\n";

        charactersHealth = characterHealth(characterLevel);

        do
        {
            charactersDamage = characterDamage(characterLevel);
            originalHp = originalHealth(characterLevel);
            monsterLevel = monsterRandomLevel(characterLevel);
            typeOfMonster = theTypeOfMonster(characterLevel);
            monsterDamage = monstersDamage(monsterLevel, characterLevel, typeOfMonster);
            playerExpGained = playerExp(typeOfMonster, monsterLevel);

            outputFile.open(outFile, ios::app);
            outputFile << "Highest Character Level(high score): " << characterLevel << endl;
            outputFile.close();
            choices(characterLevel, monsterLevel, charactersHealth, charactersDamage, monsterDamage, typeOfMonster, playerExpGained, characterExpTot, amountOfPotions, originalHp, characterName, startingClass, specialMoveName, potionBottles);
        } while(firstFloorBoss(characterLevel, charactersHealth, charactersDamage, originalHp, startingClass, specialMoveName, characterName));

        cout << "================================================================================================================\n";
        cout << "While going up the stairs, you encounter a strange man. He asks you to participate in a game and you agree.\n";
        cout << "There are 3 cups, can you guess which one the poison is in?\n";

        // MINI GAME. GUESS WHICH COIN THE CUP IS IN.

        cout << R"(
                CUP 1
             ,|`----`|
            ((|      |
             \|      |
              |      |
              '------'

                CUP 2
             ,|`----`|
            ((|      |
             \|      |
              |      |
              '------'

                CUP 3
             ,|`----`|
            ((|      |
             \|      |
              |      |
              '------')" << endl;

        do
        {

            srand(time(0));
            whichCupRandomNum = rand() % 3 + 1;

            cout << "Enter your guess (1, 2, 3): ";
            cin >> miniGameGuess;

            while(!cin)
            {
                cout << "Invalid Input!\n\nSELECTION: ";
                cin.clear();
                cin.ignore();
                cin >> miniGameGuess;
            }

            if (miniGameGuess == whichCupRandomNum)
            {
                cout << "\nCorrect! You can move on to the next floor\n";
            }
            else
                cout << "Wrong! Try again and I will let you pass\n\n";

        } while(miniGameGuess != whichCupRandomNum);

        // FLOOR 2

        cout << "You are now on the second floor.\n";

        do
        {

            originalHp = originalHealth(characterLevel);
            monsterLevel = monsterRandomLevel(characterLevel);
            typeOfMonster = theTypeOfMonster(characterLevel);
            monsterDamage = monstersDamage(monsterLevel, characterLevel, typeOfMonster);
            playerExpGained = playerExp(typeOfMonster, monsterLevel);
            //specialMoveName = (specialMoves(startingClass));

            outputFile.open(outFile, ios::app);
            outputFile << "Highest Character Level(high score): " << characterLevel << endl;
            outputFile.close();
            choices(characterLevel, monsterLevel, charactersHealth, charactersDamage, monsterDamage, typeOfMonster, playerExpGained, characterExpTot, amountOfPotions, originalHp, characterName, startingClass, specialMoveName, potionBottles);

        } while(secondFloorBoss(characterLevel, charactersHealth, charactersDamage, originalHp, startingClass, specialMoveName, characterName));

        cout << "========================================================================\n";

        cout << "You move on to the next floor, but there are 5 different entrances(The doors are the five ""M""). Move to the door you want to use.(incorrect doors will disappear)\n\n";

        print2DArray(theMatrix, 21);
        int xPos(13), yPos(8);

        do
        {
            char direction;
            doInput(direction);

            switch (direction)
            {
                case 'w':
                case 'W': if(xPos > 0)
                        {
                            xPos --;
                            theMatrix[xPos][yPos] = 'A';
                            theMatrix[xPos + 1][yPos] = 'x';
                            print2DArray(theMatrix, 21);
                        }
                        else
                            cout << "\nPlease move in a different direction!\n";
                        break;
                case 's':
                case 'S': if(xPos < 13)
                        {
                            xPos++;
                            theMatrix[xPos][yPos] = 'A';
                            theMatrix[xPos - 1][yPos] = 'x';
                            print2DArray(theMatrix, 21);

                        }
                        else
                            cout << "\nPlease move in a different direction!\n";
                        break;
                case 'a':
                case 'A': if(yPos > 0)
                        {
                            yPos --;
                            theMatrix[xPos][yPos] = 'A';
                            theMatrix[xPos][yPos + 1] = 'x';
                            print2DArray(theMatrix, 21);
                        }
                        else
                            cout << "\nPlease move in a different direction!\n";
                        break;
                case 'd':
                case 'D': if(yPos < 19)
                          {
                            yPos++;
                            theMatrix[xPos][yPos] = 'A';
                            theMatrix[xPos][yPos - 1] = 'x';
                            print2DArray(theMatrix, 21);
                          }
                        else
                            cout << "\nPlease move in a different direction!\n";
                        break;
            }

            if(xPos == 0 && yPos == 9)
                cout << "This door was created by an illusion spell! Try the other doors.\n";
            if(xPos == 7 && yPos == 0)
                cout << "This door was created by an illusion spell! Try the other doors.\n";
            if(xPos == 7 && yPos == 19)
                cout << "This door was created by an illusion spell! Try the other doors.\n";
            if(xPos == 0 && yPos == 14)
                cout << "This door was created by an illusion spell! Try the other doors.\n";


        } while(xPos != 0 || yPos != 4);

        cout << "You have found the correct door!\n";
        cout << "\nYou move on to the next floor, and see the King Skullmane on his throne.\n";

        // THIRD FLOOR

        cout << R"(                             (@@@@@@@@@@@@@,
                            @@ ,@@@@@@@ @@*
                            .%  @@@@@@@  @
                               @@@@@@@@
                           @@@@@@@@@@@@@,
                        .@@@@@@@@@@@@@@@@@@@%
                       @@@@@@@@@@@@@@@@@@@@@@@/
                       @@@@@@@@@@@@@@@@@@@@@@@@
                     @@@@@@@@@@@@@@@@@@@@@@@@@@
                       @@@@@@@@@@@@@@@@@@@@@@@@@
                       @@@@@@@@@@@@@@@@@@@@@@@@@
                      @@@@@ @@@@@@@@@@@@@@@ @@@@@
                    #@@@@@@ @@@@@@@@@@@@@@@  @@@@@@.
                    @@@@@@ &@@@@@@@@@@@@@@@@.@@@@@@@
                   @@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@
                   @@@@@@   @@@@@@@@@@@@@@@@@,@@@@@@
                  @@@@@@   @@@@@@@@@@@@@@@@@@@  @@@@@
                 @@@@@@   @@@@@@@@@@@@@@@@@@@@* @@@@@
                 @@@@*%  *@@@@@@@@@@@@@@@@@@@@  @@@@
                 @@@@    @@@@@@@@@@@@@@@@@@@@@@ @@@@
                 @@     @@@@@@@@@@@@@@@@@@@@@@&@@%@@
                @@     @@@@@@@@@@@@@@@@@@@@@@@@   @@/
               .@    ,@@@@@@@@@@@@@@@@@@@@@@@@@@   @@
               @,   /@@@@@@@@@@@@@@@@@@@@@@@@@@@.  @@@
              @/   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ,@@
             &,   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    @@@
                 #@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@&    @@
                  (@@@@@@@@@@@@ @      @@@@@@@@@@    @@@
                    (@@@@@@@@@@#       %@@@@@@@@      @@
                       @@@@@@@@          @@@@@@@      @@@
                       @@@@@@%           @@@@@@@@      @@
                       @@@@@@            %@@@@@         @@
                       @@@@@              @@@@@ %.%      /
                      @@@@@@              @@@@*
                    @@@@@@@@              @@@@,
                 @@@@@@@@@                @@@@@
                 @@@@                     @@@,
                                                )";







        do
        {
            originalHp = originalHealth(characterLevel);

        } while(thirdFloorBoss(characterLevel, charactersHealth, charactersDamage, originalHp, startingClass, specialMoveName, characterName));


        cout << "King Skullmane falls, and you reclaim the throne.\n\n";
        cout << R"(                                             ____
                      ( /(                          |   /
                      )\())     (    (  (  (        |  /
                     ((_)\ (   ))\   )\))( )\  (    | /
                    __ ((_))\ /((_) ((_)()((_) )\ ) |/
                    \ \ / ((_|_))(  _(()((_|_)_(_/((
                     \ V / _ \ || | \ V  V / | ' \))\
                      |_|\___/\_,_|  \_/\_/|_|_||_((_))";

    }

}

