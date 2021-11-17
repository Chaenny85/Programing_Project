#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch=getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

void pirntpuzzle(int puzzle[]){
    system("clear");
    int a = 0;
        for(int i=0; i<=15; i++){
            if(a%4==3){
                if(puzzle[i]==0){
                    printf("%10s\n", "");
                }
                else
                    printf("%10d\n", puzzle[i]);
            }
            else{
                if(a%4==0){
                    if(puzzle[i]==0){
                        printf("%30s", "");
                    }
                    else
                        printf("%30d", puzzle[i]); 
                }
                else{
                    if(puzzle[i]==0){
                        printf("%10s", "");
                    }
                    else
                        printf("%10d", puzzle[i]);
                }
            }
            a++;
        }
        printf("\n");
}

int checkpuzzle(int puzzle[]){
    int check = 0;
    for(int i=0; i<15; i++){
        if(puzzle[i]!=i+1){
            check++;
        }
    }
    if(check == 0){
        printf("축하합니다.\n");
        sleep(3);
        return 1;
    }
    else
    return 2;
}

int main(int argc, char *argv[]){
    int puzzle[16];

    if(!strcmp(argv[1], "1")){
        for(int i=0; i<15; i++){
            puzzle[i] = i+1;
        }
        puzzle[15] = '\0';

        pirntpuzzle(puzzle); 

        int nullposition = 15;

        int tmp;

        int ch;

        while(ch != 113){
            ch = getch();
            if(ch == 105){ //i
               if(nullposition<12){
                    tmp = puzzle[nullposition+4];
                    puzzle[nullposition+4] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition+4;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                } 
            }
            else if(ch == 106){ //j
                if(nullposition%4 != 3){
                    tmp = puzzle[nullposition+1];
                    puzzle[nullposition+1] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition+1;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }
            }
            else if(ch == 107){ //k
                if(nullposition>3){
                    tmp = puzzle[nullposition-4];
                    puzzle[nullposition-4] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition-4;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }
            }
            else if(ch == 108){ //l
                if(nullposition%4 != 0){
                    tmp = puzzle[nullposition-1];
                    puzzle[nullposition-1] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition-1;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }

            }
            else if(ch == 113){//q
                printf("종료합니다.");
            }
            else{
                printf("잘못된 방향으로 입력하였습니다. 다시 입력해주세요.\n");
            }
        }   
    }

    if(!strcmp(argv[1], "2")){
        srand(time(NULL));
        for(int i=0; i<15; i++){ //make random
            puzzle[i] = rand()%15+1;
            for(int j=0; j<i; j++){
                if(puzzle[i]==puzzle[j]){
                    i--;
                }
            }
        }
        puzzle[15] = '\0';
   
        pirntpuzzle(puzzle);

        int nullposition = 15;

        int tmp;

        int ch;

        while(ch != 113){
            ch = getch();
            if(ch == 105){ //i
               if(nullposition<12){
                    tmp = puzzle[nullposition+4];
                    puzzle[nullposition+4] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition+4;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                } 
            }
            else if(ch == 106){ //j
                if(nullposition%4 != 3){
                    tmp = puzzle[nullposition+1];
                    puzzle[nullposition+1] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition+1;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }
            }
            else if(ch == 107){ //k
                if(nullposition>3){
                    tmp = puzzle[nullposition-4];
                    puzzle[nullposition-4] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition-4;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }
            }
            else if(ch == 108){ //l
                if(nullposition%4 != 0){
                    tmp = puzzle[nullposition-1];
                    puzzle[nullposition-1] = puzzle[nullposition];
                    puzzle[nullposition] = tmp;

                    pirntpuzzle(puzzle);
                    if(checkpuzzle(puzzle)==1){
                        return 0;
                    }
                    nullposition = nullposition-1;
                }
                else{
                    printf("이동할 방향이 없습니다.\n");
                }

            }
            else if(ch == 113){//q
                printf("종료합니다.");
            }
            else{
                printf("잘못된 방향으로 입력하였습니다. 다시 입력해주세요.\n");
            }
        }
    }

    return 0;
}