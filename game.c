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
    int Attack;
} Monster ;

void init_player(Player* player) {
    printf("Send Nickname: ");
    scanf("%14s",player->Name);
    player->Hp = 20;
}

void init_monster(Monster* monster) {
    strcpy(monster->Name, "Amogus");
    monster->Hp = 12;
}

void print_status(Player player,Monster monster){
    printf("\n--- MerRPG ---\n");
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
    int damage_monster = rand() % 3 + 1;
    player ->Hp -= damage_monster;
    printf("Emeny caused %d damage\n",damage_monster);
        if (player ->Hp < 0) {
            player ->Hp =0;
    }
}



int main() {
srand(time(NULL));
int choice;
Player player;
Monster monster;
init_player(&player);
init_monster(&monster);

while(player.Hp > 0 && monster.Hp > 0 ) {
    print_status(player,monster);
    printf("1 - Attack\n");
    printf("2 - Exit\n");
    scanf("%d", &choice);
    if (choice == 1) {
        player_attack(&player,&monster);
        if ( monster.Hp > 0) {
            monster_attack(&player,&monster);
        }
    }
    else if (choice == 2) {
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

