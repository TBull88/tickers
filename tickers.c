#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_user_input(char **user_input) {
        char temp_buff[5];
        char *end_ptr;
        printf("Enter the ticker for the company you wish to display ==> ");
        fgets(temp_buff, 5, stdin);
        // puts(user_input);
        *user_input = strdup(temp_buff);
        // return user_input;


}

void find_ticker_symbol(char *companies, const char *user_input) {
        char *company_name[225] = {0};
        char delim[] = ":\n";
        int i = 0;
        // int j = 0;
        // puts(user_input);
        company_name[i] = strtok(companies, delim);

        while(company_name[i] != NULL) {
                // printf("%s\n", company_name[i]);
                company_name[++i] = strtok(NULL, delim);
        }
        for (int j = 0; j < sizeof(company_name); j++) {
                // puts(user_input);
                // puts(company_name[j]);
                if (strcmp(user_input, company_name[j]) == 0) {
                        printf("%s\n", company_name[++j]);
                }
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
        char *user_input = NULL;
        get_user_input(&user_input);
        // puts("IN main");
        // puts(&user_input);
        find_ticker_symbol(companies, user_input);
}