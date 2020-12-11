#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <string.h>
#include <curl/curl.h>


/*
    Example/ follow along of libcurl from jacob sorber yt
    Download a file, default prints it out to stdout.
    Modified it to print it into its filetype in current directory.

    Purpose: user supplies Url and program downloads contents and saves it as appropriate filetype.
*/

//Function prototypes
int curl_process(char* url);

//global
static FILE *filePointer; 

//Curl callback function 
size_t got_data(char *buffer, size_t itemsize, size_t nitems, void* additionalObj){
    size_t bytes = itemsize * nitems;

    //global access File ptr
    fwrite(buffer, itemsize,nitems,filePointer);

    printf("chunk size from download: (%zu bytes) \n", bytes); //check chunks received size
    return bytes;
}

int main(int argc, char * argv[]){

    if(argc < 2) {
        printf("Supply URL of item you wish to download as second command argument: %s %s\n",argv[0], argv[1]);
        printf("Example local usage: ./download_curl https://yolo.com/readme.md \n");
        return EXIT_FAILURE;
    } else if(argc == 2){
        //check to see if an option has been provided
        //examine first character for -
        if(argv[1][0] == '-'){
            //few options, so iterate through them
            if(strcmp(argv[1],"-h") == 0){
                printf("Usage: download_url <url> [options...]\n");
                printf("-h \t Display list of options\n");
                return EXIT_SUCCESS;
            }
            else{
                fprintf(stderr,"Invalid option passed. %s\n",argv[1]);
                return EXIT_FAILURE;
            }
        }
        else{
            //user did not select an option during invocation proceed normally
            curl_process(argv[1]);

        }


    } else if(argc == 3){
        if(strcmp(argv[2],"-h") == 0){
            printf("Usage: download_url <url> [options...]\n");
            printf("-h \t Display list of options\n");
            return EXIT_SUCCESS;
        }
        else{
            fprintf(stderr,"Invalid option passed.\n");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int curl_process(char * url){

    CURL *curl = curl_easy_init(); //initialize curl typedef

    //double check curl init correctly
    if(!curl){
        fprintf(stderr,"curl init failure");
        return EXIT_FAILURE;
    }

    //set options
    //curl detect protocol in 3rd param automatically
    printf("Downloading: %s now\n", url);
    curl_easy_setopt(curl, CURLOPT_URL,url);

    //to do something with data we need to set another option in setopt: got_data call (callback function)
    //provide a function pointer for curl setopt
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, got_data);

    //begin writing to file - hardcoded html rn
    //TODO account for file type
    
    char * filename = "result.html"; //hardcoded rn
    filePointer = fopen(filename, "w");

    //perform out action
    //use a CURLcode type to detect return status on performance of op
    CURLcode download_result = curl_easy_perform(curl);
    if(download_result != CURLE_OK){
        fprintf(stderr,"Download error for %s: %s\n",url,curl_easy_strerror(download_result));
    }

    fclose(filePointer);

    curl_easy_cleanup(curl); //cleaup curl


    return EXIT_SUCCESS;
}



