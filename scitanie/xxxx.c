    #include <stdio.h>
     
    int main()
    {
      int vstup;
 	int c;
	int k;
     
      printf("Enter an integer in decimal number system\n");
      scanf("%d", &vstup);
     
      printf("%d in binary number system is:\n", vstup);
     
      for (c = 31; c >= 0; c--)
      {
        k = vstup >> c;
     
        if (k & 1)
          printf("1");
        else
          printf("0");
      }
     
      printf("\n");
     printf("%d",k);
printf("%d", c);
printf("%d", vstup);
      return 0;
    }
