
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define SUCCESS 1;
#define FAILURE 0
#define BOMB_FLAG 1
#define LOOSER 2
#define NewGame struct GameLevel *

struct GameLevel{
    int n,m;
    int bombs;
    int GameIsLost;
    struct LevelBlock **LevelReference;
};
struct LevelBlock{
    int isLocked;
    int isBomb;
    int NumberInside;
};

struct GameLevel *CreateNewGame(int,int,int);
struct LevelBlock GetElementByPosition(struct GameLevel *LevelInfo ,int x, int y);
void SetElementByPosition(struct GameLevel *,int,int,int,int);
int UnlockByPosition(struct GameLevel *,int,int);
int SetProperDestination(struct GameLevel *LevelInfo,int x,int y);
int Create2DArray(struct GameLevel *);
int FillBombs(struct GameLevel *);
void PrintLevel(struct GameLevel *);


struct GameLevel *CreateNewGame(int rows,int collums,int bombs){
    struct GameLevel *NewGameObject =(struct GameLevel *)malloc(sizeof(struct GameLevel));
    NewGameObject->GameIsLost=0;
    if(rows<=0 || collums <=0){
        return NULL;
    }
    NewGameObject->n=rows;
    NewGameObject->m=collums;
    if(bombs>rows*collums){
        return NULL;
    }
    else{
        NewGameObject->bombs=bombs;
        return NewGameObject;
    }

}
struct LevelBlock GetElementByPosition(struct GameLevel *LevelInfo ,int x, int y){
    if(x<LevelInfo->n && x>=0 && y<LevelInfo->m && y>=0){
        return LevelInfo->LevelReference[x][y];
    }
}
void SetElementByPosition(struct GameLevel *LevelInfo,int x,int y,int Element,int has_bomb_flag) {
    if (x < LevelInfo->n && x >= 0 && y < LevelInfo->m && y >= 0) {
        if (has_bomb_flag) {
            if (!GetElementByPosition(LevelInfo, x, y).isBomb) {
                LevelInfo->LevelReference[x][y].NumberInside = Element;
//return SUCCESS;
            } else {
//return FAILURE;
            }
        } else {
            LevelInfo->LevelReference[x][y].NumberInside = Element;
//return SUCCESS;
        }
    } else {
//return FAILURE;
    }
    if (Element == -1) {
        LevelInfo->LevelReference[x][y].isBomb = 1;
    }
}
int UnlockByPosition(struct GameLevel *LevelInfo,int x,int y) {
    if (x < LevelInfo->n && x >= 0 && y < LevelInfo->m && y >= 0) {
        LevelInfo->LevelReference[x][y].isLocked = 0;
        return 1;
    }
    return 0;
}

int SetProperDestination(struct GameLevel *LevelInfo,int x,int y){
    if(x<LevelInfo->n && x>=0 && y<LevelInfo->m && y>=0){
        SetElementByPosition(LevelInfo,x,y-1,GetElementByPosition(LevelInfo,x,y-1).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x,y+1,GetElementByPosition(LevelInfo,x,y+1).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x-1,y-1,GetElementByPosition(LevelInfo,x-1,y-1).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x-1,y,GetElementByPosition(LevelInfo,x-1,y).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x-1,y+1,GetElementByPosition(LevelInfo,x-1,y+1).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x+1,y-1,GetElementByPosition(LevelInfo,x+1,y-1).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x+1,y,GetElementByPosition(LevelInfo,x+1,y).NumberInside+1,BOMB_FLAG);
        SetElementByPosition(LevelInfo,x+1,y+1,GetElementByPosition(LevelInfo,x+1,y+1).NumberInside+1,BOMB_FLAG);
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}
int Create2DArray(struct GameLevel *LevelInfo) {
    int counter;
    int i;
    LevelInfo->LevelReference=(struct LevelBlock **)malloc(LevelInfo->n*sizeof(struct LevelBlock *));
    if(LevelInfo->LevelReference==NULL)return -1;
    else{
        for (counter=0;counter<LevelInfo->m;++counter){
            LevelInfo->LevelReference[counter]=(struct LevelBlock *)malloc(LevelInfo->m*sizeof(struct LevelBlock));
            if(LevelInfo->LevelReference[counter]==NULL)return -1;
            else{
                memset(LevelInfo->LevelReference[counter],0,sizeof(struct LevelBlock)*LevelInfo->m);
            }
        }
    }
    return 1;
}
int FillBombs(struct GameLevel *LevelInfo){
    int counter=0;
    int x=0,y=0;
    int max_x=LevelInfo->n-1;
    int max_y=LevelInfo->m-1;
    srand((unsigned)time(NULL));
    for(counter=0;counter<LevelInfo->bombs;counter++){
        do{
            x=(rand()%max_x);
            y=(rand()%max_y);

        }while(GetElementByPosition(LevelInfo,x,y).isBomb);
        SetElementByPosition(LevelInfo,x,y,-1,0);
        SetProperDestination(LevelInfo,x,y);

    }
    return 1;
}
void PrintLevel(struct GameLevel *LevelInfo) {
    int counter,counter2;
    for(counter=0;counter<LevelInfo->n;++counter){
        for(counter2=0;counter2<LevelInfo->m;++counter2) {
            if(GetElementByPosition(LevelInfo,counter,counter2).isLocked){
                printf(" X ");
            }
            else{
                if(GetElementByPosition(LevelInfo,counter,counter2).isBomb){
                    printf(" @ ");
                }
                else{
                    printf(" %d ",GetElementByPosition(LevelInfo,counter,counter2).NumberInside);
                }
            }

        }
        printf("\n");
    }
}
void LockEverything(struct GameLevel *LevelInfo){
    int i,j;
    for (i = 0; i < LevelInfo->n; ++i) {
        for (j = 0; j < LevelInfo->m; ++j) {
            LevelInfo->LevelReference[i][j].isLocked=1;
        }
    }
}
int Unlock_Neighborhood(struct GameLevel *LevelInfo,int x,int y,int isPressed) {
    if(GetElementByPosition(LevelInfo,x,y).isBomb && isPressed){
        LevelInfo->GameIsLost=1;
        return LOOSER;
    }
    else if (x < LevelInfo->n && x >= 0 && y < LevelInfo->m && y >= 0) {
        LevelInfo->LevelReference[x][y].isLocked=0;
        if(y-1>=0 && LevelInfo->LevelReference[x][y-1].isLocked && LevelInfo->LevelReference[x][y-1].NumberInside==0 && !LevelInfo->LevelReference[x][y-1].isBomb)Unlock_Neighborhood(LevelInfo,x,y-1,0);
        if(y+1<LevelInfo->m &&LevelInfo->LevelReference[x][y+1].isLocked && LevelInfo->LevelReference[x][y+1].NumberInside==0 && !LevelInfo->LevelReference[x][y+1].isBomb)Unlock_Neighborhood(LevelInfo,x,y+1,0);
        if(x-1>=0 && y-1>=0 && y+1<LevelInfo->m && LevelInfo->LevelReference[x-1][y-1].isLocked && LevelInfo->LevelReference[x-1][y-1].NumberInside==0 && !LevelInfo->LevelReference[x-1][y-1].isBomb)Unlock_Neighborhood(LevelInfo,x-1,y-1,0);
        if(x-1>=0 && LevelInfo->LevelReference[x-1][y].isLocked && LevelInfo->LevelReference[x-1][y].NumberInside==0 && !LevelInfo->LevelReference[x-1][y].isBomb)Unlock_Neighborhood(LevelInfo,x-1,y,0);
        if(x-1>=0 && y+1<LevelInfo->m && LevelInfo->LevelReference[x-1][y+1].isLocked && LevelInfo->LevelReference[x-1][y+1].NumberInside==0 && !LevelInfo->LevelReference[x-1][y+1].isBomb)Unlock_Neighborhood(LevelInfo,x-1,y+1,0);
        if(x+1<LevelInfo->n && y-1>=0 && LevelInfo->LevelReference[x+1][y-1].isLocked && LevelInfo->LevelReference[x+1][y-1].NumberInside==0 && !LevelInfo->LevelReference[x+1][y-1].isBomb)Unlock_Neighborhood(LevelInfo,x+1,y-1,0);
        if(x+1<LevelInfo->n &&LevelInfo->LevelReference[x+1][y].isLocked && LevelInfo->LevelReference[x+1][y].NumberInside==0 && !LevelInfo->LevelReference[x+1][y].isBomb)Unlock_Neighborhood(LevelInfo,x+1,y,0);
        if(x+1<LevelInfo->n && y+1<LevelInfo->m && LevelInfo->LevelReference[x+1][y+1].isLocked && LevelInfo->LevelReference[x+1][y+1].NumberInside==0 && !LevelInfo->LevelReference[x+1][y+1].isBomb)Unlock_Neighborhood(LevelInfo,x+1,y+1,0);

    }
}
void PrintBeatifulStartUp(){
    printf("    __  ____                                                   \n""   /  |/  (_)___  ___  ______      _____  ___  ____  ___  _____\n""  / /|_/ / / __ \\/ _ \\/ ___/ | /| / / _ \\/ _ \\/ __ \\/ _ \\/ ___/\n"" / /  / / / / / /  __(__  )| |/ |/ /  __/  __/ /_/ /  __/ /    \n""/_/  /_/_/_/ /_/\\___/____/ |__/|__/\\___/\\___/ .___/\\___/_/     \n""                                           /_/                 \n""");
    printf("\n\t*Encoded By Stefanos Stefanou [Homework #6]*\n\n");
}
int UserInterface(){
    int n,m,bombs,x,y;
    PrintBeatifulStartUp();
    printf("Start Procceding...\n");
    printf("Please , give the number of rows-> ");
    scanf("%d",&n);
    printf("Please , give the number of collums-> ");
    scanf("%d",&m);
    do{
        printf("Please , give the number of bombs(not over 60percent of total positions)-> ");
        scanf("%d",&bombs);
    }while(((bombs*100)/(n*m))>60);

    NewGame MyGame = CreateNewGame(n,m,bombs);
    printf("Catching Memory....\n");
    Create2DArray(MyGame);
    printf("Filling Bombs....\n");
    FillBombs(MyGame);
    printf("Hiding The Level....\n");
    LockEverything(MyGame);
    do{
        PrintLevel(MyGame);
        printf("Give me the Dimensions(x,y) ->");
        scanf("%d",&x);
        scanf("%d",&y);
    }while(Unlock_Neighborhood(MyGame,x,y,1)!=LOOSER);
    if(MyGame->GameIsLost){
        printf("You are a completely looser bro :( sorry about that :P ");
    }
}
int main(){
    UserInterface();
}