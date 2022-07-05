/*

|B
|y        ┌────────────────────────────────────────────────────────────9─────────────────────────────────────┐
|         |abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst|
|L        |1┌─────────────────────6───────────────────────────────5────────────────────────────────────────┐9|
|U        |2|   b           r                l                                4                 7       u  |8|
|L        |3|    2       ███╗   ███╗██╗   ██╗    ███╗   ██╗ ██████╗ ██████╗  █████╗ ███╗   ███╗   g        |7|
|O        |4|            ████╗ ████║╚██╗ ██╔╝    ████╗  ██║██╔════╝ ██╔══██╗██╔══██╗████╗ ████║        n   |6|
|         |5|       5    ██╔████╔██║ ╚████╔╝  4  ██╔██╗ ██║██║ 3███╗██████╔╝███████║██╔████╔██║            |5|
|2        |6| x          ██║╚██╔╝██║  ╚██╔╝      ██║╚██╗██║██║   ██║██╔══██╗██╔══██║██║╚██╔╝██║      6     |4|
|0        |7|         y  ██║ ╚═╝ ██║   ██║  h    ██║ ╚████║╚██████╔╝██║8 ██║██║  ██║██║ ╚═╝ ██║        i   |3|
|2        |8|  t         ╚═╝  0  ╚═╝   ╚═╝       ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝ j   ╚═╝  z         |2|
|2        |9└──────────────────────────────────────────────────────────────────────────p───────────────────┘1|
|         |abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst|
|         └─────────────────────────────────────────────1────────────────────────────────────────────────────┘

*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define SIZE_MAX 128

int main(int argc, char** argv){
int fd =0, write_fd =0;
    char array[SIZE_MAX] = {0};

    for(int x = 1; x < argc; x++){
        for(int y = 0; argv[x][y] != '\0'; y++){
            int decoy = (int)argv[x][y];
            array[decoy] += 1;
        }
    }

    for(int i = 0; i < 128;i++){
        if(array[i] > 0){
            printf("%c:", i);
            printf("%i\n", array[i]);
            
            //write(1,&array[i],1);

        }
    }
    return 0;
}    
