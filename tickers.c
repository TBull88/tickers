#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_user_input(void) {
        char buffer[5];
        char *end_ptr;
        printf("Enter the ticker for the company you wish to display ==> ");
        fgets(buffer, 5, stdin);
        // printf("%s\n", buffer);
        
}

// void find_ticker_symbol(char *tickers) {

// }

int main(void) {
        FILE *stream;
        // Open file tickers.txt
        if ((stream = fopen("tickers.txt", "r")) == NULL) {
                perror("Could not open file");
                exit(EXIT_FAILURE);
        } 

        fseek(stream, 0, SEEK_END); // Move pointer to end of file
        long file_size = ftell(stream); // file size = 221
        // printf("%ld\n", file_size);
        fseek(stream, 0, SEEK_SET); // Move pointer back to start of file
        char tickers[file_size];
        int count = fread(tickers, sizeof(char), file_size, stream);
        fclose(stream);
        tickers[count] = '\0';
        // printf("%s\n", tickers);
        get_user_input();
}