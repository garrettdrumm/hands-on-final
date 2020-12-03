/*Implementation of wc utility
  Based on http://www.gnu.org/software/cflow/manual/html_node/Source-of-wc-command.html
*/
#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned long count_t;

count_t charcount;
count_t wordcount;
count_t linecount;

count_t totalcountC = 0;
count_t totalcountW = 0;
count_t totalcountL = 0;

static void error_print(int perr, const char *fmt, va_list ap){
  vfprintf(stderr, fmt, ap);
  if(perr)
    perror(" ");
  else
    fprintf(stderr, "\n");
  exit(1);
}

static void error_f(const char *fmt)
{
  va_list ap;

  va_start(ap, fmt);
  error_print(0, fmt, ap);
  va_end(ap);
}

static void error_p(const char *fmt){
  va_list ap;

  va_start(ap, fmt);
  error_print(1, fmt, ap);
  va_end(ap);
}
void send(const char *file, count_t charcount, count_t wordcount, count_t linecount){
  printf("%6lu %6lu %6lu %s\n", linecount, wordcount, charcount, file);
}

static int wordcheck(unsigned char c){
  return isalpha(c);
}

#define COUNT(c)
  charcount++;
  if((c) == '\n')
    linecount++;

int countword(FILE *fp){
  int i;
  int word = 0;

  if (feof(fp))
    return 0;

  while((i = getc (fp)) != EOF){
    if(wordcheck(c)){
      wordcount++;
      break;
    }
    COUNT (c);
  }
  for(; c != EOF; c = getc (fp)){
    COUNT(c);
    if(!wordcheck (c))
      break;
  }
  return c != EOF;
}

unsigned long counter(const char *file){
  FILE *fp = fopen(file, "r");

  while (countword(fp));
    fclose(fp);

  send (file, ccount, wcount, lcount);
  totalcountC += charcount;
  totalcountW += wordcount;
  totalcountL += linecount;
  return count;
}

int main(int argc, char **argv){
  int i;
  if (argc < 2)
    error_f("usage: wc FILE [FILE...]");
  for(i = 1; i < argc; i++){
    counter(argv[i]);
  }
  if(argc > 2)
    report(total, totalcountC, totalcountW, totalcountL);
  return 0;
}
