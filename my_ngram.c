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
|
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


#define SIZE_MAX 128

int main(int argc, char** argv){
    char array[SIZE_MAX] = {0};

    for(int x = 1; x < argc; x++){
        for(int y = 0; argv[x][y] != '\0'; y++){
            int decoy = (int)argv[x][y];
            array[decoy] += 1;
        }
    }

    for(int c = 0; c < 128;c++){
        if(array[c] > 0){
            int n =  array[c] + 48;
            
            write(1, &c, 1);
            write(1,":",1);
            write(1, &n, 1);
            write(1,"\n",1);
        }
    }
    return 0;
}    
