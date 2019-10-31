
int main()
{

  int a = 2, b, c = 10;
  b = a + c + 8;

  float f = 10.2;
  f = f + a;

  char ch = 'z';
  ch = 'U';

  int x = ((a * 2) / 3 ) + 3;
  a = 0;
  while(f!=0)
    printf("f = %f", f);
    f = 0;
  f=a;
  f = f + f;
  printf("f = %f", f);

  printf("a=%d, b=%d, c=%d", a, b, c);
  c = c + b;
  printf("a=%d, b=%d, c=%d", a, b, c);
  printf("ch = %c\t f=%f", ch, f);

  printf("x = %d", x);

  return 0;
}
