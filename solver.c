#include "fillit.h"
/*
** The check function validates the current position we are trying to place the block in,
** using the "coordinates" of the current block and comparing whether there is another block
** or if the block would be placed outside of the current map. 
** Coordinates need to be added to the t_etris struct. 
*/
int     check(t_map **map, t_etri piece, int curx,int cury)
{
    int x;
// curx + cury || cur_pos
    x = 0;
    if (map[curx][cury] == ".")
        x++;
    if ((curx + piece->pos[2] > map_size) || (cury + piece->pos[3] > map_size))
        return (0);
    if (map[curx + piece->pos[2]][cury + piece->pos[3]] == ".")
        x++;
    if ((curx + piece->pos[4] > map_size) || (cury + piece->pos[5] > map_size))
        return (0);    
    if (map[curx + piece->pos[4]][cury + piece->pos[5]] == ".")
        x++;
    if ((curx + piece->pos[6] > map_size) || (cury + piece->pos[7] > map_size))
        return (0); 
    if (map[curx + piece->pos[6]][cury + piece->pos[7]] == ".")
        x++;
    if (x = 4)
        return (1);
    return (0);
}

/*int     place(t_map map, t_etri piece, int cur_pos)
{
    int x;

    x = 0;
    while (x <= 4)
        map 
}*/

t_map/int   **solver(t_map **map, int map_size, t_list *lst,int cur_pos)
{
    t_etris piece;
    int     curx;
    int     cury;
    int     cur_pos;
    
    /*
     * Call with cur_pos starting with 0
     * Also add nb_pieces as a parameter
     */
    //piece = lst->content
    while (nb_pieces && cur_pos < (map_size^2))
    {
        curx = cur_pos % map_size;
        cury = cur_pos / map_size;
        if (check(map, cur_pos, piece))
        {
            place(map, cur_pos, piece); 
            //cur_pos++; <-- this is added a few rows down in the recursive call, DOUBLE CHECK LOGIC and remove from here.
            nb_pieces--;
            //piece = get_next_elem
            solver(map, map_size, lst->next, cur_pos + 1) //If solver == 0 : Erase from map?
                                            //cur_pos for recursion maybe from strichr?
        }
        cur_pos++;
    }
    if (nb_pieces == 0)
        return (1); // Return map or 1? Map will be modified anwyay
    return (0);
}
