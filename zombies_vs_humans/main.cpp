
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int getNumHumans();
int getNumZombies();
void simulateAttack (int &numHumans, int &numZombies);
void printOutcome(int startH, int startZ, int numHumans, int numZombies);

int main() {
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    cout << CLEAR_TERMINAL;
    cout << "*** ZOMBIES VS HUMANS SIMULATION *** \n\n";

    int numHumans = 0;
    int numZombies = 0;
    
    numHumans = getNumHumans();
    numZombies = getNumZombies();
    
    int startH = numHumans;
    int startZ = numZombies;
    
    cout << "\n<< SIMULATING >>" << endl << endl;
    simulateAttack (numHumans, numZombies);
    printOutcome(startH, startZ, numHumans, numZombies);

    return 0;
}

int getNumHumans()
{
    int numHumans = 0;
    cout << "Enter the number of humans: ";
    cin >> numHumans;
    while (cin.fail()) {
        cout << "Input must be a number.\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter the number of humans: ";
        cin >> numHumans;
    }
    return numHumans;
}

int getNumZombies()
{
    int numZombies = 0;
    cout << "Enter the number of zombies: ";
    cin >> numZombies;
    while (cin.fail()) {
        cout << "Input must be a number.\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter the number of zombies: ";
        cin >> numZombies;
    }
    return numZombies;
}

void simulateAttack (int &numHumans, int &numZombies)
{
    static default_random_engine randomG (time(0));
    uniform_real_distribution<float>percent(0.1f, 1.0f);
    
    //Human Parameters
    int initialHumanHealth = 100;
    int currentHumanHealth = initialHumanHealth;
    float humanAttackSuccessRate = 0.8;
    int humanAttackDamage = 40;
    
    //Zombie Parameters
    int initialZombieHealth = 80;
    int currentZombieHealth = initialZombieHealth;
    float zombieAttackSuccessRate = 0.3;
    int zombieAttackDamage = 100;
    
    bool humanTurn = true;

    while (numHumans > 0 && numZombies > 0)
    {
        while (humanTurn)
        {
            float attackPercent = percent(randomG);
            
            if (attackPercent <= humanAttackSuccessRate) {
                currentZombieHealth -= humanAttackDamage; //human hits zombie once
                if (currentZombieHealth <= 0){
                    numZombies--;
                    currentZombieHealth = initialZombieHealth;
                    humanTurn = false;
                }
            } else {
                humanTurn = false;
            }
        }
        
        while (!humanTurn)
        {
            float attackPercent = percent(randomG);
            
            if (attackPercent <= zombieAttackSuccessRate) {
                currentHumanHealth -= zombieAttackDamage; //zombie hits human once
                if (currentHumanHealth <= 0){
                    numHumans--;
                    currentHumanHealth = initialHumanHealth;
                    numZombies++;
                    humanTurn = true;
                }
            } else {
                humanTurn = true;
            }
        }
    }
}

void printOutcome(int startH, int startZ, int numHumans, int numZombies)
{
    if (numHumans > 0){
        cout << "Mankind survived the zombie apocalypse!" << endl;
        cout << "Human casualty report: " << startH - numHumans << " humans" << endl;
    } else {
        cout << "The zombies overran mankind. The earth is roaming with the undead." << endl;
        cout << "Zombie casualty report: " << startZ - numZombies << " zombies" << endl;
        
    }
    cout << endl << "There are " << numZombies << " zombies left and " << numHumans << " humans left." << endl;
}






