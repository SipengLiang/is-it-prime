#include "stdio.h"
#include "stdlib.h"


unsigned int plistSize;
unsigned long int cur;
unsigned int plistPos;

unsigned long int* appendPlist(unsigned long int* plist,
			       unsigned long int num);
unsigned long int* genPlist(unsigned long int stop);
int isP(unsigned long int n);

int main()
{
  long int num;
  printf("=== IsItPrime? (IIP) v1.0 ===\nInput 1 to exit.\n\n>>");
  scanf("%ld",&num);
  while(num != 1)
    {
      if(num > 0)
	{
	  
	  int res = isP(num);
	  if(res == 1)
	    {
	      printf("\t-> Prime\n");
	    }
	  else if(res == 0)
	    {
	      printf("\t-> Not Prime\n");
	    }
	  else if(res == -1)
	    {
	      printf("\t-> System out of memory, abort.\n");
	      return -1;
	  
	    }
	}
      else
	{
	  printf("\t-> Nice try but %ld is not 'natural'\n",num);
	}
      printf("\n>>");
      scanf("%ld",&num);
    }
  return 0;
}

int isP(unsigned long int n)
{
  unsigned long int* list = genPlist(n);
  if(!list)
    {
      return -1;
    }
  if(list[plistPos-1] != n)
    {
      free(list);
      return 0;
    }
  else
    {
      free(list);
      return 1;
    }
}

unsigned long int* genPlist(unsigned long int stop)
{
  plistSize = 64;
  cur = 3;
  plistPos = 0;
  unsigned long int* plist = (unsigned long int*)\
    calloc(plistSize,sizeof(unsigned long int));
  if(!plist) return NULL;
  plist[plistPos] = 2;
  plistPos++;
  while(cur <= stop)
    {
      int p = 1;
      for (unsigned int i = 0; i <= plistPos-1; i++)
	{
	  if(cur % plist[i] == 0)
	    {
	      if(cur == stop)
		{
		  printf("%ld %% %ld = 0\n",cur,plist[i]);
		}
	      p = 0;
	      break;
	    }
	}
      if(p)
	{
	  plist = appendPlist(plist, cur);
	  if(!plist)
	    {
	      return NULL;
	    }
	  /*printf("%d, \n",cur);*/
	}

      cur++;

    }


  return plist;

}


unsigned long int* appendPlist(unsigned long int* plist,
			       unsigned long int num)
{
  if(!plist) return NULL;
  if(plistPos == (plistSize -1) )
    {
      printf("Expand @ size=%d\n",plistSize);
      plistSize = plistSize *2;
      unsigned long int * plistNew = (unsigned long int*)\
	realloc(plist,plistSize*sizeof(unsigned long int));
      if(!plistNew) return NULL;
      plist = plistNew;
    }
  plist[plistPos] = num;
  plistPos++;
  return plist;
}



