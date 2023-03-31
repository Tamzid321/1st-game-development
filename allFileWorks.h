void swap(int *a, int *b)
{
   int t;

   t  = *b;
   *b = *a;
   *a = t;
}

void swap2(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}

void file()
{
	FILE *fp1=fopen("score.txt","r");
    FILE *fp2=fopen("name.txt","r");
    FILE *fp3=fopen("play.txt","r");


    fscanf(fp3,"%d",&numOfPlayers);

	for(int i=0;i<numOfPlayers;i++)
    {
        fgets(nameOfPlayers[i],100,fp2);
        //printf(a[i]);
        //printf("\n");
        fscanf(fp1,"%d",&score[i]);
        //printf("***%d***\n",x[i]);
    }
    int i,j;

    for(i=0;i<numOfPlayers-1;i++)
    {
        for(j=0;j<numOfPlayers-i-1;j++)
        {
            if(score[j]<score[j+1])
            {
                swap(&score[j],&score[j+1]);
                swap2(nameOfPlayers[j],nameOfPlayers[j+1]);
            }
        }
    }

    for(int k=0;k<numOfPlayers;k++)
    {
        //printf(nameOfPlayers[k]);
        //printf(" : %d\n",score[k]);
		itoa(score[k],scoreInString[k],10);
    }
	fclose(fp3);
    fclose(fp2);
    fclose(fp1);
}
