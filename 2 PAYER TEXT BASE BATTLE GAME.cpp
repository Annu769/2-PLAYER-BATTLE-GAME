#include <iostream>
#include <time.h>
using namespace std;
class Player {
protected:
  int health = 0;
  int baseDamage = 0;
  int heal;
  int addDamageMax= 0;
  int addDamageMin = 0;
  int additionalDamage = 0;
  int healingMax = 0;
  int healingMin = 0;
  int totalDamage;
  int maxHealth;

  string playerType;

public:
  Player(int _health, int _baseDamage, int _addDamagemin,
         int _addDamageMax, int _healingMin,
         int _healingMax, string _playerType) {
    health = _health;
    baseDamage = _baseDamage;
    addDamageMin = _addDamagemin;
    addDamageMax = _addDamageMax;
    healingMin = _healingMin;
    healingMax = _healingMax;
    playerType = _playerType;
    maxHealth = _health;
  }
  virtual void getAdditionalDamage() {}
  int getTotalDamage() {
    totalDamage = (baseDamage + additionalDamage);
    return totalDamage;
  }
  void TakeDamage(int _totalDamageValue) { health -= _totalDamageValue;
    if(health < 0  )
    {health -= _totalDamageValue;
      cout<<"Player Is Dead You lost\n";
    }
    else{
      //
    }
    }
  int getHealth() { return health; }
  virtual void healing() {
    if (maxHealth > health) {
      heal = rand() % healingMin + healingMax;
      health += heal;
      if (health > maxHealth) {
        health = maxHealth;
        cout << "Since Max Health is " << maxHealth
             << ", So after getting healing of : " << heal
             << ", The required health is : " << health << endl;
      } else {
        cout << "After get healing of : " << heal
             << ", The required health is : " << health << endl;
      }

    } else {
      cout << "Oops, you are already at Max Health\n";
    }
  }

  string getPlayerType() { return playerType; }
  ~Player() {}
};
//- Type-A → High Health, Low Damage, Low Healing.
//- Type B → Avg Health, Avg Damage, Avg Healing.
//- Type C → Low Health, High Damage, Avg Healing.
class Zolo : public Player {
private:
  int enforcerClanDis = 0;

public:
  Zolo(int _health, int _baseDamage, int _additionalDamageEndLimit,
         int _additionalDamageStartLimit, int _healingEndLimit,
         int _healingStartLimit, string _playerType)
      : Player(_health, _baseDamage, _additionalDamageEndLimit,
               _additionalDamageStartLimit, _healingEndLimit,
               _healingStartLimit, _playerType) {}
  void getAdditionalDamage() {
    additionalDamage =
        rand() % addDamageMax + addDamageMin;
    enforcerClanDis = rand() % 5 + 1;
    cout << "Additional Damage : " << additionalDamage << endl;
    cout << "Congo, You got Lucky some damage got nerfed by : "
         << enforcerClanDis << endl;
    int temp = additionalDamage;
    additionalDamage -= enforcerClanDis;
    cout << "Total Additional Damage done : " << temp << " - "
         << enforcerClanDis << " = " << additionalDamage << endl;
  }
  ~Zolo() {}
};
class Naruto : public Player {
private:
  int vandalClanDis = 0, vandelClanAdv = 0;

public:
  Naruto(int _health, int _baseDamage, int _additionalDamageEndLimit,
         int _additionalDamageStartLimit, int _healingEndLimit,
         int _healingStartLimit, string _playerType)
      : Player(_health, _baseDamage, _additionalDamageEndLimit,
               _additionalDamageStartLimit, _healingEndLimit,
               _healingStartLimit, _playerType) {}
  void getAdditionalDamage() {
    additionalDamage =
        rand() % addDamageMax + addDamageMin;
    vandalClanDis = rand() % 2 + 1;
    cout << "Additional Damage : " << additionalDamage << endl;
    cout << "Congo, You got Lucky some damage got nerfed by : " << vandalClanDis
         << endl;
    int temp = additionalDamage;
    additionalDamage -= vandalClanDis;
    cout << "Total Additional Damage done : " << temp << " - " << vandalClanDis
         << " = " << additionalDamage << endl;
  }
  void healing() {
    if (maxHealth > health) {
      heal = rand() %  healingMin + healingMax;
      vandelClanAdv = rand() % 6 + 1;
      heal += vandelClanAdv;
      cout << "Congo, You got some extra health buff of : " << vandelClanAdv
           << endl;
      health += heal;
      if (health > maxHealth) {
        health = maxHealth;
        cout << "Since Max Health is " << maxHealth
             << ", So after getting healing of : " << heal
             << ", The required health is : " << health << endl;
      } else {
        cout << "After get healing of : " << heal
             << ", The required health is : " << health << endl;
      }

    } else {
      cout << "Oops, you are already at Max Health\n";
    }
  }
  ~Naruto() {}
};
class Atreus : public Player {
protected:
  int museClanAdv1 = 0, museClanAdv2 = 0;

public:
  Atreus(int _health, int _baseDamage, int _additionalDamageEndLimit,
         int _additionalDamageStartLimit, int _healingEndLimit,
         int _healingStartLimit, string _playerType)
      : Player(_health, _baseDamage, _additionalDamageEndLimit,
               _additionalDamageStartLimit, _healingEndLimit,
               _healingStartLimit, _playerType) {}
  void getAdditionalDamage() {
    additionalDamage =
        rand() % addDamageMax + addDamageMin;
    museClanAdv1 = rand() % 7 + 1;
    cout << "Additional Damage : " << additionalDamage << endl;
    cout << "Oops, The damage got buffed by : " << museClanAdv1 << endl;
    int temp = additionalDamage;
    additionalDamage += museClanAdv1;
    cout << "Total Additional Damage done : " << temp << " + " << museClanAdv1
         << " = " << additionalDamage << endl;
  }
  void healing() {
    if (maxHealth > health) {
      heal = rand() % healingMin + healingMax;
      museClanAdv2 = rand() % 10 + 1;
      cout << "Yippee, you got extra health buff of : " << museClanAdv2 << endl;
      heal += museClanAdv2;
      health += heal;
      if (health > maxHealth) {
        health = maxHealth;
        cout << "Since Max Health is " << maxHealth
             << ", So after getting healing of : " << heal
             << ", The required health is : " << health << endl;
      } else {
        cout << "After get healing of : " << heal
             << ", The required health is : " << health << endl;
      }

    } else {
      cout << "Oops, you are already at Max Health\n";
    }
  }
  ~Atreus() {}
};
bool Slection(string input) {
  int n = input.length();
  if (n > 1) {
    cout << "Please enter right input" << endl;
    return false;
  }
  return true;
}
Player *assignplayer() {
  Player *player;
  bool isLooping = true;
  string value;
  // 200,20,10,5,10,5
  // 150,30,15,7,15,7
  // 100,40,18,9,17,6
  while (isLooping) {
    cout << "Enter the type of player you want to choose?\n";
    cout << "1) Zolo\n2) Naruto\n3) Atreus\n";
    cin >> value;
    if (Slection(value) == false)
      continue;
    char charValue = value[0];
    switch (charValue) {
    case '1':
      player = new Zolo(100, 30, 10, 15, 15, 1, "Hentai");
      cout << "You choose : " << player->getPlayerType()
           << " and you start with a health of : " << player->getHealth()
           << endl
           << endl;
      isLooping = false;
      break;
    case '2':
      player = new Naruto(125,20, 15, 7, 8, 16, "Naruto");
      cout << "You choose : " << player->getPlayerType()
           << " and you start with a health of : " << player->getHealth()
           << endl
           << endl;
      isLooping = false;
      break;
    case '3':
      player = new Atreus(100, 20, 10, 19, 7, 17, "Atreus");
      cout << "You choose : " << player->getPlayerType()
           << " and you start with a health of : " << player->getHealth()
           << endl
           << endl;
      isLooping = false;
      break;
    default:
      cout << "Please enter right input" << endl;
      break;
    }
  }
  return player;
}
void welcomeText() {

  cout<<"o()xxxx{}::::::::::::::::::::::::::::> BATTLE GAME <::::::::::::::::::::::::::::::{}xxxx()o\n\n";
   cout<<"*o()xxxx{}::::::::::::::::::> * HEY PLAYER WELCOME TO 2 PLAYER BATTLE GAME * <::::::::::::::::::{}xxxx()o *\n";
  cout<<"\n";
  cout<<"                 o)xxx{}::::::::::::::::::> RULES <::::::::::::::::::{}xxxx(o\n";
  cout<<"\n";
  cout<<"o()xxx{}::::::::::::::::::::::::::::>  \no()xxx{}::::::::::::::::::::::::::::>\n";
  cout<<"*  1. Each Player have only one chance at a time              *\n";
  cout<<"o()xxx{}::::::::::::::::::::::::::::>\n";
  cout<<"*  2. The player whose Health reach below 0, will die and loose the game                         *"<<endl;
  cout<<"o()xxx{}::::::::::::::::::::::::::::>\n";
  cout<<"*  4. Player can have two options in its turn, either to damage other player or to heal youself  *"<<endl;
  cout<<"o()xxx{}::::::::::::::::::::::::::::>\n";
  cout<<"*  5. You can not Choose Same Name Player Choose Diffrent type of player\n";
  cout<<"o()xxx{}::::::::::::::::::::::::::::>\n";
  cout<<"*  6. Instruction If You Pressed 'A' To Attack And 'H' To Heal Yourself. Note Use Only Capital Word \n";
  cout<<"o()xxx{}::::::::::::::::::::::::::::> LET's START <::::::::::::::::::::::::::::{}xxxx()o \n";  
  cout<<"\n";
}
void userManual() {
  cout << "c()xxxxx{}::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;::;>\n\n";
 cout<<"_____________________________________________________________\n";
  cout<<"            IN THIS GAME WE HAVE 3 TYPES OF PLAYER             \n";
  cout<<"_____________________________________________________________\n\n";
  cout<<"---------------* PLAYER 1 *------------\n\n";
  cout<<"Name Hentai and I'm a PowerFul Player\n"<<"And My Skill Is My Damage Is much more higher than others\n\n";
  cout<<"---------------* PLAYER 2 *------------\n\n";
  cout<<"Name Naruto I'm a Skillful Player\n"<<"My Skill My Healing Capacity Is much More Higher Than others\n\n";
  cout<<"---------------* PLAYER 3 *------------\n\n";
  cout<<"Name Atreus I'm A Raged Player \n"<<"My Additional Damage is Much More higher than others\n\n";
}
int main() {
  srand(time(0));
  welcomeText();
  userManual();
  Player *player1 = assignplayer();
  Player *player2 = assignplayer();

  int index = 1;
  // int x = rand()%10 + 1;
  while (player1->getHealth() > 0 && player2->getHealth() > 0) {
    // cout << player1->getHealth() << "			" << player2->getHealth() <<
    // endl;
    if (index == 1) {
      int choice;
      cout << player1->getPlayerType()
           << " it's your turn decide weather :\n1. Attack \n2. Heal\n";
      cin >> choice;
      switch (choice) {
      case 1:
        cout << "\n(Player Two) " << player2->getPlayerType()
             << " took damage.\n";
        player1->getAdditionalDamage();
        cout << "Total Damage dealt : " << player1->getTotalDamage() << endl;
        player2->TakeDamage(player1->getTotalDamage());
        cout << "Health of (Player Two) " << player2->getPlayerType()
             << " after taking damage : " << player2->getHealth() << endl
             << endl;
        break;
      case 2:
        cout << endl;
        player1->healing();
        cout << endl;
        break;
      default:
        cout << "Sorry Wrong input, You missed your chance!";
        break;
      }
      index++;
    } else if (index == 2) {
      int choice;
      cout << player2->getPlayerType()
           << " it's your turn decide weather :\n1. Attack \n2. Heal\n";
      cin >> choice;
      switch (choice) {
      case 1:
        cout << "\n(Player One) " << player1->getPlayerType()
             << " took damage.\n";
        player2->getAdditionalDamage();
        cout << "Total Damage dealt : " << player2->getTotalDamage() << endl;
        player1->TakeDamage(player2->getTotalDamage());
        cout << "Health of (Player One) " << player1->getPlayerType()
             << " after taking damage : " << player1->getHealth() << endl
             << endl;
        break;
      case 2:
        cout << endl;
        player2->healing();
        cout << endl;
        break;
      default:
        cout << "Sorry Wrong input, You missed your chance!";
        break;
      }
      index = 1;
    }
  }
  if (player1->getHealth() <= 0) {
    cout << endl
         << "Player One : " << player1->getPlayerType()
         << " has been defeated by Player Two : " << player2->getPlayerType()
         << endl
         << endl;
    cout << "Congratualtion, Player Two : " << player2->getPlayerType()
         << " for win.\n\n";
    cout << "Better Luck Next Time, Player One : " << player1->getPlayerType();
  } else {
    cout << endl
         << "Player Two : " << player2->getPlayerType()
         << " has been defeated by Player One : " << player1->getPlayerType()
         << endl
         << endl;
    cout << "Congratualtion, Player One : " << player1->getPlayerType()
         << " for win.\n\n";
    cout << "Better Luck Next Time, Player Two : " << player2->getPlayerType();
  }
}
