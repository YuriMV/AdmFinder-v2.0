/*
admin finder em c
by: vold
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX 100
#define BUFFER 300

void msg(char *str, int erro) {
    fprintf(stderr, "%s", str);
    exit(erro);
}

int main(int argc, char **argv) {
    
     if(argc != 3) {
         fprintf(stderr, "erro\n");
         fprintf(stderr, "uso: %s site lista.txt\n", argv[0]);
         exit(-1);
     }
     
   int call(void);
   void request(char psite[1024]);
   FILE *ptrfile = fopen(argv[2], "r"); 
   
    if (!ptrfile) {
      msg("erro ao abrir arquivo. \n", -1);
    }
    
    int count= 0;
  
   char armazena[MAX][BUFFER];
   
   while((fgets(armazena[count], BUFFER, ptrfile)) != NULL) {
     armazena[count][strlen(armazena[count]) + 1] = '\0';
     count++;
   }
    
    int j;
    char pathsite[1024];
    for (j = 0;j<count; j++) {
        strcpy(pathsite, argv[1]);
        strcat(pathsite, armazena[j]);
        request(pathsite);
    }
     
    fclose(ptrfile);
    return 0;
}
int call(void) {
  return 0;
}
void request(char psite[1024]) { 
   long int http_code = 0;
   CURL *curl;
    CURLcode res;

        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_URL, psite);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, call);
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if (http_code==301 || http_code==302 || http_code==200) {
            fprintf(stdout, "encontrado - >%s\n", psite);
        } else {
            fprintf(stdout, "not found - >%s\n", psite);
        }
        curl_easy_cleanup(curl);
}
