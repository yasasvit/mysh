#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "words.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fnmatch.h>

typedef struct _Node {
    char* word;
    struct _Node* next; 
} N;

N* head;
N* tail;
int size;
char* HOME;
int batch;

void execute(char** args, int argcount, N** start) {
    N* top = *start;
    // Print list
    N* ptr100 = head;
    while (ptr100) {
        // printf("%s\n", ptr->word);
        ptr100 = ptr100->next;
    }
    if (argcount == 0 || strcmp(args[0], "") == 0) return;

    char* cmd = (char*) malloc(strlen(args[0])+1);
    strcpy(cmd, args[0]);
    struct stat file_stat;
    char *dest1 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest1, "/usr/local/sbin/");
    strncat(dest1, cmd, strlen(cmd));
    char *dest2 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest2, "/usr/local/bin/");
    strncat(dest2, cmd, strlen(cmd));
    char *dest3 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest3, "/usr/sbin/");
    strncat(dest3, cmd, strlen(cmd));
    char *dest4 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest4, "/usr/bin/");
    strncat(dest4, cmd, strlen(cmd));
    char *dest5 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest5, "/sbin/");
    strncat(dest5, cmd, strlen(cmd));
    char *dest6 = (char*)malloc(strlen(cmd) + 20);
    strcpy(dest6, "/bin/");
    strncat(dest6, cmd, strlen(cmd));
     N* ptr200 = head;
    while (ptr200) {
        // printf("%s\n", ptr->word);
        ptr200 = ptr200->next;
    }
     N* ptr300 = head;
    while (ptr300) {
        // printf("%s\n", ptr->word);
        ptr300 = ptr300->next;
    }
    if (strcmp(cmd, "cd") == 0) {
        int err = argcount == 1 ? chdir(HOME) : chdir(args[1]);
        if (err == -1) {
            perror("cd");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        }
        // if (argcount == 1) {
        //     if (chdir(HOME) == -1) {
        //         perror("cd");
        //     }
        // } else {
        //     // REDIRECTION
        //     // printf("%s\n", ptr->next->word);
        //     if (chdir(args[1]) == -1) {
        //         perror("cd");
                
        //     }
        // }
         N* ptr400 = head;
        while (ptr400) {
            // printf("%s\n", ptr->word);
            ptr400 = ptr400->next;
        }
    } else if (strcmp(cmd, "exit") == 0) {
        N* free_ptr = top->next;
         N* ptr500 = head;
        while (ptr500) {
            // printf("%s\n", ptr->word);
            ptr500 = ptr500->next;
        }
        while (free_ptr != NULL) {
            N* free_temp = free_ptr;
            free_ptr = free_ptr->next;
            free(free_temp->word);
            free(free_temp);
        }
        free(head);
        for (int i = 0; i < argcount+1; i++) {
            free(args[i]);
        }
         N* ptr600 = head;
        while (ptr600) {
            // printf("%s\n", ptr->word);
            ptr600= ptr600->next;
        }
        wait(NULL);
        if (!batch)
            write(1, "mysh: exiting\n", 14);
        while(1) exit(0);
         N* ptr700 = head;
        while (ptr700) {
            // printf("%s\n", ptr->word);
            ptr700 = ptr700->next;
        }
        // REMEMBER TO EXIT PROGRAM AND FREE NEW_WORD IN MAIN()
    } else if (strcmp(cmd, "pwd") == 0) {
        char buffer[1000];
        char* res = getcwd(buffer, sizeof(buffer));
        // PRINTING LIST
         N* ptr800 = head;
        while (ptr800) {
            // printf("%s\n", ptr->word);
            ptr800 = ptr800->next;
        }
        if (res) {
            wait(NULL);
            write(1, buffer, strlen(buffer));
            write(1, "\n", 1);
        } else {
            perror("pwd");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        }
            // err = argcount == 1 ? chdir(HOME) : chdir(args[1]);
            // if (err == -1) {
            //     perror("cd");
            // } 
        // PRINTING LIST
        N* ptr900 = head;
        while (ptr900) {
            // printf("%s\n", ptr->word);
            ptr900 = ptr900->next;
        }
        // char buffer[1000];
        // if (getcwd(buffer, sizeof(buffer)) != NULL) {
        //     puts(buffer);
        // } else {
        //     perror("pwd2");
        // }
    } else if (stat(dest1, &file_stat) == 0) {
        // PRINTING LIST
        N* ptr1000 = head;
        while (ptr1000) {
            // printf("%s\n", ptr->word);
            ptr1000 = ptr1000->next;
        }
        int pid, wstatus;
        pid = fork();
        if (pid < 0) {
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr1100 = head;
        while (ptr1100) {
            // printf("%s\n", ptr->word);
            ptr1100 = ptr1100->next;
        }
            execv(dest1, args);
            perror(cmd);
            exit(1);
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            //exit(0);
            // printf("still working\n");  
        }
    } else if (stat(dest2, &file_stat) == 0) {
        int pid, wstatus;
        pid = fork();
        // PRINTING LIST
         N* ptr1200 = head;
        while (ptr1200) {
            // printf("%s\n", ptr->word);
            ptr1200 = ptr1200->next;
        }
        if (pid < 0) {
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr1300 = head;
        while (ptr1300) {
            // printf("%s\n", ptr->word);
            ptr1300 = ptr1300->next;
        }
            execv(dest2, args);
            perror(cmd);
            
            exit(1);
            // PRINTING LIST
         N* ptr1400 = head;
        while (ptr1400) {
            // printf("%s\n", ptr->word);
            ptr1400 = ptr1400->next;
        }
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    } else if (stat(dest3, &file_stat) == 0) {
        int pid, wstatus;
        pid = fork();
        if (pid < 0) {
            // PRINTING LIST
         N* ptr1500 = head;
        while (ptr1500) {
            // printf("%s\n", ptr->word);
            ptr1500 = ptr1500->next;
        }
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr1600 = head;
        while (ptr1600) {
            // printf("%s\n", ptr->word);
            ptr1600 = ptr1600->next;
        }
            execv(dest3, args);
            perror(cmd);
            exit(1);
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    } else if (stat(dest4, &file_stat) == 0) {
        int pid, wstatus;
        pid = fork();
        if (pid < 0) {
            // PRINTING LIST
         N* ptr1700 = head;
        while (ptr1700) {
            // printf("%s\n", ptr->word);
            ptr1700 = ptr1700->next;
        }
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr1800 = head;
        while (ptr1800) {
            // printf("%s\n", ptr->word);
            ptr1800 = ptr1800->next;
        }
            execv(dest4, args);
            perror(cmd);
            exit(1);
            // printf("still working\n");
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // if (!batch) {wait(NULL); write(1, "!", 1);}
            
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    } else if (stat(dest5, &file_stat) == 0) {
        int pid, wstatus;
        pid = fork();
        // PRINTING LIST
         N* ptr = head;
        while (ptr) {
            // printf("%s\n", ptr->word);
            ptr = ptr->next;
        }
        if (pid < 0) {
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr1900 = head;
        while (ptr1900) {
            // printf("%s\n", ptr->word);
            ptr1900 = ptr1900->next;
        }
            execv(dest5, args);
            perror(cmd);
            exit(1);
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    } else if (stat(dest6, &file_stat) == 0) {
        // PRINTING LIST
         N* ptr2000 = head;
        while (ptr2000) {
            // printf("%s\n", ptr->word);
            ptr2000 = ptr2000->next;
        }
        int pid, wstatus;
        pid = fork();
        if (pid < 0) {
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            // PRINTING LIST
         N* ptr2100 = head;
        while (ptr2100) {
            // printf("%s\n", ptr->word);
            ptr2100 = ptr2100->next;
        }
            execv(dest6, args);
            perror(cmd);
            exit(1);
        } else {
            // PRINTING LIST
         N* ptr2200 = head;
        while (ptr2200) {
            // printf("%s\n", ptr->word);
            ptr2200 = ptr2200->next;
        }
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    } else {
        int pid, wstatus;
        pid = fork();
        if (pid < 0) {
            perror("fork");
            if (!batch) {wait(NULL); write(1, "!", 1);}
        } else if (pid == 0) {
            execv(cmd, args);
            wait(NULL);
            write(1, cmd, strlen(cmd));
            write(1, ": command not found\n", 20);
            exit(1);
        } else {
            wait(&wstatus);
            if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) && !batch) {wait(NULL); write(1, "!", 1);}
            // printf("Worked\n");
            // //exit(0);
            // printf("still working\n");
        }
    }
    
    free(cmd);
    free(dest1);
    free(dest2);
    free(dest3);
    free(dest4);
    free(dest5);
    free(dest6);
    // PRINTING LIST
         N* ptr2300 = head;
        while (ptr2300) {
            // printf("%s\n", ptr->word);
            ptr2300 = ptr2300->next;
        }
}

int main(int argc, char** argv) {
    N* head = (N*) malloc(sizeof(N));
    head->next = NULL;
    // strcpy(head->word, "dummy");
    tail = head;
    size = 0;
    HOME = getenv("HOME");
    // PRINTING LIST
         N* ptr2400 = head;
        while (ptr2400) {
            // printf("%s\n", ptr->word);
            ptr2400 = ptr2400->next;
        }

    char *new_word;
    int fd = STDIN_FILENO;
    batch = 0;
    if (argc > 1) {
        batch = 1;
        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            perror("open");
            if (!batch) {wait(NULL); write(1, "!", 1);}
            exit(1);
        }
    }

    // PRINTING LIST
         N* ptr2500 = head;
        while (ptr2500) {
            // printf("%s\n", ptr->word);
            ptr2500 = ptr2500->next;
        }
    words_init(fd);
    // printf("ggggg\n");
    if (!batch) {
        wait(NULL);
        write(1, "Welcome to my shell!\n", 21);
        write(1, "mysh> ", 6);
    }
    // PRINTING LIST
         N* ptr2600 = head;
        while (ptr2600) {
            // printf("%s\n", ptr->word);
            ptr2600 = ptr2600->next;
        }
    int allow_newline = 1;
    while ((new_word = words_next())) {   

        if (strcmp(new_word, "") == 0) {
            continue;
        }

        int wordlen = strlen(new_word);
        // printf("ggggg\n");
        if (new_word[wordlen-1] == '<' || new_word[wordlen-1] == '>' || new_word[wordlen-1] == '|') {
            N* new_node = (N*) malloc(sizeof(N));
            new_node->next = NULL;
            tail->next = new_node;
            tail = tail->next;
            size++;
            new_node->word = (char*) malloc(sizeof(char) * (wordlen+1));
            strncpy(new_node->word, new_word, wordlen+1);
            if (wordlen >= 2) {
                new_node->word[wordlen-1] = '\0';
                N* new_node_2 = (N*) malloc(sizeof(N));
                new_node_2->next = NULL;
                tail->next = new_node_2;
                tail = tail->next;
                size++;
                new_node_2->word = (char*) malloc(sizeof(char) * (4));
                new_node_2->word[0] = new_word[wordlen - 1];
                new_node_2->word[1] = '\0';
            }
            // PRINTING LIST
         N* ptr2700 = head;
        while (ptr2700) {
            // printf("%s\n", ptr->word);
            ptr2700 = ptr2700->next;
        }
        }
        else if (new_word[wordlen-1] == '\n') {
            if (wordlen > 1) {
      
                N* new_node = (N*) malloc(sizeof(N));
                new_node->next = NULL;
                tail->next = new_node;
                
                tail = tail->next;
                size++;
                new_node->word = (char*) malloc(sizeof(char) * (wordlen+1));
                strncpy(new_node->word, new_word, wordlen+1);
                new_node->word[wordlen-1] = '\0';
            }
            
            // execute...
            if (size == 0) {
                // PRINTING LIST
             if (allow_newline && !batch) {
                    wait(NULL);
                    write(1, "mysh> ", 6);
                }
                free(new_word);
                continue;
            }
            // printf("fff\n");
            // printf("112212\n");
            N* nodeCopy100 = (N*)(malloc(sizeof(N)));
            free(nodeCopy100);
            // HOME dir ~
            N* ptr70 = head->next;
            while (ptr70) {
                if (strlen(ptr70->word) >= 2 && ptr70->word[0] == '~' && ptr70->word[1] == '/') {

                    char* tempWord = (char*) malloc(strlen(ptr70->word)+1);
                    strcpy(tempWord, ptr70->word);
                    int i = 0; 
                    ptr70->word = (char*) realloc(ptr70->word, strlen(HOME) + strlen(tempWord) + 1);
                    strcpy(ptr70->word, HOME);
                    i += 1;
                    strcat(ptr70->word, tempWord+1);
                    i += 1;
                    free(tempWord);
                    // PRINTING LIST
                    N* ptr = head;
                    while (ptr) {
                        // printf("%s\n", ptr->word);
                        ptr = ptr->next;
                    }
                } else if (strlen(ptr70->word) == 1 && ptr70->word[0] == '~') {
                    int j = 0; 
                    ptr70->word = (char*) realloc(ptr70->word, strlen(HOME) + strlen(ptr70->word) + 1);
                    strcpy(ptr70->word, HOME);
                    j += 1;
                    // PRINTING LIST
                    N* ptr = head;
                    while (ptr) {
                        // printf("%s\n", ptr->word);
                        ptr = ptr->next;
                    }
                } 
                ptr70 = ptr70->next;
            }

            N* nodeCopy = (N*)(malloc(sizeof(N)));
            free(nodeCopy);

            N* ptr30 = head;
            while (ptr30->next) {
                int wildcard = 0;
                int backslash = 0;
                for(int i = 0; i < strlen(ptr30->next->word); i += 1) {
                    if (ptr30->next->word[i] == '/') {
                        backslash = 1;
                    } else if (ptr30->next->word[i] == '*') {
                        wildcard = 1;
                    }
                   
                }
                if (!wildcard) {
                    // ptr20 = ptr20->next;
                    ptr30 = ptr30->next;
                    continue;
                }
                
                if (!backslash) {

                    DIR *dir;
                    struct dirent *entry;

                    dir = opendir(".");
                    if (dir == NULL) {
                        perror("opendir");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    
                    int matched = 0;
                    while ((entry = readdir(dir)) != NULL) {
                        // printf("fff\n");
                        // printf("%s\n", entry->d_name);
                        if (entry->d_name[0] != '.' && fnmatch(ptr30->next->word, entry->d_name, 0) == 0) {
                            // printf("Match: %s\n", entry->d_name);
                            // printf("yoloyolo\n");
                            N* wild_match = (N*) malloc(sizeof(N));
                            wild_match->word = (char*) malloc(strlen(entry->d_name) + 1);
                            strcpy(wild_match->word, entry->d_name);
                            wild_match->next = ptr30->next->next;
                            ptr30->next->next = wild_match;
                            matched = 1;
                            size++;
                            // ptr20->word = realloc(ptr20->word, strlen(entry->d_name) + 1);
                            // strcpy(ptr20->word, entry->d_name);
                            // printf("wtffff\n");
                            
                        }

                        // printf("ggg\n");
                    }

                    if (matched) {
                        N* temp30 = ptr30->next;
                        ptr30->next = ptr30->next->next;
                        free(temp30->word);
                        free(temp30);
                        size--;
                    }
                    
                    closedir(dir);
                    
                } else {
                    char originalDir[1000];
                    getcwd(originalDir, sizeof(originalDir));

                    char *dirPath = (char *) (malloc(strlen(ptr30->next->word) + 1));
                    strcpy(dirPath, ptr30->next->word);
                    char * copyDirPath = (char *) (malloc(strlen(ptr30->next->word) + 1));
                    strcpy(copyDirPath, ptr30->next->word);
                    // printf("%s\n", dirPath);
                    int index = 0;
                    int matched = 0;
                    char* token; // IDK IF NEED TO MALLOC
                    // token = (char *) malloc(100);
                    // FIRST TOKEN
                    token = strtok(dirPath, "/");
                    // printf("%s\n", token); <- CORRECT
                    int wildcard = 0;
                    for (int i = 0; i < strlen(token); i += 1) {
                        if (token[i] == '*') {
                            wildcard = 1;
                            break;
                        }
                    }

                    DIR *dir;
                    struct dirent *entry;
                    dir = opendir(".");
                    index += strlen(token)+1;
                    //printf("token: %s\n", token);
                    //printf("restPath: %s\n", copyDirPath+index);
                    if (wildcard) {
                        while ((entry = readdir(dir)) != NULL) {
                            // compare prefixes
                        // printf("fff\n");
                        //   printf("%s\n", entry->d_name);
                            //printf("entry: %s\n", entry->d_name);
                            if (entry->d_name[0] != '.' && fnmatch(token, entry->d_name, 0) == 0) {
                                //printf("MATCHED\n");
                                // printf("Match: %s\n", entry->d_name);
                                // printf("yoloyolo\n");
                                // SHOULD ALWAYS MATCH NEXT TOKEN
                                char* fullPath = (char*)(malloc(strlen(copyDirPath)+50));
                                // strcpy(fullPath, "/");
                                // strcat(fullPath, entry->d_name);
                                strcpy(fullPath, entry->d_name);
                                // printf("%s\n", fullPath); // <- WORKS NOW
                                char* restPath = copyDirPath + index;
                                // printf("%s\n", restPath);
                                strcat(fullPath, "/");
                                strcat(fullPath, restPath);
                                
                                // printf("FULL PATH: %s\n", fullPath);
                                struct stat file_stat;

                                if (stat(fullPath, &file_stat) == 0) {
                                     N* wild_match = (N*) malloc(sizeof(N));
                                    wild_match->word = (char*) malloc(strlen(copyDirPath)+50);
                                    strcpy(wild_match->word, fullPath);
                                    wild_match->next = ptr30->next->next;
                                    ptr30->next->next = wild_match;
                                    matched = 1;
                                    size++;
                                } 

                                // ptr20->word = realloc(ptr20->word, strlen(entry->d_name) + 1);
                                // strcpy(ptr20->word, entry->d_name);
                                // printf("wtffff\n");
                                free(fullPath);
                            }

                        // printf("ggg\n");
                        }
                        if (matched) {
                            N* temp30 = ptr30->next;
                            ptr30->next = ptr30->next->next;
                            free(temp30->word);
                            free(temp30);
                            size--;
                        }
                    } else {
                        //printf("CHANGED DIR\n");
                        chdir(token);
                    }
                    //printf("%d\n", index);
                    char* tempPath = (char*) (calloc(strlen(copyDirPath)+50, 1));
                    while (token != NULL) {
                        token = strtok(NULL, "/");
                        if (token == NULL) {
                            break;
                        }
                        // NOTE
                        // printf("%s\n", token);
                        int wildcard = 0;
                        for (int i = 0; i < strlen(token); i += 1) {
                            if (token[i] == '*') {
                                wildcard = 1;
                                break;
                            }
                        }
                        DIR *dir;
                        struct dirent *entry;
                        dir = opendir(".");
                        // printf("%s\n", copyDirPath);
                        if (wildcard) {
                            // printf("%s\n", tempPath);
                            strncpy(tempPath, copyDirPath, index);
                            //
                            //strcat(tempPath, "/");
                            // printf("TEMP PATH: %s %d\n", tempPath, index);
                        }
                        index += 1 + strlen(token);
                        // printf("%d\n", index);
                        if (wildcard) {
                            while ((entry = readdir(dir)) != NULL) {
                            // printf("fff\n");
                            //   printf("%s\n", entry->d_name);
                            
                                if (entry->d_name[0] != '.' && fnmatch(token, entry->d_name, 0) == 0) {
                                    // printf("Match: %s\n", entry->d_name);
                                    // printf("yoloyolo\n");
                                    // SHOULD ALWAYS MATCH NEXT TOKEN
                                    // printf("WENT IN IF\n");
                                    char* fullPath = (char*)(malloc(strlen(copyDirPath)+50));
                                    // strcpy(fullPath, "/");
                                    // strcat(fullPath, entry->d_name);
                                    strcpy(fullPath, entry->d_name);
                                    // printf("1st Full -> %s\n", fullPath);
                                    // printf("%s\n", fullPath); // <- WORKS NOW
                                    
                                    char* restPath = copyDirPath + index;
                                    // printf("Rest -> %s\n", fullPath);
                                    
                                    // printf("%s\n", restPath);
                                    if (index < strlen(copyDirPath)) {
                                        strcat(fullPath, "/");
                                        strcat(fullPath, restPath);
                                    }
                                    // printf("2nd Full -> %s\n", fullPath);

                                    
                                    struct stat file_stat;

                                    if (stat(fullPath, &file_stat) == 0) {
                                        // printf("FOUND STAT\n");
                                        N* wild_match = (N*) malloc(sizeof(N));
                                        // strcat(tempPath, fullPath);
                                        wild_match->word = (char*) malloc(strlen(tempPath) + strlen(fullPath) + 1);
                                        strcpy(wild_match->word, tempPath);
                                        strcat(wild_match->word, fullPath);
                                        wild_match->next = ptr30->next->next;
                                        ptr30->next->next = wild_match;
                                        matched = 1;
                                        size++;
                                    } 


                                    // ptr20->word = realloc(ptr20->word, strlen(entry->d_name) + 1);
                                    // strcpy(ptr20->word, entry->d_name);
                                    // printf("wtffff\n");
                                    free(fullPath);
                                }

                            // printf("ggg\n");
                            }
                            if (matched) {
                                N* temp30 = ptr30->next;
                                ptr30->next = ptr30->next->next;
                                free(temp30->word);
                                free(temp30);
                                size--;
                            }
                        } else {
                            chdir(token);
                        }
                        closedir(dir);

                    }
                    closedir(dir);
                    free(tempPath);
                    free(dirPath);
                    free(copyDirPath);
                    // free(token);
                    chdir(originalDir);

                }
                
                // ptr20 = ptr20->next;
                ptr30 = ptr30->next;
            }


                int totalCount = 0;
                // Construct args array
                int pipe2 = 0;
                int argcount = 0;
                int argcount2 = 0;
                N* ptr40 = head->next;
                int inCount = 0;
                int outCount = 0;
                while (ptr40) {
                    if (strcmp(ptr40->word, "<") == 0 || strcmp(ptr40->word, ">") == 0) {
                        if (strcmp(ptr40->word, "<") == 0) inCount++;
                        else outCount++;
                        totalCount += 1;

                        if (!pipe2) {
                            totalCount -= 1;
                            argcount--;
                        } else {
                            totalCount -= 1;
                            argcount2--;
                        }
                    } else if (strcmp(ptr40->word, "|") == 0) {
                        pipe2 = 1;
                        totalCount += 1;
                    } else {
                        if (!pipe2) {
                            totalCount += 1;
                            argcount++;
                        } else {
                            totalCount += 1;
                            argcount2++;
                        }
                    }
                    ptr40 = ptr40->next;
                }
                if (totalCount == inCount + outCount + argcount + argcount2) {
                    // printf("same # of args???");
                }

                if (inCount > 1 || outCount > 1) {
                    totalCount = 0; 
                    wait(NULL);
                    write(1, "Too many outputs specified.\n", 28);
                    write(1, "!", 1);
                    N* free_ptr = head->next;
                    while (free_ptr != NULL) {
                        totalCount += 1;
                        // printf("free\n");
                        N* free_temp = free_ptr;
                        free_ptr = free_ptr->next;
                        free(free_temp->word);
                        free(free_temp);
                    }
                    totalCount = 0;
                    size = 0;
                    tail = head;
                    if (allow_newline && !batch) {
                        wait(NULL);
                        write(1, "mysh> ", 6);
                    }
                    free(new_word);
                    continue;
                }
                totalCount = 0;
                char* args[argcount + 1];
                char* args2[argcount2 + 1];

                N* newDummy = (N*) (malloc(sizeof(N)));
                free(newDummy); 

                N* ptr1 = head->next;
                int i = 0;
                char* input_redirection;
                int y = 0;
                int foundInput = 0;
                char* output_redirection;
                int foundOutput = 0;
                int j = 0;
                int z = 0;
                int fillarg2 = 0;
                while (ptr1) {
                    y += 1;
                    if (strcmp(ptr1->word, "<") == 0) {
                        if (foundInput) free(input_redirection);
                        input_redirection = (char*) malloc(strlen(ptr1->next->word)+1);
                        z += 1;
                        for (int i = 0; i < 100; i += 1) {
                            // printf("loop hitting\n");
                        }
                        // printf("%d", i);
                        foundInput = 1;
                        strcpy(input_redirection, ptr1->next->word);
                        y -= 1;
                        ptr1 = ptr1->next;
                    } else if (strcmp(ptr1->word, ">") == 0) {
                        z += 1;
                        if (foundOutput) free(output_redirection);
                        output_redirection = (char*) malloc(strlen(ptr1->next->word)+1);
                        foundOutput = 1;
                        strcpy(output_redirection, ptr1->next->word);
                        ptr1 = ptr1->next;
                        y -= 1;
                    } else if (strcmp(ptr1->word, "|") == 0) {
                        z += 1;
                        fillarg2 = 1;
                        y -= 1;
                    } else {
                        if (!fillarg2){
                            y += 1;
                            args[i] = (char *) (malloc(strlen(ptr1->word) + 1));
                            strcpy(args[i], ptr1->word);
                            i += 1;
                        } else {
                            y += 1;
                            args2[j] = (char *) (malloc(strlen(ptr1->word) + 1));
                            strcpy(args2[j], ptr1->word);
                            j += 1;
                        }
                        if (y == z) {
                            // CHECK Y AND Z LATER
                        }
                    }
                    ptr1 = ptr1->next;
                }
                if (y + z == i + j) {
                    // DO LATER
                } 
                args[argcount] = NULL;
                args2[argcount2] = NULL;
                
                int originalSTDIN = dup(STDIN_FILENO);
                int forkCounts = 0;
                if (foundInput) {
                    int pid;
                    pid = fork();
                    forkCounts += 1;
                    if (pid < 0) {
                        forkCounts -= 1;
                        perror("fork");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                    } else if (pid == 0) {
                        
                        int fd = open(input_redirection, O_RDONLY);
                        if (fd == -1) {
                            forkCounts -= 1;
                            perror("open");
                            if (!batch) {wait(NULL); write(1, "!", 1);}
                            exit(1);
                        } else {
                            exit(0);
                        }

                        if (dup2(fd, STDIN_FILENO) == -1) {
                            perror("dup2");
                            if (!batch) {wait(NULL); write(1, "!", 1);}
                            exit(1);
                        }
                        if (forkCounts == 0) {

                        }
                        close(fd);
                        // exit(1);
                    } else {
                        wait(NULL);
                        // printf("Worked\n");
                        // //exit(0);
                        // printf("still working\n");
                    }
                }
                if (foundInput) {
                    int getout = open(input_redirection, O_RDONLY);
                    if (getout == -1) {
                        //perror("open");
                        N* free_ptr = head->next;
                        while (free_ptr != NULL) {
                            // printf("free\n");
                            N* free_temp = free_ptr;
                            free_ptr = free_ptr->next;
                            free(free_temp->word);
                            free(free_temp);
                        }
                        size = 0;
                        tail = head;
                        if (allow_newline && !batch) {
                            wait(NULL);
                            write(1, "mysh> ", 6);
                        }
                        free(new_word);
                        dup2(originalSTDIN, STDIN_FILENO);
                        close(originalSTDIN);
                        free(input_redirection);
                        if (foundOutput)
                            free(output_redirection);
                        for (int i = 0; i <= argcount; i++) free(args[i]);
                        if (pipe2) {
                            for (int i = 0; i <= argcount2; i++) free(args2[i]);
                        }
                        continue;
                    } else {
                        close(getout);
                    }
                }
                int inputFound1 = 0;
                if (foundInput) {
                    int fd = open(input_redirection, O_RDONLY);
                     if (fd == -1) {
                        inputFound1 += 1;
                        perror("open");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    if (dup2(fd, STDIN_FILENO) == -1) {
                        inputFound1 -= 1;
                        perror("dup2");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    close(fd);

                    free(input_redirection);
                }
                int outputFound1 = 0;
                int originalSTDOUT = dup(STDOUT_FILENO);
                if (foundOutput) {
                    int pid;
                    pid = fork();
                    if (pid < 0) {
                        outputFound1 += 1;
                        perror("fork");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                    } else if (pid == 0) {
                        outputFound1 -= 1;
                        int fd = open(output_redirection, O_WRONLY | O_CREAT | O_TRUNC, 0640);
                        if (fd == -1) {
                            perror("open");
                            if (!batch) {wait(NULL); write(1, "!", 1);}
                            exit(1);
                        }
                        if (dup2(fd, STDOUT_FILENO) == -1) {
                            perror("dup2");
                            if (!batch) {wait(NULL); write(1, "!", 1);}
                            exit(1);
                        }
                        close(fd);
                        exit(1);
                    } else {
                        wait(NULL);
                        // printf("Worked\n");
                        // //exit(0);
                        // printf("still working\n");
                    }
                }
                int outputFound2 = 0;
                if (foundOutput) {
                    int fd = open(output_redirection, O_WRONLY | O_CREAT | O_TRUNC, 0640);
                    if (fd == -1) {
                        outputFound2 += 1;
                        perror("open");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    if (dup2(fd, STDOUT_FILENO) == -1) {
                        outputFound2 -= 1;
                        perror("dup2");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    close(fd);
                    free(output_redirection);
                }


                if (!pipe2) {
                    execute(args, argcount, &head);
                } else if (strcmp(args[0], "exit") == 0) {
                    execute(args2, argcount2, &head);
                    execute(args, argcount, &head);
                }
                else {
                    int fd[2];
                    int pid;
                   
                    int pipeCounts = 0;
                    if (pipe(fd) == -1) {
                        pipeCounts += 1;
                        perror("pipe");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    }
                    // USE NODES MAYBE
                    pid = fork();
                    if (pid == -1) {
                        pipeCounts += 1;
                        perror("fork");
                        if (!batch) {wait(NULL); write(1, "!", 1);}
                        exit(1);
                    } else if (pid == 0) {
                        pipeCounts -= 1;
                        close(fd[0]); 
                        dup2(fd[1], STDOUT_FILENO);
                        execute(args, argcount, &head);
                        allow_newline = 0;
                        close(fd[1]);
                        exit(0); // 
                    } else {
                        pipeCounts += 1;
                        close(fd[1]); 
                        dup2(fd[0], STDIN_FILENO);
                        execute(args2, argcount2, &head);
                        allow_newline = 1;
                        close(fd[0]);
                        // exit(0); // 
                    }
                    if (pipeCounts == 0) {

                    } // printf("pipes worked i think"); 

                }
                int reset = 0;
                dup2(originalSTDOUT, STDOUT_FILENO);
                close(originalSTDOUT);
                reset += 1;
                dup2(originalSTDIN, STDIN_FILENO);
                close(originalSTDIN);
                reset += 1;
                if (reset == 2){
                    // delete later
                }
                for (int i = 0; i < argcount+1; i++) {
                    free(args[i]);
                    
                }
                if (pipe2) {
                    for (int i = 0; i < argcount2+1; i++)
                    free(args2[i]);
                }
                
            // clear list
            // printf("free start\n");
            N* free_ptr = head->next;
            while (free_ptr != NULL) {
                // printf("free\n");
                N* free_temp = free_ptr;
                free_ptr = free_ptr->next;
                free(free_temp->word);
                free(free_temp);
            }
            size = 0;
            tail = head;
            if (allow_newline && !batch) {
                wait(NULL);
                write(1, "mysh> ", 6);
            }
        } else {
            // printf("ggg\n");
            N* new_node = (N*) malloc(sizeof(N));
            new_node->next = NULL;
            tail->next = new_node;
            tail = tail->next;
            size++;
            // printf("uuuu\n");
            new_node->word = (char*) malloc(sizeof(char) * (strlen(new_word) + 1));
            strcpy(new_node->word, new_word);
            // printf("iiii\n");
        }
        // printf("jjj\n");
        free(new_word);
        // printf("iii\n");
    }
    free(head);
    // printf("iiii\n");
    return EXIT_SUCCESS;
}
