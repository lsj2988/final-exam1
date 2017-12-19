#include <stdio.h>
#include <string.h>

char getch()
{
    char str[10];
    char ch;
    
    fgets(str,3,stdin);
    str[strlen(str)-1] = '\0';

    ch = str[0];

    return ch;
}

void get_info(info *arr,int *i)
{
    int input;
    
    char name[20];
    char ch;

    while(input > 0)
    {
        printf("Student Number : ");
        input = scanf("%d",&arr[*i].sm);
        fflush(stdin);
        
        printf("Name : ");
        fgets(name,sizeof(name),stdin);
        name[strlen(name)-1] = '\0';
        strncpy(arr[*i].name,name,strlen(name));

        printf("Korean grade : ");
        scanf("%lf",&arr[*i].kor);
        fflush(stdin);

        printf("Math grade : ");
        scanf("%lf",&arr[*i].math);
        fflush(stdin);

        printf("English grade : ");
        scanf("%lf",&arr[*i].eng);
        fflush(stdin);

        arr[*i].tot = arr[*i].kor + arr[*i].math + arr[*i].eng;

        arr[*i].avg = arr[*i].tot / 3;
        
        (*i)++;
    }
}

void Save(info *arr,int *i)
{
    int j;
    FILE *fp = fopen("student.txt","wb");
    if(fp == NULL)
    {
        return;
    }

    for(j=0;j<(*i);j++)
    {
        fwrite(&arr[*i].sm,sizeof(arr[*i].sm),1,fp);
        fwrite(&arr[*i].kor,sizeof(arr[*i].kor),1,fp);
        fwrite(&arr[*i].math,sizeof(arr[*i].math),1,fp);
        fwrite(&arr[*i].eng,sizeof(arr[*i].eng),1,fp);
        fwrite(&arr[*i].tot,sizeof(arr[*i].tot),1,fp);
        fwrite(&arr[*i].avg,sizeof(arr[*i].avg),1,fp);
        fwrite(arr[*i].name,sizeof(arr[*i].name),1,fp);
    }
    
    fclose(fp);
}

void Load(info *arr, int *i)
{
    FILE *fp = fopen("student.txt","rb");
    if(fp == NULL)
    {
        return;
    }
    
    while(1)
    {
        fread(&arr[*i].sm,sizeof(arr[*i].sm),1,fp);
        fread(&arr[*i].kor,sizeof(arr[*i].kor),1,fp);
        fread(&arr[*i].math,sizeof(arr[*i].math),1,fp);
        fread(&arr[*i].eng,sizeof(arr[*i].eng),1,fp);
        fread(&arr[*i].tot,sizeof(arr[*i].tot),1,fp);
        fread(&arr[*i].avg,sizeof(arr[*i].avg),1,fp);
        fread(arr[*i].name,sizeof(arr[*i].name),1,fp);

        if(feof != 0)
            break;

        i++;
    }
    
    fclose(fp);
}

void print_info(info *arr,int *i)
{
   int j;

   for(j=0;j<(*i);j++)
   {
       printf("Student Number : %d\n",arr[j].sm); 
       printf("Name : %s\n",arr[j].name);
       printf("Korean : %.0lf\n",arr[j].kor);
       printf("Math : %.0lf\n",arr[j].math);
       printf("English : %.0lfn\n",arr[j].eng);
       printf("Total : %.0lf\n",arr[j].tot);
       printf("Average : %.1lf\n",arr[j].avg);
   }
}
