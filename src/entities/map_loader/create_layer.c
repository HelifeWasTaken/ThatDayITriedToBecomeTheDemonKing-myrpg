/*
** EPITECH PROJECT, 2020
** layer
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "distract/util.h"

bool create_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = dcalloc(sizeof(layer_t), 1);
    entity_t *managerentity = get_entity(game, LAYER_MANAGER);

    D_ASSERT(managerentity, NULL, "null", false);
    layer->manager = managerentity->instance;
    D_ASSERT(layer, NULL, "Layer could not be initted", false);
    layer->entity = entity;
    entity->instance = layer;
    layer->id = layer->manager->layers_count++;
    entity->z = layer->id;
    return (true);
}

void destroy_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;

    free(layer);
}

#include <math.h>
#include "myrpg/util.h"

void multiply_matrix(float *a, float *b, float *res)
{
    float mul[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i + k * 3] * b[k + j * 3];
        }
    }
    res[0] = mul[0][0];
    res[1] = mul[0][1];
    res[2] = mul[0][2];
    res[3] = mul[1][0];
    res[4] = mul[1][1];
    res[5] = mul[1][2];
    res[6] = mul[2][0];
    res[7] = mul[2][1];
    res[8] = mul[2][2];
}

void draw_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;
    vertex_map_t *map = &layer->manager->map;
    usize_t tilesetid = map->v_vertex.vec[layer->id].tileset;
    float defmatrix[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};

    float ax = 0.1;
    float az = 0.1;
    static float ay = 0; // not sure what it is
    float h = map->map_size.x; // maybe to change
    float xs = h / 2; // 120 ?
    float ys = az + h;
    float pretrans[9] = {0};
    float rot[9] = {0};
    float lambda = ay / h;
    float perspective_division[9] = {0};
    float posttrans[9] = {0};
    float alpha = 30;

    printf("%f\n", lambda);
    (void)ax;
    (void)ay;
    (void)xs;
    (void)ys;
    (void)posttrans;
    (void)pretrans;
    matrix_set_translation(pretrans, &VEC2F(ax, az));
    matrix_set_rotation(rot, alpha);
    matrix_set_scale(perspective_division, &VEC2F(lambda, lambda));
   // matrix_set_translation(posttrans, &VEC2F(xs, ys));
    matrix_compute(defmatrix, pretrans);
    matrix_compute(defmatrix, rot);
    matrix_compute(defmatrix, perspective_division);
    matrix_compute(defmatrix, posttrans);

    /*
    double lambda = 120.f;
    double alpha = -0.2f;

    matrix_set_rotation(matrix, alpha);
    matrix_compute(defmatrix, matrix);
    //matrix_set_translation(matrix, &VEC2F(0, lambda));
    matrix_compute(defmatrix, matrix);
    matrix_set_scale(matrix, &VEC2F(lambda, lambda));
    matrix_compute(defmatrix, matrix);
   double lam, xs, ys;
   lam = 0 * 0.16/0.16;
   xs = 120 * 0;
   ys = 128 * 0;
*/
    ay++;
    for (int i = 0; i < 9; i++) {
        map->states.transform.matrix[i] = defmatrix[i];
    }
    if (layer->id == map->v_vertex.size - 1)
        return;
    map->states.texture = map->v_texture.tileset[tilesetid];
    sfRenderWindow_drawVertexArray(game->window,
        map->v_vertex.vec[layer->id].vertex, &map->states);
}