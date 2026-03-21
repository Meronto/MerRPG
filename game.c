#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




typedef struct
{
    char Name[15];
    int Hp;
    int Attack;
} Player;

typedef struct
{
    char Name[15];
    int Hp;
    int min_attack;
    int max_attack;
} Monster ;

typedef struct 
{
  int min_heal;
  int max_heal;
} Heal;

void init_player(Player* player) {
    printf("Send Nickname: ");
    scanf("%14s",player->Name);
    player->Hp = 20;
}

void init_monster(Monster* monster) {
    Monster monster_list[3] = {
        {"Amogus",30,3,6},
        {"Slime",20,1,3},
        {"Spider",25,2,4}
    };
    int id = rand() %3;
    *monster = monster_list[id];

}

void print_status(Player player,Monster monster){
    printf("\n--- MerRPG ---\n");
    printf(" 0            /^^\\\n");
    printf("/|\\           (00)\n");
    printf("/ \\           /__\\\n");
    printf("%s HP: %d\n",player.Name, player.Hp);
    printf("%s HP: %d\n", monster.Name,monster.Hp);

}

void player_attack(Player* player,Monster* monster){
    int damage_player= rand() % 5 +1;
    monster ->Hp -= damage_player;
    printf("You caused %d damage\n",damage_player);
    if (monster ->Hp < 0) {
        monster ->Hp =0;
    }
}
void monster_attack(Player* player,Monster* monster){
    int damage_monster = rand() % (monster ->max_attack - monster ->min_attack +1) + monster ->min_attack;
    player ->Hp -= damage_monster;
    printf("Emeny caused %d damage\n",damage_monster);
        if (player ->Hp < 0) {
            player ->Hp =0;
    }
}

void player_heal(Player* player, Heal* heal) {
    int heal_player = rand() % (heal ->max_heal - heal ->min_heal + 1) + heal->min_heal;
    player ->Hp += heal_player;
    printf("You have restored %d Hp\n", heal_player);
    if (player ->Hp > 20) {
        player ->Hp = 20;
    }
}



int main() {
srand(time(NULL));
printf(" __  __           ____  ____   ____ \n");
printf("|  \\/  | ___ _ __|  _ \\|  _ \\ / ___| \n");
printf("| |\\/| |/ _ \\ '__| |_) | |_) | |  _ \n");
printf("| |  | |  __/ |  |  _ <|  __/| |_| |\n");
printf("|_|  |_|\\___|_|  |_| \\_\\_|    \\____|\n");
int choice;
Player player;
Monster monster;
Heal heal = {1,6};
init_player(&player);
init_monster(&monster);

while(player.Hp > 0 && monster.Hp > 0 ) {
    print_status(player,monster);
    printf("[0] - Exit\n");
    printf("[1] - Attack\n");
    printf("[2] - Healing\n");
    scanf("%d", &choice);
    if (choice == 1) {
        player_attack(&player,&monster);
        if ( monster.Hp > 0) {
            monster_attack(&player,&monster);
        }
    } else if (choice == 2) {
        player_heal(&player,&heal);
        monster_attack(&player,&monster);
    }
    else if (choice == 0) {
        printf("You are out of the game\n");
        break;
    } else {
        break;
    }
}
if (player.Hp == 0) {
    printf("You Lose...\n");
} else if (monster.Hp == 0){
    printf("You Win!\n");
}
return 0;
}

