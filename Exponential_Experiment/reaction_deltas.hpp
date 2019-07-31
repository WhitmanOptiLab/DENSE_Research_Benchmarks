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

STATIC_VAR int num_deltas_reaction1 = 1;
STATIC_VAR int deltas_reaction1[] = {1};
STATIC_VAR specie_id delta_ids_reaction1[] = {specie1};

STATIC_VAR int num_deltas_reaction2 = 1;
STATIC_VAR int deltas_reaction2[] = {-1};
STATIC_VAR specie_id delta_ids_reaction2[] = {specie1};

STATIC_VAR int num_deltas_reaction3 = 1;
STATIC_VAR int deltas_reaction3[] = {1};
STATIC_VAR specie_id delta_ids_reaction3[] = {specie2};

STATIC_VAR int num_deltas_reaction4 = 1;
STATIC_VAR int deltas_reaction4[] = {-1};
STATIC_VAR specie_id delta_ids_reaction4[] = {specie2};

STATIC_VAR int num_deltas_reaction5 = 1;
STATIC_VAR int deltas_reaction5[] = {1};
STATIC_VAR specie_id delta_ids_reaction5[] = {specie3};

STATIC_VAR int num_deltas_reaction6 = 1;
STATIC_VAR int deltas_reaction6[] = {-1};
STATIC_VAR specie_id delta_ids_reaction6[] = {specie3};

STATIC_VAR int num_deltas_reaction7 = 1;
STATIC_VAR int deltas_reaction7[] = {1};
STATIC_VAR specie_id delta_ids_reaction7[] = {specie4};

STATIC_VAR int num_deltas_reaction8 = 1;
STATIC_VAR int deltas_reaction8[] = {-1};
STATIC_VAR specie_id delta_ids_reaction8[] = {specie4};

STATIC_VAR int num_deltas_reaction9 = 1;
STATIC_VAR int deltas_reaction9[] = {1};
STATIC_VAR specie_id delta_ids_reaction9[] = {specie5};

STATIC_VAR int num_deltas_reaction10 = 1;
STATIC_VAR int deltas_reaction10[] = {-1};
STATIC_VAR specie_id delta_ids_reaction10[] = {specie5};

STATIC_VAR int num_deltas_reaction11 = 1;
STATIC_VAR int deltas_reaction11[] = {1};
STATIC_VAR specie_id delta_ids_reaction11[] = {specie6};

STATIC_VAR int num_deltas_reaction12 = 1;
STATIC_VAR int deltas_reaction12[] = {-1};
STATIC_VAR specie_id delta_ids_reaction12[] = {specie6};

STATIC_VAR int num_deltas_reaction13 = 1;
STATIC_VAR int deltas_reaction13[] = {1};
STATIC_VAR specie_id delta_ids_reaction13[] = {specie7};

STATIC_VAR int num_deltas_reaction14 = 1;
STATIC_VAR int deltas_reaction14[] = {-1};
STATIC_VAR specie_id delta_ids_reaction14[] = {specie7};