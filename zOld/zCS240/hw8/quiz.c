#include <stdio.h>

int main() {
    char str1[] = "Hello!";
    char *str2 = "sup!";
    

    str2[0] = 'X';
  
  
    printf("%s %s", str1, str2);
}
