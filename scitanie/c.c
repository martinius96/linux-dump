    #include <stdio.h>
    int main()
    {
      unsigned long n, c, k;
      printf("Vlozte cislo 0 - \n");
      scanf("%d", &n);
     
      printf("%d in binary number system is:\n", n);
     
      for (c = 31; c >= 0; c--)
      {
        k = n >> c;
     
        if (k & 1)
          printf("1");
        else
          printf("0");
      }
     
      printf("\n");
     
      return 0;
    }
