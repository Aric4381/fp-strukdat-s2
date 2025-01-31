#pragma once
#include "iostream"
#include "player.h"
#include "../include/queue.h"
#include "../include/myLinkedList.h"
#include "../include/Helpers.h"
#include "../include/node.h"
#include "ctime"

Queue<Player> players;
Player *playerArray;

void DrawLeaderboard()
{
    Node<Player> *temp = players.Head();
    std::cout << "===========================" << std::endl;
    std::cout << "Rank      Nama        Score" << std::endl;
    std::cout << "===========================" << std::endl;
    
    for(int i=0; i<10; i++)
    {
        std::cout << i+1 << "\t\t" << playerArray[i].name << "\t\t" << playerArray[i].score << std::endl;
    }
}
void SortScore()
{
    Node<Player> *temp = players.Head();
    int i = 0;
    while (temp->next != NULL)
    {
        *(playerArray + i) =temp->data;
        temp = temp->next;
        i++;
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; i<10; i++)
        {
            if(playerArray[j].score<playerArray[j+1].score)
            {
                tukar(&playerArray[i], &playerArray[j+1]);
            }
        }
    }
}
void SearchScore()
{

}
void PopulatePlayer()
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Player *player = new Player;
        player->name = "COM " + IntToString(i + 1);
        player->score = ((rand() % 4) * 20) + 100;
        players.Enqueue(*player);
    }
    playerArray = new Player[11];
}