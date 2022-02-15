#include <stdio.h>

// calculate the value of a single view
int ft_count_blocks(int a, int b, int c, int d)
{
    if (a == 4)
    {
        return (1);
    }
    else if (a == 3 || b == 4)
    {
        return (2);
    }
    else if (b == 3)
    {
        return (3);
    }
    else if (a == 2 && c == 4)
    {
        return (2);
    }
    else if (a == 1 && d == 4)
    {
        return (4);
    }
    else
    {
        return (3);
    }
}

// create playbook with all possible and valid maps
void ft_create_playbook(int target_view[])
{
    int i, j, k, l, m, n, o, p, q, r, s, t, dim1;
    int playbook[576][16];

    dim1 = 0;
    i = 1;
    while (i <= 4)
    {
        j = 1;
        while (j <= 4)
        {
            k = 1;
            while (k <= 4)
            {
                l = 1;
                while (l <= 4)
                {
                    if (i != j && i != k && i != l && j != k && j != l && k != l)
                    {
                        m = 1;
                        while (m <= 4)
                        {
                            n = 1;
                            while (n <= 4)
                            {
                                o = 1;
                                while (o <= 4)
                                {
                                    p = 1;
                                    while (p <= 4)
                                    {
                                        if (m != n && m != o && m != p && n != o && n != p && o != p && i != m && j != n && k != o && l != p)
                                        {
                                            q = 1;
                                            while (q <= 4)
                                            {
                                                r = 1;
                                                while (r <= 4)
                                                {
                                                    s = 1;
                                                    while (s <= 4)
                                                    {
                                                        t = 1;
                                                        while (t <= 4)
                                                        {
                                                            if (q != r && q != s && q != t && r != s && r != t && s != t && q != m && r != n && s != o && t != p && q != i && r != j && s != k && t != l)
                                                            {
                                                                playbook[dim1][0] = i;                              //////////                  //////
                                                                playbook[dim1][1] = j;                          ////        ////                //////
                                                                playbook[dim1][2] = k;                      ////                ////            //////
                                                                playbook[dim1][3] = l;                  ////                        ////        //////
                                                                playbook[dim1][4] = m;               ///                                ///     //////
                                                                playbook[dim1][5] = n;               ///                                ///     //////
                                                                playbook[dim1][6] = o;               ///                                ///     //////
                                                                playbook[dim1][7] = p;               ///                                ///     //////
                                                                playbook[dim1][8] = q;               ///                                ///     //////
                                                                playbook[dim1][9] = r;               ///                                ///     //////
                                                                playbook[dim1][10] = s;              ///                                ///     //////
                                                                playbook[dim1][11] = t;              ///                                ///     //////
                                                                playbook[dim1][12] = 10 - i - m - q;    /////                       ////        //////
                                                                playbook[dim1][13] = 10 - j - n - r;        ////                ////            ///////////////////////////////
                                                                playbook[dim1][14] = 10 - k - o - s;            ////          ///               ///////////////////////////////
                                                                playbook[dim1][15] = 10 - l - p - t;                //////////                  ///////////////////////////////
                                                                dim1++;
                                                            }
                                                            t++;
                                                        }
                                                        s++;
                                                    }
                                                    r++;
                                                }
                                                q++;
                                            }
                                        }
                                        p++;
                                    }
                                    o++;
                                }
                                n++;
                            }
                            m++;
                        }
                    }
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    dim1--;
    // create value array
    int dictionary[576][16];

    while (dim1 >= 0)
    {
        dictionary[dim1][0] = ft_count_blocks(playbook[dim1][0], playbook[dim1][4], playbook[dim1][8], playbook[dim1][12]);
        dictionary[dim1][1] = ft_count_blocks(playbook[dim1][1], playbook[dim1][5], playbook[dim1][9], playbook[dim1][13]);
        dictionary[dim1][2] = ft_count_blocks(playbook[dim1][2], playbook[dim1][6], playbook[dim1][10], playbook[dim1][14]);
        dictionary[dim1][3] = ft_count_blocks(playbook[dim1][3], playbook[dim1][7], playbook[dim1][11], playbook[dim1][15]);
        dictionary[dim1][4] = ft_count_blocks(playbook[dim1][12], playbook[dim1][8], playbook[dim1][4], playbook[dim1][0]);
        dictionary[dim1][5] = ft_count_blocks(playbook[dim1][13], playbook[dim1][9], playbook[dim1][5], playbook[dim1][1]);
        dictionary[dim1][6] = ft_count_blocks(playbook[dim1][14], playbook[dim1][10], playbook[dim1][6], playbook[dim1][2]);
        dictionary[dim1][7] = ft_count_blocks(playbook[dim1][15], playbook[dim1][11], playbook[dim1][7], playbook[dim1][3]);
        dictionary[dim1][8] = ft_count_blocks(playbook[dim1][0], playbook[dim1][1], playbook[dim1][2], playbook[dim1][3]);
        dictionary[dim1][9] = ft_count_blocks(playbook[dim1][4], playbook[dim1][5], playbook[dim1][6], playbook[dim1][7]);
        dictionary[dim1][10] = ft_count_blocks(playbook[dim1][8], playbook[dim1][9], playbook[dim1][10], playbook[dim1][11]);
        dictionary[dim1][11] = ft_count_blocks(playbook[dim1][12], playbook[dim1][13], playbook[dim1][14], playbook[dim1][15]);
        dictionary[dim1][12] = ft_count_blocks(playbook[dim1][3], playbook[dim1][2], playbook[dim1][1], playbook[dim1][0]);
        dictionary[dim1][13] = ft_count_blocks(playbook[dim1][7], playbook[dim1][6], playbook[dim1][5], playbook[dim1][4]);
        dictionary[dim1][14] = ft_count_blocks(playbook[dim1][11], playbook[dim1][10], playbook[dim1][9], playbook[dim1][8]);
        dictionary[dim1][15] = ft_count_blocks(playbook[dim1][15], playbook[dim1][14], playbook[dim1][13], playbook[dim1][12]);
        dim1--;
    }
    // search for matching
    dim1 = 575;
    int x, y, counter, gotcha;

    x = 0;
    gotcha = 0;
    while (x <= dim1 && gotcha == 0)
    {
        y = 0;
        counter = 0;
        while (y < 16)
        {
            if (target_view[y] == dictionary[x][y])
            {
                counter++;
            }
            if (counter == 16)
            {
                gotcha = 1;
            }
            y++;
        }
        x++;
    }
    // display  SOLUTION
    if (gotcha == 1)
    {
        y = 0;
        while (y < 16)
        {
            printf("%d ", playbook[x - 1][y]);
            y++;
            if (y == 4)
                printf("\n");
            if (y == 8)
                printf("\n");
            if (y == 12)
                printf("\n");
        }
    }
    else
        printf("Error");
    printf("\n");
}

int check_strlen(char *argv1)
{
    int i;

    i = 0;
    while (argv1[i])
    {
        i++;
    }
    if (i == 31)
        return (1);
    else
        return (0);
}

int check_input_format(char *argv1)
{
    int i;

    i = 0;
    while (argv1[i] && i <= 29)
    {
        if ((argv1[i] >= '1' && argv1[i] <= '4') && (argv1[i + 1] == ' ') && (argv1[30] >= '1' && argv1[30] <= '4'))
            i = i + 2;
        else
            return (0);
    }
    return (1);
}

void change_to_integer_array(char *argv1, int *result)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv1[i] != '\0')
    {
        if (argv1[i] >= '1' && argv1[i] <= '4')
        {
            result[j] = (argv1[i] - '0');
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int target_view[16];
    // only one set of view is allowed as an input
    if (argc != 2)
    {
        printf("Error\n");
        return (0);
    }
    // input format check1 (lenght)
    if (check_strlen(argv[1]) != 1)
    {
        printf("Error\n");
        return (0);
    }
    // input format check2 (only 1,2,3,4 separated by spaces)
    if (check_input_format(argv[1]) != 1)
    {
        printf("Error\n");
        return (0);
    }
    // type casting from string to int
    change_to_integer_array(argv[1], target_view);
    // and finally: play the game
    ft_create_playbook(target_view);
    return (0);
}
