#include <stdio.h>
#include <stdlib.h>

int ini_max_stars(int size)
{
    int i;
    int res;
    int nb_ligne;
    int j;
    int nb_saut;
    int k;

    i = 0;
    res = 1;
    nb_ligne = 4;
    nb_saut = 2;
    k = 1;
    while (i < size)
      {
	j = k; 
	while (j < nb_ligne)
	  {
	    res += 2;
	    j++;
	  }
	i++;
	if (i < size)
	  res -= nb_saut;
	nb_ligne++;
	if (i % 2 == 0)
	  nb_saut += 2;
      }
    return (res);
}

void    repeat_print(int nb, char c)
{
  int   i;
  i = 0;
  while (i < nb)
    {
      putchar(c);
      i++;
    }
}
void    print_tronc(int size, int nb_space_tronc)
{
  int   i;

  i = 0;
  while (i < size)
    {
      repeat_print(nb_space_tronc, ' ');
      repeat_print(size, '|');
      putchar('\n');
      i++;
    }
}

void    tree(int size)
{
    int nb_stars;
    int max_stars;
    int nb_space;
    int nb_ligne;
    int nb_space_tronc;
    int i;
    int j;
    int skip;

    skip = 1;
    nb_stars = 1;
    max_stars = ini_max_stars(size);
    nb_space = (max_stars - size) / 2 + size;
    if (size % 2 != 0)
      nb_space--;
    nb_ligne = 4;
    nb_space_tronc = max_stars / 2;
    i = 0;
    while (i < size)
      {
        j = 0;
        while (j < nb_ligne)
        {
          repeat_print(nb_space, ' ');
          repeat_print(nb_stars, '*');
          putchar('\n');
          nb_stars += 2;
          nb_space-= 1;
          j++;
        }
        nb_ligne++;
        i++;
        if ((i % 2) == 0)
          skip++;
        nb_space += skip;
        nb_stars -= 2 * skip;
      }
    if (size % 2 != 0)
      print_tronc(size, nb_space_tronc);
    else
      print_tronc(size + 1, nb_space_tronc);
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      tree (atoi(av[1]));
    }
  return (0);
      
}
