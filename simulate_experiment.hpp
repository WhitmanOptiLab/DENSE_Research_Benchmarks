#ifndef SIM_EXP_H
#define SIM_EXP_H

#include "io/arg_parse.hpp"
#include "measurement/oscillation.hpp"
#include "measurement/basic.hpp"
#include "measurement/bad_simulation_error.hpp"
#include "utility/style.hpp"
#include "utility/common_utils.hpp"
#include "io/csvr_sim.hpp"
#include "io/csvw_sim.hpp"
#include "sim/determ/determ.hpp"
#include "sim/stoch/fast_gillespie_direct_simulation.hpp"
#include "sim/stoch/next_reaction_simulation.hpp"
#include "model_impl.hpp"
#include "io/ezxml/ezxml.h"
#include "arg_parse.hpp"
#include "parse_analysis_entries.hpp"
#include "../simulate_experiment.hpp"

using dense::run_simulation;
using dense::Sim_Builder;
using dense::parse_analysis_entries;


template<class Sim>
void simulate_experiment(int ac, char** av, Static_Args* args, std::string type){
  using Simulation = Sim;
  Sim_Builder<Simulation> sim = Sim_Builder<Simulation>(args->perturbation_factors, args->gradient_factors, args->adj_graph, ac, av);
  std::vector<std::pair<std::string, std::unique_ptr<Analysis<Simulation>>>> names_and_analysis = parse_analysis_entries<Simulation>(ac, av, args->adj_graph.num_vertices());
  for(auto& entry : names_and_analysis){
    entry.first = type + ".csv";
  }
  run_simulation<Simulation>(args->simulation_duration, args->analysis_interval, std::move(sim.get_simulations(args->param_sets)), std::move(names_and_analysis));
}

#endif