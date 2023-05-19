#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_user_input(void) {
        char user_input[5];
        char *end_ptr;
        printf("Enter the ticker for the company you wish to display ==> ");
        fgets(user_input, 5, stdin);
        return user_input;


}

void find_ticker_symbol(char *companies, char *user_input) {
        char *company_name[30];
        char delim[] = "\n:";
        int i = 0;
        company_name[i] = strtok(companies, delim);

        while(company_name[i] != NULL) {
                company_name[++i] = strtok(NULL, delim);
        }
}

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
        char companies[file_size];
        int count = fread(companies, sizeof(char), file_size, stream);
        fclose(stream);
        companies[count] = '\0';
        // printf("%s\n", tickers);
        char user_input = get_user_input();
}