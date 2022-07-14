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

    // ref ITOA : https://www.strudel.org.uk/itoa/
	char* their_itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
    int my_strlen(char* param_1){
        int i = 0;
        while (param_1[i] != '\0'){
            i++;
        }
        return(i);
    }

int main(int argc, char** argv){

    int array[SIZE_MAX] = {0};

    for(int x = 1; x < argc; x++){
        for(int y = 0; argv[x][y] != '\0'; y++){
            int decoy = (int)argv[x][y];
            array[decoy] += 1;
            if(array[decoy] > 32766){
                printf("int fail");
                return 0; 
            }
        }
    }

    for(int c = 0; c < 128;c++){
        if(array[c] > 0){
            int n =  array[c] + 48;
            write(1, &c, 1);
            write(1,":",1);
            
            if(n >= 58){
                n = n - 48;
                int sizen = 0;
                char buffer[5] = {0};
                their_itoa(n, buffer, 10);
                sizen = my_strlen(buffer);
                write(1, buffer,sizen);
            }else{
                write(1, &n, 1);
            }
            write(1,"\n",1);
        }
    }
    return 0;
}    
