#include "core/reaction.hpp"

#include <cstddef>

/*

Define each reaction's reactants and products in `reaction_deltas.hpp`.
Say a reaction enumerated as `R_ONE` has the following chemical formula:

                           2A + B --> C

The proper way to define that reaction's state change vector is as follows:
        
        STATIC_VAR int num_deltas_R_ONE = 3;
        STATIC_VAR int deltas_R_ONE[] = {-2, -1, 1};
        STATIC_VAR specie_id delta_ids_R_ONE[] = {A, B, C};

*/

STATIC_VAR int num_deltas_reaction1 = 2;
STATIC_VAR int deltas_reaction1[] = {-1, 1};
STATIC_VAR specie_id delta_ids_reaction1[] = {specie1,specie2};

STATIC_VAR int num_deltas_reaction2 = 2;
STATIC_VAR int deltas_reaction2[] = {-1, 2};
STATIC_VAR specie_id delta_ids_reaction2[] = {specie4,specie1};

STATIC_VAR int num_deltas_reaction3 = 3;
STATIC_VAR int deltas_reaction3[] = {-1, 1, 1};
STATIC_VAR specie_id delta_ids_reaction3[] = {specie2,specie1,specie3};

STATIC_VAR int num_deltas_reaction4 = 3;
STATIC_VAR int deltas_reaction4[] = {-2, -1, 1};
STATIC_VAR specie_id delta_ids_reaction4[] = {specie1,specie3,specie4};

STATIC_VAR int num_deltas_reaction5 = 2;
STATIC_VAR int deltas_reaction5[] = {-2, 2};
STATIC_VAR specie_id delta_ids_reaction5[] = {specie4,specie3};

STATIC_VAR int num_deltas_reaction6 = 4;
STATIC_VAR int deltas_reaction6[] = {-1, -1, 1, 1};
STATIC_VAR specie_id delta_ids_reaction6[] = {specie1,specie4,specie3,specie2};

STATIC_VAR int num_deltas_reaction7 = 4;
STATIC_VAR int deltas_reaction7[] = {-1, -1, 1, 1};
STATIC_VAR specie_id delta_ids_reaction7[] = {specie3,specie2,specie1,specie4};