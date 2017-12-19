#include <stdio.h>
#include <string.h>

#include "info1.h"
#include "Func1.h"

int main(void)
{
    char menu;
    
    while(menu != 'Q')
    {
        printf("1.Input\n2.Print\n3.Save\n4.Load\n5.Exit\n");
        menu = getch();
        switch(menu)
        {
            case '1':
            get_info(arr,&i);
            break;

            case '2':
            print_info(arr,&i);
            break;

            case '3':
            Save(arr,&i);
            break;

            case '4':
            Load(arr,&i);
            break;

            case '5':
            menu = 'Q';
            break;
        }
    }
    return 0;
}
