#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int size;
    int times;
    int winner;
    int user_x, user_y;
    int start;
    int restart;

    restart:
    system("cls");
    printf("井字棋（Tic-Tac-Toe）游戏，先手为[Ⅹ]，最先以横、直、斜连成一线则为胜，若无人获胜则为平局。\n\n按下[Enter]键进入游戏。");
    getchar();
    system("cls");
    printf("请输入棋盘边长：");
    scanf("%d",&size);
    printf("\n本局棋盘大小为%d×%d，按下[Enter]键开始游戏。",size,size);
    getchar();
    getchar();

    int board[size][size];
    times = 0;
    winner = 0;
    user_x = 0;
    user_y = 0;

    /*清空棋盘*/
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            board[x][y] = 0;
        }
    }

    start:
    /*打印棋盘*/
    system("cls");
    for(int x = 0; x <= size; x++){
        printf("%d\t", x);
    }
    printf("\n\n\n");
    for(int x = 0; x < size; x++){
        printf("%d",x+1);
        for(int y = 0; y < size; y++){
            if(board[x][y] == 0){
                printf("\t■");
            }
            if(board[x][y] == 1){
                printf("\tⅩ");
            }
            if(board[x][y] == 2){
                printf("\t〇");
            }
        }
        printf("\n\n\n");
    }

    /*判断是否有一方胜利*/
    for(int x = 0; x < size; x++){
        int Ascore = 0, Bscore = 0;
        for(int y = 0; y < size; y++){
            if(board[x][y] == 1){
                Ascore = Ascore + 1;
            }
            if(board[x][y] == 2){
                Bscore = Bscore + 1;
            }
            if(Ascore == size){
                winner = 1;
                goto end;
            }
            if(Bscore == size){
                winner = 2;
                goto end;
            }
        }
    }

    for(int y = 0; y < size; y++){
        int Ascore = 0, Bscore = 0;
        for(int x = 0; x < size; x++){
            if(board[x][y] == 1){
                Ascore = Ascore + 1;
            }
            if(board[x][y] == 2){
                Bscore = Bscore + 1;
            }
            if(Ascore == size){
                winner = 1;
                goto end;
            }
            if(Bscore == size){
                winner = 2;
                goto end;
            }
        }
    }
    
    for(int Ascore = 0, Bscore = 0, pos = 0; pos < size; pos++){
        if(board[pos][pos] == 1){
            Ascore = Ascore + 1;
        }
        if(board[pos][pos] == 2){
            Bscore = Bscore + 1;
        }
        if(Ascore == size){
            winner = 1;
            goto end;
        }
        if(Bscore == size){
            winner = 2;
            goto end;
        }
    }

    for(int Ascore = 0, Bscore = 0, x = size - 1, y = 0; y < size; x-- , y++){
        if(board[x][y] == 1){
            Ascore = Ascore + 1;
        }
        if(board[x][y] == 2){
            Bscore = Bscore + 1;
        }
        if(Ascore == size){
            winner = 1;
            goto end;
        }
        if(Bscore == size){
            winner = 2;
            goto end;
        }

    }

    if(times == size*size){
        printf("本局为平局。\n\n\n");
        goto end;
    }

    /*玩家选择位置*/
    if(times % 2 == 0){
        printf("轮到 Ⅹ\n");
        printf("请输入位置的横坐标：");
        scanf("%d", &user_y);
        printf("请输入位置的纵坐标：");
        scanf("%d", &user_x);
        if(user_x > size||user_y > size){
            printf("该位置无效，按下[Enter]键继续。");
            getchar();
        }
        if(board[user_x - 1][user_y - 1] == 0){
            printf("[Ⅹ]将放置在[%d,%d]上，按[Enter]键确认，按[R]键重新输入。", user_y, user_x);
            reenter_1:
            start = getch();
            if(start == 'R'||start == 'r'){
                goto start;
            }
            if(start == 13){
                board[user_x - 1][user_y - 1] = 1;
                times = times + 1;
                goto start;
            }
            else{
                goto reenter_1;
            }
        }
        else{
            printf("该位置已有棋子，按下[Enter]键继续。");
            getchar();
            getchar();
            goto start;
        }
    }
    else{
        printf("轮到 〇\n");
        printf("请输入位置的横坐标：");
        scanf("%d", &user_y);
        printf("请输入位置的纵坐标：");
        scanf("%d", &user_x);
        if(user_x > size||user_y > size){
            printf("该位置无效，按下[Enter]键继续。");
            getchar();
        }
        if(board[user_x - 1][user_y - 1] == 0){
            printf("[〇]将放置在[%d,%d]上，按[Enter]键确认，按[R]键重新输入。", user_y, user_x);
            reenter_2:
            start = getch();
            if(start == 'R'||start == 'r'){
                goto start;
            }
            if(start == 13){
                board[user_x - 1][user_y - 1] = 2;
                times = times + 1;
                goto start;
            }
            else{
                goto reenter_2;
            }
        }
        else{
            printf("该位置已有棋子，按下[Enter]键继续。");
            getchar();
            getchar();
            goto start;
        }
    }

    if(times < size*size){
        goto start;
    }

    end:
    if(winner == 1){
        printf("[Ⅹ]赢了\n\n\n");
    }
    if(winner == 2){
        printf("[〇]赢了\n\n\n");
    }

    printf("按下[R]键重新开始游戏，按下[E]键退出。");
    reenter_3:
    restart = getch();
    if(restart == 'R'||restart == 'r'){
        goto restart;
    }
    if(restart == 'E'||restart == 'e'){
        exit(0);
    }
    else{
        goto reenter_3;
    }

    return 0;
}