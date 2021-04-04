#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
char *str = "aaa1010101bbb400ccc";
//char *str = "12345";
char dst[64];
char Outstr[256];
 
char ChangeBase(char *number)
{
    int max = number[0];
    int len = 1;//Мы можем оказаться на \0 в дальнейшем. По этому я использую 0 и далее -1;
    //Try find base
    for (int i = 1; number[i] != '\0'; i++) {
        max = (max < number[i]) ? (number[i]) : (max);
        len++;
    }
 
    //base
    max-=47;
    //printf("len:%d\n", len); 
    //printf("max:%d\n", max); 
    char output = 0;
//Changing base
    
    for (int i = 0;i < len; i++){
    output += (number[i] - 48)* pow(max, len-i-1) ; // Тк мы используем 0 степень
    //printf("%d:", number[i]-48);
    }
 
 
 
    //printf("\n%s\n\n", number);
    //printf("Output:%d\n\n", output);
    return output;
}
 
void main()
{
/*TODO:
//[x]1)Найти промежутки с последовательностью цифр
//[x]2)Найти систему счисления и перевести её в 10ный вид
//[x]3)Вывести в виде значения ASCII 
//[x]4)Забытый пункт
//Я вижу, что это ужасный код. Может я его перепишу.
*/
 
 
    memcpy(Outstr,"",1);
    int j = 0;
    int l = 0;
    int len = strlen(str);
    for (int i = 0; i < len+1; i++) {//len +1, для выполнения else если строка заканчивается на число.
        if (isdigit(str[i])) {
            dst[j] = str[i];
            //printf("%c\n", str[i]);
            j++;
            l++;
        } else {
            
            if (j != 0) {
                dst[j] = '\0';
    //          printf("Send:%s\n",dst);
                //Преобразовать в число в нужной системе счисления и вывести
                char result = ChangeBase(dst);
                printf("%d:[%c]\n", result, result);
                
                strncat(Outstr, (char*)&result, 1);//Тк мы встретили не число, то его нужно дописать в строку
                strncat(Outstr, &str[i], 1);
                *dst = '\0';
                j = 0;
                l++;
 
            }else{
            strncat(Outstr, &str[i], 1);
            }
            
        }
    }
printf("\n%s\n", Outstr);
}
 