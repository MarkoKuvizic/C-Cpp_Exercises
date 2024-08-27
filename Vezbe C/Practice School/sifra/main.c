#include <stdio.h>
#include <stdlib.h>
void encrypt(char *string){

    while(*string!=0){
        if(*string >='a' && *string<='z'){
            *string-=31;

            if(*string == 'z' + 1 ){

                *string = 'A';
            }

        }
        else if(*string>= 'A' && *string<='Z'){

            *string+=33;

            if(*string == 'Z' + 1 ){

                string = 'a';
            }
        }

     string++;

    }

}
int main()
{
    FILE *citanje, *pisanje;

    citanje = fopen("decrypted.txt", "r+");
    pisanje = fopen("encrypted.txt", "w+");
    char c[80];

    while(fgets(c, 80, citanje) != NULL){
        encrypt(c);
        fputs(c, pisanje);

    }
	fclose(citanje)
	fclose(pisanje)

    return 0;
}
