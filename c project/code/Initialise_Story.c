#include<stdio.h>
#include<string.h>

void InitialiseStory(char* paragraph){

    char story[2000] = {"A dumb adventurer named Steve is stuck in a dark cold cave with no light. Bob has to acquire a Minecraft torch in order to survive in the dark cold cave. The cave has multiple types of monsters such as creeper, skeleton, zombies. Steve has to push boulders to unlock different routes to the cave and get the ender dragon egg."};
    int mem = 0;
    int i = 0;
    int temp = 0;

    while (story[i] != '\0'){

        paragraph[i+temp] = story[i];

        if ((mem >= 50) && (paragraph[i+temp] == ' ')){
            temp++;
            paragraph[i+temp] = '\n';
            mem = 0;
        }
        mem++;
        i++;
    }
}

int main(void){

    char story[2000];
    InitialiseStory(story);
    printf("%s\n", story);
    return 0;
}