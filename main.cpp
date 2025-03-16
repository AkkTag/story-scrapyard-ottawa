//cout << clear;
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>
using namespace std;

//Colour variables
string blue = "\033[0;34m";
string green = "\033[0;32m";
string red = "\033[0;31m";
string cyan = "\033[0;36m";
string white = "\033[0;37m";
string yellow = "\033[0;33m";
string purple = "\033[0;35m";
string resetColour = "\033[0m";

string clear = "\x1B[2J\x1B[H";

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

//Variables
string user_inp;
int coin = 5;
int ducks = 2;
int spaget = 1;
bool lose = false;


//Delay Function
void delay(int fd){
  cout.flush();
  this_thread::sleep_for(chrono::milliseconds(fd));
}

//Text Function
void readText(string fString){
    for (int i = 0; i < fString.length(); i++){
        cout << fString[i];
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}



int rb(int min, int max) {
    int random = rand() % (max - min + 1) + min;
    return random;
}

char rb_chars() {
    char alpha[30] = "abcdefghijklmnopqrstuvwxyz";
    int rng = rand() % (25 - 0 + 1) + 0;
    return alpha[rng];
}

/*
int choose_A_B() {
    
    if (strcmp(user_inp, "A") == 0) {
        readText("")
    }
    
    else if (strcmp(users_inp, "B") == 0) {
        return 2;
    }
}
*/

void c_w() {
    readText("Press \"c\" to walk clockwise around the building. Press \"w\" to walk counterclockwise around the building: ");
    
    do {
        getline(cin, user_inp);
        cout << clear;
        if (user_inp != "c" && user_inp != "w") {
            coin--;
            
            if (coin == 0) {
                lose = true;
            }
        }
    } while (user_inp != "c" && user_inp != "w");
    
    if (user_inp == "c") {
        readText("You trip on a banana peel and die\n");
        lose = true;
    }
    
    else if (user_inp == "w") {
        readText("You walk around the building and you notice a few options. First, there\'s a Wandy\'s drivethrough around the back. The worker looks scrawny. You could probably take him. There\'s also a Wandy\'s mascot who you see strolling around and hyping up random people. Employees maybe?\n");
        readText("Finally, the two security guards at the front. There are no other entrances. Maybe you could try and sneak in somehow? How do you get in?\n\nC) Attack the drive through employee\nD) Try to steal the mascot custom\nE) Try asking the security guards nicely?\nF) Sneak your way past the security guards with a distraction\n");
    }
    
    
}

void choose_C() {
    cout << clear;
    readText("You wait until there's nobody in the drive through. You see an opportunity. You run and leap through the drive through window. Unfortunately, you aren't very athletic. You manage to jump up to your chest and somehow push yourself up to fall through the window. The employee seems unbothered, as if this were a common occurrence. He flashes a wry smile. \"Welcome to Wandy's. How may I help you today?\"\n1) Just keep moving into the main building, leave him there\n2) Steal his clothes to disguise yourself\n3) Hide his body in the meat freeze\n4) Steal his clothes AND hide the body\n");
    getline (cin, user_inp);
    cout << clear;
    while (!(user_inp == "1" || user_inp == "2" || user_inp == "3" || user_inp == "4")){
        cout << red;
        readText("HOW CAN\'T YOU INPUT A NUMBER\n");
        cout << resetColour;
        readText("\n1) Just keep moving into the main building, leave him there\n2) Steal his clothes to disguise yourself\n3) Hide his body in the meat freeze\n4) Steal his clothes AND hide the body\n");
        getline(cin, user_inp);
        cout << clear;
    }
    
    if (user_inp == "1") {
        readText("You look through the restaurant for a way into the building. It\'s pretty easy to find. You walk through the door opposite the drive through window and enter the main lobby.\n\n");
    }
    
    else if (user_inp == "2") {
        readText("You remove the man's uniform and wear it yourself. All disguised, you walk through the door opposite to the drive through window. You\'re on the first floor, in the main lobby of the building. You look at the security guards through the glass door, they utterly failed to stop you from infiltrating this place.\n\n");
    }
    
    else if (user_inp == "3") {
        readText("You drag his body all the way to the meat freezer. A whole 2 meters away. You\'re out of breath. That\'s enough exercise for today. You look through the restaurant for a way into the building. It\'s pretty easy to find. You walk through the door opposite the drive through window and enter the main lobby.\n\n");
    }
    
    else{
        readText("You drag his body all the way to the meat freezer. A whole 2 meters away. You\'re out of breath. That\'s enough exercise for today. You begin taking the man's uniform. The sensation you feel is odd. Probably because it is. Unfortunately, this takes too long, and your physical exhaustion isn\'t exactly discreet. The noise is loud enough that someone comes over to check what\'s happening. They see you in the act and scream. There goes stealth. The security guards from before appear. They arrest you, and McDougal\'s is shut down because its sole manager is in jail. Oh. And your wife divorces you.\n\n");
        lose = true;
    }
}


void choose_E() {
    readText("You politely request entry to the building. They ask for an employee ID. What do you show them?\n1) A coin\n2) A rubber duck\n3) An expired can of marinara\n4) Run away in shame\n");
    getline (cin, user_inp);
    cout << clear;
    
    while (!(user_inp == "1" || user_inp == "2" || user_inp == "3" || user_inp == "4")){
        cout << red;
        readText("It ain\'t that hard man, input correctly\n");
        cout << resetColour;
        readText("1) A coin\n2) A rubber duck\n3) An expired can of marinara\n4) Run away in shame\n");
        getline(cin, user_inp);
    }
    
    if (user_inp == "1") {
        readText("The guards don't take very kindly to your bribe. \"You think I'm going to risk my job for one measly coin!?\" The guard on the right unholsters his pistol and shoots you in the face point blank.\n\n");
        readText("\"Pathetic.\"");
        lose = true;
    }
    
    else if (user_inp == "2") {
        ducks--;
        readText("\"Holy-\" The guard on the left turns to his compatriot.\n");
        readText("\"VIP?\"\n");
        readText("\"VIP.\"\n");
        readText("The guards usher you in. They take you directly to the 3rd floor of the building. Nice. Just one more floor to go. You had an opportunity to eavesdrop on the guards while they were escorting you up. So you know the 4th floor is the highest security. That must be where they keep the recipe. The area you\'re in appears to be some sort of bar.\n\n");
    }
    
    else if (user_inp == "3") {
        spaget--;
        readText("The guards are disgusted. They cannot bear the smell of the can, and your own unholy BO doesn\'t help. You whip out the can and they faint. You stroll right past them with no difficulty. Fortunately the building has better ventilation inside than outside, so nobody else seems to care much about the odour.\n\n");
    }
    
    else if (user_inp == "4") {
        readText("In your pitiful attempt to flee, you slip on a banana and die");
        lose = true;
    }
}




int choice = 0;

void start(){
    //seed for random number
    srand((int)time(0));
    
    cout << resetColour;
    readText("You recently opened your first fast-food restaurant, McDougal\'s, and it\'s been rough. You are struggling. A prolific and Twitter-savvy chain, Wandy\'s, has been stealing all your customers! This is clearly and obviously because they produce the most perfect burgers on the planet. You need to figure out their recipe to save your livelihood. You also have a wife in this game, and we know you\'ll never have one irl, so lock in to save your e-waifu.");
    cout << "\n\n";
    readText("First, you need to find a way to get to Wandy\'s HQ. You can walk, or hire a taxi for one coin. ");
    readText("You have: ");
    cout << yellow << "\n" << coin;
    readText(" coins");
    cout << blue << "\n" << ducks;
    readText(" rubber ducks");
    cout << red << "\n" << spaget;
    readText(" expired can of spaghetti sauce");
    cout << "\n\n" << resetColour;
    readText("Do you:\nA) Hire a taxi\nB) Walk\n");
    getline(cin, user_inp);
    cout << clear;
    
    while(user_inp != "A" && user_inp !="B"){
        readText("Are you indesicive?");
        cout << "\033[1;31m";
        readText(" YOU\'RE WAIFU IS AT STEAK! ");
        cout << resetColour;
        if (coin != 0){
            coin--;
            readText("You drop a coin. ");
        }
        else if (ducks != 0){
            ducks --;
            readText("You drop a duck. ");
        }
        else if (spaget != 0){
            spaget--;
            readText("You drop your expired can of spaghetti sauce");
        }
        else{
            readText("You have dropped everything");
        }
        
        readText ("Input a valid option\n\n");
        readText("You have: ");
        cout << yellow << "\n" << coin;
        readText(" coins");
        cout << blue << "\n" << ducks;
        readText(" rubber ducks");
        cout << red << "\n" << spaget;
        readText(" expired can of spaghetti sauce");
        cout << "\n\n" << resetColour;
        readText("Do you:\nA) Hire a taxi\nB) Walk\n");
        getline(cin, user_inp);
        cout << clear;
    }
    
    if (user_inp == "A"){
        if (coin > 0){
            coin--;
            
            if (rand()%2 == 0){
                readText("You pay one coin to a taxi driver and he drops you off outside Wandy\'s. Unfortunately, you see the entrance is guarded by security. You\'ll need to find a way to sneak past.");
            }
            else{
                readText("You want to hire taxi, but you remember that one time your waifu told you to save money. So you just walk. But it takes 24 hours to get there. In that time, McDougal\'s goes bankrupt. Your e-wife divorces you because you have no money. You\'re as broke a CS Major, with the charisma of a damp sponge.");
                lose = true;
            }
        }
        else{
            readText("The taxi arrives, but you have no money like the typical CS major. Then the taxi hits you in frustration.");
            lose = true;
        }
    }
    else{
        readText("You walk. But it takes 24 hours to get there. In that time, McDougal\'s goes bankrupt. Your e-wife divorces you because she only married you for your money. Hate to break it to you.");
        lose = true;
    }
}

void loseGame(){
    delay(5000);
    cout << clear << "\033[1;31m";
    readText("You lose");
    cout << resetColour << "\n\n";
    readText("Want to play again? (yes/no): ");
    getline(cin, user_inp);
    
    for (int i = 0; i < user_inp.length(); i++){
        user_inp[i] = toupper(user_inp[i]);
    }
    
    while (user_inp != "YES" && user_inp != "NO") {
        readText("Oh my goodness. It\'s a yes or no question\nWant to play again? (yes/no): ");
        getline(cin, user_inp);
        for (int i = 0; i < user_inp.length(); i++){
            user_inp[i] = toupper(user_inp[i]);
        }
        cout << clear;
    }

    cout << clear;
    coin = 3;
    ducks = 2;
    spaget = 1;
    lose = false;
}

void d(){
    cout << clear;
    readText("You approach the Wandy\'s mascot, a man in an oversized foam burger suit dancing around like he\'s being paid in exposure. He sees you and waves excitedly. \"Hey there, fellow burger enthusiast! Care to dance?\"\n\n1) Accept the dance challenge\n2) Distract him by pointing behind him and yelling \"Oh my god, is that Ronaldo McDonaldo?!\"\n3) Knock him out and steal his costume\n");
    getline(cin, user_inp);
    cout << clear;
    
    while (!(user_inp == "1" || user_inp == "2" || user_inp == "3")){
        cout << red;
        readText("LOCK IN, HAVE A VALID INPUT");
        cout << "\n" << resetColour;
        readText("You approach the Wandy\'s mascot, a man in an oversized foam burger suit dancing around like he\'s being paid in exposure. He sees you and waves excitedly. \"Hey there, fellow burger enthusiast! Care to dance?\"\n\n1) Accept the dance challenge\n2) Distract him by pointing behind him and yelling \"Oh my god, is that Ronaldo McDonaldo?!\"\n3) Knock him out and steal his costume\n");
        getline (cin, user_inp);
    }
    
    if (user_inp == "1"){
        readText("The two of you engage in an epic dance-off. Unfortunately, you have the rhythm of a malfunctioning blender. The mascot absolutely destroys you with a flawless backflip. Humiliated, you run away and McDougal's closes down due to sheer embarrassment. Also, your wife divorces you.");
        lose = true;
    }
    else if(user_inp == "2"){
        readText("The mascot turns around in terror. You take this moment to shove him into a nearby dumpster and steal his costume. It's sweaty and smells like desperation, but it works. You waddle up to the front door, and the guards nod approvingly. \"Mascots go straight to the employee lounge. Keep up the enthusiasm!\" They let you in. You're in.");
    }
    else{
        readText("You sucker punch the mascot in the foam-covered face. He crumples like a wet napkin. You quickly put on his costume. It\'s hot. It's gross. You're questioning your life choices, but you\'re in.");
    }
    
}


void f(){
    bool repeat;
    
    do{
        repeat = false;
        readText("What distraction do you use?\n");
        readText("You have: ");
        cout << yellow << "\n" << coin;
        readText(" coins");
        cout << blue << "\n" << ducks;
        readText(" rubber ducks");
        cout << red << "\n" << spaget;
        readText(" expired can of spaghetti sauce");
        cout << "\n\n" << resetColour;
        readText("1) A coin\n2) Your can of spaghetti sauce\n3) A rubber duck\n");
        getline(cin, user_inp);
        cout << clear;
        if (user_inp == "1"){
            if (coin != 0){
                coin --;
                readText("You throw a coin off to the side of the building. One of the guards goes to check out where the sound came from, but the other stays put.");  
                delay(1000);
                readText(" Do you:\n1) Throw another coin to distract the second guard\n2) Try again and find another way to get in\n");
                getline (cin, user_inp);
                cout << clear;
                
                while (!(user_inp == "1" || user_inp == "2") ){
                    cout << red;
                    readText("THIS ISN\'T THE TIME TO STUTTER, INPUT A VALID CHOICE.");
                    cout << resetColour;
                    readText(" Do you:\n1) Throw another coin to distract the second guard\n2) Try again and find another way to get in");
                    getline(cin, user_inp);
                }
                
                if (user_inp == "1"){
                    if (coin != 0){
                        coin--;
                        readText("You throw a second coin and both guards abandon their post. You walk in with your chin up, confident you can keep your waifu happy");
                    }
                    else{
                        readText("You realize you\'re broke and get spotted by a guard");
                        lose = true;
                    }
                }
                else{
                    repeat = true;
                }
            }
            else{
                readText("You realize you dropped your coins, but it\'s too late, the guards spot you.");
                lose = true;
            }
        }
        else if (user_inp == "2"){
            if (spaget != 0){
                spaget --;
                readText("You throw the can towards the guards. It explodes in a splatter of red, and the guards are covered in expired tomato sauce. They can barely keep themselves from keeling over, and they both crawl to the nearest porta-potty to vomit their intestines out. Meanwhile, you pass through the building\'s sliding glass doors. You're in.");            
            }
            else{
                readText("You realize you dropped your sauce, but it\'s too late, the guards spot you.");
                lose = true; 
            }
        }
        else if (user_inp == "3"){
            if (ducks != 0){
                ducks--;
                readText("The duck explodes in a brilliant flash of purple. The light passes over everyone in the lobby of the building. As it does, they all appear to fall… Asleep? You can't really be sure what happened to them. Good thing is that the entire first floor is clear.");
            }
            else{
                readText("You realize you dropped your sauce, but it\'s too late, the guards spot you.");
                lose = true; 
            }
        }
        else{
            readText("You fail to make a decision in time, a guard spots you and laughs at you as you are stuffed into a chicken costume. You are then forced to stand outside Wandy\'s and advertise their brand. This causes your waifu to break up with you");
            lose = true;
        }
    }while (repeat == true);
}

int main()
{
    do{
        start();
        if (lose != true){
            
        
            c_w();
        
            if(lose != true){
                do {
                
                    getline(cin, user_inp);
                    cout << clear;
                
                    if (user_inp != "A" && user_inp != "B" && user_inp != "C" && user_inp != "D" && user_inp != "E" && user_inp != "F") {
                        int rb_result = rb(0, 1);
                        
                        if (rb_result == 0) {
                            printf("Cancelling you if you don\'t give me a valid input.\n");
                        }
                    
                        else if (rb_result == 1) {
                        printf("Bart Simpson will be upset if you keep this up.\n");
                        }
                    }
                } while (user_inp != "A" && user_inp != "B" && user_inp != "C" && user_inp != "D" && user_inp != "E" && user_inp != "F");
                
        
                if (user_inp == "C"){
                    choose_C();
                }
                else if (user_inp == "D"){
                    d();
                }
                else if (user_inp == "E"){
                    choose_E();
                }
                else{
                    f();
                }
                delay (1000);
                
                if(lose != true){
                    user_inp = "pq";
                    
                    readText("\n\nYou suddenly stumble upon a die hard Wandy\'s enthusiast. He blocks your way");
                    delay(500);
                    cout << red;
                    readText(", you must fight");
                    delay(5000);
                    cout << clear;
                    cout << resetColour;
                    
                    //Boss fight
                    int bossHealth = 150;
                    int playerHealth = 120;
                    bool strength = false;
                    int bonusDamage = 0;
                    int randHealth;
                    while(bossHealth > 0 && playerHealth > 0){
                        int attk;
                        
                        while (!(user_inp == "1" || user_inp == "2" || user_inp == "3" || user_inp == "4")){
                            
                            cout << red;
                            readText("The enthusiast has: ");
                            readText(to_string(bossHealth));
                            readText (" health\n\n");
                            
                            cout << blue;
                            readText("You have: ");
                            readText(to_string(playerHealth));
                            readText (" health\n");
                        
                            cout << coin;
                            readText(" coins");
                            cout << blue << "\n" << ducks;
                            readText(" rubber ducks");
                            cout << "\n" << spaget;
                            readText(" expired can of spaghetti sauce");
                            cout << resetColour;
                            readText("\n\nDo you want to:\n");
                            cout << "\033[1;31m";
                            readText("1) Fist Attack\n");
                            cout << yellow;
                            readText("2) Distract with coin\n");
                            cout << blue;
                            readText("3) Intimidate with duck\n");
                            cout << red;
                            readText("4) Feed with the sauce\n");
                            cout << resetColour;
               
                            getline(cin, user_inp);
                            cout << clear;
                            
                            if (!(user_inp == "1" || user_inp == "2" || user_inp == "3" || user_inp == "4")){
                                cout << red;
                                readText("IT\'S NOT HARD TO INPUT CORRECTLY\n");
                                cout << resetColour;
                            }
                        }
                        
                        cout << clear;
                        
                        if (strength == true){
                            bonusDamage = rand()%10+1;
                        }
                        else{
                            bonusDamage = 0;
                        }
                        
                        if (user_inp == "1"){
                            attk = rand() % 30 + 1;
                            cout << blue;
                            readText("You did ");
                            readText(to_string(attk + bonusDamage));
                            readText(" damage");
                            bossHealth -= (attk+bonusDamage);
                        }
                        else if (user_inp == "2"){
                            if (coin > 0){
                                if (rand()%3 >=1){
                                readText("You successfully distract the enthusiast, now\'s your time to attack: \n");
                                cout << red;
                                readText("1) Fist Attack\n");
                                cout << cyan;
                                readText("2) Super fist attack\n");
                                cout << "\n" << resetColour;
                                getline(cin, user_inp);
                                cout << clear;
                                if (user_inp == "1"){
                                    attk = rand() % 40 + 1;
                                    cout << blue;
                                    readText("You did ");
                                    readText(to_string(attk+bonusDamage));
                                    readText(" damage");
                                    bossHealth -= (attk+bonusDamage);
                                }
                                else if (user_inp == "2"){
                                    coin--;
                                    if (rand()%3 >=1){
                                        cout << cyan;
                                        readText("CRITICAL HIT");
                                        attk = rand() % 30 + 21;
                                        cout << blue;
                                        readText("You did ");
                                        readText(to_string(attk+bonusDamage));
                                        readText(" damage");
                                        bossHealth -= (attk+bonusDamage); 
                                    }
                                    else{
                                        cout << red;
                                        readText("During your wind up, you slip on a bannana and lose most of your power\n");
                                        cout << blue;
                                        readText("You did ");
                                        readText("1");
                                        readText(" damage");
                                        bossHealth -= 1;
                                    }
                                }
                                else{
                                    readText("I could give you another chance to re-type that, but you should already be able to at this point. So you wasted a turn");
                                }
                                
                                }
                                else{
                                    readText("Your distraction fails, he looks at you angrily");
                                }
                            }
                            else{
                               readText("You reach into your pocket, but no coin is to be found, and now you realize you wasted a turn"); 
                            }
                            
                        }
                        else if (user_inp == "3"){
                            if (ducks > 0){
                                ducks--;
                                if (strength == true){
                                    readText("You can only intimidate once, now he realizes your bluff, your bonus is gone");
                                    strength = false;
                                    
                                }
                               else if (rand()%2 == 0){
                                   readText("Your intimidation works! You will now have stronger attacks");
                                   strength = true;
                               } 
                               else{
                                   readText("Your intimidation failed");
                                   delay(1000);
                                   readText("\nwomp womp");
                               }
                            }
                            else{
                               readText("You reach into your pocket, but no duck is to be found, and now you realize you wasted a turn");  
                            }
                        }
                        else{ //option 4, feed boss with sauce
                            if (spaget > 0){
                                spaget--;
                                if (rand()%5 == 0){
                                    readText("You feed the man the sauce, he becomes very sick and flees");
                                    bossHealth = 0;
                                }
                                else{
                                    randHealth = rand()%15 + 1;
                                    cout << red;
                                    readText("The man gulps the sauce down and heals ");
                                    readText (to_string(randHealth));
                                    readText(" health");
                                    bossHealth += randHealth;
                                }
                            }
                        }
                        delay(3000);
                        cout << clear << red;
                        randHealth = rand()%30+1;
                        readText ("He attacks you, and he does ");
                        readText (to_string(randHealth));
                        readText(" damage");
                        playerHealth-=randHealth;
                        delay(2000);
                        cout << clear;
                        user_inp = "p9";
                    }
                    if (playerHealth <= 0 && bossHealth <= 0){
                        cout << resetColour;
                        readText("You both faint at the same time, but that doesn\'t matter, you should have won the fight");
                        loseGame();
                    }
                    else if (playerHealth <= 0){
                        cout << resetColour;
                        readText("You lose and your waifu leaves you for the enthusiast because he\'s a better fighter");
                        loseGame();
                    }
                    else{
                        cout << resetColour;
                        readText("Congrats, you surprisingly won!\n\nHere is your prize: https://codepen.io/Akshaj-Gattu/full/PwoEyNE\nPress enter to proceed");
                        getline(cin, user_inp);
                        cout << clear;
                        readText("Want to play again? (yes/no): ");
                        getline(cin, user_inp);
    
                        for (int i = 0; i < user_inp.length(); i++){
                            user_inp[i] = toupper(user_inp[i]);
                        }
    
                        while (user_inp != "YES" && user_inp != "NO") {
                            readText("Oh my goodness. It\'s a yes or no question\nWant to play again? (yes/no): ");
                            getline(cin, user_inp);
                            for (int i = 0; i < user_inp.length(); i++){
                                user_inp[i] = toupper(user_inp[i]);
                            }
                            cout << clear;
                        }
                        cout << clear;
                        coin = 5;
                        ducks = 2;
                        spaget = 1;
                        
                    }
                }
                else{
                    loseGame();
                }
                
                
                
            }
            else{
                loseGame();
            }
            
        }
        else{
            loseGame();
        }
    }while (user_inp == "YES");
    readText("CYA!!!");
}
