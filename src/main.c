#include <curses.h>
#include <stdio.h>
#include "geom.h"
#include "model.h"
#include "obj.h"
#include <string.h>

int main()
{
    MODEL_t model;

    obj_read_model(&model);
    //model_print_vertices(&model);

	return 0;
}