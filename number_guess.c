#include <stdio.h>

#define fourdots printf(".....  .....  .....  .....\n")
#define fourdots2 printf("\n:...:  :...:  :...:  :...:")
#define fivedots printf(".....  .....  .....  .....  .....\n")
#define fivedots2 printf("\n:...:  :...:  :...:  :...:  :...:")

int control_first(int);
int control_second(int);
int compare_first(int ,int);
int compare_second(int ,int);
void table4(int ,int ,int ,int);
void table5(int ,int ,int ,int,int);

int main()
{
    char yn;
    int id ,key ,guess ,right ,x ,cmp;

    printf("\nPlease enter your player ID:");
    scanf("%d",&id);
    printf("\nPlayer %d has entered the game.\n",id);
    printf("STAGE 1:\n");

        do{ printf("\nEnter a 4-digit number to be guessed:");
            scanf("%d",&key);
            x=control_first(key);
            if(x==0)printf("Invalid entry\n");
        }while(x==0);

        fourdots;
        printf(": x :  : x :  : x :  : x :");
        fourdots2;

            right=3;

            do{ printf("\nPlease %d guess:",id);
                scanf("%d",&guess);
                x=control_first(guess);
                    if(x==0)
                    {
                        right--;
                        if(right==0)
                        {
                            printf("\nYou have no more guess right! Logging off...\n");
                            return 0;
                        }
                        printf("\nInvalid input! You have %d more guess right!",right);
                    }
                    else
                    {
                        cmp=compare_first(guess,key);

                        if(cmp==0)
                        {
                            right--;
                            if(right==0)
                            {
                            printf("\nYou have no more guess right! Logging off...\n");
                            return 0;
                            }
                            printf("\nWrong guess! Try again. You have %d more guess right!",right);
                        }
                        else if(cmp==1)
                        {
                            printf("\nCongratulations! Player %d passed the first stage\n",id);
                            printf("Do you want to continue?(Y/N):");
                            getchar();
                            scanf("%c",&yn);
                        }
                    }
                    
                }while(cmp!=1);

        if(yn=='n' || yn=='N')
        {
            printf("Loading off...");
            return 0;
        }
        else if(yn=='y' || yn=='Y')
        {
            printf("STAGE 2:\n");
            
             do{ printf("\nEnter a 5-digit number to be guessed:");
                 scanf("%d",&key);
                 x=control_second(key);
                 if(x==0)printf("Invalid entry\n");
            }while(x==0);

            fivedots;
            printf(": x :  : x :  : x :  : x :  : x :");
            fivedots2;

            right=5;

            do{ printf("\nPlease %d guess:",id);
                scanf("%d",&guess);
                x=control_second(guess);
                    if(x==0)
                    {
                        right--;
                        if(right==0)
                        {
                            printf("\nYou have no more guess right! Logging off...\n");
                            return 0;
                        }
                        printf("\nInvalid input! You have %d more guess right!",right);
                    }
                    else
                    {
                        cmp=compare_second(guess,key);

                        if(cmp==0)
                        {
                            right--;
                            if(right==0)
                            {
                            printf("\nYou have no more guess right! Logging off...\n");
                            return 0;
                            }
                            printf("\nWrong guess! Try again. You have %d more guess right!",right);
                        }
                        else if(cmp==1)
                        {
                            printf("\nCongratulations! Player %d passed the second stage!\n",id);
                            printf("You have won all the stages\n");
                            return 0;
                        }
                    }

                }while(cmp!=1);
        }
        else
        {
            printf("Invalıd input\n");
            return 0;
        }
    return 0;
}

int control_first(int a)
{
    if(a<10000 && a>=1000)return 1;
    else return 0;
}

int control_second(int a)
{
    if(a<100000 && a>=10000)return 1;
    else return 0;
}


int compare_first(int guess ,int key)
{
    int a,b,c,d;
    a=b=c=d=-1;
    if((guess-guess%1000)/1000==(key-key%1000)/1000) a=(key-key%1000)/1000;
    else
    {
        table4(a,b,c,d);
        return 0;
    } 

    guess=guess-1000*a;
    key=key-1000*a;

    if((guess-guess%100)/100==(key-key%100)/100) b=(key-key%100)/100;
    else
    {
        table4(a,b,c,d);
        return 0;
    } 

    guess=guess-100*b;
    key=key-100*b;

    if((guess-guess%10)/10==(key-key%10)/10) c=(key-key%10)/10;
    else
    {
        table4(a,b,c,d);
        return 0;
    } 

    guess=guess-10*c;
    key=key-10*c;

    if(guess==key) 
    {
        d=key;
        table4(a,b,c,d);
        return 1;
    }
    else
    {
        table4(a,b,c,d);
        return 0;
    } 
}

int compare_second(int guess ,int key)
{
    int a,b,c,d,e;
    a=b=c=d=e=-1;

    if((guess-guess%10000)/10000==(key-key%10000)/10000) a=(key-key%10000)/10000;
    else
    {
        table5(a,b,c,d,e);
        return 0;
    }

    guess=guess-10000*a;
    key=key-10000*a;

    if((guess-guess%1000)/1000==(key-key%1000)/1000) b=(key-key%1000)/1000;
    else
    {
        table5(a,b,c,d,e);
        return 0;
    } 

    guess=guess-1000*b;
    key=key-1000*b;

    if((guess-guess%100)/100==(key-key%100)/100) c=(key-key%100)/100;
    else
    {
        table5(a,b,c,d,e);
        return 0;
    } 

    guess=guess-100*c;
    key=key-100*c;

    if((guess-guess%10)/10==(key-key%10)/10) d=(key-key%10)/10;
    else
    {
        table5(a,b,c,d,e);
        return 0;
    } 

    guess=guess-10*d;
    key=key-10*d;

    if(guess==key) 
    {
        e=key;
        table5(a,b,c,d,e);
        return 1;
    }
    else
    {
        table5(a,b,c,d,e);
        return 0;
    } 
}

void  table4(int a ,int b ,int c ,int d)
{
    if(a==-1)
    {
        fourdots;
        printf(": x :  : x :  : x :  : x :");
        fourdots2;
    }
    else if(b==-1)
    {
        fourdots;
        printf(": %d :  : x :  : x :  : x :",a);
        fourdots2;
    }
    else if(c==-1)
    {
        fourdots;
        printf(": %d :  : %d :  : x :  : x :",a,b);
        fourdots2;
    }
    else if(d==-1)
    {
        fourdots;
        printf(": %d :  : %d :  : %d :  : x :",a,b,c);
        fourdots2;
    }
    else 
    {
        fourdots;
        printf(": %d :  : %d :  : %d :  : %d :",a,b,c,d);
        fourdots2;
    }
}

void table5(int a ,int b ,int c ,int d ,int e)
{
    if(a==-1)
    {
        fivedots;
        printf(": x :  : x :  : x :  : x :  : x :");
        fivedots2;
    }
    else if(b==-1)
    {
        fivedots;
        printf(": %d :  : x :  : x :  : x :  : x :",a);
        fivedots2;
    }
    else if(c==-1)
    {
        fivedots;
        printf(": %d :  : %d :  : x :  : x :  : x :",a,b);
        fivedots2;
    }
    else if(d==-1)
    {
        fivedots;
        printf(": %d :  : %d :  : %d :  : x :  : x :",a,b,c);
        fivedots2;
    }
    else if(e==-1)
    {
        fivedots;
        printf(": %d :  : %d :  : %d :  : %d :  : x :",a,b,c,d);
        fivedots2;
    }
    else 
    {
        fivedots;
        printf(": %d :  : %d :  : %d :  : %d :  : %d :",a,b,c,d,e);
        fivedots2;
    }

}