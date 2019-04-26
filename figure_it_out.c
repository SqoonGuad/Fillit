/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_it_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsmith <rsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:18:12 by rsmith            #+#    #+#             */
/*   Updated: 2019/04/25 16:51:21 by rsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     put_it_there(char **row, char **piece, int x, int y)
{
    int     a;
    int     b;

    a = 0;
    b = 0;
    while (piece[a] != 0)
    {
        while (piece[a][b] != 0)
        {
            if (piece[a][b] != '.')
            {
                row[x + a][y + b] = piece[a][b];
            }
            b++;
        }
        b = 0;
        a++;
    }
    return (0);
}

int     ten_second_tidy(char **row, char **piece, int x, int y)
{
    int     a;
    int     b;

    a = 0;
    b = 0;
    while (piece[a] != 0)
    {
        while (piece[a][b] != 0)
        {
            if (piece[a][b] != '.')
            {
                row[x + a][y + b] = '.';
            }
            b++;
        }
        b = 0;
        a++;
    }
    return (0);
}

int     is_this_legit(char **row, char **piece, int x, int y)
{
    int     a;
    int     b;

    a = 0;
    b = 0;
    while (piece[a] != 0)
    {
        if (row[x + a] == 0)
            return (0);
        while(piece[a][b] != 0)
        {
            if (row[x + a][y + b] == 0)
                return (0);
            if (piece[a][b] != '.' && row[x + a][y + b] != '.')
                return (0);
            b++;
        }
        b = 0;
        a++;
    }
    return (1);
}

int     my_brain(char **row, char **piece, int i)
{
    int     a;
    int     b;

    a = 0;
    b = 0;
    if (piece[i] == 0)
        return (0);
    while (row[a] != 0)
    {
        while (row[a][b] != 0)
        {
            if (is_this_legit(row, piece[i], a, b))
            {
                put_it_there(row, piece[i], a, b);
                if (my_brain(row, piece, i + 1))
                    return (0);
                ten_second_tidy(row, piece[i], a, b);
            }
            b++;
        }
        b = 0;
        a++;
    }
    return (1);
}

int     work(char ***piece)
{
    int     tiny;
    char    **row;

    //tiny = 
    //row =
    while (my_brain(row, piece, 0))
    {
        tiny++;
        //freerow(row);
        //row =
    }
    //print_row
    return (0);
}