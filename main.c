#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_if_two_strings_equal(char first[], char second[]);
void help_create();
int create();
int copy();
void help_copy();
int remove_file();
void help_remove();
int rename_file();
void help_rename();
void help_append();
int append_file();
int move();
int delete_text();
void help_show_text();
int show_text();
void help_delete_text();
void help_move();

int main()
{
    // COMMANDS :
    // E : Exit
    // C : Create
    // D : Delete
    // R : Rename
    // O : Copy
    // M : Move
    char command[256];
    int can_finish = 0;

    printf("Select a command:\n");
    printf("E : Exit\n");
    printf("C : Create\n");
    printf("D : Delete\n");
    printf("R : Rename\n");
    printf("O : Copy\n");
    printf("M : Move\n");
    printf("A : Append Text\n");
    printf("T : Delete Text\n");
    printf("S : Show Text\n");

    while(command[0] != 'E' && can_finish == 0){
        printf("command > ");
        gets(command);
        if(command[0] == 'C'){
            char x[256] = "C /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_create();
            }else {
                create();
            }
        } else if(command[0] == 'O'){
            char x[256] = "O /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_copy();
            }else {
                copy();
            }
        } else if(command[0] == 'D'){
            char x[256] = "D /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_remove();
            }else {
                remove_file();
            }
        } else if(command[0] == 'R'){
            // Rename
            char x[256] = "R /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_rename();
            }else {
                rename_file();
            }
        }
        else if(command[0] == 'A'){
            // Append
            char x[256] = "A /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_append();
            }else {
                append_file();
            }
        }
        else if(command[0] == 'T'){
            // Append
            char x[256] = "T /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_delete_text();
            }else {
                delete_text();
            }
        }
        else if(command[0] == 'S'){
            // Append
            char x[256] = "S /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_show_text();
            }else {
                show_text();
            }
        }
        else if(command[0] == 'M'){
            // Append
            char x[256] = "M /h";
            int result = check_if_two_strings_equal(x, command);
            if (result == 1){
                help_move();
            }
            else {
                move();
            }
        }
    }
}

void help_move()
{
    printf("help for show text\n");
}

int move()
{
    char source[100], target[100];
    printf("Enter the file name to be copied: ");
    scanf("%s", source);
    printf("Enter the destination that file will be pasted: ");
    scanf("%s", target);
    int source_size = (int)strlen(source);
    int target_size = (int)strlen(target);
    target[target_size] = '/';
    target[target_size + 1] = '\0';
    target_size++;
    int i;
    for (i = 0; i < source_size; i++){
        target[target_size++] = source[i];
    }
    target[target_size] = '\0';
    FILE *read, *write;
    read = fopen(source, "r");
    if (!read){
        printf("Source file could not be opened. Copy process is cancelled.\n");
        return -1;
    }
    if (fopen(target, "r")){
        printf("Destination includes same file named with %s, press 1 to replace, press 2 to cancel copy process: ", source);
        int a = -1;
        scanf("%d", &a);
        if (a == 1){
            write = fopen(target, "w");
        }
        else if (a == 2){
            printf("Copy process is cancelled.\n");
            return -1;
        }
        else{
            printf("Invalid choice. Copy process is cancelled.\n");
            return -1;
        }
    }
    else{
        write = fopen(target, "w");
    }
    if (!write){
        printf("Destination could not be accessed. Copy process is cancelled.\n");
        return -1;
    }
    char c;
    while (!feof(read)){
        c = getc(read);
        if (feof(read)){
            break;
        }
        fputc(c, write);
    }
    fclose(read);
    fclose(write);
    printf("Copy process is completed successfuly.\n");
    remove(source);
}

void help_show_text()
{
    printf("help for show text\n");
}

int show_text(){
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE *fptr;
    char there_was_error = 0;
    char opened_in_read  = 1;
    fptr = fopen(path, "r");
    if(fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        int x;
        while ((x = fgetc(fptr)) != EOF) {
                putchar(x);
            }
        printf("\n");
        fclose(fptr);
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been created and the path is %s", path);
    return EXIT_SUCCESS;
}

void help_delete_text(){
     printf("help for delete text\n");
}

int delete_text(){
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE *fptr;
    char there_was_error = 0;
    char opened_in_read  = 1;
    fptr = fopen(path, "w+");
    if(fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        fclose(fptr);
        printf("Text int the file was deleted successfully");
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been created and the path is %s", path);
    return EXIT_SUCCESS;
}

void help_append(){
     printf("help for append\n");
}

int append_file(){
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE *fptr;
    char there_was_error = 0;
    char opened_in_read  = 1;
    fptr = fopen(path, "a");
    if(fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        char *appendText = malloc(100);
        printf("Enter a text ->\n");
        scanf(" %[^\n]s ",appendText);
        if (appendText[0]!='\0'){
            fprintf(fptr, "%s", appendText);
        }
        fclose(fptr);
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been created and the path is %s", path);
    return EXIT_SUCCESS;
}

int check_if_two_strings_equal(char first[], char second[]){
        int i = 0;
        while(i < sizeof(first) && i < sizeof(second)){
            if (first[i] != second[i])
                return 0;
            i++;
        }
        return 1;
}

void help_create(){
    printf("help for create\n");
}

int create(){
    printf("Enter the name of file \nfilename > ");
    char path[100];

    scanf("%s", path);

    FILE *fptr;
    char there_was_error = 0;
    char opened_in_read  = 1;
    fptr = fopen(path, "rb+");
    if(fptr == NULL) //if file does not exist, create it
    {
        opened_in_read = 0;
        fptr = fopen(path, "wb");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        printf("The file already exists");
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been created and the path is %s", path);
    return EXIT_SUCCESS;
}

void help_copy(){
    printf("help for copy");
}

int copy(){
    char source[100], target[100];
    printf("Enter the file name to be copied: ");
    scanf("%s", source);
    printf("Enter the destination that file will be pasted: ");
    scanf("%s", target);
    int source_size = (int)strlen(source);
    int target_size = (int)strlen(target);
    target[target_size] = '/';
    target[target_size + 1] = '\0';
    target_size++;
    int i;
    for (i = 0; i < source_size; i++){
        target[target_size++] = source[i];
    }
    target[target_size] = '\0';
    FILE *read, *write;
    read = fopen(source, "r");
    if (!read){
        printf("Source file could not be opened. Copy process is cancelled.\n");
        return -1;
    }
    if (fopen(target, "r")){
        printf("Destination includes same file named with %s, press 1 to replace, press 2 to cancel copy process: ", source);
        int a = -1;
        scanf("%d", &a);
        if (a == 1){
            write = fopen(target, "w");
        }
        else if (a == 2){
            printf("Copy process is cancelled.\n");
            return -1;
        }
        else{
            printf("Invalid choice. Copy process is cancelled.\n");
            return -1;
        }
    }
    else{
        write = fopen(target, "w");
    }
    if (!write){
        printf("Destination could not be accessed. Copy process is cancelled.\n");
        return -1;
    }
    char c;
    while (!feof(read)){
        c = getc(read);
        if (feof(read)){
            break;
        }
        fputc(c, write);
    }
    fclose(read);
    fclose(write);
    printf("Copy process is completed successfuly.\n");
}

void help_remove(){
    printf("help for remove");
}

int remove_file(){
    printf("Enter the name of file \nfilename > ");
    char path[100];
    int ret;

    scanf("%s", path);
    FILE *fp;

    ret = remove(path);

     if(ret == 0)
   {
      printf("File deleted successfully");
      return 0;
   }
   else
   {
      printf("Error: unable to delete the file");
      return 1;
   }

}

void help_rename(){
    printf("help for rename");
}

int rename_file(){
    int result;
    printf("Enter the name of file you want to rename \nfilename > ");
    char file_path_to_rename[100];
    scanf("%s", file_path_to_rename);

    printf("Enter the name of file you want to rename as \nfilename > ");
    char file_name_to_rename[100];
    scanf("%s", file_name_to_rename);

    result = rename(file_path_to_rename, file_name_to_rename);
    if(result == 0)
   {
      printf("File renamed successfully");
      return 0;
   }
   else
   {
      printf("Error: unable to rename the file");
      return 1;
   }
}
