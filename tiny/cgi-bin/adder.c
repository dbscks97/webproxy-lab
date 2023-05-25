#include "csapp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buf;
    char *p;
    char *cgiargs;
    int num1 = 0;
    int num2 = 0;

    /* Extract the query string */
    buf = getenv("QUERY_STRING");
    cgiargs = strchr(buf, '&');
    if (cgiargs) {
        *cgiargs = '\0';
        cgiargs++;
    }

    /* Parse the numbers */
    p = strchr(buf, '=');
    if (p) {
        *p = '\0';
        num1 = atoi(p + 1);
    }

    p = strchr(cgiargs, '=');
    if (p) {
        *p = '\0';
        num2 = atoi(p + 1);
    }
    int sum = num1 +num2;

    char *method = getenv("REQUEST_METHOD");


    /* Generate the HTTP response */
    if (strcmp(method, "HEAD") == 0) {
        /* Only send the headers for the HEAD request */
        printf("HTTP/1.0 200 OK\r\n");
        printf("Server: Tiny Web Server\r\n");
        printf("Content-Type: text/html; charset=utf-8\r\n");
        printf("\r\n");
    } 
    else if (strcmp(method, "GET") == 0) {
        printf("<html><body>\r\n");
        printf("Welcome to add.com: THE Internet addition portal.<br>\r\n");
        printf("The answer is: %d + %d = %d\r\n<br>",num1, num2, sum);
        printf("Thanks for visiting!\r\n");
        printf("<form><input type=\"button\" value=\"뒤로가기\" onclick=\"history.back()\"></form>\r\n");
        printf("</body></html>\r\n");
    }
    fflush(stdout);
    exit(0);
}