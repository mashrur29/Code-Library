#include<stdio.h>
#include<string.h>


       /*********************** Wrinting into Files *********************/

// process 1


int main(){
  FILE *fp;
  fp=fopen("tet.txt","w");

    fprintf(fp,"hdghd");
    fprintf(fp,"hdghd\n");
   fclose(fp);

   return 0;
}

// process 2


int main(){
  FILE *fp;
  fp=fopen("tet.txt","w");
  char str[100];

    scanf("%s",str);
    fprintf(fp,"%s\n",str);
    fprintf(fp,"%s\n",str);

   fclose(fp);

   return 0;
}


// process 3


int main(){
  FILE *fp;
 fp=fopen("t5.txt","a"); //clears the file
  char str[100];

    while(scanf("%s",str)==1){
    fputs(str,fp);
    fputs("\n",fp);
    }

 fclose(fp);
 return 0;
}


// process 4


int main(){
  FILE *fp;
 fp=fopen("t5.txt","w"); //clears the file
  char str[100];
  int num;

  while(scanf("%s %d",str,&num)==2){
  fprintf(fp,"%s %d",str,num);
  }

 fclose(fp);
 return 0;
}


       /*********************** Reading from Files *********************/

// process 1


int main(){
  FILE *fp;
 fp=fopen("t5.txt","r");
  char str[100];
  int num;

 while(fscanf(fp,"%s %d",str,&num)!=EOF){
  //fscanf(fp,"%s",str);
  printf("%s %d\n",str,num);
 }

 fclose(fp);
 return 0;
}


// process 2


int main(){
  FILE *fp;
 fp=fopen("t5.txt","r");
  char str[100];
  int num;

 while(fgets(str,100,fp)){ // takes each line at a time
  printf("%s",str);
 }

 fclose(fp);
 return 0;
}

       /*********************** Binary Files *********************/

struct threeSome{
    int n1,n2,n3;
};

// writing


int main(){
    int n;
    struct threeSome num;

    FILE *fp;
    fp=fopen("tnt.bin","wb");

    for(n=1;n<5;n++){
        num.n1=n;
        num.n2=5*n;
        num.n3=5*n+1;
        fwrite(&num, sizeof(struct threeSome), 1, * fp);
    }

    fclose(fp);
    return 0;
} 

// Reading

int main(){
    int n;
    struct threeSome num;

    FILE *fp;
    fp=fopen("tnt.bin","rb");

        for(n=1;n<5;n++){
            fread(&num,sizeof(struct threeSome),1,fp);
            printf("n1: %d\nn2: %d\nn3: %d\n",num.n1,num.n2,num.n3);
        }

   fclose(fp);
   return 0;
}

