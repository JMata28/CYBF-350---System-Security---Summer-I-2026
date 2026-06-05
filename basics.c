#include <stdio.h>

int if_example(){
    int x = 3;
    if (x == 5){
        printf("My number is five!");
    }
    else if(x == 3){
        printf("My number is three!");
    }
    else{
        printf("My number is NOT five or three!");
    }
    return 0;
}

int if_example2(){
    int x = 5;
    int y = 10;
    if (x == 6 || x == 3){ //the || symbol means OR and it sees if one or more of the conditions is True
        printf("My number is either six or three!");
    }
    else if (x == 5 && x < y){  //The && means that both conditions must be true
        printf("My number is five, which is less than y!");
    }
    else{
        printf("Neither of the previous if statements were true!");
    }
    return 0;
}

int switch_example(){
    int answer;
    printf("Choose an option from 1 to 3:\n");
    scanf("%d", &answer);
    switch (answer){
        case 1:
            printf("You chose one!\n");
            break;
        case 2:
            printf("You chose two!\n");
            break;
        case 3:
            printf("You chose three!\n");
            break;
        default:
            printf("You chose an invalid number.\n");
    }
    return 0;
}

void function_example(char name[]){
    printf("Hello %s\n", name);
};

void for_loop_example(int x){
    int i;
    for (i = x; i < 10; i+=2){
        printf("%d\n", i);
    }
}

int main(){
    //if_example();
    // if_example2();
    // switch_example();
    // function_example("John");
    // function_example("Lilly");
    for_loop_example(5);
    return 0;
}